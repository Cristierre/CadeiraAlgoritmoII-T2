#include<stdio.h>

struct candidato{
	int numeroCandidato;
	char nome[7];
	char partido[4];
	char cargo;
	int numVotos;
	float porcentagemVotos;
};

	struct candidato lista[11];
	float numVotos;

	// Nome: Cristierre Gomes Konrath

int main(){

	lista[0].numeroCandidato = 10;
	strcpy(lista[0].nome, "Jorge");
	strcpy(lista[0].partido, "ABC");
	lista[0].cargo = 'P';
	lista[0].numVotos = 0;

	lista[1].numeroCandidato = 20;
	strcpy(lista[1].nome, "Marta");
	strcpy(lista[1].partido, "XYZ");
	lista[1].cargo = 'P';
	lista[1].numVotos = 0;

	lista[2].numeroCandidato = 30;
	strcpy(lista[2].nome, "Sergio");
	strcpy(lista[2].partido, "DEF");
	lista[2].cargo = 'P';
	lista[2].numVotos = 0;

	lista[3].numeroCandidato = 1001;
	strcpy(lista[3].nome, "Bruno");
	strcpy(lista[3].partido, "ABC");
	lista[3].cargo ='D';
	lista[3].numVotos = 0;

	lista[4].numeroCandidato = 1002;
    strcpy(lista[4].nome, "Bruna");
	strcpy(lista[4].partido, "ABC");
	lista[4].cargo ='D';
	lista[4].numVotos = 0;

	lista[5].numeroCandidato = 2001;
	strcpy(lista[5].nome, "Breno");
	strcpy(lista[5].partido, "XYZ");
	lista[5].cargo ='D';
	lista[5].numVotos = 0;

	lista[6].numeroCandidato = 2002;
	strcpy(lista[6].nome, "Bruno");
	strcpy(lista[6].partido, "XYZ");
	lista[6].cargo ='D';
	lista[6].numVotos = 0;

	lista[7].numeroCandidato = 2003;
	strcpy(lista[7].nome, "Nani");
	strcpy(lista[7].partido, "XYZ");
	lista[7].cargo ='D';
	lista[7].numVotos = 0;

	lista[8].numeroCandidato = 3001;
	strcpy(lista[8].nome, "Joao");
	strcpy(lista[8].partido, "DEF");
	lista[8].cargo ='D';
	lista[8].numVotos = 0;

	lista[9].numeroCandidato = 3002;
	strcpy(lista[9].nome, "Joana");
	strcpy(lista[9].partido, "DEF");
	lista[9].cargo ='D';
	lista[9].numVotos = 0;

	lista[10].numeroCandidato = 3003;
	strcpy(lista[10].nome, "Josmar");
	strcpy(lista[10].partido, "DEF");
	lista[10].cargo ='D';
	lista[10].numVotos = 0;

	menu();
}

int menu(){
	int opc;
	int i;

	while(opc  != 6){
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

	        default:
	        	system("cls");
	        	if(opc != 6){
                    printf("Opcao invalida!!! \n");
	        	}else{
                    printf("final das eleicoes!");
	        	}
	        	break;
		}
	}

}

int votacao(){
    int paraPresidente;
    int paraDeputado;
    int numVotosDeputadoAntes = 0;
    int numVotosPresidenteAntes = 0;
    struct candidato presidenteEscolhido;
    struct candidato deputadoEscolhido;
    int i;
    int votacaoValida;
    int confirma = 2;

    presidenteEscolhido.numeroCandidato = 0;
    deputadoEscolhido.numeroCandidato = 0;

    while(confirma == 2){

		votacaoValida = 0;

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
                numVotosPresidenteAntes = lista[i].numVotos;
            }
            if(lista[i].numeroCandidato == paraDeputado && lista[i].numeroCandidato > 1000){
                deputadoEscolhido = lista[i];
                numVotosDeputadoAntes = lista[i].numVotos;
            }
        }

        if(presidenteEscolhido.numeroCandidato != 0 && deputadoEscolhido.numeroCandidato != 0){
            printf("--- PARA PRESIDENTE --- \n \n");
            printf("Nome: %s \n\n", presidenteEscolhido.nome);
            printf("Partido: %s \n\n", presidenteEscolhido.partido);
            printf("Cargo: %c \n\n", presidenteEscolhido.cargo);

            printf("--- PARA DEPUTADO --- \n \n");
            printf("Nome: %s \n\n", deputadoEscolhido.nome);
            printf("Partido: %s \n\n", deputadoEscolhido.partido);
            printf("Cargo: %c \n\n", deputadoEscolhido.cargo);

        }else{
        	printf("                VOTACAO INVALIDA!!! \n\n");
        	votacaoValida = 1;
        }

		printf("1 - CONFIRMA    0- CANCELA :");
        scanf("%d", &confirma);
        system("cls");

        if(confirma == 1 && votacaoValida == 0){
        	for(i = 0; i < 11; i++){
            	if(lista[i].numeroCandidato == paraPresidente && lista[i].numeroCandidato < 100){
              	  lista[i].numVotos += 1;
          	  	}
            	if(lista[i].numeroCandidato == paraDeputado && lista[i].numeroCandidato > 1000){
              	  lista[i].numVotos += 1;
           	 	}
        	}
		}else{
			if(confirma == 0){
				confirma = 1;
			}else{
				confirma =2;
			}
		}
    }
    system("cls");
    return 0;
}

int listaDeCandidatos (){
    int i;
    int escolha = 3;

	while(escolha != 0 ){
        printf("              --------------------LISTA DE CANDIDATOS-------------------- \n \n");
	    printf("1- Lista de Presidenciaveis \n");
	    printf("2- Lista de Deputados \n \n");
	    printf("\n 0 - Sair \n\n ");
        printf("Digite sua opcao: ");
        scanf("%d", &escolha);
        system("cls");
	    if(escolha == 1){
	        printf("                    ------- PRESIDENCIAVEIS ------- \n\n");
	        listaCandidatosPorCargo('P');

	    }else{
	        if(escolha == 2){
	            printf("                 ------- DEPUTADOS ------- \n");
	            listaCandidatosPorCargo('D');
	        }else{
                if(escolha > 2){
                    printf("Opcao Invalida!");
                }
            }
	    }

    }
    system("cls");


    return 0;
}

int listaCandidatosPorCargo(char *cargoCand){
	int i;
	int sair = 1;

	while(sair != 0 ){
		printf("   N candidato          Nome           Partido         Cargo \n\n");
		for(i = 0; i < 11; i++){
	    	if(lista[i].cargo == cargoCand){
	            printf("\t%d\t\v\t%s\t\v\t%s\t\v\t%c\t\n", lista[i].numeroCandidato, lista[i].nome, lista[i].partido, lista[i].cargo);
		   	}
	    }
     	printf("\n 0 - Sair: ");
        scanf("%d", &sair);
        	if(sair == 0){
        	    system("cls");
        	}else{
        	   printf("Digite 0 para retornar ao menu");
        	}
    	}
}
int totalVotosCandidato(){
    int i;
    int sair = 1;

    while(sair != 0 ){
    ordenaPorVotos();

    printf("                  ------------- PRESIDENCIAVEIS------------- \n \n");
    printf("   N candidato          Nome           Partido         Cargo        Num de Votos\n\n");
        for(i = 0; i < 11; i++){
            if(lista[i].cargo == 'P'){
                printf("\t%d\t\v\t%s\t\v\t%s\t\v\t%c\t\v\t%d\t\n", lista[i].numeroCandidato, lista[i].nome, lista[i].partido, lista[i].cargo, lista[i].numVotos);
            }
        }
    printf("     \n\n                     ------------- DEPUTADOS------------- \n \n");
    printf("   N candidato          Nome           Partido         Cargo        Num de Votos\n\n");
        for(i = 0; i < 11; i++){
            if(lista[i].cargo == 'D'){
                printf("\t%d\t\v\t%s\t\v\t%s\t\v\t%c\t\v\t%d\t\n", lista[i].numeroCandidato, lista[i].nome, lista[i].partido, lista[i].cargo, lista[i].numVotos);
            }
        }
         printf("\n 0 - Sair:  ");
        scanf("%d", &sair);
        if(sair == 0){
            system("cls");
        }else{
            printf("Digite 0 para retornar ao menu");
        }
    }
    return 0;
}

int apuraPercentualPorCargo(char *cargoCand){
	int i;
	int totalVotantes = 0;

	printf("        Nome           Partido         Cargo         %%Votos\n\n");


		for(i = 0 ; i < 11 ; i ++){
			if(lista[i].cargo == cargoCand){
				totalVotantes += lista[i].numVotos;
			}
		}
		for(i = 0 ; i < 11 ; i ++){
	        if(lista[i].cargo == cargoCand){
	            lista[i].porcentagemVotos = (lista[i].numVotos * 100)/totalVotantes;
	        }
	    }
	    ordenaPorPercentualDeVotos();
	    for(i = 0 ; i < 11 ; i ++){
	        if(lista[i].cargo == cargoCand){
	           printf("\t%s\t\v\t%s\t\v\t%c\t\v\t%.2f\t\n",lista[i].nome, lista[i].partido, lista[i].cargo, lista[i].porcentagemVotos);
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
    int totalVotantes = 0;
    int sair = 1;

	while(sair != 0 ){
	    for(i = 0 ; i < 11 ; i ++){
	    	totalVotantes += lista[i].numVotos;
		}

	    if(totalVotantes > 0){
	        printf("                     ---------- PRESIDENCIAVEIS ----------\n\n");
	        apuraPercentualPorCargo('P');

	        printf("\n \n                 ---------- DEPUTADOS ----------\n\n");
	        apuraPercentualPorCargo('D');

	    }else{
	    	printf("               As eleicoes ainda nao iniciaram! \n\n");
		}

	    printf("\n 0 - Sair: ");
	    scanf("%d", &sair);
	    	if(sair == 0){
	           system("cls");
			}else{
	           printf("Digite 0 para retornar ao menu");
	      	}
    }
}

int quantidadeEleitosPorPartido(){
	int abc = 0;
	int xyz = 0;
	int def = 0;

	int i;

	int presidenteEleito = 0;
	int deputadosEleitos = 1;
    struct candidato eleitos[3];
    int sair = 1;

	while(sair != 0 ){
		ordenaPorVotos();

		for(i = 0 ; i < 11 ; i ++){
	        if(lista[i].cargo == 'P' && presidenteEleito == 0){
	            eleitos[presidenteEleito] = lista[i];
	            presidenteEleito = 1;
	        }else{
	            if(lista[i].cargo == 'D' && deputadosEleitos <= 2 ){
	                eleitos[deputadosEleitos] = lista[i];
	                deputadosEleitos ++;
	            }
	        }
		}

		if(deputadosEleitos == 3){

			for(i = 0 ; i < 3 ; i ++){
				if(strcmp(eleitos[i].partido, "ABC")==0 && eleitos[i].numVotos > 0){
					abc ++;
				}else{
					if(strcmp(eleitos[i].partido, "XYZ")==0 && eleitos[i].numVotos > 0){
						xyz++;
					}else{
						if(strcmp(eleitos[i].partido, "DEF")==0 && eleitos[i].numVotos > 0){
							def++;
						}
					}
				}
			}
		}

		printf(" Partido         Candidatos Eleitos \n\n");
		printf(" ABC                    %d \n", abc);
		printf(" XYZ                    %d \n", xyz);
		printf(" DEF                    %d \n", def);

	        printf("\n 0 - Sair: ");
	        scanf("%d", &sair);
	        if(sair == 0){
	            system("cls");
	        }else{
	            printf("Digite 0 para retornar ao menu");
	        }
    }
	return 0;
}





