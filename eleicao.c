#include<stdio.h>

struct candidato{
	int numeroCandidato;
	char nome[7];
	char partido[3];
	char cargo[1];
	int numVotos;
	float porcentagemVotos;
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
	printf("4- Apuracao Percentual de Votos \n");
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
        case 4:
            apuraPercentualVotos();
            break;

        case 5:
        	quantidadeEleitosPorPartido();
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
            if(lista[i].numeroCandidato == paraPresidente && lista[i].numeroCandidato < 100){
                presidenteEscolhido = lista[i];
            }
            if(lista[i].numeroCandidato == paraDeputado && lista[i].numeroCandidato > 1000){
                deputadoEscolhido = lista[i];
            }
        }
        if(presidenteEscolhido.numeroCandidato != 0){
            printf("--- PARA PRESIDENTE --- \n \n");
            printf("Nome: %s \n\n", presidenteEscolhido.nome);
            printf("Partido: %s \n\n", presidenteEscolhido.partido);
            printf("Cargo: %s \n\n", presidenteEscolhido.cargo);

        }else{
            printf("\n Voce deve votar em um presidente! \n \n");
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
            printf(" \n Voce deve votar em um deputado! \n\n");
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
        printf("                    ------- PRESIDENCIAVEIS ------- \n\n");
        listaCandidatosPorCargo("P");

    }else{
        if(escolha == 2){
            printf("                 ------- DEPUTADOS ------- \n");
            listaCandidatosPorCargo("D");
        }
    }
    sair();
    return 0;
}

int listaCandidatosPorCargo(char *cargoCand){
	int i;
	printf("   N candidato          Nome           Partido         Cargo \n\n");
	for(i = 0; i < 11; i++){
    	if(strcmp(lista[i].cargo,cargoCand)==0){
            printf("\t%d\t\v\t%s\t\v\t%s\t\v\t%s\t\n", lista[i].numeroCandidato, lista[i].nome, lista[i].partido, lista[i].cargo);
	   	}
    }
}
int totalVotosCandidato(){
    int i;
    ordenaPorVotos();
             printf("   N candidato          Nome           Partido         Cargo        Num de Votos\n\n");
        for(i = 0; i < 11; i++){
            printf("\t%d\t\v\t%s\t\v\t%s\t\v\t%s\t\v\t%d\t\n", lista[i].numeroCandidato, lista[i].nome, lista[i].partido, lista[i].cargo, lista[i].numVotos);

        }
        sair();

    return 0;
}

int apuraPercentualPorCargo(char *cargoCand){
	int i;
	int totalVotantes = 0;
	printf("        Nome           Partido         Cargo         %%Votos\n\n");

	for(i = 0 ; i < 11 ; i ++){
		if(strcmp(lista[i].cargo, cargoCand)==0){
			totalVotantes += lista[i].numVotos;
		}
	}
	for(i = 0 ; i < 11 ; i ++){
        if(strcmp(lista[i].cargo, cargoCand)==0){
            lista[i].porcentagemVotos = (lista[i].numVotos * 100)/totalVotantes;
        }
    }
    ordenaPorPercentualDeVotos();
    for(i = 0 ; i < 11 ; i ++){
        if(strcmp(lista[i].cargo, cargoCand)==0){
           printf("\t%s\t\v\t%s\t\v\t%s\t\v\t%.2f\t\n",lista[i].nome, lista[i].partido, lista[i].cargo, lista[i].porcentagemVotos);
        }
    }


	return 0;
}
int ordenaPorVotos (){
	int i;
    int j;
    struct candidato aux;

        for(i = 0; i < 11; i++){
            for(j = 0; j < 11; j++){
                if( lista[j].numVotos < lista[j+1].numVotos ){
                    aux = lista[j];
                    lista[j] = lista[j+1];
                    lista[j+1] = aux;
                }
            }
        }

	return 0;
}
int ordenaPorPercentualDeVotos(){
	int i;
    int j;
    struct candidato aux;

        for(i = 0; i < 11; i++){
            for(j = 0; j < 11; j++){
                if( lista[j].porcentagemVotos < lista[j+1].porcentagemVotos ){
                    aux = lista[j];
                    lista[j] = lista[j+1];
                    lista[j+1] = aux;
                }
            }
        }

	return 0;
}

int apuraPercentualVotos(){
    int i;
    float porcentagem;
    int totalVotantes = 0;

    for(i = 0 ; i < 11 ; i ++){
    	totalVotantes += lista[i].numVotos;
	}

    if(totalVotantes > 0){
        printf("                     ---------- PRESIDENCIAVEIS ----------\n\n");
        apuraPercentualPorCargo("P");

        printf("\n \n                 ---------- DEPUTADOS ----------\n\n");
        apuraPercentualPorCargo("D");

    }else{
    	printf("As eleicoes ainda nao iniciaram!");
	}

    sair();
}

int quantidadeEleitosPorPartido(){
	int abc = 0;
	int xyz = 0;
	int def = 0;
	int i;
	int presidenteEleito = 0;
	int deputadosEleitos = 0;
	int numDeputadosEleitos = 0;
    struct candidato presidente;
    struct candidato deputados[1];
    struct candidato eleitos[2];


	ordenaPorVotos();

	for(i = 0 ; i < 11 ; i ++){
        if(strcmp(lista[i].cargo,"P") == 0 && presidenteEleito == 0){
            eleitos[presidenteEleito] = lista[i];
            presidenteEleito = 1;
        }else{
            if(strcmp(lista[i].cargo,"D") == 0  && deputadosEleitos <= 1 ){
                eleitos[deputadosEleitos] = lista[i];
                deputadosEleitos ++;

            }
        }
	}
    char aux[4];
	for(i = 0 ; i < 2 ; i ++){
        memcpy(&aux,eleitos[i].partido,3);
        printf("%s \n", aux);// imprime calor do cargo juntamente com o do partido
		if(strcmp(&aux, "ABC")==0){
			abc ++;
		}else{
			if(strcmp(&aux, "XYZ")==0){
				xyz++;
			}else{
				if(strcmp(&aux, "DEF")==0){
					def++;
				}
			}
		}
	}

	printf(" Partido         Candidatos Eleitos \n\n");
	printf(" ABC                    %d \n", abc);
	printf(" XYZ                    %d \n", xyz);
	printf(" DEF                    %d \n", def);

	sair();
	return 0;
}

int sair(){
	int sair = 1;

	while(sair != 0 ){
        printf("\n 0 - Sair \n ");
        scanf("%d", &sair);
        if(sair == 0){
            system("cls");
            menu();
        }else{
            printf("Digite 0 para retornar ao menu");
        }

    }
    return 0;
}



