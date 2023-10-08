#include "pilha.h"

void duplicar_pilha(Pilha p1, Pilha p2);
int max_stack(Pilha p1, Pilha p2);

int main(int argc, char** argv) {
    Pilha minhaPilha;
    Pilha minhaPilha2;
    int menu;
    int menu2;
    Tipo_Informacao valor;
    Tipo_Informacao valor2;

    init(&minhaPilha);
    init(&minhaPilha2);

    do{
        printf("\n1 - Empilha");
        printf("\n2 - Desempilha");
        printf("\n3 - Esvaziar");
        printf("\n4 - Duplicar");
        printf("\n5 - Inserir valores na segunda pilha");
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

            case 5:
                do{
                    printf("\n1 - Empilha");
                    printf("\n2 - Desempilha");
                    printf("\n3 - Esvaziar");
                    printf("\n4 - Verificar tamanho das pilhas");
                    printf("\n0 - Voltar");
                    printf("\nOpcao: ");
                    scanf("%d", &menu2);

                    switch(menu2){
                        case 1:
                            printf("\nEmpilha\n\n\tValor: ");
                            scanf("%d", &valor2);
                            if(push(minhaPilha2, valor2)){
                                printf("\nEmpilhado com sucesso\n");
                            }else{
                                printf("\nEstouro de pilha\n");
                            }
                            break;

                        case 2:
                            if(pop(minhaPilha2, &valor2)){
                                printf("\nDesempilha\n\n\tValor: %d", valor2);
                            }else{
                                printf("\nPilha vazia\n");
                            }
                            break;

                        case 3:
                            while(!is_empty(minhaPilha2)){
                                pop(minhaPilha2, &valor2);
                                printf("\nValor: %d", valor2);
                            }
                            break;

                        case 4:
                            printf("\nValores Primeira Pilha:\n");
                            while(!is_empty(minhaPilha)){
                                pop(minhaPilha, &valor);
                                printf("\nValor: %d", valor);
                            }

                            printf("\n\nValores Segunda Pilha:\n");
                            while(!is_empty(minhaPilha2)){
                                pop(minhaPilha2, &valor2);
                                printf("\nValor: %d", valor2);
                            }

                            if(max_stack(minhaPilha, minhaPilha2) == 0){
                                printf("\n\nAs pilhas são iguais\n");
                            }else if(max_stack(minhaPilha, minhaPilha2) == 1){
                                printf("\n\nA primeira fila é maior que a segunda\n");
                            }else if(max_stack(minhaPilha, minhaPilha2) == -1){
                                printf("\n\nA primeira fila é menor que a segunda\n");
                            }
                            
                            break;
                    }        
                }while(menu2 != 0);

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

int max_stack(Pilha p1, Pilha p2){
    int x;
    int y;
    int count1 = 0;
    int count2 = 0;

    Pilha aux1;
    init(&aux1);
    while(!is_empty(p1)){
        pop(p1, &x);
        push(aux1, x); 

    }

    while(!is_empty(aux1)){
        pop(aux1, &x);
        push(p1, x); 
        count1++;
    }

    Pilha aux2;
    init(&aux2);
    while(!is_empty(p2)){
        pop(p2, &y);
        push(aux2, y); 

    }

    while(!is_empty(aux2)){
        pop(aux2, &y);
        push(p2, y); 
        count2++;
    }

    if(count1 == count2){
        return 0;
    }else if(count1 > count2){
        return 1;
    }else if(count1 < count2){
        return -1;
    }
}