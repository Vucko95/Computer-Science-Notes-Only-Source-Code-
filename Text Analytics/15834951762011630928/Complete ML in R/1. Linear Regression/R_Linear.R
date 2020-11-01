df <- read.csv("E:/07_Videos/04_Linear_reg/01_Data/boston-house-prices/House_Price.csv", header = TRUE)

str(df)

summary(df)
hist(df$crime_rate)
pairs(~price+crime_rate+n_hot_rooms+rainfall, data = df)
barplot(table(df$airport))
barplot(table(df$waterbody))
barplot(table(df$bus_ter))


# Observations
# n_hot_rooms and rainfall has outliers
# n_hos_beds has missing values
# bus_term is a useless variable
# Crime_rate has some other functional relationship with price


quantile(df$n_hot_rooms, 0.99)
uv = 3*quantile(df$n_hot_rooms, 0.99)
df$n_hot_rooms[df$n_hot_rooms> uv] <- uv

summary(df$n_hot_rooms)

lv = 0.3*quantile(df$rainfall, 0.01)
df$rainfall[df$rainfall<lv] <-lv
summary(df$rainfall)

mean(df$n_hos_beds)
mean(df$n_hos_beds,na.rm = TRUE)
which(is.na(df$n_hos_beds))
df$n_hos_beds[is.na(df$n_hos_beds)] <- mean(df$n_hos_beds,na.rm = TRUE)

summary(df$n_hos_beds)
which(is.na(df$n_hos_beds))


pairs(~price+crime_rate,data = df)
plot(df$price,df$crime_rate)

df$crime_rate=log(1+df$crime_rate)

df$avg_dist = (df$dist1+df$dist2+df$dist3+df$dist4)/4

df2 <- df[,-7:-10]
df <- df2
rm(df2)

df <-df[,-14]


install.packages("dummies")

df <- dummy.data.frame(df)
df <- df[,-9]
df <- df[,-14]


cor(df)

round(cor(df),2)

df <- df[,-16]


simple_model <- lm(price~room_num, data=df)

simple_model

summary(simple_model)

plot(df$room_num,df$price)
abline(simple_model)


simple_model <- lm(price~room_num,data=df)

summary(simple_model)

plot(df$room_num,df$price)
abline(simple_model)

multiple_model <- lm(price~.,data = df)
summary(multiple_model)




install.packages("caTools")

set.seed(0)
split = sample.split(df,SplitRatio = 0.8)
training_set = subset(df,split == TRUE)
test_set = subset(df, split == FALSE)

lm_a = lm(price~.,data=training_set)

train_a = predict(lm_a,training_set)
test_a = predict(lm_a,test_set)

mean((training_set$price-train_a)^2)
mean((test_set$price-test_a)^2)




lm_best = regsubsets(price~.,data = df, nvmax = 15)

summary(lm_best)

summary(lm_best)$adjr2

which.max(summary(lm_best)$adjr2)

coef(lm_best,8)

lm_forward = regsubsets(price~.,data = df, nvmax = 15, method = "forward")
summary(lm_forward)


x = model.matrix(price~.,data=df)[,-1]
y = df$price
grid = 10^seq(10,-2, length =100)

grid

lm_ridge = glmnet(x,y,alpha = 0, lambda =grid)
summary(lm_ridge)
cv_fit = cv.glmnet(x,y,alpha = 0, lambda = grid )
plot(cv_fit)

opt_lambda = cv_fit$lambda.min
tss = sum((y-mean(y))^2)

y_a = predict(lm_ridge,s=opt_lambda , newx = x)

rss = sum((y_a-y)^2)

rsq = 1 - rss/tss

lm_lasso = glmnet(x,y,alpha = 1, lambda =grid)




