/**
* @file version1.c
* @brief Première version d'un snake destiné à la SAE1.01
* @author Aubrée Henri
* @version Version 1
* @date 15 octobre 2024
*
* <description plus complète du programme>
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>

#define N 10
#define TAILLE 30

void gotoXY(int x, int y);
int kbhit();
void afficher(int x, int y, char c);
void effacer(int x, int y);
void dessineSerpent(int laPosition[N][2]);
void progresser(int laPosition[N][2]);

int main() {

    // int positions[2][N];
	char p, feur;

	p = 'a';

	/*

    printf("Veuillez donner la position x de la tête : ");
    scanf("%d", &positions[0][0]);
    printf("Veuillez donner la position y de la tête : ");
    scanf("%d", &positions[0][1]);
	*/
    
	while (1) {
		printf("%c\n", p);
		sleep(1);
		p++;
		if (kbhit)
	}

    return EXIT_SUCCESS;
}

void afficher(int x, int y, char c) {
    gotoXY(x, y);
    printf("%c", c);
}

void gotoXY(int x, int y) { 
    printf("\033[%d;%df", y, x);
}

int kbhit(){
	// la fonction retourne :
	// 1 si un caractere est present
	// 0 si pas de caractere present
	
	int unCaractere=0;
	struct termios oldt, newt;
	int ch;
	int oldf;

	// mettre le terminal en mode non bloquant
	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
	ch = getchar();

	// restaurer le mode du terminal
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);
 
	if(ch != EOF){
		ungetc(ch, stdin);
		unCaractere=1;
	} 
	return unCaractere;
}
