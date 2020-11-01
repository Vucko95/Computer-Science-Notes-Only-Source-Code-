# Enter the first point with two double values
x1, y1 = eval(input("Enter x1 and y1: "))

# Enter the second point with two double values
x2, y2 = eval(input("Enter x2 and y2: "))
 
# Compute the distance
distance = ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) ** 0.5
    
print("The distance between the two points is", distance) 
