#include <stdio.h>
#include <stdlib.h>

struct no{
    int dado;
    struct no *prox;
};

struct descritor{
    int n;
    struct no *i, *f;
};

void delete(struct descritor *d, int value){
    struct no *after = d->i;
    struct no *before = NULL;

    //procura o valor a ser excluido
    while(after != NULL && after->dado != value){
        before = after;
        after = after->prox;
    }

    if(after != NULL){
        //se for o primeiro da lista
        if(before == NULL){
            d->i = after->prox;
        }else{
            before->prox = after->prox;
        }

        //se for o ultimo da lista
        if(after == d->f){
            d->f = before;
        }

        //libera a memoria do no excluido
        free(after);
        d->n--;

        printf("Dado removido com sucesso!\n");
    }else{
        printf("Dado nao encontrado na lista.\n");
    }
}

int main(int arg, char *argv[]){
    struct no *p, *q;
    struct descritor *d;
    int sn = 1, delete_value;

    d = malloc(sizeof(struct descritor));
    d->i = NULL;
    d->f = NULL;
    d->n = 0;

    do{
        p = malloc(sizeof(struct no));
        printf("Digite o valor a ser inserido na lista: ");
        scanf("%d", &p->dado);
        p->prox = NULL;

        if(d->n == 0){
            d->i = p;
            d->f = p;
            d->n = 1;
        }else{
            q = d->f;
            q->prox = p;
            d->f = p;
            d->n++;
        }

        printf("Deseja inserir outro no a direita? 0-nao 1-sim ");
        scanf("%d", &sn);
    }while (sn == 1);

    printf("Digite o valor a ser excluido da lista: ");
    scanf("%d", &delete_value);

    delete(d, delete_value);

    return 0;
}