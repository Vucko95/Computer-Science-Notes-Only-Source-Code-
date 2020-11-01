# Prompt the user to enter weight in pounds
weight = eval(input("Enter weight in pounds: "))
    
# Prompt the user to enter height in inches
height = eval(input("Enter height in inches: "))
    
KILOGRAMS_PER_POUND = 0.45359237 # Constant
METERS_PER_INCH = 0.0254 # Constant 
    
# Compute BMI
weightInKilograms = weight * KILOGRAMS_PER_POUND 
heightInMeters = height * METERS_PER_INCH
bmi = weightInKilograms / (heightInMeters * heightInMeters)

# Display result
print("BMI is", format(bmi, ".2f"))
if bmi < 18.5:
    print("Underweight")
elif bmi < 25:
    print("Normal")
elif bmi < 30:
    print("Overweight")
else:
    print("Obese")