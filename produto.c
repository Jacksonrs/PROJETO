#include "produto.h"

struct produto
{
    char *nome;
    float preco;
    int ID;
};

struct tenis
{
    float tamanhoCM;
    char *genero;
    char *marca;
    struct produto *prod;
};

struct camiseta
{
    char tamanho;
    char *genero;
    char *marca;
    struct produto *prod;
};

struct acessorio
{
    char *marca;
    struct produto *prod;
};

struct bola
{
    char *marca;
    struct produto *prod;
};

struct bone
{
    char *marca;
    struct produto *prod;
};

struct chinelo
{
    char *marca;
    float tamanhoCM;
    struct produto *prod;
};

struct creatina
{
    float quantidadeML;
    char *marca;
    struct produto *prod;
};

void sub_menu_realizar_cadastro_produto()
{
    printf("\tArtigos esportivos\n\n");
    printf("\t\tMENU ADMINISTRADOR\n\n");
    printf("1 - Cadastrar tenis\n");
    printf("2 - Cadastrar camiseta\n");
    printf("3 - Cadastrar acessorio\n");
    printf("4 - Cadastrar bola\n");
    printf("5 - Cadastrar bone\n");
    printf("6 - Cadastrar chinelo\n");
    printf("7 - Cadastrar creatina\n");
    printf("0 - Sair\n");
}

void sub_menu_realizar_listar_produtos()
{
    printf("\tArtigos esportivos\n\n");
    printf("\t\tMENU ADMINISTRADOR\n\n");
    printf("1 - Listar tenis\n");
    printf("2 - Listar camisetas\n");
    printf("3 - Listar acessorios\n");
    printf("4 - Listar bolas\n");
    printf("5 - Listar bones\n");
    printf("6 - Listar chinelos\n");
    printf("7 - Listar creatinas\n");
    printf("8 - Listar todos\n");
    printf("0 - Sair\n");
}

void sub_menu_realizar_edicao_produtos()
{
    printf("\tArtigos esportivos\n\n");
    printf("\t\tMENU ADMINISTRADOR\n\n");
    printf("1 - Editar tenis\n");
    printf("2 - Editar camisetas\n");
    printf("3 - Editar acessorios\n");
    printf("4 - Editar bolas\n");
    printf("5 - Editar bones\n");
    printf("6 - Editar chinelos\n");
    printf("7 - Editar creatinas\n");
    printf("0 - Sair\n");
}
void sub_menu_edicao_produtos()
{
    int op;
    do
    {
        sub_menu_realizar_edicao_produtos();
        scanf("%i", &op);
        switch (op)
        {
        case 1:
            editar_tenis();
            break;
        case 2:
            editar_camiseta();
            break;
        case 3:
            editar_acessorio();
            break;
        case 4:
            editar_bola();
            break;
        case 5:
            editar_bone();
            break;
        case 6:
            editar_chinelo();
            break;
        case 7:
            editar_creatina();
            break;
        case 0:
            system("cls");
            printf("Obrigado por utilizar nossos servicos!\n");
            break;
        default:
            break;
        }

    } while (op != 0);
}

void sub_menu_cadastro_produtos()
{
    int op;
    do
    {
        sub_menu_realizar_cadastro_produto();
        scanf("%i", &op);
        switch (op)
        {
        case 1:
            realizar_cadastro_produto_tenis();
            break;
        case 2:
            realizar_cadastro_produto_camiseta();
            break;
        case 3:
            realizar_cadastro_produto_acessorio();
            break;
        case 4:
            realizar_cadastro_produto_bola();
            break;
        case 5:
            realizar_cadastro_produto_bone();
            break;
        case 6:
            realizar_cadastro_produto_chinelo();
            break;
        case 7:
            realizar_cadastro_produto_creatina();
            break;
        case 0:
            system("cls");
            printf("Obrigado por utilizar nossos servicos!\n");
            break;
        default:
            break;
        }

    } while (op != 0);
}
void sub_menu_listar_produtos()
{

    int op;
    FILE *arch;
    do
    {
        sub_menu_realizar_listar_produtos();
        scanf("%i", &op);
        switch (op)
        {
        case 1:
            arch = fopen("tenis.txt", "r");
            listar_tenis(arch);
            fclose(arch);
            break;
        case 2:
            arch = fopen("camiseta.txt", "r");
            listar_camisetas(arch);
            fclose(arch);
            break;
        case 3:
            arch = fopen("acessorio.txt", "r");

            listar_acessorios(arch);
            fclose(arch);
            break;
        case 4:
            arch = fopen("bola.txt", "r");

            listar_bolas(arch);
            fclose(arch);
            break;
        case 5:
            arch = fopen("bone.txt", "r");

            listar_bones(arch);
            fclose(arch);
            break;
        case 6:
            arch = fopen("chinelo.txt", "r");

            listar_chinelos(arch);
            fclose(arch);
            break;
        case 7:
            arch = fopen("creatina.txt", "r");

            listar_creatinas(arch);
            fclose(arch);
            break;
        case 8:
            listar_produtos();
            break;
        case 0:
            system("cls");
            printf("Obrigado por utilizar nossos servicos!\n");
            break;
        default:
            break;
        }

    } while (op != 0);
}

struct produto *criar_produto(char *nome, float preco, int ID)
{
    struct produto *novo = (struct produto *)malloc(sizeof(struct produto));
    novo->nome = (char *)malloc((strlen(nome) + 1) * sizeof(char));
    novo->preco = preco;
    novo->ID = ID;
    strcpy(novo->nome, nome);
    return novo;
}

struct produto *criar_tenis_novo(char *genero, float tamanhoCM, char *marca)
{
    struct tenis *novo = (struct tenis *)malloc(sizeof(struct tenis));
    novo->genero = (char *)malloc((strlen(genero) + 1) * sizeof(char));
    novo->marca = (char *)malloc((strlen(marca) + 1) * sizeof(char));
    novo->tamanhoCM = tamanhoCM;
    strcpy(novo->genero, genero);
    strcpy(novo->marca, marca);

    return novo;
}

struct tenis *dados_tenis_novo()
{
    float tamanhoCM;
    char *genero = (char *)malloc(15 * sizeof(char));
    char *marca = (char *)malloc(30 * sizeof(char));
    printf("Insira tamanho do tenis em cm: ");
    scanf("%f", &tamanhoCM);
    printf("Defina para qual genero é o tenis: ");
    scanf("%s", genero);
    printf("Insira a marca do tenis: ");
    scanf("%s", marca);

    return criar_tenis_novo(genero, tamanhoCM, marca);
}

void inserir_tenis_no_arquivo(struct tenis *tenisNovo)
{

    FILE *arch = fopen("tenis.txt", "a");
    if (arch == NULL)
    {
        exit(EXIT_FAILURE);
    }

    fprintf(arch, "nome do produto: %s\nvalor: %f\nID: %i\n", tenisNovo->prod->nome, tenisNovo->prod->preco, tenisNovo->prod->ID);
    fprintf(arch, "tamanho: %f\ngenero: %s\nmarca: %s\n", tenisNovo->tamanhoCM, tenisNovo->genero, tenisNovo->marca);
    fclose(arch);
    free(tenisNovo);
}

void realizar_cadastro_produto_tenis()
{
    char *nome = (char *)malloc(30 * sizeof(char));
    float preco;
    int ID;
    printf("Insira o nome do produto: ");
    scanf("%s", nome);
    printf("Insira o nome do valor de venda do produto: ");
    scanf("%f", &preco);
    printf("Insira o ID para o produto: ");
    scanf("%i", &ID);
    struct tenis *tenisNovo = (struct tenis *)malloc(sizeof(struct tenis));
    tenisNovo->prod = (struct produto *)malloc(sizeof(struct produto));
    struct produto *prod = (struct produto *)malloc(sizeof(struct produto));
    // tenisNovo->prod = cadastrar_produto(nome, preco, ID, "tenis.txt");
    prod = cadastrar_produto(nome, preco, ID, "tenis.txt");
    if (tenisNovo->prod != NULL)
    {
        tenisNovo = dados_tenis_novo();
        tenisNovo->prod = prod;
        inserir_tenis_no_arquivo(tenisNovo);
    }
}

struct produto *cadastrar_produto(char *nome, float preco, int ID, const char *nome_arquivo)
{
    struct produto *novo;
    novo = criar_produto(nome, preco, ID);

    if (verificar_produto(novo->ID, nome_arquivo) != NULL)
    {
        system("cls");
        printf("Produto ja cadastrado no sistema\n");
        return NULL;
    }
    else
    {
        return novo;
    }
}

struct produto *verificar_produto(int ID, const char *nome_arquivo)
{
    FILE *arch = fopen(nome_arquivo, "r");
    if (arch == NULL)
    {
        exit(EXIT_FAILURE);
    }
    char nome[MAX_LEN];
    float valor;
    int IDaux;

    while (fscanf(arch, "nome do produto: %99[^\n]\nvalor: %f\nID: %i\n", nome, &valor, &IDaux) == 3)
    {
        if (IDaux == ID)
        {
            struct produto *aux = criar_produto(nome, valor, IDaux);
            fclose(arch);
            return aux;
        }
    }

    fclose(arch);
    return NULL;
}
struct camiseta *criar_camiseta_nova(char tamanho, char *genero, char *marca, char *nome, float preco, int ID, const char *nome_arquivo)
{
    struct camiseta *nova = (struct camiseta *)malloc(sizeof(struct camiseta));
    nova->tamanho = tamanho;
    nova->genero = (char *)malloc((strlen(genero) + 1) * sizeof(char));
    nova->marca = (char *)malloc((strlen(marca) + 1) * sizeof(char));
    nova->prod = cadastrar_produto(nome, preco, ID, nome_arquivo);

    if (nova->prod == NULL)
    {
        free(nova->genero);
        free(nova->marca);
        free(nova);
        return NULL;
    }

    strcpy(nova->genero, genero);
    strcpy(nova->marca, marca);

    return nova;
}

struct camiseta *dados_camiseta_nova(const char *nome_arquivo)
{
    char tamanho;
    char *genero = (char *)malloc(15 * sizeof(char));
    char *marca = (char *)malloc(30 * sizeof(char));
    char *nome = (char *)malloc(30 * sizeof(char));
    float preco;
    int ID;

    printf("Insira o tamanho da camiseta: ");
    scanf(" %c", &tamanho);
    printf("Defina para qual genero é a camiseta: ");
    scanf("%s", genero);
    printf("Insira a marca da camiseta: ");
    scanf("%s", marca);
    printf("Insira o nome do produto: ");
    scanf("%s", nome);
    printf("Insira o preco da camiseta: ");
    scanf("%f", &preco);
    printf("Insira o ID para a camiseta: ");
    scanf("%d", &ID);

    return criar_camiseta_nova(tamanho, genero, marca, nome, preco, ID, nome_arquivo);
}

void inserir_camiseta_no_arquivo(struct camiseta *camisetaNova, const char *nome_arquivo)
{
    FILE *arch = fopen(nome_arquivo, "a");
    if (arch == NULL)
    {
        exit(EXIT_FAILURE);
    }

    fprintf(arch, "nome do produto: %s\nvalor: %f\nID: %i\n", camisetaNova->prod->nome, camisetaNova->prod->preco, camisetaNova->prod->ID);
    fprintf(arch, "tamanho: %c\ngenero: %s\nmarca: %s\n", camisetaNova->tamanho, camisetaNova->genero, camisetaNova->marca);
    fclose(arch);
}

void realizar_cadastro_produto_camiseta()
{
    struct camiseta *camisetaNova = dados_camiseta_nova("camisetas.txt");
    if (camisetaNova != NULL)
    {
        inserir_camiseta_no_arquivo(camisetaNova, "camisetas.txt");
        free(camisetaNova->genero);
        free(camisetaNova->marca);
        free(camisetaNova->prod->nome);
        free(camisetaNova->prod);
        free(camisetaNova);
    }
}

struct acessorio *criar_acessorio_novo(char *marca, char *nome, float preco, int ID, const char *nome_arquivo)
{
    struct acessorio *novo = (struct acessorio *)malloc(sizeof(struct acessorio));
    novo->marca = (char *)malloc((strlen(marca) + 1) * sizeof(char));
    novo->prod = cadastrar_produto(nome, preco, ID, nome_arquivo);

    if (novo->prod == NULL)
    {
        free(novo->marca);
        free(novo);
        return NULL;
    }

    strcpy(novo->marca, marca);
    return novo;
}

struct acessorio *dados_acessorio_novo(const char *nome_arquivo)
{
    char *marca = (char *)malloc(30 * sizeof(char));
    char *nome = (char *)malloc(30 * sizeof(char));
    float preco;
    int ID;

    printf("Insira a marca do acessório: ");
    scanf("%s", marca);
    printf("Insira o nome do produto: ");
    scanf("%s", nome);
    printf("Insira o preco do acessório: ");
    scanf("%f", &preco);
    printf("Insira o ID para o acessório: ");
    scanf("%d", &ID);

    return criar_acessorio_novo(marca, nome, preco, ID, nome_arquivo);
}

void inserir_acessorio_no_arquivo(struct acessorio *acessorioNovo, const char *nome_arquivo)
{
    FILE *arch = fopen(nome_arquivo, "a");
    if (arch == NULL)
    {
        exit(EXIT_FAILURE);
    }

    fprintf(arch, "nome do produto: %s\nvalor: %f\nID: %i\n", acessorioNovo->prod->nome, acessorioNovo->prod->preco, acessorioNovo->prod->ID);
    fprintf(arch, "marca: %s\n", acessorioNovo->marca);
    fclose(arch);
}

void realizar_cadastro_produto_acessorio()
{
    struct acessorio *acessorioNovo = dados_acessorio_novo("acessorio.txt");
    if (acessorioNovo != NULL)
    {
        inserir_acessorio_no_arquivo(acessorioNovo, "acessorio.txt");
        free(acessorioNovo->marca);
        free(acessorioNovo->prod->nome);
        free(acessorioNovo->prod);
        free(acessorioNovo);
    }
}

struct bola *criar_bola_nova(char *marca, char *nome, float preco, int ID, const char *nome_arquivo)
{
    struct bola *nova = (struct bola *)malloc(sizeof(struct bola));
    nova->marca = (char *)malloc((strlen(marca) + 1) * sizeof(char));
    nova->prod = cadastrar_produto(nome, preco, ID, nome_arquivo);

    if (nova->prod == NULL)
    {
        free(nova->marca);
        free(nova);
        return NULL;
    }

    strcpy(nova->marca, marca);
    return nova;
}

struct bola *dados_bola_nova(const char *nome_arquivo)
{
    char *marca = (char *)malloc(30 * sizeof(char));
    char *nome = (char *)malloc(30 * sizeof(char));
    float preco;
    int ID;

    printf("Insira a marca da bola: ");
    scanf("%s", marca);
    printf("Insira o nome do produto: ");
    scanf("%s", nome);
    printf("Insira o preco da bola: ");
    scanf("%f", &preco);
    printf("Insira o ID para a bola: ");
    scanf("%d", &ID);

    return criar_bola_nova(marca, nome, preco, ID, nome_arquivo);
}

void inserir_bola_no_arquivo(struct bola *bolaNova, const char *nome_arquivo)
{
    FILE *arch = fopen(nome_arquivo, "a");
    if (arch == NULL)
    {
        exit(EXIT_FAILURE);
    }

    fprintf(arch, "nome do produto: %s\nvalor: %f\nID: %i\n", bolaNova->prod->nome, bolaNova->prod->preco, bolaNova->prod->ID);
    fprintf(arch, "marca: %s\n", bolaNova->marca);
    fclose(arch);
}

void realizar_cadastro_produto_bola()
{
    struct bola *bolaNova = dados_bola_nova("bola.txt");
    if (bolaNova != NULL)
    {
        inserir_bola_no_arquivo(bolaNova, "bola.txt");
        free(bolaNova->marca);
        free(bolaNova->prod->nome);
        free(bolaNova->prod);
        free(bolaNova);
    }
}

struct bone *criar_bone_novo(char *marca, char *nome, float preco, int ID, const char *nome_arquivo)
{
    struct bone *novo = (struct bone *)malloc(sizeof(struct bone));
    novo->marca = (char *)malloc((strlen(marca) + 1) * sizeof(char));
    novo->prod = cadastrar_produto(nome, preco, ID, nome_arquivo);

    if (novo->prod == NULL)
    {
        free(novo->marca);
        free(novo);
        return NULL;
    }

    strcpy(novo->marca, marca);
    return novo;
}

struct bone *dados_bone_novo(const char *nome_arquivo)
{
    char *marca = (char *)malloc(30 * sizeof(char));
    char *nome = (char *)malloc(30 * sizeof(char));
    float preco;
    int ID;

    printf("Insira a marca do boné: ");
    scanf("%s", marca);
    printf("Insira o nome do produto: ");
    scanf("%s", nome);
    printf("Insira o preco do boné: ");
    scanf("%f", &preco);
    printf("Insira o ID para o boné: ");
    scanf("%d", &ID);

    return criar_bone_novo(marca, nome, preco, ID, nome_arquivo);
}

void inserir_bone_no_arquivo(struct bone *boneNovo, const char *nome_arquivo)
{
    FILE *arch = fopen(nome_arquivo, "a");
    if (arch == NULL)
    {
        exit(EXIT_FAILURE);
    }

    fprintf(arch, "nome do produto: %s\nvalor: %f\nID: %i\n", boneNovo->prod->nome, boneNovo->prod->preco, boneNovo->prod->ID);
    fprintf(arch, "marca: %s\n", boneNovo->marca);
    fclose(arch);
}

void realizar_cadastro_produto_bone()
{
    struct bone *boneNovo = dados_bone_novo("bone.txt");
    if (boneNovo != NULL)
    {
        inserir_bone_no_arquivo(boneNovo, "bone.txt");
        free(boneNovo->marca);
        free(boneNovo->prod->nome);
        free(boneNovo->prod);
        free(boneNovo);
    }
}

struct chinelo *criar_chinelo_novo(char *marca, float tamanhoCM, char *nome, float preco, int ID, const char *nome_arquivo)
{
    struct chinelo *novo = (struct chinelo *)malloc(sizeof(struct chinelo));
    novo->marca = (char *)malloc((strlen(marca) + 1) * sizeof(char));
    novo->prod = cadastrar_produto(nome, preco, ID, nome_arquivo);

    if (novo->prod == NULL)
    {
        free(novo->marca);
        free(novo);
        return NULL;
    }

    strcpy(novo->marca, marca);
    novo->tamanhoCM = tamanhoCM;
    return novo;
}

struct chinelo *dados_chinelo_novo(const char *nome_arquivo)
{
    char *marca = (char *)malloc(30 * sizeof(char));
    char *nome = (char *)malloc(30 * sizeof(char));
    float tamanhoCM;
    float preco;
    int ID;

    printf("Insira a marca do chinelo: ");
    scanf("%s", marca);
    printf("Insira o tamanho do chinelo em cm: ");
    scanf("%f", &tamanhoCM);
    printf("Insira o nome do produto: ");
    scanf("%s", nome);
    printf("Insira o preco do chinelo: ");
    scanf("%f", &preco);
    printf("Insira o ID para o chinelo: ");
    scanf("%d", &ID);

    return criar_chinelo_novo(marca, tamanhoCM, nome, preco, ID, nome_arquivo);
}

void inserir_chinelo_no_arquivo(struct chinelo *chineloNovo, const char *nome_arquivo)
{
    FILE *arch = fopen(nome_arquivo, "a");
    if (arch == NULL)
    {
        exit(EXIT_FAILURE);
    }

    fprintf(arch, "nome do produto: %s\nvalor: %f\nID: %i\n", chineloNovo->prod->nome, chineloNovo->prod->preco, chineloNovo->prod->ID);
    fprintf(arch, "tamanho: %f\nmarca: %s\n", chineloNovo->tamanhoCM, chineloNovo->marca);
    fclose(arch);
}

void realizar_cadastro_produto_chinelo()
{
    struct chinelo *chineloNovo = dados_chinelo_novo("chinelo.txt");
    if (chineloNovo != NULL)
    {
        inserir_chinelo_no_arquivo(chineloNovo, "chinelo.txt");
        free(chineloNovo->marca);
        free(chineloNovo->prod->nome);
        free(chineloNovo->prod);
        free(chineloNovo);
    }
}

struct creatina *criar_creatina_nova(float quantidadeML, char *marca, char *nome, float preco, int ID, const char *nome_arquivo)
{
    struct creatina *nova = (struct creatina *)malloc(sizeof(struct creatina));
    nova->quantidadeML = quantidadeML;
    nova->marca = (char *)malloc((strlen(marca) + 1) * sizeof(char));
    nova->prod = cadastrar_produto(nome, preco, ID, nome_arquivo);

    if (nova->prod == NULL)
    {
        free(nova->marca);
        free(nova);
        return NULL;
    }

    strcpy(nova->marca, marca);
    return nova;
}

struct creatina *dados_creatina_nova(const char *nome_arquivo)
{
    char *marca = (char *)malloc(30 * sizeof(char));
    char *nome = (char *)malloc(30 * sizeof(char));
    float quantidadeML;
    float preco;
    int ID;

    printf("Insira a quantidade de creatina em ml: ");

    scanf("%f", &quantidadeML);
    printf("Insira a marca da creatina: ");
    scanf("%s", marca);
    printf("Insira o nome do produto: ");
    scanf("%s", nome);
    printf("Insira o preco da creatina: ");
    scanf("%f", &preco);
    printf("Insira o ID para a creatina: ");
    scanf("%d", &ID);

    return criar_creatina_nova(quantidadeML, marca, nome, preco, ID, nome_arquivo);
}

void inserir_creatina_no_arquivo(struct creatina *creatinaNova, const char *nome_arquivo)
{
    FILE *arch = fopen(nome_arquivo, "a");
    if (arch == NULL)
    {
        exit(EXIT_FAILURE);
    }

    fprintf(arch, "nome do produto: %s\nvalor: %f\nID: %i\n", creatinaNova->prod->nome, creatinaNova->prod->preco, creatinaNova->prod->ID);
    fprintf(arch, "quantidade: %f\nmarca: %s\n", creatinaNova->quantidadeML, creatinaNova->marca);
    fclose(arch);
}

void realizar_cadastro_produto_creatina()
{
    struct creatina *creatinaNova = dados_creatina_nova("creatina.txt");
    if (creatinaNova != NULL)
    {
        inserir_creatina_no_arquivo(creatinaNova, "creatina.txt");
        free(creatinaNova->marca);
        free(creatinaNova->prod->nome);
        free(creatinaNova->prod);
        free(creatinaNova);
    }
}

void listar_tenis(FILE *arch)
{
    char nome[MAX_LEN];
    float preco;
    int ID;
    float tamanhoCM;
    char genero[MAX_LEN];
    char marca[MAX_LEN];

    printf("\n--- Listagem de Tênis ---\n");
    while (fscanf(arch, "nome do produto: %99[^\n]\nvalor: %f\nID: %i\ntamanho: %f\ngenero: %99[^\n]\nmarca: %99[^\n]\n",
                  nome, &preco, &ID, &tamanhoCM, genero, marca) == 6)
    {
        printf("nome do produto: %s\nvalor: %f\nID: %i\ntamanho: %f\ngenero: %s\nmarca: %s\n",
               nome, preco, ID, tamanhoCM, genero, marca);
    }
}

void listar_camisetas(FILE *arch)
{
    char nome[MAX_LEN];
    float preco;
    int ID;
    char tamanho;
    char genero[MAX_LEN];
    char marca[MAX_LEN];

    printf("\n--- Listagem de Camisetas ---\n");
    while (fscanf(arch, "nome do produto: %99[^\n]\nvalor: %f\nID: %i\ntamanho: %c\ngenero: %99[^\n]\nmarca: %99[^\n]\n",
                  nome, &preco, &ID, &tamanho, genero, marca) == 6)
    {
        printf("nome do produto: %s\nvalor: %f\nID: %i\ntamanho: %c\ngenero: %s\nmarca: %s\n",
               nome, preco, ID, tamanho, genero, marca);
    }
}

void listar_acessorios(FILE *arch)
{
    char nome[MAX_LEN];
    float preco;
    int ID;
    char marca[MAX_LEN];

    printf("\n--- Listagem de Acessórios ---\n");
    while (fscanf(arch, "nome do produto: %99[^\n]\nvalor: %f\nID: %i\nmarca: %99[^\n]\n",
                  nome, &preco, &ID, marca) == 4)
    {
        printf("nome do produto: %s\nvalor: %f\nID: %i\nmarca: %s\n",
               nome, preco, ID, marca);
    }
}

void listar_bolas(FILE *arch)
{
    char nome[MAX_LEN];
    float preco;
    int ID;
    char marca[MAX_LEN];

    printf("\n--- Listagem de Bolas ---\n");
    while (fscanf(arch, "nome do produto: %99[^\n]\nvalor: %f\nID: %i\nmarca: %99[^\n]\n",
                  nome, &preco, &ID, marca) == 4)
    {
        printf("nome do produto: %s\nvalor: %f\nID: %i\nmarca: %s\n",
               nome, preco, ID, marca);
    }
}

void listar_bones(FILE *arch)
{
    char nome[MAX_LEN];
    float preco;
    int ID;
    char marca[MAX_LEN];

    printf("\n--- Listagem de Bonés ---\n");
    while (fscanf(arch, "nome do produto: %99[^\n]\nvalor: %f\nID: %i\nmarca: %99[^\n]\n",
                  nome, &preco, &ID, marca) == 4)
    {
        printf("nome do produto: %s\nvalor: %f\nID: %i\nmarca: %s\n",
               nome, preco, ID, marca);
    }
}

void listar_chinelos(FILE *arch)
{
    char nome[MAX_LEN];
    float preco;
    int ID;
    char marca[MAX_LEN];
    float tamanhoCM;

    printf("\n--- Listagem de Chinelos ---\n");
    while (fscanf(arch, "nome do produto: %99[^\n]\nvalor: %f\nID: %i\ntamanho: %f\nmarca: %99[^\n]\n",
                  nome, &preco, &ID, &tamanhoCM, marca) == 5)
    {
        printf("nome do produto: %s\nvalor: %f\nID: %i\ntamanho: %f\nmarca: %s\n",
               nome, preco, ID, tamanhoCM, marca);
    }
}

void listar_creatinas(FILE *arch)
{
    char nome[MAX_LEN];
    float preco;
    int ID;
    char marca[MAX_LEN];
    float quantidadeML;

    printf("\n--- Listagem de Creatinas ---\n");
    while (fscanf(arch, "nome do produto: %99[^\n]\nvalor: %f\nID: %i\nquantidade: %f\nmarca: %99[^\n]\n",
                  nome, &preco, &ID, &quantidadeML, marca) == 5)
    {
        printf("nome do produto: %s\nvalor: %f\nID: %i\nquantidade: %f\nmarca: %s\n",
               nome, preco, ID, quantidadeML, marca);
    }
}

void listar_produtos()
{
    const char *arquivos[] = {
        "camiseta.txt",
        "acessorio.txt",
        "bola.txt",
        "bone.txt",
        "chinelo.txt",
        "creatina.txt",
        "tenis.txt"};

    size_t num_arquivos = sizeof(arquivos) / sizeof(arquivos[0]);
    FILE *arch = NULL;

    for (size_t i = 0; i < num_arquivos; ++i)
    {
        arch = fopen(arquivos[i], "r");
        if (arch == NULL)
        {
            printf("Não foi possível abrir o arquivo %s\n", arquivos[i]);
            continue;
        }

        if (strstr(arquivos[i], "camiseta") != NULL)
        {
            listar_camisetas(arch);
        }
        else if (strstr(arquivos[i], "acessorio") != NULL)
        {
            listar_acessorios(arch);
        }
        else if (strstr(arquivos[i], "bola") != NULL)
        {
            listar_bolas(arch);
        }
        else if (strstr(arquivos[i], "bone") != NULL)
        {
            listar_bones(arch);
        }
        else if (strstr(arquivos[i], "chinelo") != NULL)
        {
            listar_chinelos(arch);
        }
        else if (strstr(arquivos[i], "creatina") != NULL)
        {
            listar_creatinas(arch);
        }
        else if (strstr(arquivos[i], "tenis") != NULL)
        {
            listar_tenis(arch);
        }

        fclose(arch);
    }
}

void editar_camiseta()
{
    int ID;
    char nome[MAX_LEN];
    float preco;
    int encontrado = 0;

    printf("Insira o ID da camiseta a ser editada: ");
    scanf("%d", &ID);

    FILE *arch = fopen("camiseta.txt", "r");
    if (arch == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    FILE *temp = fopen("camiseta_temp.txt", "w");
    if (temp == NULL)
    {
        perror("Erro ao criar o arquivo temporário");
        fclose(arch);
        exit(EXIT_FAILURE);
    }

    char nome_temp[MAX_LEN];
    float preco_temp;
    int ID_temp;
    char tamanho;
    char genero[MAX_LEN];
    char marca[MAX_LEN];

    while (fscanf(arch, "nome do produto: %99[^\n]\nvalor: %f\nID: %i\ntamanho: %c\ngenero: %99[^\n]\nmarca: %99[^\n]\n",
                  nome_temp, &preco_temp, &ID_temp, &tamanho, genero, marca) == 6)
    {
        if (ID_temp == ID)
        {
            encontrado = 1;
            printf("Camiseta encontrada! Insira os novos dados:\n");

            printf("Novo nome do produto: ");
            scanf(" %[^\n]", nome);
            printf("Novo valor do produto: ");
            scanf("%f", &preco);
            printf("Novo tamanho: ");
            scanf(" %c", &tamanho);
            printf("Novo gênero: ");
            scanf(" %[^\n]", genero);
            printf("Nova marca: ");
            scanf(" %[^\n]", marca);

            fprintf(temp, "nome do produto: %s\nvalor: %f\nID: %i\ntamanho: %c\ngenero: %s\nmarca: %s\n",
                    nome, preco, ID, tamanho, genero, marca);
        }
        else
        {
            fprintf(temp, "nome do produto: %s\nvalor: %f\nID: %i\ntamanho: %c\ngenero: %s\nmarca: %s\n",
                    nome_temp, preco_temp, ID_temp, tamanho, genero, marca);
        }
    }

    if (!encontrado)
    {
        printf("Camiseta com ID %d não encontrada.\n", ID);
    }

    fclose(arch);
    fclose(temp);

    if (remove("camiseta.txt") != 0)
    {
        perror("Erro ao remover o arquivo original");
        exit(EXIT_FAILURE);
    }

    if (rename("camiseta_temp.txt", "camiseta.txt") != 0)
    {
        perror("Erro ao renomear o arquivo temporário");
        exit(EXIT_FAILURE);
    }
}

void editar_acessorio()
{
    int ID;
    char nome[MAX_LEN];
    float preco;
    int encontrado = 0;

    printf("Insira o ID do acessório a ser editado: ");
    scanf("%d", &ID);

    FILE *arch = fopen("acessorio.txt", "r");
    if (arch == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    FILE *temp = fopen("acessorio_temp.txt", "w");
    if (temp == NULL)
    {
        perror("Erro ao criar o arquivo temporário");
        fclose(arch);
        exit(EXIT_FAILURE);
    }

    char nome_temp[MAX_LEN];
    float preco_temp;
    int ID_temp;
    char marca[MAX_LEN];

    while (fscanf(arch, "nome do produto: %99[^\n]\nvalor: %f\nID: %i\nmarca: %99[^\n]\n",
                  nome_temp, &preco_temp, &ID_temp, marca) == 4)
    {
        if (ID_temp == ID)
        {
            encontrado = 1;
            printf("Acessório encontrado! Insira os novos dados:\n");

            printf("Novo nome do produto: ");
            scanf(" %[^\n]", nome);
            printf("Novo valor do produto: ");
            scanf("%f", &preco);
            printf("Nova marca: ");
            scanf(" %[^\n]", marca);

            fprintf(temp, "nome do produto: %s\nvalor: %f\nID: %i\nmarca: %s\n",
                    nome, preco, ID, marca);
        }
        else
        {
            fprintf(temp, "nome do produto: %s\nvalor: %f\nID: %i\nmarca: %s\n",
                    nome_temp, preco_temp, ID_temp, marca);
        }
    }

    if (!encontrado)
    {
        printf("Acessório com ID %d não encontrado.\n", ID);
    }

    fclose(arch);
    fclose(temp);

    if (remove("acessorio.txt") != 0)
    {
        perror("Erro ao remover o arquivo original");
        exit(EXIT_FAILURE);
    }

    if (rename("acessorio_temp.txt", "acessorio.txt") != 0)
    {
        perror("Erro ao renomear o arquivo temporário");
        exit(EXIT_FAILURE);
    }
}

void editar_bola()
{
    int ID;
    char nome[MAX_LEN];
    float preco;
    int encontrado = 0;

    printf("Insira o ID da bola a ser editada: ");
    scanf("%d", &ID);

    FILE *arch = fopen("bola.txt", "r");
    if (arch == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    FILE *temp = fopen("bola_temp.txt", "w");
    if (temp == NULL)
    {
        perror("Erro ao criar o arquivo temporário");
        fclose(arch);
        exit(EXIT_FAILURE);
    }

    char nome_temp[MAX_LEN];
    float preco_temp;
    int ID_temp;
    char marca[MAX_LEN];

    while (fscanf(arch, "nome do produto: %99[^\n]\nvalor: %f\nID: %i\nmarca: %99[^\n]\n",
                  nome_temp, &preco_temp, &ID_temp, marca) == 4)
    {
        if (ID_temp == ID)
        {
            encontrado = 1;
            printf("Bola encontrada! Insira os novos dados:\n");

            printf("Novo nome do produto: ");
            scanf(" %[^\n]", nome);
            printf("Novo valor do produto: ");
            scanf("%f", &preco);
            printf("Nova marca: ");
            scanf(" %[^\n]", marca);

            fprintf(temp, "nome do produto: %s\nvalor: %f\nID: %i\nmarca: %s\n",
                    nome, preco, ID, marca);
        }
        else
        {
            fprintf(temp, "nome do produto: %s\nvalor: %f\nID: %i\nmarca: %s\n",
                    nome_temp, preco_temp, ID_temp, marca);
        }
    }

    if (!encontrado)
    {
        printf("Bola com ID %d não encontrada.\n", ID);
    }

    fclose(arch);
    fclose(temp);

    if (remove("bola.txt") != 0)
    {
        perror("Erro ao remover o arquivo original");
        exit(EXIT_FAILURE);
    }

    if (rename("bola_temp.txt", "bola.txt") != 0)
    {
        perror("Erro ao renomear o arquivo temporário");
        exit(EXIT_FAILURE);
    }
}

void editar_bone()
{
    int ID;
    char nome[MAX_LEN];
    float preco;
    int encontrado = 0;

    printf("Insira o ID do boné a ser editado: ");
    scanf("%d", &ID);

    FILE *arch = fopen("bone.txt", "r");
    if (arch == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    FILE *temp = fopen("bone_temp.txt", "w");
    if (temp == NULL)
    {
        perror("Erro ao criar o arquivo temporário");
        fclose(arch);
        exit(EXIT_FAILURE);
    }

    char nome_temp[MAX_LEN];
    float preco_temp;
    int ID_temp;
    char marca[MAX_LEN];

    while (fscanf(arch, "nome do produto: %99[^\n]\nvalor: %f\nID: %i\nmarca: %99[^\n]\n",
                  nome_temp, &preco_temp, &ID_temp, marca) == 4)
    {
        if (ID_temp == ID)
        {
            encontrado = 1;
            printf("Boné encontrado! Insira os novos dados:\n");

            printf("Novo nome do produto: ");
            scanf(" %[^\n]", nome);
            printf("Novo valor do produto: ");
            scanf("%f", &preco);
            printf("Nova marca: ");
            scanf(" %[^\n]", marca);

            fprintf(temp, "nome do produto: %s\nvalor: %f\nID: %i\nmarca: %s\n",
                    nome, preco, ID, marca);
        }
        else
        {
            fprintf(temp, "nome do produto: %s\nvalor: %f\nID: %i\nmarca: %s\n",
                    nome_temp, preco_temp, ID_temp, marca);
        }
    }

    if (!encontrado)
    {
        printf("Boné com ID %d não encontrado.\n", ID);
    }

    fclose(arch);
    fclose(temp);

    if (remove("bone.txt") != 0)
    {
        perror("Erro ao remover o arquivo original");
        exit(EXIT_FAILURE);
    }

    if (rename("bone_temp.txt", "bone.txt") != 0)
    {
        perror("Erro ao renomear o arquivo temporário");
        exit(EXIT_FAILURE);
    }
}

void editar_chinelo()
{
    int ID;
    char nome[MAX_LEN];
    float preco;
    int encontrado = 0;

    printf("Insira o ID do chinelo a ser editado: ");
    scanf("%d", &ID);

    FILE *arch = fopen("chinelo.txt", "r");
    if (arch == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    FILE *temp = fopen("chinelo_temp.txt", "w");
    if (temp == NULL)
    {
        perror("Erro ao criar o arquivo temporário");
        fclose(arch);
        exit(EXIT_FAILURE);
    }

    char nome_temp[MAX_LEN];
    float preco_temp;
    int ID_temp;
    float tamanhoCM;
    char marca[MAX_LEN];

    while (fscanf(arch, "nome do produto: %99[^\n]\nvalor: %f\nID: %i\ntamanho: %f\nmarca: %99[^\n]\n",
                  nome_temp, &preco_temp, &ID_temp, &tamanhoCM, marca) == 5)
    {
        if (ID_temp == ID)
        {
            encontrado = 1;
            printf("Chinelo encontrado! Insira os novos dados:\n");

            printf("Novo nome do produto: ");
            scanf(" %[^\n]", nome);
            printf("Novo valor do produto: ");
            scanf("%f", &preco);
            printf("Novo tamanho: ");
            scanf("%f", &tamanhoCM);
            printf("Nova marca: ");
            scanf(" %[^\n]", marca);

            fprintf(temp, "nome do produto: %s\nvalor: %f\nID: %i\ntamanho: %f\nmarca: %s\n",
                    nome, preco, ID, tamanhoCM, marca);
        }
        else
        {
            fprintf(temp, "nome do produto: %s\nvalor: %f\nID: %i\ntamanho: %f\nmarca: %s\n",
                    nome_temp, preco_temp, ID_temp, tamanhoCM, marca);
        }
    }

    if (!encontrado)
    {
        printf("Chinelo com ID %d não encontrado.\n", ID);
    }

    fclose(arch);
    fclose(temp);

    if (remove("chinelo.txt") != 0)
    {
        perror("Erro ao remover o arquivo original");
        exit(EXIT_FAILURE);
    }

    if (rename("chinelo_temp.txt", "chinelo.txt") != 0)
    {
        perror("Erro ao renomear o arquivo temporário");
        exit(EXIT_FAILURE);
    }
}

void editar_creatina()
{
    int ID;
    char nome[MAX_LEN];
    float preco;
    int encontrado = 0;

    printf("Insira o ID da creatina a ser editada: ");
    scanf("%d", &ID);

    FILE *arch = fopen("creatina.txt", "r");
    if (arch == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    FILE *temp = fopen("creatina_temp.txt", "w");
    if (temp == NULL)
    {
        perror("Erro ao criar o arquivo temporário");
        fclose(arch);
        exit(EXIT_FAILURE);
    }

    char nome_temp[MAX_LEN];
    float preco_temp;
    int ID_temp;
    float quantidadeML;
    char marca[MAX_LEN];

    while (fscanf(arch, "nome do produto: %99[^\n]\nvalor: %f\nID: %i\nquantidade: %f\nmarca: %99[^\n]\n",
                  nome_temp, &preco_temp, &ID_temp, &quantidadeML, marca) == 5)
    {
        if (ID_temp == ID)
        {
            encontrado = 1;
            printf("Creatina encontrada! Insira os novos dados:\n");

            printf("Novo nome do produto: ");
            scanf(" %[^\n]", nome);
            printf("Novo valor do produto: ");
            scanf("%f", &preco);
            printf("Nova quantidade em ML: ");
            scanf("%f", &quantidadeML);
            printf("Nova marca: ");
            scanf(" %[^\n]", marca);

            fprintf(temp, "nome do produto: %s\nvalor: %f\nID: %i\nquantidade: %f\nmarca: %s\n",
                    nome, preco, ID, quantidadeML, marca);
        }
        else
        {
            fprintf(temp, "nome do produto: %s\nvalor: %f\nID: %i\nquantidade: %f\nmarca: %s\n",
                    nome_temp, preco_temp, ID_temp, quantidadeML, marca);
        }
    }

    if (!encontrado)
    {
        printf("Creatina com ID %d não encontrada.\n", ID);
    }

    fclose(arch);
    fclose(temp);

    if (remove("creatina.txt") != 0)
    {
        perror("Erro ao remover o arquivo original");
        exit(EXIT_FAILURE);
    }

    if (rename("creatina_temp.txt", "creatina.txt") != 0)
    {
        perror("Erro ao renomear o arquivo temporário");
        exit(EXIT_FAILURE);
    }
}

void editar_tenis()
{
    int ID;
    char nome[MAX_LEN];
    float preco;
    int encontrado = 0;

    printf("Insira o ID do tênis a ser editado: ");
    scanf("%d", &ID);

    FILE *arch = fopen("tenis.txt", "r");
    if (arch == NULL)
    {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    FILE *temp = fopen("tenis_temp.txt", "w");
    if (temp == NULL)
    {
        perror("Erro ao criar o arquivo temporário");
        fclose(arch);
        exit(EXIT_FAILURE);
    }

    char nome_temp[MAX_LEN];
    float preco_temp;
    int ID_temp;
    float tamanhoCM;
    char genero[MAX_LEN];
    char marca[MAX_LEN];

    while (fscanf(arch, "nome do produto: %99[^\n]\nvalor: %f\nID: %i\ntamanho: %f\ngenero: %99[^\n]\nmarca: %99[^\n]\n",
                  nome_temp, &preco_temp, &ID_temp, &tamanhoCM, genero, marca) == 6)
    {
        if (ID_temp == ID)
        {
            encontrado = 1;
            printf("Tênis encontrado! Insira os novos dados:\n");

            printf("Novo nome do produto: ");
            scanf(" %[^\n]", nome);
            printf("Novo valor do produto: ");
            scanf("%f", &preco);
            printf("Novo tamanho em CM: ");
            scanf("%f", &tamanhoCM);
            printf("Novo gênero: ");
            scanf(" %[^\n]", genero);
            printf("Nova marca: ");
            scanf(" %[^\n]", marca);

            fprintf(temp, "nome do produto: %s\nvalor: %f\nID: %i\ntamanho: %f\ngenero: %s\nmarca: %s\n",
                    nome, preco, ID, tamanhoCM, genero, marca);
        }
        else
        {
            fprintf(temp, "nome do produto: %s\nvalor: %f\nID: %i\ntamanho: %f\ngenero: %s\nmarca: %s\n",
                    nome_temp, preco_temp, ID_temp, tamanhoCM, genero, marca);
        }
    }

    if (!encontrado)
    {
        printf("Tênis com ID %d não encontrado.\n", ID);
    }

    fclose(arch);
    fclose(temp);

    if (remove("tenis.txt") != 0)
    {
        perror("Erro ao remover o arquivo original");
        exit(EXIT_FAILURE);
    }

    if (rename("tenis_temp.txt", "tenis.txt") != 0)
    {
        perror("Erro ao renomear o arquivo temporário");
        exit(EXIT_FAILURE);
    }
}
