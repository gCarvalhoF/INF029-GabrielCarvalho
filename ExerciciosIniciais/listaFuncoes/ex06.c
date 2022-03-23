#include <stdio.h>
#define TAM_VETOR 3

int ler3Letras(char values[]){
  int i;
  char value;

  for(i=0; i<TAM_VETOR; i++){
    scanf("%c", &value);
    getchar();
    
    values[i] = value;
  }

}

void main(){
  char values[TAM_VETOR];
  int i;
  
  ler3Letras(values);

  for(i=0; i<TAM_VETOR; i++){
    printf("%c - ", values[i]);
  }
}