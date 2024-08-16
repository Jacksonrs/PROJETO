#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100
struct administrador;
struct administrador *login_como_adm(char *nome, char *senha);
struct administrador *criar_administrador(char *nome, char *senha);
struct administrador *verificar_administrador(char *nome, char *senha);
void realizar_login_adm();
void texto_menu_sem_login();
void menu_sem_login();
void menu_adm();