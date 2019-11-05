#include<stdio.h>
struct candidato{
	int numeroCanditado;
	char nome[6];
	char partido[3];
	char cargo[1];
	int numVotos;	
};

	struct candidato lista[11];


	
int main(){
	lista[0].numeroCanditado = 10;
	strcpy(lista[0].nome, "Jorge");
	strcpy(lista[0].partido, "ABC");
	strcpy(lista[0].cargo, "P");
	lista[0].numVotos = 0;
	
	lista[1].numeroCanditado = 20;
	strcpy(lista[1].nome, "Marta");
	strcpy(lista[1].partido, "XYZ");
	strcpy(lista[1].cargo, "P");
	lista[1].numVotos = 0;
	
	lista[2].numeroCanditado = 30;
	strcpy(lista[2].nome, "Sergio");
	strcpy(lista[2].partido, "DEF");
	strcpy(lista[2].cargo, "P");
	lista[2].numVotos = 0;
	
	lista[3].numeroCanditado = 1001;
	strcpy(lista[3].nome, "Bruno");
	strcpy(lista[3].partido, "ABC");
	strcpy(lista[3].cargo, "D");
	lista[3].numVotos = 0;
	
	lista[4].numeroCanditado = 1002;
    strcpy(lista[4].nome, "Bruna");
	strcpy(lista[4].partido, "ABC");
	strcpy(lista[4].cargo, "D");
	lista[4].numVotos = 0;
	
	lista[5].numeroCanditado = 2001;
	strcpy(lista[5].nome, "Breno");
	strcpy(lista[5].partido, "XYZ");
	strcpy(lista[5].cargo, "D");
	lista[5].numVotos = 0;
	
	lista[6].numeroCanditado = 2002;
	strcpy(lista[6].nome, "Bruno");
	strcpy(lista[6].partido, "XYZ");
	strcpy(lista[6].cargo, "D");
	lista[6].numVotos = 0;
	
	lista[7].numeroCanditado = 2003;
	strcpy(lista[7].nome, "Nani");
	strcpy(lista[7].partido, "XYZ");
	strcpy(lista[7].cargo, "D");
	lista[7].numVotos = 0;
	
	lista[8].numeroCanditado = 3001;
	strcpy(lista[8].nome, "Joao");
	strcpy(lista[8].partido, "DEF");
	strcpy(lista[8].cargo, "D");
	lista[8].numVotos = 0;
	
	lista[9].numeroCanditado = 3002;
	strcpy(lista[9].nome, "Joana");
	strcpy(lista[9].partido, "DEF");
	strcpy(lista[9].cargo, "D");
	lista[9].numVotos = 0;
	
	lista[10].numeroCanditado = 3003;
	strcpy(lista[10].nome, "Josmar");
	strcpy(lista[10].partido, "DEF");
	strcpy(lista[10].cargo, "D");
	lista[10].numVotos = 0;
	
	menu();
}

int menu(){
	int opc; 
	
	printf("----------------- ELEICOES ----------------- \n\n");
	printf("1- Votar \n");
	printf("2- Lista de Candidatos Por Cargo \n");
	printf("3- Total de Votos Por Candidato \n");
	printf("4- Apuracao Percentual de Votos");
	printf("5- Quantidade Eleitos Por Partido Politico \n");
	printf("6- Sair \n \n");
	
	printf("Digite a opcao desejada: ");
	scanf("%d",&opc);
	system("cls");
}



