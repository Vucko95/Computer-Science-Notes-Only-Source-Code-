#include <stdio.h>

#define NUM_PEOPLE 3

typedef enum age{
    VERY_YOUNG,
    YOUNG,
    ADULT,
    MATURE,
    OLD,
    VERY_OLD
} age ;


typedef struct person {
    char name[20];
    age age_label;
} person;

 void initialize_people (person people[NUM_PEOPLE]){
    for(int i =0; i < NUM_PEOPLE; i++){
        int age =0;

        printf("Insert the next person\n");
        printf("Person name: ");
        scanf("%s", people[i].name);
        printf("Person age: ");
        scanf("%d", &age);

        if(age < 12) people[i].age_label = VERY_YOUNG;
        if(age >= 12 && age < 25) people[i].age_label = YOUNG;
        if(age >= 26 && age < 50) people[i].age_label = ADULT;
        if(age >= 50 && age < 70) people[i].age_label = MATURE;
        if(age >= 70 && age < 90) people[i].age_label = OLD;
        if(age >= 90) people[i].age_label = VERY_OLD;
    }
}

 void print_people (person people[NUM_PEOPLE]){
    for(int i =0; i < NUM_PEOPLE; i++){
        printf("\nPerson %d", i+1);
        printf("\nName: %s", people[i].name);
        printf("\nAge: ");
        if(people[i].age_label == VERY_YOUNG) printf("VERY YOUNG");
        if(people[i].age_label == YOUNG) printf("YOUNG");
        if(people[i].age_label == ADULT) printf("ADULT");
        if(people[i].age_label == MATURE) printf("MATURE");
        if(people[i].age_label == OLD) printf("OLD");
        if(people[i].age_label == VERY_OLD) printf("VERY OLD");
    }
}



int main() {
    person people[NUM_PEOPLE];

    initialize_people(people);

    print_people(people);

    return 0;
}
