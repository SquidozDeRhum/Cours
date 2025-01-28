#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MAXREF 21
#define INITDATE 1

#define ENTER 1
#define SELL 2
#define TIME 3
#define STOP 0

#define EXPIRY 3

typedef char chaine10[11] ;

typedef struct{
    chaine10 reference;
    int dateEntStock;
} produit;

typedef struct{
    produit tabElts[MAX];
    int nbElts;
}t_file;

const produit ELT_VIDE = {"NUL", -1};

// Fonction de gestion de produits

void saisir(produit *adr_prod, int dateJ);
void afficher(produit prod);

// Fonction de gestion de la file

int estVide(t_file *f);
int estPleine(t_file *f);
void enfiler(t_file* adrFile, produit elt);
produit defiler(t_file* adrFile);
t_file initialiser();
void vider(t_file *adrFile);

// Fonction IO
void enter(t_file *f);
void sell(t_file *f);
void modifdate();

// Menu
int menu();

int dateJ = INITDATE;

int main() {
    int choice = menu();
    t_file pile = initialiser();

    while (choice != STOP)
    {
        switch (choice)
        {
        case ENTER:
            enter(&pile);
            break;

        case SELL:
            sell(&pile);
            break;

        case TIME:
            modifdate();
            printf("Jour actuel : %d\n", dateJ);
            break;
        
        default:
            printf("Erreur de saisie\n\n");
            break;
        }
        choice = menu();
    }

    printf("Fin du programme\n");

    return EXIT_SUCCESS;
}

// Fonction de gestion de produits

void saisir(produit *adr_prod, int dateJ){
    // met dans *adr_prod un produit saisi au clavier à la date dateJ
    printf("référence ?\n");
    scanf("%s",adr_prod->reference);
    adr_prod->dateEntStock=dateJ;
}
void afficher(produit prod){
    // affiche à l'écran le produit prod
    printf("%s %d\n",prod.reference,prod.dateEntStock);
}

void modifdate(){
    //tourne la page de l'éphéméride
    dateJ++;
}

// Fonction de gestion de la file

int estVide(t_file *f) { // p : paramètre formel en entrée
    return (f->nbElts == 0);
}

int estPleine(t_file *f) {
    return (f->nbElts == MAX);
}

void enfiler(t_file *adrFile, produit elt){
    if (!estPleine(adrFile)) {
        adrFile->tabElts[adrFile->nbElts]=elt ; // affectation globale
        (adrFile->nbElts)++;
        // Attention aux indices du tableau
    }
    else{
        printf("La pile est pleine");
    }
}

produit defiler(t_file *adrFile){
    produit elt;
    if (!(estVide(adrFile))) {
        elt = adrFile-> tabElts[0];
        (adrFile-> nbElts)--;
        //Décalage de tous les autres éléments de la file
        for (int i = 1; i <= adrFile->nbElts; i++) {
            adrFile->tabElts[i - 1] = adrFile->tabElts[i];
        }
    }
    else{
        elt = ELT_VIDE;
    }
    return elt;
}

t_file initialiser() {
    t_file f;
    for (int i=0; i<MAX; i++)
    f.tabElts[i] = ELT_VIDE; // tous les éléments de la pile sont initialisés
    f.nbElts=0 ;
    return f;
}

void vider(t_file *adrFile){
    while (adrFile->nbElts >0){
        (adrFile->nbElts)-- ;
        adrFile->tabElts[adrFile->nbElts-1] = ELT_VIDE; //à définir
    }
}

int menu() {
    int choice;
    printf("Logiciel de gestion de stock\n");
    printf("1) Entrée d'un produit dans le stock\n");
    printf("2) Vente d'un produit sorti du stock\n");
    printf("3) Le temps passe\n");
    printf("0) Quitter\n");
    printf("Votre choix : ");
    scanf("%d", &choice);
    printf("\n");
    return choice;
}

void enter(t_file *f) {
    produit prod;

    if (!estPleine(f)) {
        saisir(&prod, dateJ);
        printf("Opération effectuée\n\n");
        enfiler(f, prod);
    } else {
        printf("La pile est pleine\n\n");
    }

}

void sell(t_file *f) {
    produit prod;

    if (!estVide(f)) {
        prod = defiler(f);
        if (prod.dateEntStock < dateJ - EXPIRY) {
            printf("Produit '%s' périmé, date produit : %d, date du jour : %d\n\n", prod.reference, prod.dateEntStock, dateJ);
        } else {
            printf("Produit '%s' valide, date produit : %d, date du jour : %d\n\n", prod.reference, prod.dateEntStock, dateJ);
        }
    } else {
        printf("La pile est vide\n\n");
    }

}