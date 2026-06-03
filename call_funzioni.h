#ifndef CALL_FUNZIONI_H
#define CALL_FUNZIONI_H

#include "tipi.h"

#define FILE_ADMIN      "admin.dat"
#define FILE_FANTACOACH "fantacoach.dat"

void inizializza_admin(void);

void salva_fantacoach(fantacoach_t coach);

int verifica_admin(char *nickname, char *password);
int verifica_fantacoach(char *nickname, char *password);

int nickname_fantacoach_esistente(char *nickname);

#endif