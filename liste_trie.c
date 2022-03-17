
/* Liste Trié */

struct listt
{
    int valeur;
    struct liste *psvt;
};

struct listet *pliste;

/* Creer la liste */

pliste []-> NULL /* La liste existe et elle est vide */

/* INSERTION dans une liste triée */

struct listet *ptemp = NULL, *pt = NULL, *ptprec = NULL;

ptemp = (struct listet *)malloc(sizeof(struct listet));
ptemp->valeur = .....;

/* Si la liste est vide OU si le nouvel élément doit venir en 1ere position */
if (pliste == NULL || ptemp->valeur < pliste->valeur)
{
    ptemp->psvt = pliste;
    pliste = ptemp;
}
else
{
    pt = pliste;
    while (pt != NULL && ptemp->valeur > pt->valeur)
    {
        ptprec = pt;
        pt = pt->psvt;
    }
    ptprec->psvt = ptemp;
    ptemp->psvt = pt;

}

// 17 MARS


void main()
{
    struct listet *pliste = NULL, *pt = NULL;       // pliste [-]-> [8|-]->[15|-]->[37|-]->[51|-]->NULL
    int nbre;
    int trouve; // Va recevoir 0 ou 1, si trouver dans la fonction de recherche
    /* Insertion d'un entier dans la liste trié */

    /* Affichage de tout les entiers de la liste*/
    pt = pliste;
    while (pt != NULL)
    {
        printf("%d\n", pt->valeur);
        // pt doit changer pour pointer la prochaine valeur
        pt = pt->psvt;
    }
    /* Fin affichage valeur liste */

    /* recherche d'un entier dans la liste */

    scanf("%d", &nbre);
    trouve = Recherche(pliste, nbre);

    /* Code permettant de rechercher et supprimer un entier
     * si il est présent dnas la liste
     */

    scanf("%d", &nbre);
    suppression(&pliste);

}

/* Fonction de recherche */
/* Retourne "vrai l'entier est dans liste", 'faux l'entier n'est pas dans la liste */
/* Pas oublier que pliste est trié */
int Recherche(struct listet* pliste, int nbre)
{
    struct listet *pt = NULL; // Pas obligatoire car quand on retourne dans le main, pliste n'aura pas changer meme si on l'incremente ici.

    pt = pliste; // Mais pour être sur on travaille avec un pointeur de travail meme si comme dit, pas obligatoire

    while (pt != NULL && nbre > pt->valeur)
    {
        pt = pt->psvt;
    }

    if (pt != NULL && nbre == pt->valeur)   // Vérifier qu'on est toujours dans la liste car si pt == NULL et quon demande pt->valeur alors SegFault !
        return 1;   // Retourne 1 si trouve 
    
    return 0;   // Sinon on arrive ici et on a pas trouve l'entier recherché.
}   

/* fonction de suppression */
/* Comme pliste va etre changer, si on supprime le premier élément de pliste
 * Des le retour dans le main, ne changera pas d'adresse. Or, pliste devra changer d'adresse si on supp le 1er element
 * Si la fonction retourne qq chose, alors on devra dans le main ecrire : pliste = suppression();
 * Mais ici, certains prof exigent que la fonction retourne void. Donc on va passer un double pointeur
 */

void suppression(struct listet **, int);
void suppression(struct listet **ptpliste, int nbre)
{
    struct listet *pt = NULL, *ptprec = NULL; // ptprec doit obligatoirement etre à NULL

    pt = *ptpliste;
    while (pt != NULL && nbre > pt->valeur)
    {
        ptprec = pt;
        pt = pt->psvt;

    }

    /* On doit testet ptprec car imaginons que l'on veut supprimer le premier élément, 
     * La boucle précedente met prprec = pt. Mais si c'est le premier élément, on ne rentre pas dans la boucle
     * Par conséquent, ptprec = NULL et si on ne vérifie pas avec : if (ptprec == NULL), alors SegFault car on
     * demande : *ptpliste = pt->psvt mais comme ptprec->psvt n'existe pas, alors SegFault.
     */
    if (pt != NULL && nbre == pt->valeur)
    {
        if (ptprec == NULL) 
        {
            *ptpliste = pt->psvt;
        }
        else
            ptprec->psvt = pt->psvt;
    }

}