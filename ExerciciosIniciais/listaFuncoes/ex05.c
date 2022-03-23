#include <stdio.h>
#define TAM_VETOR 4

typedef struct {
  int number;
} Numbers;

int ler4Numeros(Numbers values[]){
  int i, value;

  for(i=0; i<TAM_VETOR; i++){
    scanf("%d", &value);
    values[i].number = value;
  }
}

void main(){
  Numbers values[TAM_VETOR];
  int i;
  
  ler4Numeros(values);

  for(i=0; i<TAM_VETOR; i++){
    printf("%d -", values[i].number);
  }
}