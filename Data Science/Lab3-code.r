#This will remove (almost) everything in the working environment before you start
rm(list=ls())

#Load the library dlookr and dplyr
library('dlookr')
library('dplyr')


########################################
#         read in the data             #
########################################

#The flights data frame is data about departure and arrival on all flights departing from NYC in 2013.
library(nycflights13)

dim(flights)

head(flights)

diagnose(flights)

# Select columns by name
diagnose(flights, year, month, day)

# Select all columns between year and day (inclusive)
diagnose(flights, year:day)

# Select all columns except those from year to day (inclusive)
diagnose(flights, -(year:day))

#By using dplyr, variables including missing values can be sorted by the weight of missing values:
flights %>%
  diagnose() %>%
  select(-unique_count, -unique_rate) %>% 
  filter(missing_count > 0) %>% 
  arrange(desc(missing_count))

#Diagnosis of numeric variables with diagnose_numeric()
diagnose_numeric(flights)

#If a numeric variable can not logically have a negative or zero value, it can be used with filter() to easily find a variable that does not logically match:
diagnose_numeric(flights) %>% 
  filter(minus > 0 | zero > 0) 

#Diagnosis of categorical variables with diagnose_category()
diagnose_category(flights)

#Diagnosing outliers with diagnose_outlier()
diagnose_outlier(flights)

#Numeric variables that contain anomalies are easily found with filter().:
diagnose_outlier(flights) %>% 
  filter(outliers_cnt > 0) 

#The following is a list of numeric variables with anomalies greater than 5%.:
diagnose_outlier(flights) %>% 
  filter(outliers_ratio > 5) %>% 
  mutate(rate = outliers_mean / with_mean) %>% 
  arrange(desc(rate)) %>% 
  select(-outliers_cnt)

#If the outlier is larger than the average of all observations, it may be desirable to replace or remove the outlier in the data analysis process.

#Visualization of outliers using plot_outlier()
#plot_outlier() visualizes outliers of numarical variables(continious and discrete) of data.frame. Usage is the same diagnose(). 

#plot_outlier() can visualize an anomaly in the arr_delay variable of flights as follows:
flights %>%
  plot_outlier(arr_delay) 

#Use the function of the dplyr package and plot_outlier() and diagnose_outlier() to visualize anomaly values of all numeric variables with an outlier ratio of 0.5% or more.:
flights %>%
  plot_outlier(diagnose_outlier(flights) %>% 
                 filter(outliers_ratio >= 0.5) %>% 
                 select(variables) %>% 
                 unlist())

#You should look at the visualization results and decide whether to remove or replace the outliers. In some cases, it is important to consider removing the variables that contain anomalies from the data analysis model.
