#include <stdio.h>
#include "tipi.h"
#include "menu.h"
#include "call_funzioni.h"

void(*opzioni[])(void) = {
    accesso_admin, // si trova in posizione 0 nell'array
    accesso_fantacoach, //si trova in posizione 1 nell'array
    registrazione_fantacoach //si trova in posizione 2 nell'array
};

void menu_princiaple(void){
    int scelta;
do{
    printf("\n=======================================\n");
    printf("===========MENU FANTA-TENNIS===========\n");
    printf("=======================================\n");
    printf("1) Accesso come Amministratore\n");
    printf("2) Accesso come Fantacoach\n");
    printf("3) Registrazione Fantacoach\n");
    printf("0) Esci\n");
    printf("Scelta: \n");
    scanf("%d", &scelta);

    if(scelta >= 1 &&  scelta <= 3){
        (*opzioni[scelta -1]); //scelta = 1 -> opzioni[0] -> Accesso amministratore
    }else if(scelta =! 0 ){
        printf("Scelta non valida!");
    }
}while(scelta != 0);

printf("Arrivederci!");
}

void accesso_admin(void){
    amministratore_t admin;

    printf("\n=========================================\n");
    printf("=========ACCESSO AMMINISTRATORI==========\n");
    printf("=========================================\n");
    printf("Nickname: \n");
    scanf("%s", admin.nickname);
    printf("Password : \n");
    scanf("%s", admin.password);

    if(verifica_admin(admin.nickname, admin.password)){
        printf("Benvenuto, %s!\n", admin.nickname);
        }else{
            printf("Credenziali errate!");
        }
}

void accesso_fantacoach(void){
    fantacoach_t coach;

    printf("\n=========================================\n");
    printf("=========ACCESSO FANTACOACH==============\n");
    printf("=========================================\n");
    printf("Nickname: \n");
    scanf("%s", coach.nickname);
    printf("Password: \n");
    scanf("%s", coach.password);

    if(verifica_fantacoach(coach.nickname, coach.password)){
        printf("Benvenuto, %s!\n", coach.nickname);
    }else{
        printf("Credenziali errate!");
    }
}

void registrazione_fantacoach(void){
    fantacoach_t nuovo;

    printf("\n===============================================\n");
    printf("=========REGISTRAZIONE FANTACOACH==============\n");
    printf("===============================================\n");
    do{
    printf("Scegli nickname: \n");
    scanf("%s", nuovo.nickname);
    
    if(nickname_fantacoach_esistente(nuovo.nickname)){
        printf("Nickname gia' esistente, reinserire.\n");
    }

    }while(nickname_fantacoach_esistente(nuovo.nickname)); //ripete finchè il nickname non esiste nel file

    printf("Scegli password: \n");
    scanf("%s", nuovo.password);
    
    salva_fantacoach(nuovo);
    printf("Registrazione completata!");
}