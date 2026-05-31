#ifndef TIPI_H
#define TIPI_H

#define NICKNAME 30
#define PASSWORD 20

typedef struct{
    char nickname[NICKNAME];
    char password[PASSWORD];
} amministratore_t;

typedef struct{
    char nickname[NICKNAME];
    char password[PASSWORD];
}fantacoach_t;

#endif