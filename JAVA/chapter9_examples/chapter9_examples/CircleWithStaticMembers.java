package chapter9_examples;

class CircleWithStaticMembers {
	double radius; // The radius
	static int numberOfObjects = 0; // Number of objects created 

	// Construct a circle with radius 1
	CircleWithStaticMembers() {
		radius = 1.0;
		numberOfObjects++;
	}

	// Construct a circle with the specified radius
	CircleWithStaticMembers(double newRadius) {
		radius = newRadius;
		numberOfObjects++;
	}

	// Return the number of objects created
	static int getNumberOfObjects() {
		return numberOfObjects;
	}

	// Return the area
	double getArea() {
		return radius * radius * Math.PI;
	}
}

