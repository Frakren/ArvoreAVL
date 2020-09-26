#include "ArvoreAVL.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
int maxNum(int a, int b)
{
    if(a>b)
        return a;
    return b;
}
ArAVL insAvl(ArAVL a,TipoA elem)
{
    if(vaziaArAVL(a))
    {
        ArAVL novoNo=(ArAVL)malloc(sizeof(TADArAVL));
        novoNo->esq=novoNo->dir=NULL;
        strcpy(novoNo->info,elem);
        novoNo->alt=0;
        return novoNo;
    }
    else if(strcmp(elem,a->info)<0)
    {
        a->esq=insAvl(esqArAVL(a),elem);
        if((altura(esqArAVL(a))-altura(dirArAVL(a)))==2)
        {
            if(strcmp(elem,a->esq->info)<0)
                return rotacaoDireita(a);
            else
                return rotacaoEsqDir(a);
        }
    }
    else
    {
        if(strcmp(elem,a->info)>0)
        {
            a->dir=insAvl(dirArAVL(a),elem);
            if((altura(esqArAVL(a))-altura(dirArAVL(a)))==2)
            {
                if(strcmp(elem,a->esq->info)>0)
                    return rotacaoEsquerda(a);
                else
                    return rotacaoDirEsq(a);
            }
        }
    }
    a->alt=maxNum(altura(esqArAVL(a)),altura(dirArAVL(a)))+1;
    return a;
}

ArAVL inicArAVL()
{
    return NULL;
}
int altura(ArAVL a)
{
    if(vaziaArAVL(a))
        return -1;
    return a->alt;
}
ArAVL rotacaoDirEsq(ArAVL a)
{
    a->dir=rotacaoDireita(dirArAVL(a));
    return rotacaoEsquerda(a);
}
ArAVL rotacaoEsqDir(ArAVL a)
{
    a->esq=rotacaoEsquerda(esqArAVL(a));
    return rotacaoDireita(a);
}
ArAVL rotacaoDireita(ArAVL a)
{
    ArAVL No=esqArAVL(a);
    a->esq=No->dir;
    No->dir=a;
    a->alt=maxNum(altura(dirArAVL(a)),altura(esqArAVL(a)))+1;
    No->alt=maxNum(altura(esqArAVL(No)),altura(a))+1;
    return a=No;
}
ArAVL rotacaoEsquerda(ArAVL a)
{
    ArAVL No=dirArAVL(a);
    a->dir=No->esq;
    No->esq=a;
    a->alt= maxNum(altura(dirArAVL(a)),altura(esqArAVL(a)))+1;
    No->alt=maxNum(altura(dirArAVL(No)),altura(a))+1;
    return a=No;
}
void visitarAVL(ArAVL elem)
{
    printf("%s ",elem->info);
}
void preOrdem(ArAVL a)
{
    if(!vaziaArAVL(a))
    {
        visitarAVL(a);
        preOrdem(esqArAVL(a));
        preOrdem(dirArAVL(a));
    }
}

ArAVL esqArAVL(ArAVL a)
{
    return a->esq;
}
ArAVL dirArAVL(ArAVL a)
{
    return a->dir;
}
int vaziaArAVL(ArAVL a)
{
    if(a==NULL)
        return 1;
    else
        return 0;
}
void destruirArAVL(ArAVL a)
{
    if(!vaziaArAVL(a))
    {
        destruirArAVL(esqArAVL(a));
        destruirArAVL(dirArAVL(a));
        free(a);
    }
}
