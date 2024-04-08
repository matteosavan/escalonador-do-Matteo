#include <stdio.h>
#define MAX 100

void linhas_e_colunas(int *linhas, int *colunas) {
  printf("quantas linhas?\n");
  scanf("%d", linhas);
  printf("quantas colunas?\n");
  scanf("%d", colunas);
}

void iniciar(int linhas, int colunas, int vetor_numerador[MAX][MAX],
             int vetor_denominador[MAX][MAX]) {
  char opcao;
  printf("primeiro, os numeradores ou numeros inteiros:\n");

  for (int i = 0; i < linhas; i++) {
    printf("linha[%d]: ", i + 1);
    for (int j = 0; j < colunas; j++) {
      scanf("%d", &vetor_numerador[i][j]);
    }
  }
  printf("tem denominadores diferentes de 1? S ou N: ");
  scanf(" %c", &opcao);
  if (opcao == 'S' || opcao == 's') {
    printf("agora, os denominadores:\n");
    for (int i = 0; i < linhas; i++) {
      printf("linha[%d]: ", i + 1);
      for (int j = 0; j < colunas; j++) {
        scanf("%d", &vetor_denominador[i][j]);
      }
    }
  }
  else {
    for (int i = 0; i < linhas; i++) {
      for (int j = 0; j < colunas; j++) {
        vetor_denominador[i][j] = 1;
      }
    }
  }
}


void transforma_elementos_fracao_em_inteiro_caso_preciso(int linhas, int colunas, int vetor_numerador[MAX][MAX], int vetor_denominador[MAX][MAX]){
  
  for(int i=0;i<linhas;i++){
    for(int j=0;j<colunas;j++){
      if (vetor_denominador[i][j]==0)continue;
      if (vetor_numerador[i][j]%vetor_denominador[i][j]==0){
        vetor_numerador[i][j] = vetor_numerador[i][j]/vetor_denominador[i][j];
        vetor_denominador[i][j] = 1;
      }
    }
  }
}
void consertar_sinal(int linhas, int colunas, int vetor_numerador[MAX][MAX], int vetor_denominador[MAX][MAX]){
  for(int i=0;i<linhas;i++){
    for(int j=0;j<colunas;j++){
      if (vetor_numerador[i][j]<0 && vetor_denominador[i][j]<0){
        vetor_denominador[i][j]=-vetor_denominador[i][j];
        vetor_numerador[i][j]=-vetor_numerador[i][j];
      }
      else if(vetor_numerador[i][j]>0 && vetor_denominador[i][j]<0){
        vetor_denominador[i][j]=-vetor_denominador[i][j];
        vetor_numerador[i][j]=-vetor_numerador[i][j];
      }
    }
  }
}
void printar_vetor(int linhas, int colunas, int vetor_numerador[MAX][MAX],
                   int vetor_denominador[MAX][MAX]) {
  transforma_elementos_fracao_em_inteiro_caso_preciso(linhas, colunas, vetor_numerador, vetor_denominador);
  consertar_sinal(linhas, colunas, vetor_numerador, vetor_denominador);
    
  printf("\na matriz: \n");
  for (int i = 0; i < linhas; i++) {
    printf("linha[%d]: ", i + 1);
    for (int j = 0; j < colunas; j++) {
      printf("%d", vetor_numerador[i][j]);
      if (vetor_denominador[i][j] != 1) {
        printf("/%d ", vetor_denominador[i][j]);
      } else {
        printf("   ");
      }
    }
    printf("\n");
  }
}
void multiplicar_linha(int linhas, int colunas, int vetor_numerador[MAX][MAX], int vetor_denominador[MAX][MAX]){
  int num_linha, num_multiplicar;
  printf("qual a linha? ");
  scanf("%d", &num_linha);
  num_linha--;
  printf("por quanto quer multiplicar? ");
  scanf("%d", &num_multiplicar);
  for(int i=0;i<colunas;i++){
    vetor_numerador[num_linha][i]=vetor_numerador[num_linha][i]* num_multiplicar;
    }
  }

void dividir_linha(int linhas, int colunas, int vetor_numerador[MAX][MAX], int vetor_denominador[MAX][MAX]){
  int num_linha, num_dividir;
  printf("qual a linha? ");
  scanf("%d", &num_linha);
  num_linha--;
  printf("por quanto quer dividir? ");
  scanf("%d", &num_dividir);
  for(int i=0;i<colunas;i++){
    vetor_denominador[num_linha][i]=vetor_denominador[num_linha][i]* num_dividir;
    }
  }


void trocar_linhas(int linhas, int colunas, int vetor_numerador[MAX][MAX], int vetor_denominador[MAX][MAX]){
  int aux, linha_1, linha_2;

  printf("deseja trocar a linha: ");
  scanf ("%d", &linha_1);
  linha_1--;
  printf("com a linha: ");
  scanf ("%d", &linha_2);
  linha_2--;

  for(int i=0;i<colunas;i++){
    aux = vetor_numerador[linha_1][i];
    vetor_numerador[linha_1][i] = vetor_numerador[linha_2][i];
    vetor_numerador[linha_2][i] = aux;

    aux = vetor_denominador[linha_1][i];
    vetor_denominador[linha_1][i] = vetor_denominador[linha_2][i];
    vetor_denominador[linha_2][i] = aux;
  }  
}

void somar_linhas(int linhas, int colunas, int vetor_numerador[MAX][MAX], int vetor_denominador[MAX][MAX]){
  int linha_1, linha_2, aux_numerador[MAX], aux_denominador[MAX];
  printf("primeiramente, qual a linha que vai receber a soma? ");
  scanf ("%d", &linha_1);
  linha_1--; 
  printf("ela vai somar com quem? ");
  scanf ("%d", &linha_2);
  linha_2--;

  for(int i=0;i<colunas;i++){
      aux_numerador[i] = vetor_numerador[linha_2][i];
      aux_denominador[i] = vetor_denominador[linha_2][i];      
    }
  

  for(int i=0;i<colunas;i++){
    if (vetor_denominador[linha_1][i]!=aux_denominador[i]){
      vetor_numerador[linha_1][i] *= aux_denominador[i];
      aux_numerador[i] *= vetor_denominador[linha_1][i];
      
      vetor_denominador[linha_1][i] *= aux_denominador[i];
    }
    vetor_numerador[linha_1][i] += aux_numerador[i];
    
  }
  
}

void subtrair_linhas(int linhas, int colunas, int vetor_numerador[MAX][MAX], int vetor_denominador[MAX][MAX]){
  int linha_1, linha_2, aux_numerador[MAX], aux_denominador[MAX];
  printf("primeiramente, qual a linha que vai receber a subtração? ");
  scanf ("%d", &linha_1);
  linha_1--; 
  printf("ela vai subtrair com quem? ");
  scanf ("%d", &linha_2);
  linha_2--;

  for(int i=0;i<colunas;i++){
      aux_numerador[i] = vetor_numerador[linha_2][i];
      aux_denominador[i] = vetor_denominador[linha_2][i];      
    }
  

  for(int i=0;i<colunas;i++){
    if (vetor_denominador[linha_1][i]!=aux_denominador[i]){
      vetor_numerador[linha_1][i] *= aux_denominador[i];
      aux_numerador[i] *= vetor_denominador[linha_1][i];
      
      vetor_denominador[linha_1][i] *= aux_denominador[i];
    }
    vetor_numerador[linha_1][i] -= aux_numerador[i];
    
  }
  
}

void simplificar_fracoes (int linhas, int colunas, int vetor_numerador[MAX][MAX],int vetor_denominador[MAX][MAX]){
  int primos[25]= {2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
  31, 37, 41, 43, 47,53, 59, 61, 67, 71,
  73, 79, 83, 89, 97};

  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j < colunas; j++) {
      if (vetor_denominador[i][j]!= 1){
        for(int k=24; k>=0 ;k--){
          if ((vetor_denominador[i][j]%primos[k]==0) && (vetor_numerador[i][j]%primos[k]==0)){
            vetor_numerador[i][j]=vetor_numerador[i][j]/primos[k];
            vetor_denominador[i][j] = vetor_denominador[i][j]/primos[k];
          }
        }
      }
    }
  }
     
}

int main(void) {
  int vetor_numerador[MAX][MAX], vetor_denominador[MAX][MAX], linhas, colunas,
      *ponteiro_linhas, *ponteiro_colunas;
  ponteiro_linhas = &linhas;
  ponteiro_colunas = &colunas;
  char op;

  linhas_e_colunas(ponteiro_linhas, ponteiro_colunas);

  iniciar(linhas, colunas, vetor_numerador, vetor_denominador);
  printar_vetor(linhas, colunas, vetor_numerador, vetor_denominador);

  do {
    scanf("%c", &op);
    if (op == '\n')continue;
    switch(op){
      case 'p':
        printar_vetor(linhas, colunas, vetor_numerador, vetor_denominador);
      break;

      case 's':
        simplificar_fracoes(linhas, colunas, vetor_numerador, vetor_denominador);
      break;
    

    case '*':
      multiplicar_linha(linhas, colunas, vetor_numerador, vetor_denominador);
    break;
      
    case '/':
      dividir_linha(linhas, colunas, vetor_numerador, vetor_denominador);
  break;

    case 't':
      trocar_linhas(linhas, colunas, vetor_numerador, vetor_denominador);
    break;
    
    case '+':
      somar_linhas(linhas, colunas, vetor_numerador, vetor_denominador);
  break;
    case '-':
      subtrair_linhas(linhas, colunas, vetor_numerador, vetor_denominador);  
  break;
      }
    if (op != 'p')printar_vetor(linhas, colunas, vetor_numerador, vetor_denominador);
  } while (op!='.');


  return 0;
}
