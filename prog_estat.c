#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int num;
    int i, j;
    float *vetor;
    float soma=0, var=0;
    float min, max;
    float med, media, dp;
    float temp;
    
    printf("Numeros na serie:");     
    scanf("%d", &num);
    
    vetor = malloc(num * sizeof(float));
    if(!vetor){ //alocação não foi bem sucedida => pd == NULL
       printf("Erro de alocação dinamica de memória!\n");
       exit(-1);
    }

    printf("Entre com os numeros:\n");     
    for(int i=0; i<num; i++) {
       printf(">");     
       scanf("%f", &vetor[i]);
       soma+=vetor[i];
    }    
    media = soma/num;

    for(int j=0; j<num; j++){
      for(int i=0; i<num; i++) {
        temp=vetor[i];
        if(temp > vetor[i+1] & (i+1) < num){
           vetor[i] = vetor[i+1];
           vetor[i+1] = temp; 
        }
      }  
    }
    if((num%2)==0){
      med = (vetor[(num/2)-1] + vetor[num/2]) / 2;
    }else {
      med = vetor[num/2];
    }

    soma = 0;
    min=vetor[0];
    max=0;
    for(int i=0; i<num; i++) {
       if(vetor[i]<min){
         min=vetor[i];  
       }
       if(vetor[i]>max){
         max=vetor[i];  
       }
       soma += (vetor[i]-media) * (vetor[i]-media);
    }
    dp = sqrt(soma/num);

    printf("Valor Minimo: %.2f\n", min); 
    printf("Valor Maximo: %.2f\n", max); 
    printf("Media: %.3f\n", media); 
    printf("Med: %.3f\n", med); 
    printf("Desvio Padrao: %.6f\n", dp);      

}
