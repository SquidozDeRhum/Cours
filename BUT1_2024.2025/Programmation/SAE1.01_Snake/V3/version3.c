/**
 * @file version3.c
 * @brief Troisième version d'un snake destiné à la SAE1.01
 * @author Aubrée Henri
 * @version 1.0
 * @date 15 octobre 2024
 *
 * Ce programme permet à l'utilisateur de saisir les coordonnées X et Y de la tête du serpent,
 * puis affiche et fait avancer le serpent vers la droite.
 */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <time.h>

#define N 10                            /** Nombre de segments du serpent */
#define ARRET 'a'                       /** Caractère pour arrêter le jeu */
#define MIN 1                           /** Valeur minimale des coordonnées */
#define MAX 40                          /** Valeur maximale des coordonnées */
#define LARGEUR 80                      /** Largeur du plateau de jeu (nombre de colonnes). */
#define HAUTEUR 40                      /** Hauteur du plateau de jeu (nombre de lignes). */
#define HAUT 'z'                        /** Touche de déplacement haut */
#define BAS 's'                         /** Touche de déplacement bas */   
#define GAUCHE 'q'                      /** Touche de déplacement gauche */
#define DROITE 'd'                      /** Touche de déplacement droit */
#define TEMPORISATION 100000            /** Temps entre chaque déplacement (en microsecondes)*/
#define X_INIT 40                       /** Position X initiale du serpent */
#define Y_INIT 20                       /** Position Y initiale du serpent */
#define BORD '#'                        /** Caractère représentant les bordures du plateau. */
#define VIDE ' '                        /** Caractère représentant une case vide du plateau. */
#define TAILLE_PAVE 5                   /** Taille d'un obstacle carré sur le plateau. */
#define NOMBRE_PAVE 5                   /** Nombre d'obstacles générés sur le plateau. */
#define ESPACEMENT_PAVE_BORD_UN 2       /** Espace minimal entre les obstacles et les bordures. */
#define ESPACEMENT_PAVE_BORD_DEUX 3     /** Espace maximal pour placer les obstacles. */
#define ESPACEMENT_PAVE_SERPENT 3       /** Distance minimale entre les obstacles et le serpent. */

/**
 * @brief Déplace le curseur à la position spécifiée dans la console.
 * @param x La position horizontale
 * @param y La position verticale
 */
void gotoXY(int x, int y);

/**
 * @brief Vérifie si une touche a été pressée.
 * @return 1 si une touche est pressée, 0 sinon
 */
int kbhit();

/**
 * @brief Affiche un caractère à la position spécifiée.
 * @param x La position horizontale
 * @param y La position verticale
 * @param c Le caractère à afficher
 */
void afficher(int x, int y, char c);

/**
 * @brief Efface le caractère à la position spécifiée.
 * @param x La position horizontale
 * @param y La position verticale
 */
void effacer(int x, int y);

/**
 * @brief Dessine le serpent à partir de ses positions dans la grille.
 * @param laPosition Tableau contenant les coordonnées des segments du serpent
 */
void dessineSerpent(int laPosition[N][2]);

/**
 * @brief Fait avancer le serpent dans la direction donnée, en mettant à jour ses coordonnées.
 *        Vérifie également si le serpent entre en collision avec les murs ou lui-même.
 * @param laPosition Tableau contenant les coordonnées actuelles des segments du serpent.
 * @param direction La direction dans laquelle le serpent doit avancer ('z', 's', 'q', 'd').
 * @param collision Pointeur vers un entier signalant une collision (1 si collision, 0 sinon).
 */
void progresser(int laPosition[N][2], char direction, int *collision);

/**
 * @brief Désactive l'affiche des saisies
 */
void disableEcho();

/**
 * @brief Active l'affiche des saisies
 */
void enableEcho();

/**
 * @brief Fonction principale du programme.
 * Demande les coordonnées initiales du serpent, l'affiche, et le fait avancer jusqu'à l'arrêt du jeu.
 */

/**
 * @brief Initialise le plateau de jeu avec les bordures et les obstacles.
 * @param tableau Tableau représentant le plateau de jeu.
 */
void initPlateau(char tableau[HAUTEUR][LARGEUR]);

/**
 * @brief Affiche le plateau de jeu à l'écran.
 * @param tableau Tableau contenant les éléments à afficher sur le plateau.
 */
void dessinePlateau(char tableau[HAUTEUR][LARGEUR]);

char tableau[HAUTEUR][LARGEUR]; //Tableau à double entrées représentant le plateau de jeu

int main() {
    int positions[N][2];
    char pressed_car;
	char direction = DROITE;
    int collision = 0;

    srand(time(NULL));

    initPlateau(tableau);

    printf("Snake Version 2\n");
    positions[0][0] = X_INIT;
    positions[0][1] = Y_INIT;

    disableEcho();

    dessinePlateau(tableau);

    for (int i = 1; i < N; i++) {
        positions[i][0] = positions[i - 1][0] - 1;
        positions[i][1] = positions[0][1];
    }

    while (pressed_car != ARRET && collision != 1) {
        progresser(positions, direction, &collision);
        usleep(TEMPORISATION);
        if (kbhit()) { // Récupération du caractère pressé
            scanf("%c", &pressed_car);

			switch (pressed_car)
			{
			case HAUT:
				if (direction != BAS) {
					direction = HAUT;
				}
				break;
			case BAS:
				if (direction != HAUT) {
					direction = BAS;
				}
				break;
			case GAUCHE:
				if (direction != DROITE) {
					direction = GAUCHE;
				}
				break;
			case DROITE:
				if (direction != GAUCHE) {
					direction = DROITE;
				}
				break;
			}
        }
    }
    
    system("clear");
    enableEcho();
    return EXIT_SUCCESS;
}

void disableEcho() {
    struct termios tty;

    // Obtenir les attributs du terminal
    if (tcgetattr(STDIN_FILENO, &tty) == -1) {
        perror("tcgetattr");
        exit(EXIT_FAILURE);
    }

    // Desactiver le flag ECHO
    tty.c_lflag &= ~ECHO;

    // Appliquer les nouvelles configurations
    if (tcsetattr(STDIN_FILENO, TCSANOW, &tty) == -1) {
        perror("tcsetattr");
        exit(EXIT_FAILURE);
    }
}

void enableEcho() {
    struct termios tty;

    // Obtenir les attributs du terminal
    if (tcgetattr(STDIN_FILENO, &tty) == -1) {
        perror("tcgetattr");
        exit(EXIT_FAILURE);
    }

    // Reactiver le flag ECHO
    tty.c_lflag |= ECHO;

    // Appliquer les nouvelles configurations
    if (tcsetattr(STDIN_FILENO, TCSANOW, &tty) == -1) {
        perror("tcsetattr");
        exit(EXIT_FAILURE);
    }
}

int kbhit() {
    int unCaractere = 0;
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        unCaractere = 1;
    }
    return unCaractere;
}

void gotoXY(int x, int y) {
    printf("\033[%d;%df", y, x);
}

void afficher(int x, int y, char c) {
    gotoXY(x + 1, y + 1);
    printf("%c", c);
}

void dessineSerpent(int laPosition[N][2]) {
    for (int i = 1; i < N; i++) {
        if (laPosition[i][0] >= MIN && laPosition[i][1] >= MIN) {
            afficher(laPosition[i][0], laPosition[i][1], 'X');
        }
    }
    if (laPosition[0][0] >= MIN && laPosition[0][1] >= MIN) {
        afficher(laPosition[0][0], laPosition[0][1], 'O');  
    }
    fflush(stdout);
}

void progresser(int laPosition[N][2], char direction, int *collision) {

    // Déplacement des segments
    for (int i = N - 1; i > 0; i--) {
        laPosition[i][0] = laPosition[i - 1][0];
        laPosition[i][1] = laPosition[i - 1][1];
    }

    // Mise à jour de la position de la tête en fonction de la direction choisie.
    switch (direction) {
        case HAUT:
            laPosition[0][1]--;
            break;
        case BAS:
            laPosition[0][1]++;
            break;
        case GAUCHE:
            laPosition[0][0]--;
            break;
        case DROITE:
            laPosition[0][0]++;
            break;
    }


    // Réaffiche le serpent après mise à jour des positions.
    dessineSerpent(laPosition);

    // Vérification de collision avec les murs.
    if (tableau[laPosition[0][1]][laPosition[0][0]] == BORD) {
        *collision = 1;
    }

    // Vérification de collision avec lui-même.
    for (int i = 1; i < N; i++) {
        if (laPosition[i][0] == laPosition[0][0] && laPosition[i][1] == laPosition[0][1]) {
            *collision = 1;
        }
    }
    // Efface l'affichage du dernier segment.
    effacer(laPosition[N - 1][0], laPosition[N - 1][1]);
}


void effacer(int x, int y) {
    afficher(x, y, ' ');
}

void initPlateau(char tableau[HAUTEUR][LARGEUR]) {
    int x_pave, y_pave;
    for (int i = 0; i < LARGEUR; i ++) {
        tableau[0][i] = BORD;
    }
    for (int i = 1; i < HAUTEUR - 1; i++) {
        tableau[i][0] = BORD;
        tableau[i][LARGEUR - 1] = BORD;
        for (int p = 1; p < LARGEUR - 1; p ++) {
            tableau[i][p] = VIDE;
        }
    }
    for (int i = 0; i < LARGEUR; i++) {
        tableau[HAUTEUR - 1][i] = BORD;
    }
    for (int i = 0; i < NOMBRE_PAVE; i++) {
        do {
            x_pave = rand() % (LARGEUR - TAILLE_PAVE - ESPACEMENT_PAVE_BORD_DEUX) + ESPACEMENT_PAVE_BORD_UN;
        } while ((x_pave > X_INIT - TAILLE_PAVE - N - ESPACEMENT_PAVE_SERPENT && x_pave < X_INIT + ESPACEMENT_PAVE_SERPENT));
        do {
            y_pave = rand() % (HAUTEUR - TAILLE_PAVE - ESPACEMENT_PAVE_BORD_DEUX) + ESPACEMENT_PAVE_BORD_UN;
        } while ((y_pave > Y_INIT - TAILLE_PAVE - ESPACEMENT_PAVE_SERPENT && y_pave < Y_INIT + ESPACEMENT_PAVE_SERPENT));
        for (int l = x_pave; l < x_pave + TAILLE_PAVE; l++) {
            for (int h = y_pave; h < y_pave + TAILLE_PAVE; h++) {
                tableau[h][l] = BORD;
            }
        }
    }
}

void dessinePlateau(char tableau[HAUTEUR][LARGEUR]) {
    system("clear");
    for (int i = 0; i < HAUTEUR; i ++) {
        for (int p = 0; p < LARGEUR; p++) {
            afficher(p, i, tableau[i][p]);
        }
    }
}