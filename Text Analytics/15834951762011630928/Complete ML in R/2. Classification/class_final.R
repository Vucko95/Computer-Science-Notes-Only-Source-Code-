
lda.fit = lda(Sold~., data = df)

lda.fit
lda.pred = predict(lda.fit, df)
lda.pred$posterior

lda.class = lda.pred$class
table(lda.class, df$Sold)

sum(lda.pred$posterior[ ,1]>0.8)


set.seed(0)
split =sample.split(df,SplitRatio = 0.8)
train_set = subset(df,split == TRUE)
test_set = subset(df,split == FALSE)

train.fit = glm(Sold~., data = train_set, family = binomial)
test.probs = predict(train.fit,test_set, type = 'response')

test.pred = rep ('NO',120)
test.pred[test.probs>0.5] = 'YES'
table(test.pred,test_set$Sold)


trainX = train_set[,-16]
testX = test_set[,-16]
trainy = train_set$Sold
testy = test_set$Sold

k =3

trainX_s = scale(trainX)
testX_s = scale(testX)

set.seed(0)

knn.pred = knn(trainX_s, testX_s,trainy, k = k)

table(knn.pred,testy)

glm.fit=glm(Sold???. ,data=train_set ,family =binomial )
summary (glm.fit )

glm.probs = predict(glm.fit,test_set,type='response')
glm.pred = rep('NO',120)
glm.pred[glm.probs>0.5] = 'YES'
table(glm.pred, test_set$Sold)


lda.fit = lda(Sold~., data = train_set)
lda.pred = predict(lda.fit, test_set)
lda.class = lda.pred$class
table(lda.class, test_set$Sold)

table(knn.pred,testy)






