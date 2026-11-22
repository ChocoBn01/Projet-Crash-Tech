#include "Biblio.h"

void init_tab(Tab tab[]) {
    for (int i = 0; i < NB_YEARS; i++) {
        tab[i].year = MIN_YEAR + i;
        tab[i].nb_accidents = 0;
        tab[i].nb_uninjured = 0;
        tab[i].nb_deaths = 0;
        tab[i].nb_seriously_injured = 0;
        tab[i].nb_minor_injuries = 0;
    }
}



void menu_year_data(){
    int year;
    int choice = 0;
    printf("\n----- MENU YEAR DATA -----\n");
    printf("Please enter the year for which you would like to view the statistics : ");
    if(scanf("%d", &year) != 1){
        printf("Error in entering the year");
        exit(3);
    }
    printf("\n");
    do{
        do{
        printf("Please enter a value between 2005 and 2024 : ");
        if(scanf("%d", &year) != 1){
            printf("Error in entering the year");
            exit(2);
        }
        }while(year < 2005 || year > 2024);
        data(0);

        printf("Would you like to stop looking at the statistics ? (yes = 1/ no = 0)");
        if(scanf("%d", &choice) != 1){
            printf("Error entering a selection");
            exit(4);
        }
    }while(choice != 1);
    
}


Tab data(int* tot_nb_accidents){
    int nb_deaths = 0;
    int nb_seriously_injured = 0;
    int nb_minor_injuries = 0;
    int nb_uninjured = 0;
    FILE* f = fopen("Data(small)/cy_crash_tech_small2_sorted.csv", "r");
    if(f == NULL){
        printf("File Opening Error");
        exit(1);
    }
    fscanf(f, "%d;%d;%s;%d;%d;%d", &Accident.year, &Accident.collision_id, Accident.vehicle_id, 
        &Accident.location, &Accident.user_type, &Accident.severity);

    if(Accident.severity == 1){
        nb_uninjured++;
    }else if(Accident.severity == 2){
        nb_deaths++;
    }else if(Accident.severity == 3){
        nb_seriously_injured++;
    }else if(Accident.severity == 4){
        nb_minor_injuries++;
    }

    
}


int main(int argc, char* argv[]){   


}
