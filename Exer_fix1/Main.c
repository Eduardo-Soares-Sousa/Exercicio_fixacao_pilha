#include "pilha.h"

void duplicar_pilha(Pilha p1, Pilha p2);

int main(int argc, char** argv) {
    Pilha minhaPilha;
    Pilha minhaPilha2;
    int menu;
    Tipo_Informacao valor;

    init(&minhaPilha);
    init(&minhaPilha2);

    do{
        printf("\n1 - Empilha");
        printf("\n2 - Desempilha");
        printf("\n3 - Esvaziar");
        printf("\n4 - Duplicar");
        printf("\n0 - Sair");
        printf("\nOpcao: ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                printf("\nEmpilha\n\n\tValor: ");
                scanf("%d", &valor);
                if(push(minhaPilha, valor)){
                    printf("\nEmpilhado com sucesso\n");
                }else{
                    printf("\nEstouro de pilha\n");
                }
                break;
            case 2:
                if(pop(minhaPilha, &valor)){
                    printf("\nDesempilha\n\n\tValor: %d", valor);
                }else{
                    printf("\nPilha vazia\n");
                }
                break;
            case 3:
                while(!is_empty(minhaPilha)){
                    pop(minhaPilha, &valor);
                    printf("\nValor: %d", valor);
                }
                break;

            case 4:
                duplicar_pilha(minhaPilha, minhaPilha2);

                printf("\nValores Primeira Pilha:\n");
                while(!is_empty(minhaPilha)){
                    pop(minhaPilha, &valor);
                    printf("\nValor: %d", valor);
                }

                printf("\nValores Segunda Pilha:\n");
                while(!is_empty(minhaPilha2)){
                    pop(minhaPilha2, &valor);
                    printf("\nValor: %d", valor);
                }
                break;
        }
    }while(menu != 0);
    return 0;
}

void duplicar_pilha(Pilha p1, Pilha p2){
    int x;
    Pilha aux;
    init(&aux);

    while(!is_empty(p1)){
        pop(p1, &x);
        push(aux, x); 
    }

    while(!is_empty(aux)){
        pop(aux, &x);
        push(p1, x);
        push(p2, x); 
    }
    
}