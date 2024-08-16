#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

struct usuario;
struct usuario *criar_usuario(char *nome, char *email, char *senha);
struct usuario *verificar_usuario(char *email);
int cadastrar_usuario(char *nome, char *email, char *senha);
struct usuario *login(char *email, char *senha);
int validacao_de_email(char *email);
void realizar_login();
void realizar_cadastro();
void editar_usuario();
void listar_usuarios();
void excluir_usuario();
