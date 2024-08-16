#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100
struct produto;
struct produto *verificar_produto(int ID, const char *nome_arquivo);
struct produto *criar_produto(char *nome, float preco, int ID);

struct produto *criar_tenis_novo(char *genero, float tamanhoCM, char *marca);
struct tenis *dados_tenis_novo();
void inserir_tenis_no_arquivo(struct tenis *tenisNovo);
void realizar_cadastro_produto_tenis();
struct produto *cadastrar_produto(char *nome, float preco, int ID, const char *nome_arquivo);
struct camiseta *criar_camiseta_nova(char tamanho, char *genero, char *marca, char *nome, float preco, int ID, const char *nome_arquivo);
struct camiseta *dados_camiseta_nova(const char *nome_arquivo);
void inserir_camiseta_no_arquivo(struct camiseta *camisetaNova, const char *nome_arquivo);
void realizar_cadastro_produto_camiseta();
struct acessorio *criar_acessorio_novo(char *marca, char *nome, float preco, int ID, const char *nome_arquivo);
struct acessorio *dados_acessorio_novo(const char *nome_arquivo);
void inserir_acessorio_no_arquivo(struct acessorio *acessorioNovo, const char *nome_arquivo);
void realizar_cadastro_produto_acessorio();
struct bola *criar_bola_nova(char *marca, char *nome, float preco, int ID, const char *nome_arquivo);
struct bola *dados_bola_nova(const char *nome_arquivo);
void inserir_bola_no_arquivo(struct bola *bolaNova, const char *nome_arquivo);
void realizar_cadastro_produto_bola();
struct bone *criar_bone_novo(char *marca, char *nome, float preco, int ID, const char *nome_arquivo);
struct bone *dados_bone_novo(const char *nome_arquivo);
void inserir_bone_no_arquivo(struct bone *boneNovo, const char *nome_arquivo);
void realizar_cadastro_produto_bone();
struct chinelo *criar_chinelo_novo(char *marca, float tamanhoCM, char *nome, float preco, int ID, const char *nome_arquivo);
struct chinelo *dados_chinelo_novo(const char *nome_arquivo);
void inserir_chinelo_no_arquivo(struct chinelo *chineloNovo, const char *nome_arquivo);
void realizar_cadastro_produto_chinelo();
struct creatina *criar_creatina_nova(float quantidadeML, char *marca, char *nome, float preco, int ID, const char *nome_arquivo);
struct creatina *dados_creatina_nova(const char *nome_arquivo);
void inserir_creatina_no_arquivo(struct creatina *creatinaNova, const char *nome_arquivo);
void realizar_cadastro_produto_creatina();

void listar_tenis(FILE *arch);
void listar_camisetas(FILE *arch);
void listar_acessorios(FILE *arch);
void listar_bolas(FILE *arch);
void listar_bones(FILE *arch);
void listar_chinelos(FILE *arch);
void listar_creatinas(FILE *arch);
void listar_produtos();

void sub_menu_realizar_listar_produtos();
void sub_menu_listar_produtos();
void sub_menu_realizar_cadastro_produto();
void sub_menu_cadastro_produtos();
void sub_menu_edicao_produtos();
void sub_menu_realizar_edicao_produtos();

void editar_camiseta();
void editar_bone();
void editar_acessorio();
void editar_chinelo();
void editar_creatina();
void editar_tenis();
void editar_bola();
