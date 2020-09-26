#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.c"
void Menu();
void InserirArvore(ArAVL raiz);
void Exibir(ArAVL raiz);
void Exibir(ArAVL raiz)
{
    printf("PreOrdem\n");
    preOrdem(raiz);
    printf("\n");
    printf("\n");
}
void InserirArvore(ArAVL raiz)
{
    char string[tam];
    printf("Digite uma palavra\n");
    scanf("%s",string);
    raiz=insAvl(raiz,string);
}
void Menu()
{
    printf("Escolha uma das opcoes abaixo\n");
    printf("1-Carregar Arvore\n");
    printf("2-Inserir na Arvore\n");
    printf("3-Exibir\n");
    printf("0-Sair\n");
}
int main()
{
    char string[tam];
    ArAVL raiz=inicArAVL();
    FILE *Arq=NULL;
    int op;
    do
    {
        Menu();
        scanf("%i",&op);
        switch(op)
        {
        case 1:
            Arq=fopen("entrada.txt","r");
            if(Arq==NULL)
            {
                printf("Nao eh possivel carregar o arquivo, porfavor verifique o arquivo\n");
            }
            else
            {
                while((fscanf(Arq,"%s",string))!=EOF)
                {
                    raiz=insAvl(raiz,string);
                }
            }
            fclose(Arq);
            break;
        case 2:
            InserirArvore(raiz);
            break;
        case 3:
            Exibir(raiz);
            break;
        default:
            printf("Fim do programa\n");
            break;
        }
    }
    while(op!=0);
    return 0;
}
