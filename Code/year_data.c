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

void load_data(char* filename, Tab tab[]) {
    init_tab(tab);

    FILE* f = fopen(filename, "r");
    if(f == NULL){
        printf("Erreur ouverture fichier");
        exit(1);
    }
    char line[512];
    if(fgets(line, sizeof(line), f) == NULL){
        printf("Le fichier est vide");
        fclose(f);
        exit(2);
    }

    int year, location, user_type, severity, gender, birth_year, purpose;
    long collision_id;
    char vehicle_id[64]; 

    while(fgets(line, sizeof(line), f) != NULL){
        int res = sscanf(line, "%d;%ld;%s;%d;%d;%d;%d;%d;%d", &year, &collision_id, vehicle_id, &location, &user_type, 
            &severity, &gender, &birth_year, &purpose);
        // Corresponding cell in the table
        int index = year - MIN_YEAR;

        // Counting by gravity
        if(severity == 1){
            tab[index].nb_uninjured++;
        }else if(severity == 2){
            tab[index].nb_deaths++;
        }else if(severity == 3){
            tab[index].nb_seriously_injured++;
        }else if(severity == 4){
            tab[index].nb_minor_injuries++;
        }

        fclose(f);
    }

}


void display_year(Tab tab[], int year){
    int index = year - MIN_YEAR;
    int total_victims = tab[index].nb_uninjured + tab[index].nb_deaths + tab[index].nb_seriously_injured + tab[index].nb_minor_injuries;

    printf("\n------ Statistiques pour %d ------\n");
    printf("Total accidents : %d\n", tab[index].nb_accidents);
    printf("Nombre total de victimes : %d\n", total_victims);
    printf("   - Indemne : %d\n", tab[index].nb_uninjured);
    printf("   - Morts : %d\n", tab[index].nb_deaths);
    printf("   - blessé grave : %d\n", tab[index].nb_seriously_injured);
    printf("   - blessé léger : %d\n", tab[index].nb_minor_injuries);
    printf("----------------------------------------\n");
}


void menu_year_data(char* filename){
    // Size by number of years
    Tab tab[20];
    load_data(filename, tab);

    int choice = -1;
    int year = 0;

    while(choice != 0){
        printf("\n====== MENU YEAR DATA ======\n");
        printf("1. Voir les statistiques pour un an (2005-2024)\n");
        printf("2. Voir la meilleure et la pire année (pas encore faite)\n");
        printf("0. Quitter\n");
        printf("Veuillez faire votre choix : ");

        if(scanf("%d", &choice) != 1){
            printf("Erreur de saisie\n");
            exit(3);
        }
        if(choice == 1){
            do{
                printf("Entrer une année entre 2005 et 2024 : ");
                if(scanf("%d", &year) != 1){
                    printf("Erreur de saisie\n");
                    exit(4);
                }
            }while(year < MIN_YEAR || year > MAX_YEAR);
            display_year(tab, year);
        }else if(choice == 2){

        }else if(choice != 0){
            printf("Choix incorrect, veuillez réessayer.\n");
        }
    }
}


