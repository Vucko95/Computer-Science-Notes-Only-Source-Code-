import NearestPoints

def main():
    numberOfPoints = eval(input("Enter the number of points: "))

    # Create a list to store points
    points = []
    print("Enter", numberOfPoints, "points:", end = '')
    for i in range(numberOfPoints):
        point = 2 * [0]
        point[0], point[1] = \
            eval(input("Enter coordinates separated by a comma: "))
        points.append(point)

    # p1 and p2 are the indices in the points list
    p1, p2 = NearestPoints.nearestPoints(points)  

    # Display result
    print("The closest two points are (" +
        str(points[p1][0]) + ", " + str(points[p1][1]) + ") and (" +
        str(points[p2][0]) + ", " + str(points[p2][1]) + ")")

main() # Call the main function
