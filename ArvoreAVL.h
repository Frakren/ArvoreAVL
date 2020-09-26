#ifndef ARVOREAVL_H_INCLUDED
#define ARVOREAVL_H_INCLUDED
#include <stdio.h>
#define tam 100
typedef char TipoA[tam];
typedef struct NodoAVL
{
    TipoA info;
    int alt;
    struct NodoAVL *esq,*dir;
}TADArAVL,*ArAVL;

void visitarAVL(ArAVL elem);
ArAVL insAvl(ArAVL a,TipoA elem);
ArAVL rotacaoEsqDir(ArAVL a);
ArAVL rotacaoDirEsq(ArAVL a);
int altura(ArAVL a);
ArAVL rotacaoEsquerda(ArAVL a);
ArAVL rotacaoDireita(ArAVL a);
ArAVL inicArAVL();// cria e retorna uma arvore binaria vazia
ArAVL esqArAVL(ArAVL a);//retorna a subArvore esquerda
ArAVL dirArAVL(ArAVL a);//retorna a subArvore direita
int vaziaArAVL(ArAVL a);// retorna true se a arvore estiver vazia
void destruirArAVL(ArAVL a);
void preOrdem(ArAVL a);
void inOrdem(ArAVL a);
void posOrdem(ArAVL a);
//void niveisArbin(ArAVL a);
#endif // ARVOREAVL_H_INCLUDED
