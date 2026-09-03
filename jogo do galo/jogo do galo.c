#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char menu(char mesa[3][3]);
char inicializar(char mesa[3][3]);
char jogar(char mesa[3][3],char nome1[61],char nome2[61]);
char computadorimp(char mesa[3][3],char nome1[61]);
char computadorfacil(char mesa[3][3],char nome1[61]);

//where is the matrix is cleaned and the user chose game mode. 1x1/easy/hardcore
int main(int argc, char *argv[]) {
	
	char mesa[3][3];
	
	inicializar(mesa);
	
	menu(mesa);
	
	return 0;
}

//function to put "." in every matrix positions
char inicializar(char mesa[3][3]){
	int i=0;
	int c=0;
	char zero[1]={"a"};
	
	for(i=0;i<3;i++){
		for(c=0;c<3;c++){
			mesa[i][c] = '.' ;
		}
	}
}

//jogar 1vs1
char jogar(char mesa[3][3],char nome1[61],char nome2[61]){
	int i=0;
	int c=0;
	int jogada=0;
	
	system("cls");//clean screen
	
	//show playing table
	for(i=0;i<3;i++){
		for(c=0;c<3;c++){
			printf("%c  ",mesa[i][c]);
		}
		printf("\n");
	}
	
	//chose how starts the game
	for(jogada=1;jogada<10;jogada++){
		switch(jogada){
			
			case 1: 
			printf("%s onde quer jogar?\n",nome1);
			goto jogador1;
			
			case 2: 
			printf("%s onde quer jogar?\n",nome2);
			goto jogador2;
			
			case 3: 
			printf("%s onde quer jogar?\n",nome1);
			goto jogador1;
			
			case 4: 
			printf("%s onde quer jogar?\n",nome2);
			goto jogador2;
			
			case 5: 
			printf("%s onde quer jogar?\n",nome1);
			goto jogador1;
			
			case 6: 
			printf("%s onde quer jogar?\n",nome2);
			goto jogador2;
			
			case 7: 
			printf("%s onde quer jogar?\n",nome1);
			goto jogador1;
			
			case 8: 
			printf("%s onde quer jogar?\n",nome2);
			goto jogador2;
			
			case 9: 
			printf("%s onde quer jogar?\n",nome1);
			goto jogador1;
		}
	
	
	jogador1:
		scanf("%d",& i);
		scanf("%d",& c);
		
		//verify if the verifica se a jogada e dentro do tabuleiro e se esta disponivel o espaço para jogar
		if(i>3 || c>3 || i<1 ||c<1){
			printf("jogada invalida tente jogar dentro do tabuleiro \n");
			goto jogador1;
		}
		if(mesa[i-1][c-1]=='x' || mesa[i-1][c-1]=='o'){
			printf("jogada invalida tente outra \n");
			goto jogador1;
		}
		else{
			mesa[i-1][c-1]='x';
			system("cls");
			
			//mostrar a mesa
			for (i=0;i<3;i++){
				for(c=0;c<3;c++){
					printf("%c  ",mesa[i][c]);
				}
				printf("\n");
			}	
		}
		
		//verificar se ganhou
		if(mesa[0][0]=='x' && mesa[0][1]=='x' && mesa[0][2]=='x' || mesa[1][0]=='x' && mesa[1][1]=='x' && mesa[1][2]=='x' || mesa[2][0]=='x' && mesa[2][1]=='x' && mesa[2][2]=='x'){
			printf("%s ganhou",nome1);
			exit(0);
		}
		else if(mesa[0][0]=='x' && mesa[1][0]=='x' && mesa[2][0]=='x' || mesa[0][1]=='x' && mesa[1][1]=='x' && mesa[2][1]=='x' || mesa[0][2]=='x' && mesa[1][2]=='x' && mesa[2][2]=='x'){
			printf("%s ganhou",nome1);
			exit(0);
		}
		else if(mesa[0][0]=='x' && mesa[1][1]=='x' && mesa[2][2]=='x' || mesa[0][2]=='x' && mesa[1][1]=='x' && mesa[2][0]=='x'){
			printf("%s ganhou",nome1);
			exit(0);
		}
		
	goto inicio;
	
	jogador2:
		scanf("%d",& i);
		scanf("%d",& c);
		if(i>3 || c>3 || i<1 ||c<1){
			printf("jogada invalida tente jogar dentro do tabuleiro \n");
			goto jogador2;
		}
		if(mesa[i-1][c-1]=='x' || mesa[i-1][c-1]=='o'){
			printf("jogada invalida tente outra \n");
			goto jogador2;
		}
		else{
			mesa[i-1][c-1]= 'o';
			system("cls");
			
		//mostrar a mesa
			for (i=0;i<3;i++){
				for(c=0;c<3;c++){
					printf("%c  ",mesa[i][c]);
				}
				printf("\n");
			}
		}
		
		//verificar se ganhou
		if(mesa[0][0]=='o' && mesa[0][1]=='o' && mesa[0][2]=='o' || mesa[1][0]=='o' && mesa[1][1]=='o' && mesa[1][2]=='o' || mesa[2][0]=='o' && mesa[2][1]=='o' && mesa[2][2]=='o'){
			printf("%s ganhou",nome2);
			exit(0);
		}
		else if(mesa[0][0]=='o' && mesa[1][0]=='o' && mesa[2][0]=='o' || mesa[0][1]=='o' && mesa[1][1]=='o' && mesa[2][1]=='o' || mesa[0][2]=='o' && mesa[1][2]=='o' && mesa[2][2]=='o'){
			printf("%s ganhou",nome2);
			exit(0);
		}
		else if(mesa[0][0]=='o' && mesa[1][1]=='o' && mesa[2][2]=='o' || mesa[0][2]=='o' && mesa[1][1]=='o' && mesa[2][0]=='o'){
			printf("%s ganhou",nome2);
			exit(0);
		}
	
	inicio:	
		printf("\n");
}
}

//menu
char menu(char mesa[3][3]){
	int escolha=0;
	char nome1[61];
	char nome2[61];
	
	inicio:
		
	printf("1-jogar contra o computador(impossivel);\n2-jogar contra o computador(facil);\n3-jogar 1vs1;\n4-sair;\n");
	scanf("%d",& escolha);
	
	switch(escolha){
		case 1:
			printf("insira o seu nome: ");
  			scanf("%s",nome1);
			computadorimp(mesa,nome1);
		case 2:
			printf("insira o seu nome: ");
  			scanf("%s",nome1);
			computadorfacil(mesa,nome1);
		case 3:
			printf("jogador 1 insira o seu nome: ");
  			scanf("%s",nome1);
  
  	
  			printf("jogador 2 insira o seu nome: ");
  			scanf("%s",nome2);
  
	
			jogar(mesa,nome1,nome2);
		case 4:
			exit(0);
		default:
			printf("escolha uma opcao valida");
			sleep(1);
			system("cls");			
			goto inicio;		
			
	}
	
}

//jogar contra o pc em hard
char computadorimp(char mesa[3][3],char nome1[61]){
	int jogada=0;
	int i=0;
	int c=0;
	
	system("cls");
	//mostra a mesa
	for(i=0;i<3;i++){
		for(c=0;c<3;c++){
			printf("%c  ",mesa[i][c]);
		}
		printf("\n");
	}
	
	for(jogada=1;jogada<10;jogada++){
		switch(jogada){
			
			case 1: 
			printf("%s onde quer jogar?\n",nome1);
			goto jogador1;
			
			case 2: 
			if (mesa[0][0]=='x'){
				mesa[1][1]='o';
			}
			else if(mesa[0][2]=='x'){
				mesa[1][1]='o';
			}
			else if(mesa[2][2]=='x'){
				mesa[1][1]='o';
			}
			else if(mesa[2][0]=='x'){
				mesa[1][1]='o';
			}
			else if(mesa[1][1]=='x'){
				mesa[2][0]='o';
			}
			else if(mesa[0][1]=='x'){
				mesa[1][1]='o';
			}
			else if(mesa[1][0]=='x'){
				mesa[1][1]='o';
			}
			else if(mesa[1][2]=='x'){
				mesa[1][1]='o';
			}
			else if(mesa[2][1]=='x'){
				mesa[1][1]='o';
			}
			for (i=0;i<3;i++){
				for(c=0;c<3;c++){
					printf("%c  ",mesa[i][c]);
				}
				printf("\n");
			}			
			case 3: 
			printf("%s onde quer jogar?\n",nome1);
			goto jogador1;
			
			case 4: 
			goto jogador2;
			
			case 5: 
			printf("%s onde quer jogar?\n",nome1);
			goto jogador1;
			
			case 6: 
			goto jogador2;
			
			case 7: 
			printf("%s onde quer jogar?\n",nome1);
			goto jogador1;
			
			case 8: 
			goto jogador2;
			
			case 9: 
			printf("%s onde quer jogar?\n",nome1);
			goto jogador1;
		}
	
	
	
	jogador1:
		scanf("%d",& i);
		scanf("%d",& c);
		if(i>3 || c>3 || i<1 ||c<1){
			printf("jogada invalida tente jogar dentro do tabuleiro \n");
			goto jogador1;
		}
		if(mesa[i-1][c-1]=='x' || mesa[i-1][c-1]=='o'){
			printf("jogada invalida tente outra \n");
			goto jogador1;
		}
		else{
			mesa[i-1][c-1]='x';
			system("cls");
			//mostra a mesa
			for (i=0;i<3;i++){
				for(c=0;c<3;c++){
					printf("%c  ",mesa[i][c]);
				}
				printf("\n");
			}	
		}
		
		//verifica se ganhou
		if(mesa[0][0]=='x' && mesa[0][1]=='x' && mesa[0][2]=='x' || mesa[1][0]=='x' && mesa[1][1]=='x' && mesa[1][2]=='x' || mesa[2][0]=='x' && mesa[2][1]=='x' && mesa[2][2]=='x'){
			printf("%s ganhou",nome1);
			exit(0);
		}
		else if(mesa[0][0]=='x' && mesa[1][0]=='x' && mesa[2][0]=='x' || mesa[0][1]=='x' && mesa[1][1]=='x' && mesa[2][1]=='x' || mesa[0][2]=='x' && mesa[1][2]=='x' && mesa[2][2]=='x'){
			printf("%s ganhou",nome1);
			exit(0);
		}
		else if(mesa[0][0]=='x' && mesa[1][1]=='x' && mesa[2][2]=='x' || mesa[0][2]=='x' && mesa[1][1]=='x' && mesa[2][0]=='x'){
			printf("%s ganhou",nome1);
			exit(0);
		}
		
	goto fim;
	
	//vez do computador
	jogador2:
		
 	if(mesa[0][0]=='x' && mesa[0][1]=='x' && mesa[0][2]=='.')	{		//1linha
 		mesa[0][2]='o';
 		goto passa;
 	}
 	else if(mesa[0][0]=='x' && mesa[0][2]=='x' && mesa[0][1]=='.')	{
 		mesa[0][1]='o';
 		goto passa;
 	}
 	else if(mesa[0][1]=='x' && mesa[0][2]=='x' && mesa[0][0]=='.')	{
 		mesa[0][0]='o';
 		goto passa;
 	}
 	
 	//2linha
 	else if(mesa[1][0]=='x' && mesa[1][1]=='x')	{	
 		mesa[1][2]='o';
 		goto passa;
 	}
 	else if(mesa[1][0]=='x' && mesa[1][2]=='x')	{
 		mesa[1][1]='o';
 		goto passa;
 	}
 	else if(mesa[1][1]=='x' && mesa[1][2]=='x')	{
 		mesa[1][0]='o';
 		goto passa;
 	}
 	
 	//3linha
 	else if(mesa[2][0]=='x' && mesa[2][1]=='x')	{	
 		mesa[2][2]='o';
 		goto passa;
 	}
 	else if(mesa[2][0]=='x' && mesa[2][2]=='x')	{
 		mesa[2][1]='o';
 		goto passa;
 	}
 	else if(mesa[2][1]=='x' && mesa[2][2]=='x')	{
 		mesa[2][0]='o';
 		goto passa;
 	}
 	
 	//1coluna
 	else if(mesa[0][0]=='x' && mesa[1][0]=='x')	{	
 		mesa[2][0]='o';
 		goto passa;
 	}
 	else if(mesa[0][0]=='x' && mesa[2][0]=='x')	{
 		mesa[1][0]='o';
 		goto passa;
 	}
 	else if(mesa[1][0]=='x' && mesa[2][0]=='x')	{
 		mesa[0][0]='o';
 		goto passa;
 	}
 	
 	//2coluna
 	else if(mesa[0][1]=='x' && mesa[1][1]=='x')	{	 
 		mesa[2][1]='o';
 		goto passa;
 	}
 	else if(mesa[0][1]=='x' && mesa[2][1]=='x')	{
 		mesa[1][1]='o';
 		goto passa;
 	}
 	else if(mesa[1][1]=='x' && mesa[2][1]=='x')	{
 		mesa[0][1]='o';
 		goto passa;
 	}
 	
 	//3coluna
	else if(mesa[0][2]=='x' && mesa[1][2]=='x')	{	 
 		mesa[2][2]='o';
 		goto passa;
 	}
 	else if(mesa[0][2]=='x' && mesa[2][2]=='x')	{
 		mesa[1][2]='o';
 		goto passa;
 	}
 	else if(mesa[1][2]=='x' && mesa[2][2]=='x')	{
 		mesa[0][2]='o';
 		goto passa;
 	}
	 
	//diagonal1 
	else if(mesa[0][0]=='x' && mesa[1][1]=='x')	{	
 		mesa[2][2]='o';
 		goto passa;
 	}
 	else if(mesa[0][0]=='x' && mesa[2][2]=='x')	{
 		mesa[1][1]='o';
 		goto passa;
 	}
 	else if(mesa[1][1]=='x' && mesa[2][2]=='x')	{
 		mesa[0][0]='o';
 		goto passa;
 	}
	 
	//diagonal2 
	else if(mesa[0][2]=='x' && mesa[1][1]=='x')	{	
 		mesa[2][0]='o';
 		goto passa;
 	}
 	else if(mesa[0][2]=='x' && mesa[2][0]=='x')	{
 		mesa[1][1]='o';
 		goto passa;
 	}
 	else if(mesa[1][1]=='x' && mesa[2][0]=='x')	{
 		mesa[0][2]='o';
 		goto passa;
 	}
	
	srand ( time(0) );

	i=rand()%5+1;
		
if(i==1 && mesa[0][0]=='.') {
mesa[0][0]='o';
}

else if(i==1 && mesa[0][1]=='.') {
mesa[0][1]='o';
}

else if(i==1 && mesa[0][2]=='.') {
mesa[0][2]='o';
} 

else if(i==1 && mesa[1][0]=='.') {
mesa[1][0]='o';
}

else if(i==1 && mesa[1][1]=='.') {
mesa[1][1]='o';
}

else if(i==1 && mesa[1][2]=='.') {
mesa[1][2]='o';
}

else if(i==1 && mesa[2][0]=='.') {
mesa[2][0]='o';
}

else if(i==1 && mesa[2][1]=='.') {
mesa[2][1]='o';
}

else if(i==1 && mesa[2][2]=='.') {
mesa[2][2]='o';
}

//se sair o 2
else if(i==2 && mesa[0][1]=='.') {
mesa[0][1]='o';
}

else if(i==2 && mesa[2][0]=='.') {
mesa[2][0]='o';
}

else if(i==2 && mesa[0][2]=='.') {
mesa[0][2]='o';
} 

else if(i==2 && mesa[1][0]=='.') {
mesa[1][0]='o';
}

else if(i==2 && mesa[2][2]=='.') {
mesa[2][2]='o';
}

else if(i==2 && mesa[1][1]=='.') {
mesa[1][1]='o';
}

else if(i==2 && mesa[2][1]=='.') {
mesa[2][1]='o';
}

else if(i==2 && mesa[1][2]=='.') {
mesa[1][2]='o';
}

else if(i==2 && mesa[0][0]=='.') {
mesa[0][0]='o';
}

//se sair o 3
else if(i==3 && mesa[0][1]=='.') {
mesa[0][1]='o';
}

else if(i==3 && mesa[1][2]=='.') {
mesa[1][2]='o';
}

else if(i==3 && mesa[2][0]=='.') {
mesa[2][0]='o';
}

else if(i==3 && mesa[1][1]=='.') {
mesa[1][1]='o';
}

else if(i==3 && mesa[0][2]=='.') {
mesa[0][2]='o';
} 

else if(i==3 && mesa[0][0]=='.') {
mesa[0][0]='o';
}

else if(i==3 && mesa[2][2]=='.') {
mesa[2][2]='o';
}

else if(i==3 && mesa[1][0]=='.') {
mesa[1][0]='o';
}

else if(i==3 && mesa[2][1]=='.') {
mesa[2][1]='o';
}

//se sair o 4
else if(i==4 && mesa[0][0]=='.') {
mesa[0][0]='o';
}

else if(i==4 && mesa[1][2]=='.') {
mesa[1][2]='o';
}

else if(i==4 && mesa[2][0]=='.') {
mesa[2][0]='o';
}

else if(i==4 && mesa[1][0]=='.') {
mesa[1][0]='o';
}

else if(i==4 && mesa[2][1]=='.') {
mesa[2][1]='o';
}

else if(i==4 && mesa[1][1]=='.') {
mesa[1][1]='o';
}

else if(i==4 && mesa[0][2]=='.') {
mesa[0][2]='o';
}

else if(i==4 && mesa[0][1]=='.') {
mesa[0][1]='o';
} 

else if(i==4 && mesa[2][2]=='.') {
mesa[2][2]='o';
}

//se sair 5
else if(i==5 && mesa[1][1]=='.') {
mesa[1][1]='o';
}

else if(i==5 && mesa[0][2]=='.') {
mesa[0][2]='o';
} 

else if(i==5 && mesa[2][2]=='.') {
mesa[2][2]='o';
}

else if(i==5 && mesa[0][1]=='.') {
mesa[0][1]='o';
}

else if(i==5 && mesa[1][2]=='.') {
mesa[1][2]='o';
}

else if(i==5 && mesa[2][0]=='.') {
mesa[2][0]='o';
}

else if(i==5 && mesa[1][0]=='.') {
mesa[1][0]='o';
}

else if(i==5 && mesa[0][0]=='.') {
mesa[0][0]='o';
}

else if(i==5 && mesa[2][1]=='.') {
mesa[2][1]='o';
}

passa:
		
	for (i=0;i<3;i++){
				for(c=0;c<3;c++){
					printf("%c  ",mesa[i][c]);
				}
				printf("\n");
			}
			
	fim:		
		printf("\n");
}
}

//jogar contra o pc com jogadas aleatorias	
char computadorfacil(char mesa[3][3],char nome1[61]){
	int jogada=0;
	int i=0;
	int c=0;
	char simnao[1]={};
	
	system("cls");
	
	for(i=0;i<3;i++){
		for(c=0;c<3;c++){
			printf("%c  ",mesa[i][c]);
		}
		printf("\n");
	}
	
		for(jogada=1;jogada<11;jogada++){
		switch(jogada){
			
			case 1: 
			printf("%s onde quer jogar?\n",nome1);
			goto jogador1;
			
			case 2: 
			goto jogador2;
			
			case 3: 
			printf("%s onde quer jogar?\n",nome1);
			goto jogador1;
			
			case 4: 
			goto jogador2;
			
			case 5: 
			printf("%s onde quer jogar?\n",nome1);
			goto jogador1;
			
			case 6: 
			goto jogador2;
			
			case 7: 
			printf("%s onde quer jogar?\n",nome1);
			goto jogador1;
			
			case 8: 
			goto jogador2;
			
			case 9: 
			printf("%s onde quer jogar?\n",nome1);
			goto jogador1;
			
			case 10:
			printf("voce empatou mais sorte da proxima :(");
			printf("quer voltar ao menu? (s/n)");
			scanf("%s",&simnao);
			if(simnao[1]=='s'){
				menu(mesa);
			}
			else if(simnao[1]=='n'){
				exit(0);
			}
		}
	
	
	jogador1:
		scanf("%d",& i);
		scanf("%d",& c);
		if(i>3 || c>3 || i<1 ||c<1){
			printf("jogada invalida tente jogar dentro do tabuleiro \n");
			goto jogador1;
		}
		if(mesa[i-1][c-1]=='x' || mesa[i-1][c-1]=='o'){
			printf("jogada invalida tente outra \n");
			goto jogador1;
		}
		else{
			mesa[i-1][c-1]='x';
			system("cls");
			for (i=0;i<3;i++){
				for(c=0;c<3;c++){
					printf("%c  ",mesa[i][c]);
				}
				printf("\n");
			}	
		}
		
		//verificar se gahou
		
		if(mesa[0][0]=='x' && mesa[0][1]=='x' && mesa[0][2]=='x' || mesa[1][0]=='x' && mesa[1][1]=='x' && mesa[1][2]=='x' || mesa[2][0]=='x' && mesa[2][1]=='x' && mesa[2][2]=='x'){
			printf("%s ganhou",nome1);
			exit(0);
		}
		else if(mesa[0][0]=='x' && mesa[1][0]=='x' && mesa[2][0]=='x' || mesa[0][1]=='x' && mesa[1][1]=='x' && mesa[2][1]=='x' || mesa[0][2]=='x' && mesa[1][2]=='x' && mesa[2][2]=='x'){
			printf("%s ganhou",nome1);
			exit(0);
		}
		else if(mesa[0][0]=='x' && mesa[1][1]=='x' && mesa[2][2]=='x' || mesa[0][2]=='x' && mesa[1][1]=='x' && mesa[2][0]=='x'){
			printf("%s ganhou",nome1);
			exit(0);
		}
		
	goto inicio;
	//computador
	jogador2:
	srand ( time(0) );

	i=rand()%5+1;
		
if(i==1 && mesa[0][0]=='.') {
mesa[0][0]='o';
}

else if(i==1 && mesa[0][1]=='.') {
mesa[0][1]='o';
}

else if(i==1 && mesa[0][2]=='.') {
mesa[0][2]='o';
} 

else if(i==1 && mesa[1][0]=='.') {
mesa[1][0]='o';
}

else if(i==1 && mesa[1][1]=='.') {
mesa[1][1]='o';
}

else if(i==1 && mesa[1][2]=='.') {
mesa[1][2]='o';
}

else if(i==1 && mesa[2][0]=='.') {
mesa[2][0]='o';
}

else if(i==1 && mesa[2][1]=='.') {
mesa[2][1]='o';
}

else if(i==1 && mesa[2][2]=='.') {
mesa[2][2]='o';
}

//se sair o 2
else if(i==2 && mesa[0][1]=='.') {
mesa[0][1]='o';
}

else if(i==2 && mesa[2][0]=='.') {
mesa[2][0]='o';
}

else if(i==2 && mesa[0][2]=='.') {
mesa[0][2]='o';
} 

else if(i==2 && mesa[1][0]=='.') {
mesa[1][0]='o';
}

else if(i==2 && mesa[2][2]=='.') {
mesa[2][2]='o';
}

else if(i==2 && mesa[1][1]=='.') {
mesa[1][1]='o';
}

else if(i==2 && mesa[2][1]=='.') {
mesa[2][1]='o';
}

else if(i==2 && mesa[1][2]=='.') {
mesa[1][2]='o';
}

else if(i==2 && mesa[0][0]=='.') {
mesa[0][0]='o';
}

//se sair o 3
else if(i==3 && mesa[0][1]=='.') {
mesa[0][1]='o';
}

else if(i==3 && mesa[1][2]=='.') {
mesa[1][2]='o';
}

else if(i==3 && mesa[2][0]=='.') {
mesa[2][0]='o';
}

else if(i==3 && mesa[1][1]=='.') {
mesa[1][1]='o';
}

else if(i==3 && mesa[0][2]=='.') {
mesa[0][2]='o';
} 

else if(i==3 && mesa[0][0]=='.') {
mesa[0][0]='o';
}

else if(i==3 && mesa[2][2]=='.') {
mesa[2][2]='o';
}

else if(i==3 && mesa[1][0]=='.') {
mesa[1][0]='o';
}

else if(i==3 && mesa[2][1]=='.') {
mesa[2][1]='o';
}

//se sair o 4
else if(i==4 && mesa[0][0]=='.') {
mesa[0][0]='o';
}

else if(i==4 && mesa[1][2]=='.') {
mesa[1][2]='o';
}

else if(i==4 && mesa[2][0]=='.') {
mesa[2][0]='o';
}

else if(i==4 && mesa[1][0]=='.') {
mesa[1][0]='o';
}

else if(i==4 && mesa[2][1]=='.') {
mesa[2][1]='o';
}

else if(i==4 && mesa[1][1]=='.') {
mesa[1][1]='o';
}

else if(i==4 && mesa[0][2]=='.') {
mesa[0][2]='o';
}

else if(i==4 && mesa[0][1]=='.') {
mesa[0][1]='o';
} 

else if(i==4 && mesa[2][2]=='.') {
mesa[2][2]='o';
}

//se sair 5
else if(i==5 && mesa[1][1]=='.') {
mesa[1][1]='o';
}

else if(i==5 && mesa[0][2]=='.') {
mesa[0][2]='o';
} 

else if(i==5 && mesa[2][2]=='.') {
mesa[2][2]='o';
}

else if(i==5 && mesa[0][1]=='.') {
mesa[0][1]='o';
}

else if(i==5 && mesa[1][2]=='.') {
mesa[1][2]='o';
}

else if(i==5 && mesa[2][0]=='.') {
mesa[2][0]='o';
}

else if(i==5 && mesa[1][0]=='.') {
mesa[1][0]='o';
}

else if(i==5 && mesa[0][0]=='.') {
mesa[0][0]='o';
}

else if(i==5 && mesa[2][1]=='.') {
mesa[2][1]='o';
}

//mostrar mesa
for (i=0;i<3;i++){
				for(c=0;c<3;c++){
					printf("%c  ",mesa[i][c]);
				}
				printf("\n");
			}
			
	//verificar se ganhou	
		if(mesa[0][0]=='o' && mesa[0][1]=='o' && mesa[0][2]=='o' || mesa[1][0]=='o' && mesa[1][1]=='o' && mesa[1][2]=='o' || mesa[2][0]=='o' && mesa[2][1]=='o' && mesa[2][2]=='o'){
			printf("%s perdeu",nome1);
			exit(0);
		}
		else if(mesa[0][0]=='o' && mesa[1][0]=='o' && mesa[2][0]=='o' || mesa[0][1]=='o' && mesa[1][1]=='o' && mesa[2][1]=='o' || mesa[0][2]=='o' && mesa[1][2]=='o' && mesa[2][2]=='o'){
			printf("%s perdeu",nome1);
			exit(0);
		}
		else if(mesa[0][0]=='o' && mesa[1][1]=='o' && mesa[2][2]=='o' || mesa[0][2]=='o' && mesa[1][1]=='o' && mesa[2][0]=='o'){
			printf("%s perdeu",nome1);
			exit(0);
		}
	
	inicio:	
		printf("\n");
}
}
