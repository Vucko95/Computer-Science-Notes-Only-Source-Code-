#include <stdio.h>

struct Dish {
      char name[50];
      float price;
      int spiciness;
};

struct Menu {        
      struct Dish starters[50];    
      struct Dish mains[50];     
      struct Dish deserts[50];
      };

int main() {
   struct Dish myDish;
   long size = sizeof(myDish.name) + sizeof(myDish.price) + sizeof(myDish.spiciness);
   printf( "I calculate the Dish struct to be %lu bytes\n", size );
   printf( "A Dish is actually %lu bytes\n", sizeof(struct Dish) );

   struct Menu myMenu;
   long size2 = sizeof(myMenu.starters) + sizeof(myMenu.mains) + sizeof(myMenu.deserts);
   long size3 = sizeof(struct Dish) * 150; 
   printf( "I calculate the Menu struct to be %lu bytes\n", size2 );
   printf( "A different way gives %lu bytes\n", size3 );
   printf( "A Menu is actually %lu bytes\n", sizeof(struct Menu) );
}
