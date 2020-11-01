
#import dataset
movie <- read.csv("E:/07_Videos/08_Advanced/Presentation/Movie_regression.csv")
View(movie)

#Data Preprocessing
summary(movie)
movie$Time_taken[is.na(movie$Time_taken)] <- mean(movie$Time_taken,na.rm = TRUE)









# Test-Train Split
install.packages('caTools')
library(caTools)
set.seed(0)
split =sample.split(movie,SplitRatio = 0.8)
train = subset(movie,split == TRUE)
test = subset(movie,split == FALSE)












#install required packages
install.packages('rpart')
install.packages('rpart.plot')
library(rpart)
library(rpart.plot)

#Run regression tree model on train set
regtree <- rpart(formula = Collection~., data = train, control = rpart.control(maxdepth = 3))
#press F1 on rpart for help on this function

#Plot the decision Tree
rpart.plot(regtree, box.palette="RdBu", digits = -3)

#Predict value at any point
test$pred <- predict(regtree, test, type = "vector")

MSE2 <- mean((test$pred - test$Collection)^2)







#Tree Pruning
fulltree <- rpart(formula = Collection~., data = train, control = rpart.control( cp = 0))
rpart.plot(fulltree, box.palette="RdBu", digits = -3)
printcp(fulltree)
plotcp(regtree)

mincp <- regtree$cptable[which.min(regtree$cptable[,"xerror"]),"CP"]

prunedtree <- prune(fulltree, cp = mincp)
rpart.plot(prunedtree, box.palette="RdBu", digits = -3)

test$fulltree <- predict(fulltree, test, type = "vector")
MSE2full <- mean((test$fulltree - test$Collection)^2)

test$pruned <- predict(prunedtree, test, type = "vector")
MSE2pruned <- mean((test$pruned - test$Collection)^2)




accuracy_postprun <- mean(test$pred == test$left)

data.frame(base_accuracy, accuracy_preprun, accuracy_postprun)

printcp(regtree)
fit$cptable[which.min(fit$cptable[,”xerror”]),”CP”]
plotcp(regtree)

#Bagging
library (randomForest)
set.seed (1)
bagging =randomForest(Collection~Budget+Trailer_views, data = train ,mtry=2, importance =TRUE)
test$bagging <- predict(bagging, test)
MSE2bagging <- mean((test$bagging - test$Collection)^2)

#Random forest
install.packages('randomForest')
library(randomForest)

fit <- randomForest(Collection~Budget+Trailer_views, data = train,ntree=500)
summary(fit)
#Predict Output 
test$random <- predict(fit, test)
MSE2random <- mean((test$random - test$Collection)^2)


#Boosting
install.packages('gbm')
library (gbm)
set.seed (1)
boosting = gbm(Collection~Budget+Trailer_views, data = train, distribution="gaussian",n.trees =5000 , interaction.depth =4, shrinkage =0.2,verbose =F)
test$boost = predict (boosting, test,n.trees =5000)
MSE2boost <- mean((test$boost - test$Collection)^2)


#XGBoost
install.packages('xgboost')
library(xgboost)
train <- agaricus.train
test <- agaricus.test
bst <- xgboost(data = train$data, label = train$label, max_depth = 2, eta = 1,nrounds = 2, objective = "binary:logistic")
pred <- predict(bst, test$data)


#AdaBoost
install.packages('adabag')
library(adabag)
ada = adaboost(dat$X[train_index,], dat$y[train_index], tree_depth = 2,n_rounds = 200, verbose = TRUE)
print(ada)
model_adabag <- boosting(flag~a+b, data=train, boos=TRUE, mfinal=10)
names(model_adabag)
test$ada = predict (ada, test)
MSE2boost <- mean((test$ada - test$Collection)^2)



> fit <- randomForest(Species ~ ., x,ntree=500)
> summary(fit)
#Predict Output 
> predicted= predict(fit,x_test)

table(lda.class, df$Sold)

score <- c(35, 38, 40, 45, 35, 65, 70, 75, 80, 85)
hours <- c(6, 5, 7, 6, 8, 11, 12, 18, 14, 12)
midterm <- c(42, 65, 35, 75, 60, 50, 45, 40, 80, 82)


df <- data.frame(score, hours, midterm)
rm(score,hours,midterm)
#Run regression tree model on train set
regtree <- rpart(formula = score~., data = df, control = rpart.control(minsplit=1, minbucket=1, cp=0.1))
#press F1 on rpart for help on this function

#Plot the decision Tree
rpart.plot(regtree, box.palette="RdBu", shadow.col="gray", nn=TRUE, digits = -2)
df$pred <- predict(regtree, df, type = "vector")

MSE2 <- mean((df$pred - df$score)^2)


####################################################################################
################################ CLASSIFICATION ####################################
####################################################################################

#import dataset

df <- read.csv("C:/Users/pukhr/Documents/cLASSIFICATION/Movie_classification.csv")
View(df)

#Data Preprocessing
summary(df)
df$Time_taken[is.na(df$Time_taken)] <- mean(df$Time_taken,na.rm = TRUE)

# Test-Train Split
install.packages('caTools')
library(caTools)
set.seed(0)
split =sample.split(movie,SplitRatio = 0.8)
trainc = subset(df,split == TRUE)
testc = subset(df,split == FALSE)

#install required packages
install.packages('rpart')
install.packages('rpart.plot')
library(rpart)
library(rpart.plot)

#Run Classification tree model on train set
classtree <- rpart(formula = Start_Tech_Oscar~., data = trainc, method = 'class', control = rpart.control(maxdepth = 3))
#press F1 on rpart for help on this function

#Plot the decision Tree
rpart.plot(classtree, box.palette="RdBu", digits = -3)

#Predict value at any point
testc$pred <- predict(classtree, testc, type = "class")

table(testc$Start_Tech_Oscar,testc$pred)
63/112



####################################################################################
################################ Ensemble Method ###################################
####################################################################################

# Bagging
install.packages('randomForest')
library (randomForest)
set.seed (0)

bagging =randomForest(formula = Collection~., data = train ,mtry=17)
test$bagging <- predict(bagging, test)
MSE2bagging <- mean((test$bagging - test$Collection)^2)


#Random forest
install.packages('randomForest')
library(randomForest)

randomfor <- randomForest(Collection~., data = train,ntree=500)
#Predict Output 
test$random <- predict(randomfor, test)
MSE2random <- mean((test$random - test$Collection)^2)










#Boosting
install.packages('gbm')
library (gbm)
set.seed (0)
boosting = gbm(Collection~., data = train, distribution="gaussian",n.trees =5000 , interaction.depth =4, shrinkage =0.2,verbose =F)
#distribution = 'Gaussian' for regression and 'Bernoulli' for classification
test$boost = predict (boosting, test, n.trees =5000)
MSE2boost <- mean((test$boost - test$Collection)^2)







# Adaboost

install.packages("adabag")
library(adabag);

trainc$Start_Tech_Oscar <- as.factor(trainc$Start_Tech_Oscar)

adaboost <- boosting(Start_Tech_Oscar~., data=trainc, boos=TRUE,mfinal=1000)

predada <- predict(adaboost,testc)
table(predada$class,testc$Start_Tech_Oscar)
70/113
77/113

t1<-adaboost$trees[[1]]
plot(t1)
text(t1,pretty=100)








#XGBOOST

install.packages("xgboost")
library(xgboost)

trainY = trainc$Start_Tech_Oscar == "1"


trainX <- model.matrix(Start_Tech_Oscar ~ .-1, data = trainc)
trainX <- trainX[,-12]

testY = testc$Start_Tech_Oscar == "1"

testX <- model.matrix(Start_Tech_Oscar ~ .-1, data = testc)
testX <- testX[,-12]
#delete additional variable

Xmatrix <- xgb.DMatrix(data = trainX, label= trainY)
Xmatrix_t <- xgb.DMatrix(data = testX, label = testY)

Xgboosting <- xgboost(data = Xmatrix, # the data   
                      nround = 50, # max number of boosting iterations
                      objective = "multi:softmax",eta = 0.3, num_class = 2, max_depth = 10)

xgpred <- predict(Xgboosting, Xmatrix_t)
table(testY, xgpred)

74/113













