#include <stdio.h>

struct point{
    int x;
    int y;
};

int main(){
    struct point rectangle[4];

    for(int i=0; i<4;i++){
        printf("Insert point %d (x and y coordinates):\n", i+1);
        scanf( "%d %d",&rectangle[i].x, &rectangle[i].y);
    }

    printf("\nThe vertexes of your rectangle are:\n");
    for(int i=0; i<4;i++){
        printf("Point %d {%d,%d}\n",
               i,rectangle[i].x, rectangle[i].y);
    }
}

