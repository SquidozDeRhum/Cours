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
void dessineSerpent(int laPosition[2][N]);
void progresser(int laPosition[2][N]);

int main() {

    int positions[2][N];
	int car;

    printf("Veuillez donner la position x de la tête : ");
    scanf("%d", &positions[0][0]);
    printf("Veuillez donner la position y de la tête : ");
    scanf("%d", &positions[0][1]);

	for (int i = 1; i < N; i++) {
		positions[i][0] = positions[i - 1][0] - 1;
		positions[i][1] = positions[0][1];
	}

	while (car != 'a')
	{
		progresser(positions);
		usleep(999999);
		if (kbhit()) {
			car = getchar();
		}
	}
	
	system("clear");
    return EXIT_SUCCESS;
}

void gotoXY(int x, int y) { 
    printf("\033[%d;%df", y, x);
}

void afficher(int x, int y, char c) {
    gotoXY(x, y);
    printf("%c", c);
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

void dessineSerpent(int laPosition[2][N]) {
	system("clear");
	for (int i = 1; i < N; i++) {
			if (laPosition[i][0] > 0 && laPosition[i][1] > 0) {
				afficher(laPosition[i][0], laPosition[i][1], 'o');
			}
		}
	afficher(laPosition[0][0], laPosition[0][1], '*');
	gotoXY(TAILLE, TAILLE);
	fflush(stdout);
}

void progresser(int laPosition[2][N]) {
	dessineSerpent(laPosition);
	for (int i = 0; i < N; i++) {
			laPosition[i][0]++;
	}
}
