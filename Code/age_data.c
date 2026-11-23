#include "Biblio.h"
Age* put_at_beginning(Age* new_head, Age* tree){
    Age* p=tree;
    Age* previous=NULL;
    if(new_head==tree){
        return tree;
    }
    while(p!=NULL){
        if(p==new_head){
            if(previous!=NULL){
                previous->next=p->next;
                p->next=tree;
                return p;
            }
        }
        else{
            previous=p;
            p=p->next;
        }
    }
    return tree;
}
Age* tri(Age* age){
    if(age==NULL || age->next==NULL){
        return age;
    }
    Age* p=age;
    Age* smallest=p;
    int nb_age=0;
    int turn=0;
    while(p!=NULL){
        nb_age++;
        p=p->next;
    }
    for(int i=0; i<nb_age; i++){
        p=age;
        for(int j=0; j<turn; j++){
            p=p->next;
        }
        smallest=p;
        while(p!=NULL){
            if(p->age<smallest->age){
                smallest=p;
            }
            p=p->next;
        }
        age=put_at_beginning(smallest, age);
        turn++;
    }
    return age;
}
void type(Age* age, int choice, int type_people){
    if(age!=NULL){
        printf("\n\n\nPiramides des ages en fonction ");
        Age* p=age;
        int max_walker=0;
        int max_driver=0;
        int max_passenger=0;
        int max_male=0;
        int max_female=0;
        while(p!=NULL){
            max_walker+=p->walker;
            max_driver+=p->driver;
            max_passenger+=p->passenger;
            max_female+=p->female;
            max_male+=p->male;
            p=p->next;
        }
        p=age;
        int value=0;
        if(choice==1){
            if(type_people==1){
                printf("du pourcentage de pietons :\n\n");
                while(p!=NULL){
                    value=10000*p->walker;
                    value=value/max_walker;
                    if(p->age>1){
                        printf("%d ans  | %d | :[", p->age, p->walker);
                    }
                    else if(p->age==1){
                        printf("%d an  | %d | :[", p->age, p->walker);
                    }
                    else{
                        printf("Nouveau ne  | %d | :[", p->walker);
                    }
                    for(int i=0; i<value; i++){
                        printf("###");
                    }
                    printf("]\n");
                    p=p->next;
                }
            }
            else if(choice==2){
                printf("du pourcentage de conducteur :\n\n");
                while(p!=NULL){
                    value=100*p->driver;
                    value=value/max_driver;
                    if(p->age>1){
                        printf("%d ans  | %d | :[", p->age, p->driver);
                    }
                    else if(p->age==1){
                        printf("%d an  | %d | :[", p->age, p->driver);
                    }
                    else{
                        printf("Nouveaux nes | %d | :[", p->driver);
                    }
                    for(int i=0; i<value; i++){
                        printf("###");
                    }
                    printf("]\n");
                    p=p->next;
                }
            }
            else{
                printf("du pourcentage de passager :\n\n");
                while(p!=NULL){
                    value=100*p->passenger;
                    value=value/max_passenger;
                    if(p->age>1){
                        printf("%d ans  | %d | :[", p->age, p->passenger);
                    }
                    else if(p->age==1){
                        printf("%d an  | %d | :[", p->age, p->passenger);
                    }
                    else{
                        printf("Nouveau ne  | %d | :[", p->passenger);
                    }
                    for(int i=0; i<value; i++){
                        printf("###");
                    }
                    printf("]\n");
                    p=p->next;
                }
            }
        }
        else{
            if(type_people==1){
                printf("du pourcentage d'homme :\n\n");
                while(p!=NULL){
                    value=100*p->male;
                    value=value/max_male;
                    if(p->age>1){
                        printf("%d ans  | %d | :[", p->age, p->male);
                    }
                    else if(p->age==1){
                        printf("%d an  | %d | :[", p->age, p->male);
                    }
                    else{
                        printf("Nouveau ne  | %d | :[", p->male);
                    }
                    for(int i=0; i<value; i++){
                        printf("###");
                    }
                    printf("]\n");
                    p=p->next;
                }
            }
            else{
                printf("du pourcentage de femme :\n\n");
                while(p!=NULL){
                    value=100*p->female;
                    value=value/max_female;
                    if(p->age>1){
                        printf("%d ans  | %d | :[", p->age, p->female);
                    }
                    else if(p->age==1){
                        printf("%d an  | %d | :[", p->age, p->female);
                    }
                    else{
                        printf("Nouveau ne  | %d | :[", p->female);
                    }
                    for(int i=0; i<value; i++){
                        printf("###");
                    }
                    printf("]\n");
                    p=p->next;
                }
            }
        }
    }
}
void main(int argc, char **argv){


    int verif=0;
    int ans=-1;
    while(1){
        while(verif==0){
            printf("\n\n\nQue voulez vous analyser :\n          -Statistique en fonction du type de personne(pieton, passager ou conduteur)  [tapez 1]\n          -Statistique en fonction du genre  [tapez 2]\n          -Quitter [tapez 0]");
            scanf("%d", &ans);
            if(ans==0||ans==1||ans==2){
                verif=1;
            }
        }
        verif=0;
        if(ans==0){
            return;
        }
        else if(ans==1){
            ans=-1;
            while(verif==0){
                printf("\n\nDe quel type de personne voulez vous les infos :\n          -Les pietons  [tapez 1]\n          -Les conducteurs  [tapez 2]\n          -Les passagers  [tapez 3]\n          -Quitter  [tapez 0]");
                scanf("%d", &ans);
                if(ans==1||ans==2||ans==3||ans==0){
                    verif=1;
                }
            }
            if(ans!=0){
                type(  , 1, ans);
            }
        }
        else{
            ans=-1;
            while(verif==0){
                printf("\n\nDe quel sexe voulez vous les infos :\n          -Les hommes  [tapez 1]\n          -Les femmes  [tapez 2]\n          -Quitter  [tapez 0]");
                scanf("%d", &ans);
                if(ans==1||ans==2||ans==0){
                    verif=1;
                }
            }
            if(ans!=0){
                type(  , 2, ans);
            }
        }
    }
}
