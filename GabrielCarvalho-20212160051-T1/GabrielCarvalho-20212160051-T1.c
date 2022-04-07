#include <stdio.h>

validarData(char data[]){
  int strlen = sinzeof(data) / sizeof(char);
  int i;
  int dia, mes, ano;
  
  for(i=0; i < strlen; i++){
    if (strlen == 10){
      
    }
      
  }
}

void main(){
  char dataStr;
  int dataValida;
  int dia, mes, ano;

  printf("Informe a data (Formatos: dd/mm/aaaa d/m/aa d/m/aaaa)");
  fgets(dataStr, stdin, 10);

  dataValida = validarData(dataStr); 
  
}