# For more details see: http://r-statistics.co/Linear-Regression.html

#This will remove (almost) everything in the working environment before you start
rm(list=ls())

#if you set the seed you will get the same results every time, if not, you will get different results every time.
set.seed(100)   #try putting a # in front of this line and run the code a few times to see what happens, then remove the # and run it a few times to see the difference...

####################################
#         read in the data         #
####################################

#Load the cars data set
#cars is a standard built-in dataset that comes with R by default
print("read in the data")
data(cars)
head(cars)  # display the first 6 observations

#######################################
#         Visualize your data         #
#######################################
print("Visualize your data")

# Scatterplot
png("Scatterplot.png")
scatter.smooth(x=cars$speed, y=cars$dist, main="Dist ~ Speed")  
dev.off()

#BoxPlot – Check for outliers
png("BoxPlot.png")
par(mfrow=c(1, 2))  # divide graph area in 2 columns
boxplot(cars$speed, main="Speed", sub=paste("Outlier rows: ", boxplot.stats(cars$speed)$out))  # box plot for 'speed'
boxplot(cars$dist, main="Distance", sub=paste("Outlier rows: ", boxplot.stats(cars$dist)$out))  # box plot for 'distance'
dev.off()

###############################
#         Correlation         #
###############################
print("Correlation")

# calculate correlation between speed and distance 
correlation <- cor(cars$speed, cars$dist)

print(correlation)

######################################
#         Build Linear Model         #
######################################
print("Build Linear Model")

# build linear regression model on full data
linearMod <- lm(dist ~ speed, data=cars)  
print(linearMod)

#########################################################
#         Checking for statistical significance         #
#########################################################
print("Checking for statistical significance")

# model summary
summary(linearMod)  

#################################################
#         Build Predictive Linear Model         #
#################################################
print("Build Predictive Linear Model")

# Create Training and Test data -
trainingRowIndex <- sample(1:nrow(cars), 0.8*nrow(cars))  # row indices for training data
trainingData <- cars[trainingRowIndex, ]  # model training data
testData  <- cars[-trainingRowIndex, ]   # test data

# Build the model on training data -
lmMod <- lm(dist ~ speed, data=trainingData)  # build the model

#the predict() Function
#predict(object, newdata)
#    object is the formula which is already created using the lm() function
#    newdata is the vector containing the new values

distPred <- predict(lmMod, testData)  # predict distance

#Review statistics
summary(lmMod)  

####################################
#         Model Evaluation         #
####################################
print("Model Evaluation")

# make dataframe.
actual_pred <- data.frame(cbind(actual=testData$dist, predicted=distPred))  
correlation_accuracy <- cor(actual_pred)  

print(head(actual_pred))
print(head(correlation_accuracy))

# Plot training data
png("Regression_training.png")
plot(trainingData$speed,trainingData$dist,col = "blue",main = "Speed & Distance Regression",
abline(lmMod),cex = 1.3,pch = 16,xlab = "Speed",ylab = "Distance", xlim=c(0,30),ylim=c(0,125))
dev.off()

# Plot training data
png("Regression_test.png")
plot(testData$speed,testData$dist,col = "blue",main = "Speed & Distance Regression",
abline(lmMod),cex = 1.3,pch = 16,xlab = "Speed",ylab = "Distance", xlim=c(0,30),ylim=c(0,125))
dev.off()


