#include <stdio.h>
#define TAM_VETOR 3

int ler3Numeros(int values[]){
  int i, value;

  for(i=0; i<TAM_VETOR; i++){
    scanf("%d", &value);
    values[i] = value;
  }

}

void main(){
  int values[TAM_VETOR];
  int i;
  
  ler3Numeros(values);

  for(i=0; i<TAM_VETOR; i++){
    printf("%d -", values[i]);
  }
}