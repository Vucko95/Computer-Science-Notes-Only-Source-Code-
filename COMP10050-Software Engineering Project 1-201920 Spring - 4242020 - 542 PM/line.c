#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct point{
	int x;
	int y;
};

struct line{
	struct point p1;
	struct point p2;
};

int main(){
    struct line myLine;
    int  distX,distY;
    double segment;

    myLine.p1.x=10;
    myLine.p1.y=10;
    myLine.p2.x=50;
    myLine.p2.y=30;

    distX = abs(myLine.p1.x - myLine.p2.x);
    distY = abs(myLine.p1.y - myLine.p2.y);

    segment = pow(distX,2) + pow(distY,2);

    printf("The Line Segment is %.2lf\n",segment);
}
