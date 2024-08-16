#include "administrador.c"

int main()
{
    int r;
    printf("login como administrador?\n");
    printf("1 - Sim\n");
    printf("2 - Nao\n");
    scanf("%i", &r);
    if (r == 1)
    {
        realizar_login_adm();
    }
    else
    {
        menu_sem_login();
    }
}


