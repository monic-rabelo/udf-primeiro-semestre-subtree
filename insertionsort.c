#include <stdio.h>
#include <string.h>

// função insertion sort com o parametro array
void insertion_sort(char *arr) {
    // variaveis i para percorrer o array nao ordenado, j para percorrer a versao ordenada (a esquerda de i)
    // aux para armazenar temporariamente o valor de i para a parte ordenada
    int i, j, aux;  

    // for com o i começando no segundo numero do array, porque o primeiro numero já é ordenado
    for(i = 1; i < 8; i++) { 
        aux = arr[i]; // a cada looping, o aux armazena o valor atual contido em i
        j = i - 1; // j começa valendo o primeiro numero do array, que é o indice 0, anterior ao i

        //while para testar se o valor atual de j é maior/igual a 0 e se o numero armazenado em aux é menor que o armazenado em j
        // aux = segundo indice (1), j = primeiro indice (0)
        while((j >= 0) && (aux < arr[j])) {
            // desloca o elemento maior uma posicao para a direita
            arr[j + 1] = arr[j];
            // j é decrementado, para continuar comparando a esquerda
            j--;
        }

        // posicao que estava em aux é armazenado na posicao 0 
        arr[j + 1] = aux;
    }
}


int main () {
    
    char rgm[9]; // 8 digitos + caractere nulo
    
    printf("Digite seu RGM (8 digitos): ");
    //8s para ler a entrada de somente os primeiros 8 digitos
    scanf("%8s", rgm);
    
    // verificando tamanho da string para caso seja diferente de 8
    if(strlen(rgm) != 8) {
        printf("O RGM deve conter apenas 8 digitos.\n");
        return 1;
    }
    
    // aplicando função insertion sort
    insertion_sort(rgm);
    
    printf("RGM ordenado em ordem crescente: %s", rgm);
    
    return 0;

}
