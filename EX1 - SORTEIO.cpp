/* Construa um programa que sorteie 30 n�meros entre 0 e 500 utilizando um 
procedimento SORTEIADADOS. Posteriormente, fa�a um procedimento que 
classifique-o em ordem crescente (qualquer t�cnica) denominado CLASSIFICADADOS.
Em seguida, solicite um dado num�rico, e atrav�s de uma fun��o denominada 
BUSCA, realize a busca no vetor e retorne 0 (zero) caso o elemento n�o seja 
localizado ou o seu endere�o no vetor caso seja encontrado. */

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<time.h>

int dados[30];
void sorteiadados();
void classificados();
int busca();

int main(){
    setlocale(LC_ALL,"Portuguese");
    sorteiadados();
    classificados();
    for(int i = 0; i < 30; i++){
        printf("%i ",dados[i]);
    } 
    busca();
    system("pause");  
}

void sorteiadados(){
    srand(time(NULL));
    for(int i = 0; i < 30; i++){
        dados[i] = rand() % 501;       
    }     
}

void classificados(){
    int aux;
    for(int i = 0; i < 29; i++){
            for(int x = i + 1; x < 30; x++){
                    if(dados[i] > dados[x]){
                        aux = dados[i];
                        dados[i] = dados[x];
                        dados[x] = aux;   
                    }
            }
    }
}

int busca(){
    int num;
    bool x;
    printf("\nDigite um n�mero para saber se o mesmo est� no vetor: ");
    scanf("%i",&num);
    fflush(stdin);
    for(int i = 0; i < 30; i++){
            if(num == dados[i]){
                x = true;
            }
    }
            if(x == true){ 
                printf("O n�mero %i est� nos dados\n",num);
            }
            else{
                printf("O n�mero %i n�o est� nos dados\n",num);
                return(0);
            }
}
