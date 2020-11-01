library("scmamp")

# Read in data set and prepare it for Freidman aligned ranks test
AverageRanksCalcRaw <- read_csv("./AverageRanksCalcScores.csv")
AverageRanksCalcRaw <- data.frame(AverageRanksCalcRaw)
AverageRanksCalc <- AverageRanksCalcRaw[,-1]
rownames(AverageRanksCalc) <- AverageRanksCalcRaw[,1]
AverageRanksCalc <- t(AverageRanksCalc)

# Perform the Freidman aligned ranks test
friedmanAlignedRanksTest(AverageRanksCalc)

# Perform pair-wise Nemenyi test
test <- nemenyiTest(AverageRanksCalc, alpha=0.05)
test
test$diff.matrix
abs(test$diff.matrix) > test$statistic

# Generate a critical differences plot
plotCD (AverageRanksCalc, alpha=0.05, cex=1.25)