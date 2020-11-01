# A researcher is interested in how variables, such as GRE (Graduate Record Exam scores), GPA (grade point average) and prestige of the undergraduate institution, effect admission into graduate school. The response variable, admit/don’t admit, is a binary variable.
#This dataset has a binary response (outcome, dependent) variable called admit. There are three predictor variables: gre, gpa and rank. We will treat the variables gre and gpa as continuous. The variable rank takes on the values 1 through 4. Institutions with a rank of 1 have the highest prestige, while those with a rank of 4 have the lowest. 
#See https://stats.idre.ucla.edu/r/dae/logit-regression/ for more details

#This will remove (almost) everything in the working environment before you start
rm(list=ls())

#if you set the seed you will get the same results every time, if not, you will get different results every time.
set.seed(123)   #try putting a # in front of this line and run the code a few times to see what happens, then remove the # and run it a few times to see the difference...

#Load the library caret
#For more details on caret see https://topepo.github.io/caret/index.html
library('caret')

#Load the library Hmisc and corrplot
library('Hmisc')
library('corrplot')

########################################
#         read in the data             #
########################################

data <- read.csv("binary.csv")

str(data)

summary(data)

print(describe(data))

########################################
#         Visualizing Data             #
########################################

jpeg("hist.jpg")
par(mfrow=c(1,3))
boxplot(data$gre, main="",xlab="GRE",cex = 1.5, cex.axis=1.5, cex.lab=1.5)
boxplot(data$gpa, main="",xlab="GPA",cex = 1.5, cex.axis=1.5, cex.lab=1.5)
boxplot(data$rank, main="",xlab="Rank",cex = 1.5, cex.axis=1.5, cex.lab=1.5)
dev.off()

correlationMatrix <- cor(data[, 1:4])
jpeg("correlationMatrix.jpg")
corrplot(correlationMatrix, method = "circle")
dev.off()

#What else should you do to check the quality of your data?
#Data Quality Report
#Identify and handle any data quality issues e.g. missing values, irregular cardinality or outliers
#Feature Selection
#Normalization?

########################################
#        Training And Test Sets        #
########################################

#Factors are variables in R which take on a limited number of different values; such variables are often referred to as categorical variables. Since categorical variables enter into models differently than continuous variables, storing data as factors insures that the modelling functions will treat such data correctly.
#Factors in R are stored as a vector of integer values with a corresponding set of character values to use when the factor is displayed. The factor function is used to create a factor. 
data$admit <- factor(data$admit,labels=c('reject','admit'))

#We convert rank to a factor to indicate that rank should be treated as a categorical variable.
data$rank <- factor(data$rank)
is.factor(data$rank)

#The function createDataPartition can be used to create a stratified random sample of the data into training and test sets:
#see ?createDataPartition for more details of the function
#create a training set with 75% of the date
inTraining <- createDataPartition(data$admit, p = .75, list = FALSE)
training <- data[ inTraining,]#this is the training set
testing  <- data[-inTraining,]#this is the test set

#For best results the number of instances of both classes needs to be present at more or less the same ratio in your training and test sets. You can check this using:
table(training$admit)
table(testing$admit)

#How many students in the training set are admitted?
#training$admit
#  0   1 
#204  96 

#How many students in the test set are admitted?
#testing$admit
# 0  1 
#69 31 

#What issues does this raise?
#There are more than twice as many non-admitted students as admitted students
#This means that the data sat is "unbalanced"
#We could use sampling to "balance" the dataset, or we can chose to be very careful with our evaluation metrics i.e. do not depend on one metric (e.g. accuracy!)

########################################
#    Build Logistic Regression Model   #
########################################

#The training set will be used to fit our model which we will be testing with the testing set. See ?glm for more details.
glm.fit <- glm(admit ~ gre+gpa+rank,data=training,family="binomial")

#what results would you get if you use a difference set of features?
#gre+gpa+rank F1_measure = 0.8181818
#gre+gpa F1_measure = 0.8025478
#gpa+rank F1_measure = 0.8205128
#gre F1_measure = 0.7721519
#gpa F1_measure = 0.8143713
#rank F1_measure = 0.8258065

#By using function summary() we obtain the results of our model:
summary(glm.fit)
#See here: https://stats.idre.ucla.edu/r/dae/logit-regression/ for more details on how to interpret the output



########################################
#        Model Evaluation              #
########################################

#Assessing the predictive ability of the model
#By setting the parameter type='response', R will output probabilities in the form of P(y=1|X). Our decision boundary will be 0.5. If P(y=1|X) > 0.5 then y = 1 otherwise y=0. Note that for some applications different thresholds could be a better option.
glm.probs <- predict(glm.fit,testing, type='response')#predicted probabilities
glm.pred = ifelse(glm.probs > 0.5, "admit", "reject")

table(glm.pred, testing$admit)
Accuracy <- mean(glm.pred == testing$admit)
print('Accuracy')
print(Accuracy)

#Is there any problem with using Accuracy?
#What other metrics might be better?
#(Take a look at last week's Lab!)

# The columns are target, while rows are predicted.
#see ?confusionMatrix for more details
cm<-confusionMatrix(data=as.factor(glm.pred), reference=testing$admit)

print(cm)

cmt<-cm$table

print(cmt)

cmbc<-cm$byClass

print(cmbc)

TP= cmt[1,1]
TN= cmt[2,2]
FN= cmt[2,1]
FP= cmt[1,2]

print('TP')
print(TP)
print('TN')
print(TN)
print('FP')
print(FP)
print('FN')
print(FN)

classification_accuracy=(TP+TN)/(TP + TN + FP + FN)
misclassification_rate=(FP + FN)/(TP + TN + FP + FN)

print("classification_accuracy")
print(classification_accuracy)

print("misclassification_rate")
print(misclassification_rate)

TRP=TP/(TP+FN)
TNR=TN/(TN+FP)
FPR=FP/(TN+FP)
FNR=FN/(TP+FN)

precision=TP/(TP+FP)
recall=TP/(TP+FN)

print("precision")
print(precision)

print("recall")
print(recall)

F1_measure =2*(precision*recall)/(precision+recall)

print("F1_measure")
print(F1_measure)

##################################################
#If you have time compare the performance of an SVM and/or KNN to you Logistic Regression Model 
#Which performs best? 
##################################################




