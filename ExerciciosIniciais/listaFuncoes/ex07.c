#include <stdio.h>
#define TAM_VETOR 3

int ler3Palavras(char values[]){
  int i;
  char value[10];

  for(i=0; i<TAM_VETOR; i++){
    fgets(10, stdin,value);
    getchar();
    
    values[i] = value;
  }

}

void main(){
  char values[TAM_VETOR];
  int i;
  
  ler3Palavras(values);

  for(i=0; i<TAM_VETOR; i++){
    printf("%c - ", values[i]);
  }
}