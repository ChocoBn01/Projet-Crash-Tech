#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#define couleur(param) printf("\033[%sm",param)

// accident's structure
typedef struct{
    int year;
    int collision_id;
    char* vehicle_id;
    int location;
    int user_type;
    int severity;
    int gender;
    int birth_year;
    int purpose;
}Accident;

//YEAR_DATA's structure
typedef struct{
    Accident* accident;
}Tab;

// AGE_DATA's structure
typedef struct Node{
    Accident accident;
    struct Node* next;
}Node;

//CRASH_DATA's structure
typedef struct Leaf{
    Accident accident;
    int eq;
    struct Leaf* ls;
    struct Leaf* rs;
}Leaf;

