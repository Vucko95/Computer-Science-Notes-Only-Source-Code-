from CircleWithException import Circle

try:
    c1 = Circle(5)
    print("c1's area is", c1.getArea())
    c2 = Circle(-5)
    print("c2's area is", c2.getArea())
    c3 = Circle(0)
    print("c3's area is", c3.getArea())
except RuntimeError as ex:
    print("Invalid radius", ex)
