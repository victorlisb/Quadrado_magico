#include<stdio.h>

void imprimirMatriz(int n,int matriz[n][n]);

int main(){

	int n;
 
	int soma_linhas = 0,soma_colunas = 0;
	int soma_diagonal_principal = 0,soma_diagonal_secundaria = 0;

	printf("Digite a ordem do quadrado:");
	scanf("%d",&n);
	printf("Digite os elementos da matriz:");
    
	int matriz[n][n];

	for(int i = 0; i < n; i++){
         for(int j = 0; j < n; j++){

			getchar();
			scanf("%d",&matriz[i][j]);
	    }
	}

	//Calculando a soma das linhas e armazenando em um vetor
	int vetor_soma_linhas[n];

	for(int i = 0; i < n; i++){

		soma_linhas = 0;

		for(int j = 0; j < n; j++){
			
			soma_linhas = soma_linhas + matriz[i][j];
			
	    } 
		vetor_soma_linhas[i] = soma_linhas;
	}

	int vetor_soma_colunas[n];

    //Calculando a soma das colunas e armazenando em um vetor
	for (int j = 0; j < n; j++){

		soma_colunas = 0;

		for(int i = 0; i < n; i++){

			soma_colunas = soma_colunas + matriz[i][j];
		}

		vetor_soma_colunas[j] = soma_colunas;

	}

    //Calculando a soma da diagonal principal
	for(int i = 0; i < n; i++ ){

		for(int j = 0; j < n;j++){

			if(i == j){

				soma_diagonal_principal +=matriz[i][j]; 
			}
		}
	}

	//Calculando a soma da diagonal secundaria
	for(int i = 0; i < n; i++){

		soma_diagonal_secundaria+=matriz[i][n-i-1];
	}

	int soma = 0;

    //Fazendo a comparação dos resultados obtidos
	for (int i = 0; i < n; i++){

		if((vetor_soma_linhas[i] == vetor_soma_colunas[i])&&(vetor_soma_linhas[i] == soma_diagonal_principal)&&(vetor_soma_linhas[i]==soma_diagonal_secundaria)){

			soma = soma +1;
			
		}
	}

	if(soma == n){

		printf("\nMatriz:\n");
		imprimirMatriz(n,matriz);
		printf("\n"); 
        printf("A matriz é um quadrado e a soma mágica é: %d",soma_diagonal_principal);
	}
	else{
		printf("O quadrado não é magico.\n");
		printf("Resultado da soma = -1");
		return -1;
	}

	return 0;
}

void imprimirMatriz(int n,int matriz[n][n]){

	for (int i = 0; i < n; i++){

		for(int j = 0; j < n; j++){

			printf("%d ",matriz[i][j]);
		}
		printf("\n");
	}
}

