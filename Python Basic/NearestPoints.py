# Compute the distance between two points (x1, y1) and (x2, y2)
def distance(x1, y1, x2, y2):
    return ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) ** 0.5

def nearestPoints(points):
    # p1 and p2 are the indices in the points list
    p1, p2 = 0, 1  # Initial two points

    shortestDistance = distance(points[p1][0], points[p1][1], 
        points[p2][0], points[p2][1]) # Initialize shortestDistance
    
    # Compute distance for every two points
    for i in range(len(points)):
        for j in range(i + 1, len(points)):
            d = distance(points[i][0], points[i][1], 
                         points[j][0], points[j][1])  # Find distance

            if shortestDistance > d:
                p1, p2 = i, j # Update p1, p2
                shortestDistance = d # New shortestDistance 

    return p1, p2
