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
}t_pile;

const produit ELT_VIDE = {"NUL", -1};

// Fonction de gestion de produits

void saisir(produit *adr_prod, int dateJ);
void afficher(produit prod);

// Fonction de gestion de la file

int estVide(t_pile *p);
int estPleine(t_pile *p);
void empiler(t_pile* adrPile, produit elt);
produit depiler(t_pile* adrPile);
t_pile initialiser();
void vider(t_pile *adrPile);
produit sommet(t_pile *p);

// Fonction IO
void enter(t_pile *p);
void sell(t_pile *p);
void modifdate();

// Menu
int menu();

int dateJ = INITDATE;

int main() {
    int choice = menu();
    t_pile pile = initialiser();

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

int estVide(t_pile *p) { // p : paramètre formel en entrée
    return (p->nbElts == 0);
}

int estPleine(t_pile *p) {
    return (p->nbElts == MAX);
}

void empiler(t_pile *adrPile, produit elt){
    if (!estPleine(adrPile)) {
        adrPile->tabElts[adrPile->nbElts]=elt ; // affectation globale
        (adrPile->nbElts)++;
        // Attention aux indices du tableau
    }
    else{
        printf("La pile est pleine");
    }
}

produit depiler(t_pile *adrPile){
    produit elt;
    if (!(estVide(adrPile))) {
        elt =adrPile-> tabElts[adrPile-> nbElts-1] ;
        (adrPile-> nbElts)--;
        // nettoyage de la pile
        adrPile->tabElts[adrPile-> nbElts] = ELT_VIDE;
    }
    else{
        elt = ELT_VIDE;
    }
    return elt;
}

t_pile initialiser() {
    t_pile p;
    for (int i=0; i<MAX; i++)
    p.tabElts[i] = ELT_VIDE; // tous les éléments de la pile sont initialisés
    p.nbElts=0 ;
    return p;
}

void vider(t_pile *adrPile){
    while (adrPile->nbElts >0){
        (adrPile->nbElts)-- ;
        adrPile->tabElts[adrPile->nbElts-1] = ELT_VIDE; //à définir
    }
}

produit sommet(t_pile *p) {
    produit elt;
    if (!(estVide(p))) {
        // le sommet de la pile est à l’indice p.nbElts - 1
        elt = p->tabElts[p->nbElts-1];
    }
    else{
        elt = ELT_VIDE; //à définir
    }
    return elt;
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

void enter(t_pile *p) {
    produit prod;

    if (!estPleine(p)) {
        saisir(&prod, dateJ);
        printf("Opération effectuée\n\n");
        empiler(p, prod);
    } else {
        printf("La pile est pleine\n\n");
    }

}

void sell(t_pile *p) {
    produit prod;

    if (!estVide(p)) {
        prod = depiler(p);
        if (prod.dateEntStock < dateJ - EXPIRY) {
            printf("Produit '%s' périmé, sortie de tous les autres produits\n\n", prod.reference);
            vider(p);
        } else {
            printf("Produit '%s' valide, date produit : %d, date du jour : %d\n\n", prod.reference, prod.dateEntStock, dateJ);
        }
    } else {
        printf("La pile est vide\n\n");
    }

}