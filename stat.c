/*
 stat.c: EP1 - Estatística Básica
 Autor: Gabriel Yoshioka Salermo de Andrade
 Data: 09/09/2023
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//Calcular a média
float calcularMedia(float num[], int quant_n) {
    float soma = 0;
    for (int i = 0; i < quant_n; i++) {
        soma += num[i];
    }
    return soma / quant_n;
}

//Trocar dois valores
void trocar(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

//Ordenar o vetor em ordem crescente
void bubbleSort(float num[], int quant_n) {
    int i, j;
    for (i = 0; i < quant_n - 1; i++) {
        for (j = 0; j < quant_n - i - 1; j++) {
            if (num[j] > num[j + 1]) {
                trocar(&num[j], &num[j + 1]);
            }
        }
    }
}

//Calcular a mediana
float calcularMediana(float num[], int quant_n) {
    bubbleSort(num, quant_n);
    
    if (quant_n % 2 == 1) {
        return num[quant_n / 2];
    } 
    
    else {
        float mediana = (num[quant_n / 2 - 1] + num[quant_n / 2]) / 2.0;
        return mediana;
    }
}

//Calcular o desvio padrão
float calcularDesvioPadrao(float num[], int quant_n) {
    float media = calcularMedia(num, quant_n);
    float somaDosQuadrados = 0;

    for (int i = 0; i < quant_n; i++) {
        float diferenca = num[i] - media;
        somaDosQuadrados += diferenca * diferenca;
    }

    float variancia = somaDosQuadrados / (quant_n-1);
    float desvioPadrao = sqrt(variancia);
    return desvioPadrao;
}

int main() {
    int quant_n;
    float *num, media, mediana, menor, maior,dvp;
    
    do{
        printf("Quantos numeros na sua serie (N): ");
        scanf("%d", &quant_n);
        num = malloc(quant_n * sizeof(int));
        
        
        if(quant_n == 0 || quant_n == 1){
            printf("Quantidade de serie insuficiente!\n\n");
        }
        
    }while(quant_n == 0 || quant_n == 1);

    // Ler os valores da série
    printf("Entre com os números:\n");
    for (int i = 0; i < quant_n; i++) {
        scanf("%f", &num[i]);
    }
    
    // Inicializar menor e maior com o primeiro elemento do vetor
    menor = num[0];
    maior = num[0];
    
    for (int i = 1; i < quant_n; i++) {
        if (num[i] < menor) {
            menor = num[i];
        }
        if (num[i] > maior) {
            maior = num[i];
        }
    }
    
    // Calcular a média
    media = calcularMedia(num, quant_n);
    
    // Calcular a mediana
    mediana = calcularMediana(num, quant_n);
    
    // Calcular desvio-padrao
    dvp = calcularDesvioPadrao(num, quant_n);
    
    printf("\nValor mínimo: %.2f", menor);
    printf("\nValor máximo: %.2f", maior);
    printf("\nMédia: %.2f", media);
    printf("\nMediana: %.2f", mediana);
    printf("\nDesvio padrão: %f\n", dvp);

    return 0;
}