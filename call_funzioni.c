#include <stdio.h>
#include "call_funzioni.h"
#include "tipi.h"
#include <string.h>
    
void salva_fantacoach(fantacoach_t fantacoach){
    FILE *fp = fopen(FILE_FANTACOACH, "ab");
    if(fp == NULL) {
        printf("Errore aprtura file: Fantacoach.\n");
        return;
    }
    fwrite(&fantacoach, sizeof(fantacoach_t), 1, fp);
    fclose(fp);
}

int verifica_admin(char *nickname, char *password){

    amministratore_t admin;

    FILE *fp = fopen(FILE_ADMIN, "rb");
    if(fp == NULL) {
        printf("Nessun admin registrato\n");
        return 0;
    }
    while (fread(&admin, sizeof(amministratore_t), 1, fp)){
        if(strcmp(admin.nickname, nickname) == 0 &&
        strcmp(admin.password, password) == 0) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int verifica_fantacoach(char *nickname, char *password){
    fantacoach_t coach;
    FILE *fp = fopen(FILE_FANTACOACH, "rb");
    if(fp == NULL){
        printf("Nessun fantacoach registrato");
        return 0;
    }
    while (fread(&coach, sizeof(fantacoach_t), 1, fp)){
        if(strcmp(coach.nickname, nickname) == 0 &&
        strcmp (coach.password, password) == 0){
        fclose(fp);
        return 1;
        }
    }
    fclose(fp);
    return 0;
}

int nickname_fantacoach_esistente(char *nickname){
    fantacoach_t coach;
    FILE *fp = fopen(FILE_FANTACOACH, "rb");
    if(fp == NULL) return 0;
    while (fread(&coach, sizeof(fantacoach_t), 1, fp)){
        if(strcmp(coach.nickname, nickname) == 0){
            fclose(fp);
            return 1;
        }
        }
        fclose(fp);
        return 0;
    }