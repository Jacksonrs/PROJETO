#include "usuario.h"

struct usuario
{
    char *nome;
    char *email;
    char *senha;
};

struct usuario *verificar_usuario(char *email)
{
    FILE *arch = fopen("usuarios.txt", "r");
    if (arch == NULL)
    {
        exit(EXIT_FAILURE);
    }
    char nome[MAX_LEN];
    char email_aux[MAX_LEN];
    char senha[MAX_LEN];

    while (fscanf(arch, "nome do usuario: %99[^\n]\nemail: %99[^\n]\nsenha: %99[^\n]\n", nome, email_aux, senha) == 3)
    {
        if (strcmp(email, email_aux) == 0)
        {
            struct usuario *aux = criar_usuario(nome, email, senha);
            fclose(arch);
            return aux;
        }
    }

    fclose(arch);
    return NULL;
}

struct usuario *criar_usuario(char *nome, char *email, char *senha)
{
    struct usuario *novo = (struct usuario *)malloc(sizeof(struct usuario));
    novo->nome = (char *)malloc((strlen(nome) + 1) * sizeof(char));
    novo->email = (char *)malloc((strlen(email) + 1) * sizeof(char));
    novo->senha = (char *)malloc((strlen(senha) + 1) * sizeof(char));
    strcpy(novo->nome, nome);
    strcpy(novo->email, email);
    strcpy(novo->senha, senha);

    return novo;
}

void realizar_cadastro()
{
    char *nome = (char *)malloc(30 * sizeof(char));
    char *email = (char *)malloc(30 * sizeof(char));
    char *senha = (char *)malloc(30 * sizeof(char));
    printf("Insira o seu nome: \n");
    scanf("%s", nome);
    printf("Insira o email: \n");
    scanf("%s", email);
    printf("Insira a senha: \n");
    scanf("%s", senha);

    if (validacao_de_email(email) == 1)
    {
        system("cls");
        printf("formato de email invalido\n");
    }
    else
    {
        cadastrar_usuario(nome, email, senha);
    }
}

int cadastrar_usuario(char *nome, char *email, char *senha)
{
    struct usuario *novo;
    novo = criar_usuario(nome, email, senha);

    FILE *arch = fopen("usuarios.txt", "a");
    if (arch == NULL)
    {
        exit(EXIT_FAILURE);
    }
    if (verificar_usuario(novo->email) != NULL)
    {
        system("cls");
        printf("Email ja cadastrado no sistema\n");
        return -1;
    }
    else
    {
        fprintf(arch, "nome do usuario: %s\nemail: %s\nsenha: %s\n", novo->nome, novo->email, novo->senha);
        fclose(arch);

        return 0;
    }
}

void realizar_login()
{

    char *email = (char *)malloc(30 * sizeof(char));
    char *senha = (char *)malloc(30 * sizeof(char));
    struct usuario *usuario = NULL;
    int validador;
    do
    {
        printf("Insira o email: \n");
        scanf("%s", email);
        printf("Insira a senha: \n");
        scanf("%s", senha);
        validador = validacao_de_email(email);
        if (validador == 1)
        {
            system("cls");
            printf("formato de email invalido\n");
        }
        else if (validador == 0)
        {
            usuario = login(email, senha);
        }

    } while (usuario == NULL);
    printf("Logado com sucesso!\n");
    free(usuario->email);
    free(usuario->nome);
    free(usuario->senha);
    free(usuario);
}

struct usuario *login(char *email, char *senha)
{

    struct usuario *usuario_de_login;

    usuario_de_login = verificar_usuario(email);
    if (usuario_de_login != NULL)
    {
        if ((strcmp(usuario_de_login->senha, senha) && strcmp(usuario_de_login->email, email)) == 0)
        {
            return usuario_de_login;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

int validacao_de_email(char *email)
{
    char *validacao = strstr(email, "@");
    if ((validacao) && (strlen(email) < 80))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void editar_usuario()
{
    char email[MAX_LEN];
    char novo_nome[MAX_LEN];
    char nova_senha[MAX_LEN];
    int encontrado = 0;

    printf("Insira o email do usuário a ser editado: ");
    scanf("%s", email);

    FILE *arch = fopen("usuarios.txt", "r");
    if (arch == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    FILE *temp = fopen("usuarios_temp.txt", "w");
    if (temp == NULL)
    {
        perror("Erro ao criar o arquivo temporário");
        fclose(arch);
        exit(EXIT_FAILURE);
    }

    char nome[MAX_LEN];
    char email_aux[MAX_LEN];
    char senha[MAX_LEN];

    while (fscanf(arch, "nome do usuario: %99[^\n]\nemail: %99[^\n]\nsenha: %99[^\n]\n", nome, email_aux, senha) == 3)
    {
        if (strcmp(email, email_aux) == 0)
        {
            encontrado = 1;
            printf("Usuário encontrado! Insira os novos dados:\n");
            printf("Novo nome do usuário: ");
            scanf(" %[^\n]", novo_nome);
            printf("Nova senha: ");
            scanf("%s", nova_senha);

            fprintf(temp, "nome do usuario: %s\nemail: %s\nsenha: %s\n", novo_nome, email, nova_senha);
        }
        else
        {
            fprintf(temp, "nome do usuario: %s\nemail: %s\nsenha: %s\n", nome, email_aux, senha);
        }
    }

    if (!encontrado)
    {
        printf("Usuário com email %s não encontrado.\n", email);
    }

    fclose(arch);
    fclose(temp);

    if (remove("usuarios.txt") != 0)
    {
        perror("Erro ao remover o arquivo original");
        exit(EXIT_FAILURE);
    }

    if (rename("usuarios_temp.txt", "usuarios.txt") != 0)
    {
        perror("Erro ao renomear o arquivo temporário");
        exit(EXIT_FAILURE);
    }
}

void listar_usuarios()
{
    FILE *arch = fopen("usuarios.txt", "r");
    if (arch == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    char nome[MAX_LEN];
    char email[MAX_LEN];
    char senha[MAX_LEN];

    printf("Lista de Usuários:\n");
    while (fscanf(arch, "nome do usuario: %99[^\n]\nemail: %99[^\n]\nsenha: %99[^\n]\n", nome, email, senha) == 3)
    {
        printf("Nome: %s\n", nome);
        printf("Email: %s\n", email);
        printf("Senha: %s\n\n", senha);
    }

    fclose(arch);
}

void excluir_usuario()
{
    char email[MAX_LEN];
    int encontrado = 0;

    printf("Insira o email do usuário a ser excluído: ");
    scanf("%s", email);

    FILE *arch = fopen("usuarios.txt", "r");
    if (arch == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    FILE *temp = fopen("usuarios_temp.txt", "w");
    if (temp == NULL)
    {
        perror("Erro ao criar o arquivo temporário");
        fclose(arch);
        exit(EXIT_FAILURE);
    }

    char nome[MAX_LEN];
    char email_aux[MAX_LEN];
    char senha[MAX_LEN];

    while (fscanf(arch, "nome do usuario: %99[^\n]\nemail: %99[^\n]\nsenha: %99[^\n]\n", nome, email_aux, senha) == 3)
    {
        if (strcmp(email, email_aux) == 0)
        {
            encontrado = 1;
            printf("Usuário com email %s foi excluído.\n", email);
            continue;
        }

        fprintf(temp, "nome do usuario: %s\nemail: %s\nsenha: %s\n", nome, email_aux, senha);
    }

    if (!encontrado)
    {
        printf("Usuário com email %s não encontrado.\n", email);
    }

    fclose(arch);
    fclose(temp);

    if (remove("usuarios.txt") != 0)
    {
        perror("Erro ao remover o arquivo original");
        exit(EXIT_FAILURE);
    }

    if (rename("usuarios_temp.txt", "usuarios.txt") != 0)
    {
        perror("Erro ao renomear o arquivo temporário");
        exit(EXIT_FAILURE);
    }
}
