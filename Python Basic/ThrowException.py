def getArea(radius):
    if radius < 0:
        raise RuntimeError("Negative radius")
    
    return radius * radius * 3.1415

try:
    print(getArea(5))
    print(getArea(-5))
except RuntimeError:
    print("Invalid radius")
