#include<stdio.h>

struct candidato{
	int numeroCandidato;
	char nome[7];
	char partido[3];
	char cargo[1];
	int numVotos;
};


	struct candidato lista[11];
	float numVotos;



int main(){

	lista[0].numeroCandidato = 10;
	strcpy(lista[0].nome, "Jorge");
	strcpy(lista[0].partido, "ABC");
	strcpy(lista[0].cargo, "P");
	lista[0].numVotos = 0;

	lista[1].numeroCandidato = 20;
	strcpy(lista[1].nome, "Marta");
	strcpy(lista[1].partido, "XYZ");
	strcpy(lista[1].cargo, "P");
	lista[1].numVotos = 0;

	lista[2].numeroCandidato = 30;
	strcpy(lista[2].nome, "Sergio");
	strcpy(lista[2].partido, "DEF");
	strcpy(lista[2].cargo, "P");
	lista[2].numVotos = 0;

	lista[3].numeroCandidato = 1001;
	strcpy(lista[3].nome, "Bruno");
	strcpy(lista[3].partido, "ABC");
	strcpy(lista[3].cargo, "D");
	lista[3].numVotos = 0;

	lista[4].numeroCandidato = 1002;
    strcpy(lista[4].nome, "Bruna");
	strcpy(lista[4].partido, "ABC");
	strcpy(lista[4].cargo, "D");
	lista[4].numVotos = 0;

	lista[5].numeroCandidato = 2001;
	strcpy(lista[5].nome, "Breno");
	strcpy(lista[5].partido, "XYZ");
	strcpy(lista[5].cargo, "D");
	lista[5].numVotos = 0;

	lista[6].numeroCandidato = 2002;
	strcpy(lista[6].nome, "Bruno");
	strcpy(lista[6].partido, "XYZ");
	strcpy(lista[6].cargo, "D");
	lista[6].numVotos = 0;

	lista[7].numeroCandidato = 2003;
	strcpy(lista[7].nome, "Nani");
	strcpy(lista[7].partido, "XYZ");
	strcpy(lista[7].cargo, "D");
	lista[7].numVotos = 0;

	lista[8].numeroCandidato = 3001;
	strcpy(lista[8].nome, "Joao");
	strcpy(lista[8].partido, "DEF");
	strcpy(lista[8].cargo, "D");
	lista[8].numVotos = 0;

	lista[9].numeroCandidato = 3002;
	strcpy(lista[9].nome, "Joana");
	strcpy(lista[9].partido, "DEF");
	strcpy(lista[9].cargo, "D");
	lista[9].numVotos = 0;

	lista[10].numeroCandidato = 3003;
	strcpy(lista[10].nome, "Josmar");
	strcpy(lista[10].partido, "DEF");
	strcpy(lista[10].cargo, "D");
	lista[10].numVotos = 0;

	menu();

}

int menu(){
	int opc;
	int i;

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

	switch(opc){
        case 1:
            votacao();
            break;
        case 2:
            listaDeCandidatos();
            break;
        case 3:
            totalVotosCandidato();
            break;
	}

}

int votacao(){
    int paraPresidente;
    int paraDeputado;
    struct candidato presidenteEscolhido;
    struct candidato deputadoEscolhido;
    int i;
    int confirma = 0;

    presidenteEscolhido.numeroCandidato = 0;
    deputadoEscolhido.numeroCandidato = 0;

    while(confirma == 0){

        printf("-------- VOTO PARA PRESIDENTE -------\n \n");
        printf("Digite o numero do candidato para presidencia: ");
        scanf("%d", &paraPresidente);
        printf("\n\n-------- VOTO PARA DEPUTADO  ------- \n \n");
        printf("Digite o numero do candidato para deputado: ");
        scanf("%d", &paraDeputado);
        system("cls");

        for(i = 0; i < 11; i++){
            if(lista[i].numeroCandidato == paraPresidente){
                presidenteEscolhido = lista[i];
            }
            if(lista[i].numeroCandidato == paraDeputado){
                deputadoEscolhido = lista[i];
            }
        }
        if(presidenteEscolhido.numeroCandidato != 0){
            printf("--- PARA PRESIDENTE --- \n \n");
            printf("Nome: %s \n\n", presidenteEscolhido.nome);
            printf("Partido: %s \n\n", presidenteEscolhido.partido);

        }else{
            printf("Voce deve votar em um presidente! \n \n");
        }
        if(deputadoEscolhido.numeroCandidato != 0){
            printf("--- PARA DEPUTADO --- \n \n");
            printf("Nome: %s \n\n", deputadoEscolhido.nome);
            printf("Partido: %s \n\n", deputadoEscolhido.partido);

            printf("1 - CONFIRMA    0- CANCELA :");
            scanf("%d", &confirma);

            if(confirma == 1){
                    printf("\a");
                for(i = 0; i < 11; i++){
                    if(lista[i].numeroCandidato == paraDeputado){

                        lista[i].numVotos += 1;

                    }
                    if(lista[i].numeroCandidato == paraPresidente){
                        lista[i].numVotos += 1;
                    }
                }
            }
        }else{
            printf(" Voce deve votar em um deputado!");
        }
    }
    system("cls");
    menu();
    return 0;
}

int listaDeCandidatos (){
    int i;
    int escolha = 0;
    printf("1- Lista de Presidenciaveis \n");
    printf("2- Lista de Deputados \n \n");
    printf("0 - Sair \n");
    printf("Digite a opcao desejada:");
    scanf("%d",&escolha);
    system("cls");
    if(escolha == 1){
        printf("------- PRESIDENCIAVEIS ------- \n\n");
        printf("   N candidato          Nome           Partido         Cargo \n\n");

        for(i = 0; i < 11; i++){
           if(strcmp(lista[i].cargo,"P")==0){
               printf("\v\t%d\t\v\t%s\t\v\t%s\t\v\t%s\t\v\n", lista[i].numeroCandidato, lista[i].nome, lista[i].partido, lista[i].cargo);
           }
        }
         printf("0 - Sair");
        scanf("%d",&escolha);
    }else{
        if(escolha == 2){
            printf("------- DEPUTADOS ------- \n");
            printf("   N candidato          Nome           Partido         Cargo \n\n");

            for(i = 0; i < 11; i++){
                if(strcmp(lista[i].cargo, "D") == 0){
                   printf("\v\t%d\t\v\t%s\t\v\t%s\t\v\t%s\t\v\n", lista[i].numeroCandidato, lista[i].nome, lista[i].partido, lista[i].cargo);
                }
            }
        }else{
            menu();
        }
    }
    return 0;
}
int totalVotosCandidato(){
    int i;
    int j;
    struct candidato aux;
    int escolha;


        for(i = 0; i < 11; i++){
            for(j = 0; j < 11; j++){
                if( lista[j].numVotos < lista[j+1].numVotos ){
                    aux = lista[j];
                    lista[j] = lista[j+1];
                    lista[j+1] = aux;
                }
            }
        }
             printf("   N candidato          Nome           Partido         Cargo         Numero de Votos\n\n");
        for(i = 0; i < 11; i++){
            printf("\v\t%d\t\v\t%s\t\v\t%s\t\v\t%s\t\v\t%d\t\v\n", lista[i].numeroCandidato, lista[i].nome, lista[i].partido, lista[i].cargo, lista[i].numVotos);

        }
        printf("0 - Sair");
        scanf("%d",&escolha);
        if(escolha != 0){
            system("cls");
            printf("digite 0 para sair! \n");
        }

    menu();
    return 0;
}



