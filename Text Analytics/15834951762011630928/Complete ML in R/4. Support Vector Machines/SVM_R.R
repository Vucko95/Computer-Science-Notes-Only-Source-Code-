
## Import data from CSV file. Note a forward slash '/' is used in file location.

movie <- read.csv("C:/Users/pukhr/Documents/SVM/Movie_classification.csv", header = TRUE)


## Data Preprocessing
summary(movie)
movie$Time_taken[is.na(movie$Time_taken)] <- mean(movie$Time_taken,na.rm = TRUE)

## Test-Train Split

install.packages('caTools')
library(caTools)
set.seed(0)
split =sample.split(movie,SplitRatio = 0.8)
trainc = subset(movie,split == TRUE)
testc = subset(movie,split == FALSE)


## For Classification
trainc$Start_Tech_Oscar <- as.factor(trainc$Start_Tech_Oscar)
testc$Start_Tech_Oscar <- as.factor(testc$Start_Tech_Oscar)



## Importing relevant Library e1071

install.packages('e1071')
library (e1071)


svmfit = svm (Start_Tech_Oscar∼., data=trainc , kernel = "linear", cost =1 ,scale = TRUE)
summary (svmfit)

## Predicting on test set
ypred=predict (svmfit ,testc)
table(predict =ypred , truth= testc$Start_Tech_Oscar)

69/108
## To check the support vectors
svmfit$index


## Finding best value of C / Tuning the hyperparameter

set.seed (0)
tune.out = tune(svm, Start_Tech_Oscar~.,data=trainc ,kernel="linear", ranges =list(cost=c(0.001 , 0.01, 0.1, 1,10,100)))

bestmod = tune.out$best.model
summary (bestmod)

ypredL=predict (bestmod ,testc)
table(predict =ypredL , truth= testc$Start_Tech_Oscar)


## Polynomial Kernel

svmfitP = svm(Start_Tech_Oscar~., data=trainc , kernel ="polynomial", cost=1, degree=2)

# Hyperparameter Tuning
tune.outP=tune(svm ,Start_Tech_Oscar~.,data=trainc, cross = 4, kernel="polynomial", ranges =list(cost=c(0.001,0.1, 1,5,10),degree=c(0.5,1,2,3,5) ))
bestmodP =tune.outP$best.model
summary (bestmodP)
ypredP = predict (bestmodP,testc)
table(predict = ypredP, truth = testc$Start_Tech_Oscar)


## Radial Kernel

svmfitR = svm(Start_Tech_Oscar~., data=trainc , kernel = "radial", gamma =1, cost =1)

tune.outR = tune(svm ,Start_Tech_Oscar~.,data=trainc ,kernel="radial", ranges = list(cost=c(0.001, 0.01,0.1 ,1 ,10 ,100 ,1000), gamma=c(0.01, 0.1,0.5,1,2,3,4,10, 50) ))
summary(tune.outR)
bestmodR =tune.outR$best.model
summary (bestmodR)

ypredR=predict (bestmodR,testc)
table(predict =ypredR, truth= testc$Start_Tech_Oscar)



###### Regression SVM

## Import data from CSV file. Note a forward slash '/' is used in file location.

df <- read.csv("C:/Users/abhis/Movie_regression.csv", header = TRUE)


## Data Preprocessing
summary(df)
df$Time_taken[is.na(df$Time_taken)] <- mean(df$Time_taken,na.rm = TRUE)

## Test-Train Split

install.packages('caTools')
library(caTools)
set.seed(0)
split =sample.split(movie,SplitRatio = 0.8)
train = subset(df,split == TRUE)
test = subset(df,split == FALSE)

## Importing relevant Library e1071

install.packages('e1071')
library (e1071)

svmfit = svm(Collection∼., data=train , kernel = "linear", cost =0.01, scale = TRUE )
summary (svmfit)

## Predicting on test set
ypred = predict (svmfit ,test)

mse <- mean((ypred-test$Collection)^2)


