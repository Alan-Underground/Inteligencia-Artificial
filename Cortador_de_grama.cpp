#define simbolo 248
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <conio.h>
#include <time.h>
int encontra_posicao(int,int);
void imprime_matriz(int mat_mostra[8][8]);
int verifica_de_novo(int mat_mostra[8][8],int mat_marca[8][8]);
void faz_jogada(int escolhaIJ, int mat_campo[8][8], int mat_mapa[8][8], int mat_mostra[8][8]);

 main(){
FILE *arquivo;
	char c;
	int cont, contagem=0, vet[64], mat_mapa[8][8],bomba=0,mat_foi_jogado[8][8],mat_marca[8][8];
	int i=0,j=0,escolhidoI,escolhidoJ,escolhaIJ, mat_campo[8][8],mat_mostra[8][8],contador=0;
	int opcao;
	int mapa_ja_escolhido=0;
	int d = 0;
	int num_do_mapa =0;
	int numeroMapa;
	char Mapaa[8] = "Mapa_";
	int escolha_de_mapa_errado = 0;

		for(i=0; i<8; i++){
			for(j=0; j<8; j++){
				mat_campo[i][j] = contador++;	 // mat_campo tavalendo 0 1 2 3 4 ...
			}
		}
		for(i=0; i<8; i++){
			for(j=0; j<8; j++){
				mat_mostra[i][j] = -2;			// mat_mostra ta valendo -2 -2 -2 -2
				mat_marca[i][j] = -2;		// mat_marca recebe valor -2 -2 -2 -2 -2
			}
		}
















		do{
   			system("cls");
   		//	system("color F1");
		 printf ("------------------ Cortador de grama ------------------\n");
		 printf ("|  Selecione uma opcao:                        |\n");
		 printf ("|  1 - Escolha o Mapa                          |\n");
		 printf ("|  2 - Veja o computador Cortar a grama        |\n");
		 printf ("|  3 - Corte a grama                           |\n");
		 printf ("|  4 - Sair                                    |\n");
		 printf ("------------------------------------------------\n");
		  scanf ("%d",&opcao);
		    switch (opcao){


			case 4://Sair do programa
				printf("\n\nObrigado por usar este Software\n\n");
	  			exit(0);
			break;













			case 1: //escolha do mapa
			do{

			printf("Ha varios mapas para voce escolher:\n");
			printf("Mapa_1   Mapa_2   Mapa_3   Mapa_4  Mapa_5\n");
			printf("Escolha o numero do mapa que voce quer\n");
			printf("Mapa_");
			scanf ("%d",&numeroMapa);
			printf("%d",numeroMapa);
									//gets(numeroMapa); // ERA PRA PEDIR PRO USUARIO DIGITAR O NUMERO DO MAPA MAS APARECE O TEXTO A CIMA E NAO PEDE NADA!@!@!@!@  BOSTA !@!!!!
					if (numeroMapa > 5 || numeroMapa <1 ){
				printf("Por favor Digite um Numero de Mapa Valido!");
				printf("\n por acaso %d parece valido heim",numeroMapa);
				escolha_de_mapa_errado = 1;
				//break;
			}
			if (numeroMapa == 1){		//OBS: Dessa forma observei pelos testes, que so posso escolher o numero do mapa 1 vez =(
				strcat(Mapaa,"1.txt");
				escolha_de_mapa_errado = 0;
			}
			if (numeroMapa == 2){
				strcat(Mapaa,"2.txt");
				escolha_de_mapa_errado = 0;
			}
			if (numeroMapa == 3){
				strcat(Mapaa,"3.txt");
				escolha_de_mapa_errado = 0;
			}
			if (numeroMapa == 4){
				strcat(Mapaa,"4.txt");
				escolha_de_mapa_errado = 0;
			}
			if (numeroMapa == 5){
				strcat(Mapaa,"5.txt");
				escolha_de_mapa_errado = 0;
			}




								// Mapaa devia ter a string "MAPA_"  e numeroMapa devia ter o numero q a pessoa digita
								// logo ficaria como exemplo   Mapa_2


								//	puts (numeroMapa);
	 printf("\n");
	puts(Mapaa);
	printf("Escolhido com sucesso.");
								//arq= fopen (nome,"w");
	arquivo = fopen (Mapaa,"r");
	c = getc (arquivo);
	mat_mapa[0][0] = c; //recebe primeiro valor
	cont =0; // depois tenho q mudar, para, se for o carater 1 salva o 1 na posição [0] [0]
	while (c != EOF){
	//	printf("%c",c);
			if(c == '0'){
				vet[cont]=0;
				cont = cont +1;
			}
			if(c == '1'){
				vet[cont]=1;
				cont = cont +1;
			}

			if (c == '-'){ // -1 é formigueiro
				vet[cont]= -1;
				cont = cont +1;
				c= getc(arquivo); // encontrei o valor ( - ) entao eu salvo -1 no vetor e ja pulo uma casa que é o 1(vem depois do menos) para nao verificar no c == 1,
//				printf("%c",c);	 // imprimo o 1 que é o proximo caracter depois do menos
			}
		c = getc(arquivo);
	}
		fclose (arquivo); // Ate aqui ja li os caracteres do arquivo e ja salvei todos como int no Vetor

		for(i=0; i<8; i++){		// esse for ta salvando os valores do vetor na matriz
			for(j=0; j<8; j++){
				mat_mapa[i][j]= vet[contagem];  // mat_mapa ta  0 1 3 -1 2 1 -1 1
				contagem++;
			}
		}
		for(i=0;i<8;i++){
			for(j=0;j<8;j++){ //esse for imprime a matriz mostra pela primeira vez( toda preenchida com valor -2)
				//printf("[%i] ",mat_mostra[i][j]);
			}
			printf("\n");
		}
		printf("Mapa escolhido com sucesso!");
		system("PAUSE");
		mapa_ja_escolhido=1;
	}while(mapa_ja_escolhido==0);
    	break;





	case 2:
		if (mapa_ja_escolhido!= 1){
			printf("Voce nao escolheu um mapa\nEscolha uma mapa agora\n\n");
			system("Pause");
			break;
		}
	  printf("\n");
		imprime_matriz(mat_mostra); //chamando a funcao imprime matriz
			printf("Escolha uma das linhas  1 2 3 4 5 6 7 8: ");
			scanf("%i",&escolhidoI);
			printf("Escolha uma das Colunas 1 2 3 4 5 6 7 8: ");
			scanf("%i",&escolhidoJ);
			escolhaIJ = encontra_posicao(escolhidoI,escolhidoJ);
			faz_jogada(escolhaIJ,mat_campo,mat_mapa,mat_mostra);

	while (escolhaIJ!= -1){ // i valendo 0 e j valendo 0
		escolhaIJ = verifica_de_novo(mat_mostra,mat_marca);
		faz_jogada(escolhaIJ,mat_campo,mat_mapa,mat_mostra);//-----------------------------------------------------CHAMA A FUNÇÃO faz_jogada
//-------------//-------------//-------------//-------------//-------------//-------------//-------------//-------------//-------------// FAZ JOGADA
	}

	} //fecha do swith
 } while (d < 200); // chave do DO principal
} //fecha chaves do main

//	verifica_de_novo(int mat_mostra[8][8]);
	void faz_jogada(int escolhaIJ, int mat_campo[8][8], int mat_mapa[8][8], int mat_mostra[8][8]){

		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
//------------------------------------------------------------------------------------------------------------------INICIO do que fazer se encontrar o -1
				if(escolhaIJ == mat_campo[i][j]&& mat_mapa[i][j] == -1 ){ // se for aberta a posição x e tive -1, ou melhor uma bomba
					mat_mostra[i][j]= -1;
					imprime_matriz(mat_mostra);
				}
//------------------------------------------------------------------------------------------------------------------Fim do que fazer se encontrar o -1
//------------------------------------------------------------------------------------------------------------------INICIO do que fazer se encontrar o 0
				if(escolhaIJ == mat_campo[i][j]&& mat_mapa[i][j] == 0 ){ // se aberta a posição x y e tive o valor 0
					if(escolhaIJ == 63 ){  //se aberta a posição 63 e tive 0 tenho que abrir a posição 54, 55, 62
						if(mat_mostra[i][j]==-2){// verifica se a casa ainda não foi aberta
							mat_mostra[i][j]= 0; // posição 63 recebe o valor 0
							imprime_matriz(mat_mostra);//mat foi jogado quer dizer que essa casa ja foi aberta
						}
						if (mat_mostra[i][j-1] == -2){ //se ainda não foi aberta
							mat_mostra[i][j-1] = mat_mapa[i][j-1]; //posição 62
							imprime_matriz(mat_mostra);
						}
						if (mat_mostra[i-1][j-1] == -2 ){//se ainda não foi aberta
							mat_mostra[i-1][j-1] = mat_mapa[i-1][j-1]; // posição 54
							imprime_matriz(mat_mostra);
						}
						if (mat_mostra[i-1][j] == -2){//se ainda não foi aberta
							mat_mostra[i-1][j] = mat_mapa[i-1][j]; // posição 55
							imprime_matriz(mat_mostra);
						}
					}
					//escolhaIJ = verifica_de_novo(mat_mostra);
					if (escolhaIJ == 0){  //se aberta a posição 0 e tive 0 abrir a posição 1, 8, 9
						if(mat_mostra[i][j]== -2){//se ainda não foi aberta
							mat_mostra[i][j]= 0; // posição 0
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i][j+1] == -2){//se ainda não foi aberta
							mat_mostra[i][j+1] = mat_mapa[i][j+1]; //posição  1
							imprime_matriz(mat_mostra);
						}
						if(	mat_mostra[i+1][j] == -2) {
							mat_mostra[i+1][j] = mat_mapa[i+1][j]; // posição 8
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i+1][j+1] ==-2){
						mat_mostra[i+1][j+1] = mat_mapa[i+1][j+1]; // posição 9
						imprime_matriz(mat_mostra);
						}
					}
					//escolhaIJ = verifica_de_novo(mat_mostra);
					if (escolhaIJ == 7){ //se aberta a posição 7 e tive o numero 0 abrir a posição 6, 14, 15
						if(mat_mostra[i][j]==-2){
							mat_mostra[i][j]= 0; // posição 7
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i][j-1] ==-2){
							mat_mostra[i][j-1] = mat_mapa[i][j-1]; //posição  6
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i+1][j-1] == -2){
							mat_mostra[i+1][j-1] = mat_mapa[i+1][j-1]; // posição 14
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i+1][j]== -2){//verifica se nao foi aberta ainda
							mat_mostra[i+1][j] = mat_mapa[i+1][j]; // posição 15
							imprime_matriz(mat_mostra);
						}
					}
				//	escolhaIJ = verifica_de_novo(mat_mostra);
					if (escolhaIJ == 56){ ////se aberta a posição 56 e tive 0 abrir a posição 48, 49, 57
						if(mat_mostra[i][j]== -2){
							mat_mostra[i][j]= 0; // posição 56
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i-1][j] == -2){
							mat_mostra[i-1][j] = mat_mapa[i-1][j]; //posição 48
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i-1][j+1] == -2 ){
							mat_mostra[i-1][j+1] = mat_mapa[i-1][j+1]; // posição 49
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i][j+1] == -2){
						mat_mostra[i][j+1] = mat_mapa[i][j+1]; // posição 57
						imprime_matriz(mat_mostra);
						}
					}
				//	escolhaIJ = verifica_de_novo(mat_mostra);
					if (escolhaIJ >=1 && escolhaIJ <=6){ // abre uma de 1 a 6 inclusive
						if(mat_mostra[i][j]==-2){
							mat_mostra[i][j]= 0; // posição 2 a 7 //digamos q seja a posição 4
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i][j-1] == -2){
							mat_mostra[i][j-1] = mat_mapa[i][j-1]; //supondo 4  vai abrir a 3
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i][j+1] == -2){
							mat_mostra[i][j+1] = mat_mapa[i][j+1]; // supondo 4 vai abrir a 5
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i+1][j-1] == -2){
							mat_mostra[i+1][j-1] = mat_mapa[i+1][j-1]; // supondo 4 vai abrir a 11
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i+1][j] == -2){
							mat_mostra[i+1][j] = mat_mapa[i+1][j]; 		// supondo 4 vai abrir a 12
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i+1][j+1] ==-2){
						mat_mostra[i+1][j+1] = mat_mapa[i+1][j+1];  // supondo 4 vai abri a 13
						imprime_matriz(mat_mostra);
						}
					}
				//	escolhaIJ = verifica_de_novo(mat_mostra);
					if (escolhaIJ >=57 && escolhaIJ <=62){ //
						if (mat_mostra[i][j]== -2){
							mat_mostra[i][j]= 0; // posição 57 a 62 //digamos q seja a posição 57
							imprime_matriz(mat_mostra);
						}
						if (mat_mostra[i-1][j-1] == -2 ){
							mat_mostra[i-1][j-1] = mat_mapa[i-1][j-1]; //supondo 57  vai abrir a 48
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i-1][j] == -2){
							mat_mostra[i-1][j] = mat_mapa[i-1][j]; // supondo 57 vai abrir a 49
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i-1][j+1] == -2){
							mat_mostra[i-1][j+1] = mat_mapa[i-1][j+1]; // supondo 57 vai abrir a 50
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i][j-1] == -2){
							mat_mostra[i][j-1] = mat_mapa[i][j-1]; 		// supondo 57 vai abrir a 56
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i][j+1] ==-2){
							mat_mostra[i][j+1] = mat_mapa[i][j+1];  // supondo 57 vai abri a 58
							imprime_matriz(mat_mostra);
						}
					}
				//	escolhaIJ = verifica_de_novo(mat_mostra);
					if (escolhaIJ == 15 || escolhaIJ == 23 || escolhaIJ == 31 ||escolhaIJ == 39 || escolhaIJ == 47 || escolhaIJ == 55) { //
						if(mat_mostra[i][j]== -2){
							mat_mostra[i][j]= 0; // supondo que seja 15 abre a casa 15
							imprime_matriz(mat_mostra);
						}
						if (mat_mostra[i-1][j-1] == -2){
							mat_mostra[i-1][j-1] = mat_mapa[i-1][j-1]; //supondo 15  vai abrir a 6
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i-1][j] == -2){
							mat_mostra[i-1][j] = mat_mapa[i-1][j]; // supondo 15 vai abrir a 7
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i][j-1] == -2){
							mat_mostra[i][j-1] = mat_mapa[i][j-1]; // supondo 15 vai abrir a 14
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i+1][j-1] ==-2){
							mat_mostra[i+1][j-1] = mat_mapa[i+1][j-1]; 		// supondo 15 vai abrir a 22
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i+1][j] == -2){
							mat_mostra[i+1][j] = mat_mapa[i+1][j];  // supondo 15 vai abri a 23
							imprime_matriz(mat_mostra);
						}
					}
				//	escolhaIJ = verifica_de_novo(mat_mostra);
					if (escolhaIJ == 8 || escolhaIJ == 16 || escolhaIJ == 24 ||escolhaIJ == 32 || escolhaIJ == 40 || escolhaIJ == 48) { //
						if(mat_mostra[i][j]== -2){
							mat_mostra[i][j]= 0; // supondo que seja 8 abre a casa 8
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i-1][j] == -2){
							mat_mostra[i-1][j] = mat_mapa[i-1][j]; //supondo 8  vai abrir a 0
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i-1][j+1] == -2){
							mat_mostra[i-1][j+1] = mat_mapa[i-1][j+1]; // supondo 8 vai abrir a 1
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i][j+1] == -2){
							mat_mostra[i][j+1] = mat_mapa[i][j+1]; // supondo 8 vai abrir a 9
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i+1][j] == -2){
							mat_mostra[i+1][j] = mat_mapa[i+1][j];// supondo 8 vai abrir a 16
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i+1][j+1] == -2){
							mat_mostra[i+1][j+1] = mat_mapa[i+1][j+1];  // supondo 8 vai abri a 17
							imprime_matriz(mat_mostra);
						}
					}
				//	escolhaIJ = verifica_de_novo(mat_mostra);
					if (escolhaIJ == 8 || escolhaIJ == 16 || escolhaIJ == 24 ||escolhaIJ == 32 || escolhaIJ == 40 || escolhaIJ == 48) { //
						if(	mat_mostra[i][j]== -2){
							mat_mostra[i][j]= 0; // supondo que seja 8 abre a casa 8
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i-1][j] == -2){
							mat_mostra[i-1][j] = mat_mapa[i-1][j]; //supondo 8  vai abrir a 0
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i-1][j+1] == -2){
							mat_mostra[i-1][j+1] = mat_mapa[i-1][j+1]; // supondo 8 vai abrir a 1
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i][j+1] == -2){
							mat_mostra[i][j+1] = mat_mapa[i][j+1]; // supondo 8 vai abrir a 9
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i+1][j] == -2){
							mat_mostra[i+1][j] = mat_mapa[i+1][j];// supondo 8 vai abrir a 16
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i+1][j+1] == -2){
							mat_mostra[i+1][j+1] = mat_mapa[i+1][j+1];  // supondo 8 vai abri a 17
							imprime_matriz(mat_mostra);
						}
					}
				//	escolhaIJ = verifica_de_novo(mat_mostra);
					if ((escolhaIJ >=9 && escolhaIJ <=14) || (escolhaIJ >=17 && escolhaIJ <=22) || (escolhaIJ >=25 && escolhaIJ <=30) || (escolhaIJ >=33 && escolhaIJ <=38)  || (escolhaIJ >=41 && escolhaIJ <=46)|| (escolhaIJ >=49 && escolhaIJ <=54)  ){ //
						if(mat_mostra[i][j]== -2){
							mat_mostra[i][j]= 0; // supondo que seja 12 abre a casa 12
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i-1][j-1] == -2){
							mat_mostra[i-1][j-1] = mat_mapa[i-1][j-1]; //supondo 12  vai abrir a 3
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i-1][j] == -2){
							mat_mostra[i-1][j] = mat_mapa[i-1][j]; // supondo 12 vai abrir a 4
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i-1][j+1] == -2){
							mat_mostra[i-1][j+1] = mat_mapa[i-1][j+1]; // supondo 12 vai abrir a 5
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i][j-1] == -2){
							mat_mostra[i][j-1] = mat_mapa[i][j-1];// supondo 12 vai abrir a 11
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i][j+1] == -2){
							mat_mostra[i][j+1] = mat_mapa[i][j+1];  // supondo 12 vai abri a 13
							imprime_matriz(mat_mostra); //if( =-2){
						}
						if(mat_mostra[i+1][j-1] ==-2){
							mat_mostra[i+1][j-1] = mat_mapa[i+1][j-1]; // supondo 12 vai abrir a 19
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i+1][j] ==-2){
							mat_mostra[i+1][j] = mat_mapa[i+1][j];// supondo 12 vai abrir a 20
							imprime_matriz(mat_mostra);
						}
						if(mat_mostra[i+1][j+1] ==-2){
							mat_mostra[i+1][j+1] = mat_mapa[i+1][j+1];  // supondo 12 vai abri a 21
							imprime_matriz(mat_mostra);
						}
					}
				//	escolhaIJ = verifica_de_novo(mat_mostra);

				}
//------------------------------------------------------------------------------------------------------------------Fim do que fazer se encontrar o 0
				if(escolhaIJ == mat_campo[i][j]&& mat_mapa[i][j] == 1 ){ //oque fazer se encontrar o valor 1
					mat_mostra[i][j]= 1;
					imprime_matriz(mat_mostra);
				}
				if(escolhaIJ == mat_campo[i][j]&& mat_mapa[i][j] == 2 ){//oque fazer se encontrar o valor 2
					mat_mostra[i][j]= 2;
					imprime_matriz(mat_mostra);
				}
				if(escolhaIJ == mat_campo[i][j]&& mat_mapa[i][j] == 3 ){ //oque fazer se encontrar o valor 3
					mat_mostra[i][j]= 3;
					imprime_matriz(mat_mostra);
				}
				if(escolhaIJ == mat_campo[i][j]&& mat_mapa[i][j] == 4 ){ //oque fazer se encontrar o valor 4
					mat_mostra[i][j]= 4;
					imprime_matriz(mat_mostra);
				}
				if(escolhaIJ == mat_campo[i][j]&& mat_mapa[i][j] == 5 ){ //oque fazer se encontrar o valor 5
					mat_mostra[i][j]= 5;
					imprime_matriz(mat_mostra);
				}
				if(escolhaIJ == mat_campo[i][j]&& mat_mapa[i][j] == 6 ){ //oque fazer se encontrar o valor 6
					mat_mostra[i][j]= 6;
					imprime_matriz(mat_mostra);
				}
				if(escolhaIJ == mat_campo[i][j]&& mat_mapa[i][j] == 7 ){ //oque fazer se encontrar o valor 7
					mat_mostra[i][j]= 7;
					imprime_matriz(mat_mostra);
				}
				if(escolhaIJ == mat_campo[i][j]&& mat_mapa[i][j] == 8 ){ //oque fazer se encontrar o valor 8
					mat_mostra[i][j]= 8;
					imprime_matriz(mat_mostra);
				}
			}
		//	printf("\n");
		}
		//imprime_matriz(mat_mostra); //chamando a funcao imprime matriz para o usuario e passando a matriz
		printf("\n");
	}




/*******************************************************************************************************pkpokopkopkopkpk**/
		void imprime_matriz(int mat_mostra[8][8]){
			int contador_de_casas_restantes = 59;
		system("cls");
		printf("\n\n------------ Cortador de Grama ------------\n\n");
		int i,j,bomba=0;
		for(i=0;i<8;i++){		//esse for imprime a matriz que o usuario vê
			for(j=0;j<8;j++){
				if(mat_mostra[i][j]==-1){
					printf("[-1] ");
					bomba=1;
					//contador_de_casas_restantes --;
				}//
				if(mat_mostra[i][j]==0){
					printf("[0 ] ");
					contador_de_casas_restantes --;
				}
				if(mat_mostra[i][j]==1){
					printf("[1 ] ");
					contador_de_casas_restantes --;
				}
				if(mat_mostra[i][j]==2){
					printf("[2 ] ");
					contador_de_casas_restantes --;
				}
				if(mat_mostra[i][j]==3){
					printf("[3 ] ");
					contador_de_casas_restantes --;
				}
				if(mat_mostra[i][j]==-2){
					printf("[-2] ");
				}
			}
				printf("\n");
		}
		printf("Ainda tem %d casas para abrir! Pressione Enter! ",contador_de_casas_restantes);
		if (bomba==1){
			printf("\n-----FORMIGUEIRO ENCONTRADO-----\n");
			printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
			system("PAUSE");


		}
		if(contador_de_casas_restantes ==0){
			printf("\n\n! ! ! P  A  R  A  B  E  N  S  !  !  ! \n\n Voce cortou toda a grama \\o/ \\o/ \\o/");
			getch();
			getch();
		}
		//printf("Aperte Enter\n");
		getch();

		printf("\n");


}

int verifica_de_novo(int mat_mostra[8][8],int mat_marca[8][8]){
	int encontrei_zero;
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){


















					/*
	possi 1 	possi 2 	possi 3		possi 4		possi 5		possi 6		possi 7		possi 8		possi 9		possi 10	possi 11	possi 12	possi 13	possi 14
	1  1		1  2		2  1		1  1		1  1		1  1		2  2		2  1		1  1		1  1		2  2		2  1		1  1
	1 -2		1 -2		1 -2		2 -2		1 -2		1 -2		1 -2		2 -2		2 -2		1 -2		2 -2		2 -2		2 -2
	1  1		1  1		1  1		1  1		2  1		1  2		1  1		1  1		2  1		2  2		1  1		2  1		2  2

	//15 23 31 39 47 55
	2  2  2
	3 -2  1
	*/				//esse if de baixo marca uma possivel bomba aqui !!
					// 1  1
					// 1 -2 tenho que arrumar esses diferente de -2 pra igual a 1, mas por enquanto vou deixar assim
					// 1  1
				if(mat_mostra[i][j]== -2 && mat_mostra[i-1][j-1]!= -2 && mat_mostra[i-1][j]!= -2 && mat_mostra[i][j-1]!= -2 && mat_mostra[i+1][j-1]!= -2 && mat_mostra[i+1][j]!= -2 ){
					mat_marca[i][j]=-59; // to dizendo que -59 é suspeita de ter uma boma
				}
				//esse if de baixo marca uma possivel bomba aqui !!
					// 1  1  1
					// 1 -2  1
				if(mat_mostra[i][j]== -2 && mat_mostra[i-1][j-1]!= -2 && mat_mostra[i-1][j]!= -2 && mat_mostra[i-1][j+1]!= -2&& mat_mostra[i][j-1]!= -2 && mat_mostra[i][j+1]!= -2){
					mat_marca[i][j]=-59; // to dizendo que -59 é suspeita de ter uma boma
				} // to marcando as casas com possiveis bombas =)

					//esse if de baixo marca uma possivel bomba aqui !!
					// 1 -2  1
					// 1  1  1
					if(mat_mostra[i][j]== -2 && mat_mostra[i][j-1]!= -2 && mat_mostra[i][j+1]!= -2 && mat_mostra[i+1][j-1]!= -2&& mat_mostra[i+1][j]!= -2 && mat_mostra[i+1][j+1]!= -2){
					mat_marca[i][j]=-59; // to dizendo que -59 é suspeita de ter uma boma
				}
					//esse if de baixo marca uma possivel bomba aqui!!
					// 1  1
					//-2  1
					// 1  1
					if(mat_mostra[i][j]== -2 && mat_mostra[i-1][j]!= -2 && mat_mostra[i-1][j+1]!= -2 && mat_mostra[i][j+1]!= -2&& mat_mostra[i+1][j]!= -2 && mat_mostra[i+1][j+1]!= -2){
					mat_marca[i][j]=-59; // to dizendo que -59 é suspeita de ter uma boma
				}
					//esse if de baix marca uma possivel bomba aqui!!
					// N  N  N
					// N  1* N	esse 1 do meio indica q tem uma bomba em volta, e como todas as casas em volta nao tem bomba, exeto uma q nao foi aberta, a bomba está alí.
					//-2  N  N	estou marcando esse -2 como bomba

					//tenho que fazer um desse pra cada -.-'

					if(mat_mostra[i][j]== 1 && mat_mostra[i-1][j-1]!= -2 && mat_mostra[i-1][j]!= -2 && mat_mostra[i-1][j+1]!= -2&& mat_mostra[i][j-1]!= -2 && mat_mostra[i][j+1]!= -2 && mat_mostra[i+1][j-1]== -2 && mat_mostra[i+1][j]!= -2  && mat_mostra[i+1][j+1]!= -2 ){
					mat_marca[i+1][j-1]= -59; // to dizendo que -59 é suspeita de ter uma boma
				}

				//esse if de baix marca uma possivel bomba aqui!!
					// N  N  N
					//-2  1* N	esse 1 do meio indica q tem uma bomba em volta, e como todas as casas em volta nao tem bomba, exeto uma q nao foi aberta, a bomba está alí.
					// N  N  N	estou marcando esse -2 como bomba

					if(mat_mostra[i][j]== 1 && mat_mostra[i-1][j-1]!= -2 && mat_mostra[i-1][j]!= -2 && mat_mostra[i-1][j+1]!= -2&& mat_mostra[i][j-1]== -2 && mat_mostra[i][j+1]!= -2 && mat_mostra[i+1][j-1]!= -2 && mat_mostra[i+1][j]!= -2  && mat_mostra[i+1][j+1]!= -2 ){
					mat_marca[i][j-1]= -59; // to dizendo que -59 é suspeita de ter uma boma
				}

				//esse if de baix marca uma possivel bomba aqui!!
					//-2  N  N
					// N  1* N	esse 1 do meio indica q tem uma bomba em volta, e como todas as casas em volta nao tem bomba, exeto uma q nao foi aberta, a bomba está alí.
					// N  N  N	estou marcando esse -2 como bomba

					if(mat_mostra[i][j]== 1 && mat_mostra[i-1][j-1]== -2 && mat_mostra[i-1][j]!= -2 && mat_mostra[i-1][j+1]!= -2 && mat_mostra[i][j-1]!= -2 && mat_mostra[i][j+1]!= -2 && mat_mostra[i+1][j-1]!= -2 && mat_mostra[i+1][j]!= -2  && mat_mostra[i+1][j+1]!= -2 ){
					mat_marca[i-1][j-1]= -59; // to dizendo que -59 é suspeita de ter uma boma
				}

				//esse if de baix marca uma possivel bomba aqui!!
					// N -2  N
					// N  1* N	esse 1 do meio indica q tem uma bomba em volta, e como todas as casas em volta nao tem bomba, exeto uma q nao foi aberta, a bomba está alí.
					// N  N  N	estou marcando esse -2 como bomba

					if(mat_mostra[i][j]== 1 && mat_mostra[i-1][j-1]!= -2 && mat_mostra[i-1][j]== -2 && mat_mostra[i-1][j+1]!= -2 && mat_mostra[i][j-1]!= -2 && mat_mostra[i][j+1]!= -2 && mat_mostra[i+1][j-1]!= -2 && mat_mostra[i+1][j]!= -2  && mat_mostra[i+1][j+1]!= -2 ){
					mat_marca[i-1][j]= -59; // to dizendo que -59 é suspeita de ter uma boma
				}

				//esse if de baix marca uma possivel bomba aqui!!
					// N  N -2
					// N  1* N	esse 1 do meio indica q tem uma bomba em volta, e como todas as casas em volta nao tem bomba, exeto uma q nao foi aberta, a bomba está alí.
					// N  N  N	estou marcando esse -2 como bomba

					if(mat_mostra[i][j]== 1 && mat_mostra[i-1][j-1]!= -2 && mat_mostra[i-1][j]!= -2 && mat_mostra[i-1][j+1]== -2 && mat_mostra[i][j-1]!= -2 && mat_mostra[i][j+1]!= -2 && mat_mostra[i+1][j-1]!= -2 && mat_mostra[i+1][j]!= -2  && mat_mostra[i+1][j+1]!= -2 ){
					mat_marca[i-1][j+1]= -59; // to dizendo que -59 é suspeita de ter uma boma
				}

				//esse if de baix marca uma possivel bomba aqui!!
					// N  N  N
					// N  1*-2	esse 1 do meio indica q tem uma bomba em volta, e como todas as casas em volta nao tem bomba, exeto uma q nao foi aberta, a bomba está alí.
					// N  N  N	estou marcando esse -2 como bomba

					if(mat_mostra[i][j]== 1 && mat_mostra[i-1][j-1]!= -2 && mat_mostra[i-1][j]!= -2 && mat_mostra[i-1][j+1]!= -2 && mat_mostra[i][j-1]!= -2 && mat_mostra[i][j+1]== -2 && mat_mostra[i+1][j-1]!= -2 && mat_mostra[i+1][j]!= -2  && mat_mostra[i+1][j+1]!= -2 ){
					mat_marca[i][j+1]= -59; // to dizendo que -59 é suspeita de ter uma boma
				}

					//esse if de baix marca uma possivel bomba aqui!!
					// N  N  N
					// N  1* N	esse 1 do meio indica q tem uma bomba em volta, e como todas as casas em volta nao tem bomba, exeto uma q nao foi aberta, a bomba está alí.
					// N  N -2	estou marcando esse -2 como bomba

					if(mat_mostra[i][j]== 1 && mat_mostra[i-1][j-1]!= -2 && mat_mostra[i-1][j]!= -2 && mat_mostra[i-1][j+1]!= -2 && mat_mostra[i][j-1]!= -2 && mat_mostra[i][j+1]!= -2 && mat_mostra[i+1][j-1]!= -2 && mat_mostra[i+1][j]!= -2  && mat_mostra[i+1][j+1]== -2 ){
					mat_marca[i+1][j+1]= -59; // to dizendo que -59 é suspeita de ter uma boma
				}

				//esse if de baix marca uma possivel bomba aqui!!
					// N  N  N
					// N  1* N	esse 1 do meio indica q tem uma bomba em volta, e como todas as casas em volta nao tem bomba, exeto uma q nao foi aberta, a bomba está alí.
					// N -2  N	estou marcando esse -2 como bomba

					if(mat_mostra[i][j]== 1 && mat_mostra[i-1][j-1]!= -2 && mat_mostra[i-1][j]!= -2 && mat_mostra[i-1][j+1]!= -2 && mat_mostra[i][j-1]!= -2 && mat_mostra[i][j+1]!= -2 && mat_mostra[i+1][j-1]!= -2 && mat_mostra[i+1][j]== -2  && mat_mostra[i+1][j+1]!= -2 ){
					mat_marca[i+1][j]= -59; // to dizendo que -59 é suspeita de ter uma boma
				}

				//----------------//----------------//-----------------///-----------------///----------
					//esse if de baixo marca duas possiveis bombas aqui!!!
				//-2 -2  N
				// N  2* N
				// N  N  N
				if(mat_mostra[i][j]== 2 && mat_mostra[i-1][j-1]== -2 && mat_mostra[i-1][j]== -2 && mat_mostra[i-1][j+1]!= -2 && mat_mostra[i][j-1]!= -2 && mat_mostra[i][j+1]!= -2 && mat_mostra[i+1][j-1]!= -2 && mat_mostra[i+1][j]!= -2  && mat_mostra[i+1][j+1]!= -2 ){
					mat_marca[i-1][j-1]= -59;
					mat_marca[i-1][j] = -59; // to dizendo que -59 é suspeita de ter uma boma
				}

				//esse if de baixo marca duas possiveis bombas aqui!!!
				//-2  N -2
				// N  2* N
				// N  N  N
				if(mat_mostra[i][j]== 2 && mat_mostra[i-1][j-1]== -2 && mat_mostra[i-1][j]!= -2 && mat_mostra[i-1][j+1]== -2 && mat_mostra[i][j-1]!= -2 && mat_mostra[i][j+1]!= -2 && mat_mostra[i+1][j-1]!= -2 && mat_mostra[i+1][j]!= -2  && mat_mostra[i+1][j+1]!= -2 ){
					mat_marca[i-1][j-1]= -59;
					mat_marca[i-1][j+1] = -59; // to dizendo que -59 é suspeita de ter uma boma
				}
				//esse if de baixo marca duas possiveis bombas aqui!!!
				//-2  N  N
				// N  2*-2
				// N  N  N
				if(mat_mostra[i][j]== 2 && mat_mostra[i-1][j-1]== -2 && mat_mostra[i-1][j]!= -2 && mat_mostra[i-1][j+1]!= -2 && mat_mostra[i][j-1]!= -2 && mat_mostra[i][j+1]== -2 && mat_mostra[i+1][j-1]!= -2 && mat_mostra[i+1][j]!= -2  && mat_mostra[i+1][j+1]!= -2 ){
					mat_marca[i-1][j-1]= -59;
					mat_marca[i][j+1]= -59; // to dizendo que -59 é suspeita de ter uma boma
				}

				//esse if de baixo marca duas possiveis bombas aqui!!!
				//-2  N  N
				// N  2* N
				// N  N -2
				if(mat_mostra[i][j]== 2 && mat_mostra[i-1][j-1]== -2 && mat_mostra[i-1][j]!= -2 && mat_mostra[i-1][j+1]!= -2 && mat_mostra[i][j-1]!= -2 && mat_mostra[i][j+1]!= -2 && mat_mostra[i+1][j-1]!= -2 && mat_mostra[i+1][j]!= -2  && mat_mostra[i+1][j+1]== -2 ){
					mat_marca[i-1][j-1]= -59;
					mat_marca[i+1][j+1]= -59; // to dizendo que -59 é suspeita de ter uma boma
				}

				//esse if de baixo marca duas possiveis bombas aqui!!!
				//-2  N  N
				// N  2* N
				// N -2  N
				if(mat_mostra[i][j]== 2 && mat_mostra[i-1][j-1]== -2 && mat_mostra[i-1][j]!= -2 && mat_mostra[i-1][j+1]!= -2 && mat_mostra[i][j-1]!= -2 && mat_mostra[i][j+1]!= -2 && mat_mostra[i+1][j-1]!= -2 && mat_mostra[i+1][j]== -2  && mat_mostra[i+1][j+1]!= -2 ){
					mat_marca[i-1][j-1]= -59;
					mat_marca[i+1][j]= -59; // to dizendo que -59 é suspeita de ter uma boma
				}

				//esse if de baixo marca duas possiveis bombas aqui!!!
				//-2  N  N
				// N  2* N
				//-2  N  N
				if(mat_mostra[i][j]== 2 && mat_mostra[i-1][j-1]== -2 && mat_mostra[i-1][j]!= -2 && mat_mostra[i-1][j+1]!= -2 && mat_mostra[i][j-1]!= -2 && mat_mostra[i][j+1]!= -2 && mat_mostra[i+1][j-1]== -2 && mat_mostra[i+1][j]!= -2  && mat_mostra[i+1][j+1]!= -2 ){
					mat_marca[i-1][j-1]= -59;
					mat_marca[i+1][j-1]= -59; // to dizendo que -59 é suspeita de ter uma boma
				}

					//esse if de baixo marca duas possiveis bombas aqui!!!
				//-2  N  N
				//-2  2* N
				// N  N  N
				if(mat_mostra[i][j]== 2 && mat_mostra[i-1][j-1]== -2 && mat_mostra[i-1][j]!= -2 && mat_mostra[i-1][j+1]!= -2 && mat_mostra[i][j-1]== -2 && mat_mostra[i][j+1]!= -2 && mat_mostra[i+1][j-1]!= -2 && mat_mostra[i+1][j]!= -2  && mat_mostra[i+1][j+1]!= -2 ){
					mat_marca[i-1][j-1]= -59;
					mat_marca[i][j-1]= -59; // to dizendo que -59 é suspeita de ter uma boma
				}

				//FAZER O IF do 3




														   // IMPOOOOOOOOORTANTE
				//Caso particular observado no mapa1       // PRECISO LEMBRAR FUTURAMENTE DE OBSERVAR QUE O 0(ZERO) É POSIÇÃO I0(i ZERO) J0(j ZERO)
				//so se aplica se o primeiro 0 (zero)  estiver na primeira casa do jogo
				//esse if de baixo acha duas bombas por causa da situação
				// 0  1 -2		0  1
				// 0  2 -2		0  2.-1  // <<<<  to pegando esse 2 como base esse que tem um ponto de marcação
				// 0  2 -2		0  2 -1
				// 1  2 -2		1  2
				//-2 -2 -2

				 if(mat_mostra[i][j]== 2 && mat_mostra[i-1][j-1]!= -2 && mat_mostra[i-1][j]== 1 && mat_mostra[i][j-1]!= -2 && mat_mostra[i][j+1]== -2 && mat_mostra[i+1][j-1]!= -2 && mat_mostra[i+1][j]== 2  && mat_mostra[i+1][j+1]== -2 && mat_mostra[i+2][j-1]== 1 && mat_mostra[i+2][j]== 2 ){
					mat_marca[i][j+1]= -59;		// marcando a bomba
					mat_marca[i+1][j+1]= -59; //marcando a bomba
				}


														   // IMPOOOOOOOOORTANTE  Ta bugado!
				//Caso particular observado no mapa1       // PRECISO LEMBRAR FUTURAMENTE DE OBSERVAR QUE O 0(ZERO) É POSIÇÃO I0(i ZERO) J0(j ZERO)
				//esse if de baixo acha UMA bomba por causa da situação
				// 2 -2 -2 -2								2 -2 -1 -2  // << Bomba so pode estar aqui
				// 2  1  1  1								2  1. 1  1 // <<<<  to pegando esse primeiro 1 da esquerda como base o que tem um ponto
				// 1  0  0  0								1  0  0  0
				//Fazer esse if


				if(mat_mostra[i][j]== 1 && mat_mostra[i-1][j-1]== 2 && mat_mostra[i-1][j+1]== -2 && mat_mostra[i][j+1]== 1 && mat_mostra[i][j+2]==1 && mat_mostra[i+1][j-1]!=-2 && mat_mostra[i+1][j]== 0  && mat_mostra[i+1][j+1]==0 && mat_mostra[i+1][j+2]== 0 ){
					mat_marca[i-1][j+1]= -59;		// marcando a bomba
				}










































				while(mat_mostra[i][j]==0 && mat_marca[i][j]== -2){ // Lembrar no futuro que esse While << abre as casa em volta do zero que ainda nao foram abertas
					mat_marca[i][j]= -1;							// e marca as casas que ja tiveram todas as casas em volta dela liberada
					encontrei_zero = encontra_posicao(i+1,j+1);    // passo as cordenadas de onde encontrei um zero com casas disponiveis em volta
						return encontrei_zero;	// retorno pra função faz_jogada qual a casa onde tem um zero com casas disponiveis
				}
				/*else{
				 srand(time(NULL));
				 encontrei_zero = rand()%63;
				 return encontrei_zero;
				}*/
			}



		}//

		//9999999999999999999999999//

	//	while(numero_que_nao_foi_aberto == mat[mostra[i][j]  == -2)
	//esta gambiarra aqui faz com que o pc escolha uma casa aleatoriamente QUE AINDA NAO FOI ABERTA!!!  caso acabe de abrir todas as casas em volta do zero
				int ok =0;
				int contador =0;
				int mat_campo[8][8];
					for(int i=0;i<8;i++){
						for(int j=0;j<8;j++){
							mat_campo[i][j]= contador;
							contador = contador+1;
						}
					}

				while(ok!=1){
					srand(time(NULL)); // se ja foram abertas todas as casas em volta do zero, o programa simplesmente joga em um numero aleatorio entre 0 e 63
					 encontrei_zero = rand()%63;
							for(int i=0;i<8;i++){
						for(int j=0;j<8;j++){// printf("%d",mat_mostra[i][j]);//printf("%d",encontrei_zero);
					 if(encontrei_zero == mat_campo[i][j] && mat_mostra[i][j]== -2 && mat_marca[i][j]!= -59){ // eu no futuro quando tentar fazer o codigo, tenho que lembrar o seguinte>>> a ideia é marcar as casas com suspeita de bomba
				 		printf("%d",encontrei_zero);
				 		ok = 1;
				 		return encontrei_zero;
				 	 }
						}// a ideia é fazer um while aqui entre //9999999999// e //999999999// que verifique o seguinte....
		 					}
				//a ideia é fazer tambem um menu que pergunta o nome do mapa a ser testado caso nao tenha nenhum nome seja usado o mapa1 =D


				}//// tenho que pesquisar um numero aleatorio enquanto ele seja diferente de uma casa que ja foi aberta e seja diferente de uma casa com suspeita de boma.

				// ou melhor vou trazer um numero aleatorio. se esse numero aleatorio for uma casa que ja foi aberta... pesquise outro numero aleatorio.. pesquisou ? entao verifica se e uma casa que ja foi aberta
				//ainda nao foi aberta ? entao verifica se nao é suspeita de bomba... é suspeita de bomba? entao traga outro numero aleatorio e verifique tudo de novo
		//99999999999999999999999999//

	}

	 int encontra_posicao(int escolhidoI, int escolhidoJ){
	 	int escolhaIJ, i, j;

		if(escolhidoI ==0 && escolhidoJ ==0){ // sair do programa
			escolhaIJ =-1;
		}
		if(escolhidoI ==1 && escolhidoJ ==1){ //11 - 11 = 0     12 - 11 = 1     22 - 11 = 11
			escolhaIJ =0;
		}
		if(escolhidoI ==1 && escolhidoJ ==2){
			escolhaIJ =1;
		}
		if(escolhidoI ==1 && escolhidoJ ==3){
			escolhaIJ =2;
		}
		if(escolhidoI ==1 && escolhidoJ ==4){
			escolhaIJ =3;
		}
		if(escolhidoI ==1 && escolhidoJ ==5){
			escolhaIJ =4;
		}
		if(escolhidoI ==1 && escolhidoJ ==6){
			escolhaIJ =5;
		}
		if(escolhidoI ==1 && escolhidoJ ==7){
			escolhaIJ =6;
		}
		if(escolhidoI ==1 && escolhidoJ ==8){
			escolhaIJ =7;
		}
		if(escolhidoI ==2 && escolhidoJ ==1){
			escolhaIJ =8;
		}
		if(escolhidoI ==2 && escolhidoJ ==2){
			escolhaIJ =9;
		}
		if(escolhidoI ==2 && escolhidoJ ==3){
			escolhaIJ =10;
		}
		if(escolhidoI ==2 && escolhidoJ ==4){
			escolhaIJ =11;
		}
		if(escolhidoI ==2 && escolhidoJ ==5){
			escolhaIJ =12;
		}
		if(escolhidoI ==2 && escolhidoJ ==6){
			escolhaIJ =13;
		}
		if(escolhidoI ==2 && escolhidoJ ==7){
			escolhaIJ =14;
		}
		if(escolhidoI ==2 && escolhidoJ ==8){
			escolhaIJ =15;
		}
		if(escolhidoI ==3 && escolhidoJ ==1){
			escolhaIJ =16;
		}
		if(escolhidoI ==3 && escolhidoJ ==2){
			escolhaIJ =17;
		}
		if(escolhidoI ==3 && escolhidoJ ==3){
			escolhaIJ =18;
		}
		if(escolhidoI ==3 && escolhidoJ ==4){
			escolhaIJ =19;
		}
		if(escolhidoI ==3 && escolhidoJ ==5){
			escolhaIJ =20;
		}
		if(escolhidoI ==3 && escolhidoJ ==6){
			escolhaIJ =21;
		}
		if(escolhidoI ==3 && escolhidoJ ==7){
			escolhaIJ =22;
		}
		if(escolhidoI ==3 && escolhidoJ ==8){
			escolhaIJ =23;
		}
		if(escolhidoI ==4 && escolhidoJ ==1){
			escolhaIJ =24;
		}
		if(escolhidoI ==4 && escolhidoJ ==2){
			escolhaIJ =25;
		}
		if(escolhidoI ==4 && escolhidoJ ==3){
			escolhaIJ =26;
		}
		if(escolhidoI ==4 && escolhidoJ ==4){
			escolhaIJ =27;
		}
		if(escolhidoI ==4 && escolhidoJ ==5){
			escolhaIJ =28;
		}
		if(escolhidoI ==4 && escolhidoJ ==6){
			escolhaIJ =29;
		}
		if(escolhidoI ==4 && escolhidoJ ==7){
			escolhaIJ =30;
		}
		if(escolhidoI ==4 && escolhidoJ ==8){
			escolhaIJ =31;
		}
		if(escolhidoI ==5 && escolhidoJ ==1){
			escolhaIJ =32;
		}
		if(escolhidoI ==5 && escolhidoJ ==2){
			escolhaIJ =33;
		}
		if(escolhidoI ==5 && escolhidoJ ==3){
			escolhaIJ =34;
		}
		if(escolhidoI ==5 && escolhidoJ ==4){
			escolhaIJ =35;
		}
		if(escolhidoI ==5 && escolhidoJ ==5){
			escolhaIJ =36;
		}
		if(escolhidoI ==5 && escolhidoJ ==6){
			escolhaIJ =37;
		}
		if(escolhidoI ==5 && escolhidoJ ==7){
			escolhaIJ =38;
		}
		if(escolhidoI ==5 && escolhidoJ ==8){
			escolhaIJ =39;
		}
		if(escolhidoI ==6 && escolhidoJ ==1){
			escolhaIJ =40;
		}
		if(escolhidoI ==6 && escolhidoJ ==2){
			escolhaIJ =41;
		}
		if(escolhidoI ==6 && escolhidoJ ==3){
			escolhaIJ =42;
		}
		if(escolhidoI ==6 && escolhidoJ ==4){
			escolhaIJ =43;
		}
		if(escolhidoI ==6 && escolhidoJ ==5){
			escolhaIJ =44;
		}
		if(escolhidoI ==6 && escolhidoJ ==6){
			escolhaIJ =45;
		}
		if(escolhidoI ==6 && escolhidoJ ==7){
			escolhaIJ =46;
		}
		if(escolhidoI ==6 && escolhidoJ ==8){
			escolhaIJ =47;
		}
		if(escolhidoI ==7 && escolhidoJ ==1){
			escolhaIJ =48;
		}
		if(escolhidoI ==7 && escolhidoJ ==2){
			escolhaIJ =49;
		}
		if(escolhidoI ==7 && escolhidoJ ==3){
			escolhaIJ =50;
		}
		if(escolhidoI ==7 && escolhidoJ ==4){
			escolhaIJ =51;
		}
		if(escolhidoI ==7 && escolhidoJ ==5){
			escolhaIJ =52;
		}
		if(escolhidoI ==7 && escolhidoJ ==6){
			escolhaIJ =53;
		}
		if(escolhidoI ==7 && escolhidoJ ==7){
			escolhaIJ =54;
		}
		if(escolhidoI ==7 && escolhidoJ ==8){
			escolhaIJ =55;
		}
		if(escolhidoI ==8 && escolhidoJ ==1){
			escolhaIJ =56;
		}
		if(escolhidoI ==8 && escolhidoJ ==2){
			escolhaIJ =57;
		}
		if(escolhidoI ==8 && escolhidoJ ==3){
			escolhaIJ =58;
		}
		if(escolhidoI ==8 && escolhidoJ ==4){
			escolhaIJ =59;
		}
		if(escolhidoI ==8 && escolhidoJ ==5){
			escolhaIJ =60;
		}
		if(escolhidoI ==8 && escolhidoJ ==6){
			escolhaIJ =61;
		}
		if(escolhidoI ==8 && escolhidoJ ==7){
			escolhaIJ =62;
		}
		if(escolhidoI ==8 && escolhidoJ ==8){
			escolhaIJ =63;
		}
		return escolhaIJ;
	}

	//MATRIZ	MAPA
	//
	// 0  1  3 -1  2  1 -1  1
	// 0  2 -1 -1  2  1  1  1
	// 0  2 -1  3  1  0  0  0
	// 1  2  2  1  0  0  1  1
	// 2 -1  3  1  1  0  1 -1  // esse -1 a direita do 2 é bomba porque o cara um a esquerda um pra cima é o 1 e nao tem bomba perto dele so essa
	// 2 -1  3 -1  1  0  1  1
	// 1  1  2  2  2  1  0  0
	// 0  0  0  1 -1  1  0  0








	// 0  1  2  3  4  5  6  7
	// 8  9  10 11 12 13 14 15
	// 16 17 18 19 20 21 22 23
	// 24 25 26 27 28 29 30 31
	// 32 33 34 35 36 37 38 39
	// 40 41 42 43 44 45 46 47
	// 48 49 50 51 52 53 54 55
	// 56 57 58 59 60 61 62 63
