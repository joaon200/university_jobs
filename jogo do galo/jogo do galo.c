#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void menu(char mesa[3][3]);
void inicializar(char mesa[3][3]);
void jogar(char mesa[3][3],char nome1[61],char nome2[61]);
void computadorimp(char mesa[3][3],char nome1[61]);
void computadorfacil(char mesa[3][3],char nome1[61]);
char verifica(char mesa[3][3], char jogador);

//where is the matrix is cleaned and the user chose game mode. 1x1/easy/hardcore
int main(int argc, char *argv[]) {

	char mesa[3][3];
	
	menu(mesa);

}

//menu
void menu(char mesa[3][3]){
	int escolha=0;
	char nome1[61];
	char nome2[61];
	int x = 1;
	
	do{
		printf("1-jogar contra o computador(impossivel);\n2-jogar contra o computador(facil);\n3-jogar 1vs1;\n4-sair;\n");
		scanf(" %d",& escolha);
		
		switch(escolha){
			case 1:
				inicializar(mesa);
				printf("insira o seu nome: ");
				scanf("%s",nome1);
				computadorimp(mesa,nome1);
				break;

			case 2:
				inicializar(mesa);
				printf("insira o seu nome: ");
				scanf("%s",nome1);
				computadorfacil(mesa,nome1);
				break;

			case 3:
				inicializar(mesa);
				printf("jogador 1 insira o seu nome: ");
				scanf("%s",nome1);
				printf("jogador 2 insira o seu nome: ");
				scanf("%s",nome2);
				jogar(mesa,nome1,nome2);
				break;

			case 4:
				exit(0);

			default:
				printf("escolha uma opcao valida");
				Sleep(1000);
				system("cls");
				break;						
		}
	} while (x==1);	
}

//function to verify if the player won
char verifica(char mesa[3][3],char jogador){	

	if(mesa[0][0]==jogador && mesa[0][1]==jogador && mesa[0][2]==jogador || mesa[1][0]==jogador && mesa[1][1]==jogador && mesa[1][2]==jogador || mesa[2][0]==jogador && mesa[2][1]==jogador && mesa[2][2]==jogador){
		return 's';
	}
	//Check the columns
	else if(mesa[0][0]==jogador && mesa[1][0]==jogador && mesa[2][0]==jogador || mesa[0][1]==jogador && mesa[1][1]==jogador && mesa[2][1]==jogador || mesa[0][2]==jogador && mesa[1][2]==jogador && mesa[2][2]==jogador){
		return 's';
	}
	//Check the diagonals
	else if(mesa[0][0]==jogador && mesa[1][1]==jogador && mesa[2][2]==jogador || mesa[0][2]==jogador && mesa[1][1]==jogador && mesa[2][0]==jogador){
		return 's';
	}
	return 'n';
}

//function to put "." in every matrix positions
void inicializar(char mesa[3][3]){
	int i=0;
	int c=0;
	
	for(i=0;i<3;i++){
		for(c=0;c<3;c++){
			mesa[i][c] = '.' ;
		}
	}
}

//1vs1 
void jogar(char mesa[3][3],char nome1[61],char nome2[61]){
	int i=0;
	int c=0;
	int jogada=0;
	char simnao;
	int ciclo = 0;

	do{
		//show playing table
		system("cls");
		for(i=0;i<3;i++){
			for(c=0;c<3;c++){
				printf("%c  ",mesa[i][c]);
			}
			printf("\n");
		}
		
		//starts the game
		for(jogada=1;jogada<11;jogada++){
			
			//If the game reaches this point, it will be tied.
			if(jogada == 10){ 
				printf("voce empatou mais sorte da proxima :(\n");
				printf("quer voltar a jogar? (s/n)");//Ask the players if they want to play again.
				scanf(" %c",&simnao);
				if(simnao=='s'){//if the players wants to play again
					inicializar(mesa);//initialise table with "."
					ciclo = 1;
					break;
				}
				else if(simnao=='n'){//if the players didn't want to play again
					return;
				}
			}
		
			else if (jogada%2 == 1){//this condition find if "jogada" is a odd number
				printf("%s onde quer jogar?\n",nome1);
				scanf("%d",& i);
				scanf("%d",& c);
				
				//check if the move is valid
				while(i>3 || c>3 || i<1 ||c<1){
					printf("jogada invalida tente jogar dentro do tabuleiro \n");
					scanf("%d",& i);
					scanf("%d",& c);
				}
				while(mesa[i-1][c-1]=='x' || mesa[i-1][c-1]=='o'){
					printf("jogada invalida tente outra \n");
					scanf("%d",& i);
					scanf("%d",& c);	
				}
				
				//save the move in the matrix
				mesa[i-1][c-1]='x';
				
				//show game table
				system("cls");
				for (i=0;i<3;i++){
					for(c=0;c<3;c++){
						printf("%c  ",mesa[i][c]);
					}
					printf("\n");
				}	
				
				//verify if the player won
				if(verifica(mesa,'x')=='s'){
						printf("%s, Ganhou :)\n",nome1);
						printf("quer voltar a jogar? (s/n)");//Ask the players if they want to play again.
						scanf(" %c",&simnao);
						if(simnao=='s'){//if the players wants to play again
							inicializar(mesa);//initialise table with "."
							ciclo = 1;
							break;
						}
						else if(simnao=='n'){//if the players didn't want to play again
							return;
						}
				}
				
			}
			
			else if (jogada%2 == 0){//this condition find if "jogada" is a pair number
				printf("%s onde quer jogar?\n",nome2);
				scanf("%d",& i);
				scanf("%d",& c);
				//check if the move is valid
				while(i>3 || c>3 || i<1 ||c<1){
					printf("jogada invalida tente jogar dentro do tabuleiro \n");
					scanf("%d",& i);
					scanf("%d",& c);
				}
				while(mesa[i-1][c-1]=='x' || mesa[i-1][c-1]=='o'){
					printf("jogada invalida tente outra \n");
					scanf("%d",& i);
					scanf("%d",& c);
				}
				
				//save the move in the matrix
				mesa[i-1][c-1]= 'o';
				
				//show game table				
				system("cls");	
				for (i=0;i<3;i++){
					for(c=0;c<3;c++){
						printf("%c  ",mesa[i][c]);
					}
					printf("\n");
				}
				
				//verify if the player won
				if(verifica(mesa,'o')=='s'){
					printf("%s, Ganhou :)",nome1);
					printf("quer voltar a jogar? (s/n)");//Ask the players if they want to play again.
					scanf(" %c",&simnao);
					if(simnao=='s'){//if the players wants to play again
						inicializar(mesa);//initialise table with "."
						ciclo = 1;
						break;
					}
					else if(simnao=='n'){//if the players didn't want to play again
						return;
					}
				}
			}
			
			printf("\n");
		}
	} while (ciclo == 1);
}

//jogar contra o pc em hard
void computadorimp(char mesa[3][3],char nome1[61]){
	int jogada=0;
	int i=0;
	int c=0;
	char simnao;
	int ciclo = 0;
	
	do{
		//show game table
		system("cls");
		for(i=0;i<3;i++){
			for(c=0;c<3;c++){
				printf("%c  ",mesa[i][c]);
			}
			printf("\n");
		}
		
		//game start
		for(jogada=1;jogada<11;jogada++){
			
			//If the game reaches this point, it will be tied.
			if(jogada == 10){ 
				printf("voce empatou mais sorte da proxima :(\n");
				printf("quer voltar a jogar? (s/n) ");//Ask the players if they want to play again.
				scanf(" %c",&simnao);
				if(simnao=='s'){//if the players wants to play again
					inicializar(mesa);//initialise table with "."
					ciclo = 1;
					break;
				}
				else if(simnao=='n'){//if the players didn't want to play again
					return;
				}
			}
			
			//first move of the computer
			else if(jogada == 2){
				//define a seed based on data time
				srand ( time(0) );
				//finde a random move
				i=rand()%3;
				c=rand()%3;
				//if the move are invalid keep trying until you find a valid move
				while (mesa[i][c]!='.'){
					i=rand()%3;
					c=rand()%3;
				}

				//save the move in the matrix
				mesa[i][c] = 'o';

				//print the new game table
				system("cls");
				for (i=0;i<3;i++){
					for(c=0;c<3;c++){
						printf("%c  ",mesa[i][c]);
					}
					printf("\n");
				}
			}
		
			else if (jogada%2 == 1){//this condition find if "jogada" is a odd number
				printf("%s onde quer jogar?\n",nome1);
				scanf("%d",& i);
				scanf("%d",& c);
				
				//check if the move is valid
				while(i>3 || c>3 || i<1 ||c<1){
					printf("jogada invalida tente jogar dentro do tabuleiro \n");
					scanf("%d",& i);
					scanf("%d",& c);
				}
				while(mesa[i-1][c-1]=='x' || mesa[i-1][c-1]=='o'){
					printf("jogada invalida tente outra \n");
					scanf("%d",& i);
					scanf("%d",& c);	
				}
				
				//save the move in the matrix
				mesa[i-1][c-1]='x';
				
				//show game table
				system("cls");
				for (i=0;i<3;i++){
					for(c=0;c<3;c++){
						printf("%c  ",mesa[i][c]);
					}
					printf("\n");
				}	
				
				//verify if the player won
				if(verifica(mesa,'x')=='s'){
					printf("%s, Ganhou :)\n",nome1);
					printf("quer voltar a jogar? (s/n)");//Ask the players if they want to play again.
					scanf(" %c",&simnao);
					if(simnao=='s'){//if the players wants to play again
						inicializar(mesa);//initialise table with "."
						ciclo = 1;
						break;
					}
					else if(simnao=='n'){//if the players didn't want to play again
						return;
					}
				}
				
			}
		
			//computer turn
			else if(jogada %2 == 0){
				//if the player have a chance to win, computer try to block her
				//lines
				if(     mesa[0][0]=='x' && mesa[0][1]=='x' && mesa[0][2]=='.')	{		
					mesa[0][2]='o';
				}
				else if(mesa[0][0]=='x' && mesa[0][1]=='.' && mesa[0][2]=='x')	{
					mesa[0][1]='o';
				}
				else if(mesa[0][0]=='.' && mesa[0][1]=='x' && mesa[0][2]=='x')	{
					mesa[0][0]='o';
				}

				else if(mesa[1][0]=='x' && mesa[1][1]=='x' && mesa[1][2]=='.')	{	
					mesa[1][2]='o';
				}
				else if(mesa[1][0]=='x' && mesa[1][1]=='.' && mesa[1][2]=='x')	{
					mesa[1][1]='o';
				}
				else if(mesa[1][0]=='.' && mesa[1][1]=='x' && mesa[1][2]=='x')	{
					mesa[1][0]='o';
				}
				
				else if(mesa[2][0]=='x' && mesa[2][1]=='x' && mesa[2][2]=='.')	{	
					mesa[2][2]='o';
				}
				else if(mesa[2][0]=='x' && mesa[2][1]=='.' && mesa[2][2]=='x')	{
					mesa[2][1]='o';
				}
				else if(mesa[2][0]=='.' && mesa[2][1]=='x' && mesa[2][2]=='x')	{
					mesa[2][0]='o';
				}
				
				//rows
				else if(mesa[0][0]=='x' && mesa[1][0]=='x' && mesa[2][0]=='.')	{	
					mesa[2][0]='o';
				}
				else if(mesa[0][0]=='x' && mesa[1][0]=='.' && mesa[2][0]=='x')	{
					mesa[1][0]='o';
				}
				else if(mesa[0][0]=='.' &&mesa[1][0]=='x' && mesa[2][0]=='x')	{
					mesa[0][0]='o';
				}
				
				else if(mesa[0][1]=='x' && mesa[1][1]=='x' && mesa[2][1]=='.')	{	 
					mesa[2][1]='o';
				}
				else if(mesa[0][1]=='x' && mesa[1][1]=='.' && mesa[2][1]=='x')	{
					mesa[1][1]='o';
				}
				else if(mesa[0][1]=='.' && mesa[1][1]=='x' && mesa[2][1]=='x')	{
					mesa[0][1]='o';
				}
				
				else if(mesa[0][2]=='x' && mesa[1][2]=='x' && mesa[2][2]=='.')	{	 
					mesa[2][2]='o';
				}
				else if(mesa[0][2]=='x' && mesa[1][2]=='.' && mesa[2][2]=='x')	{
					mesa[1][2]='o';
				}
				else if(mesa[0][2]=='.' && mesa[1][2]=='x' && mesa[2][2]=='x')	{
					mesa[0][2]='o';
				}
				
				//diagonal
				else if(mesa[0][0]=='x' && mesa[1][1]=='x' && mesa[2][2]=='.')	{	
					mesa[2][2]='o';
				}
				else if(mesa[0][0]=='x' && mesa[1][1]=='.' && mesa[2][2]=='x')	{
					mesa[1][1]='o';
				}
				else if(mesa[0][0]=='.' && mesa[1][1]=='x' && mesa[2][2]=='x')	{
					mesa[0][0]='o';
				}
				
				else if(mesa[0][2]=='x' && mesa[1][1]=='x' && mesa[2][0]=='.')	{	
					mesa[2][0]='o';
				}
				else if(mesa[0][2]=='x' && mesa[1][1]=='.' && mesa[2][0]=='x')	{
					mesa[1][1]='o';
				}
				else if(mesa[0][2]=='.' && mesa[1][1]=='x' && mesa[2][0]=='x')	{
					mesa[0][2]='o';
				}
				
				//if player don't have a chance to win computer play randomly
				else{
					//define a seed based on data time
					srand ( time(0) );
					//finde a random move
					i=rand()%3;
					c=rand()%3;
					//if the move are invalid keep trying until you find a valid move
					while (mesa[i][c]!='.'){
						i=rand()%3;
						c=rand()%3;
					}
					mesa[i][c] = 'o';

				}

				//print game table
				system("cls");
				for (i=0;i<3;i++){
					for(c=0;c<3;c++){
						printf("%c  ",mesa[i][c]);
					}
					printf("\n");
				}

				//checks if the computer has won
				if(verifica(mesa,'o')=='s'){
					printf("Perdeu :(\n");
					printf("quer voltar a jogar? (s/n)");
					scanf(" %c",&simnao);
					if(simnao=='s'){
						inicializar(mesa);//initialise table with "."
						ciclo = 1;
						break;
					}
					else if(simnao=='n'){
						return;
					}
				}
			}			
		}
	} while (ciclo == 1);	
}

//jogar contra o pc com jogadas aleatorias	
void computadorfacil(char mesa[3][3],char nome1[61]){
	int jogada=0;
	int i=0;
	int c=0;
	char simnao;
	int ciclo = 0;
	
	

	do{

		system("cls");
		//print game table
		for(i=0;i<3;i++){
			for(c=0;c<3;c++){
				printf("%c  ",mesa[i][c]);
			}
			printf("\n");
		}
	
		for(jogada=1;jogada<11;jogada++){
		
			
			//If the game reaches this point, it will be tied.
			if(jogada == 10){ 
				printf("voce empatou mais sorte da proxima :(\n");
				printf("quer voltar a jogar? (s/n) ");//Ask the players if they want to play again.
				scanf(" %c",&simnao);
				if(simnao=='s'){//if the players wants to play again
					inicializar(mesa);//initialise table with "."
					ciclo = 1;
					break;
				}
				else if(simnao=='n'){//if the players didn't want to play again
					return;
				}
			}
		
			else if (jogada%2 == 1){//this condition find if "jogada" is a odd number
				printf("%s onde quer jogar?\n",nome1);
				scanf("%d",& i);
				scanf("%d",& c);
				
				//check if the move is valid
				while(i>3 || c>3 || i<1 ||c<1){
					printf("jogada invalida tente jogar dentro do tabuleiro \n");
					scanf("%d",& i);
					scanf("%d",& c);
				}
				while(mesa[i-1][c-1]=='x' || mesa[i-1][c-1]=='o'){
					printf("jogada invalida tente outra \n");
					scanf("%d",& i);
					scanf("%d",& c);	
				}
				
				//save the move in the matrix
				mesa[i-1][c-1]='x';
				
				//show game table
				system("cls");
				for (i=0;i<3;i++){
					for(c=0;c<3;c++){
						printf("%c  ",mesa[i][c]);
					}
					printf("\n");
				}	
				
				//verify if the player won
				if(verifica(mesa,'x')=='s'){
					printf("%s, Ganhou :)\n",nome1);
					printf("quer voltar a jogar? (s/n)");//Ask the players if they want to play again.
					scanf(" %c",&simnao);
					if(simnao=='s'){//if the players wants to play again
						inicializar(mesa);//initialise table with "."
						ciclo = 1;
						break;
					}
					else if(simnao=='n'){//if the players didn't want to play again
						return;
					}
				}
				
			}

				
			//computer turns
			else if(jogada %2 == 0){//this condition find if "jogada" is a pair number

				//define a seed based on data time
				srand ( time(0) );
				//finde a random move
				i=rand()%3;
				c=rand()%3;
				//if the move are invalid keep trying until you find a valid move
				while (mesa[i][c]!='.'){
					i=rand()%3;
					c=rand()%3;
				}

				//save the move in the matrix
				mesa[i][c] = 'o';

				//show game table
				system("cls");
				for (i=0;i<3;i++){
						for(c=0;c<3;c++){
							printf("%c  ",mesa[i][c]);
						}
						printf("\n");
					}

				//checks if the computer has won
				if(verifica(mesa,'o')=='s'){
					printf("Perdeu :(\n");
					printf("quer voltar a jogar? (s/n)");
					scanf(" %c",&simnao);
					if(simnao=='s'){
						inicializar(mesa);//initialise table with "."
						ciclo = 1;
						break;
					}
					else if(simnao=='n'){
						return;
					}
				}
			}			
		}
	} while (ciclo == 1);	
}
