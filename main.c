/* La pile */
/*LIFO*/

struct pile{
    int valeur;
    struct pile* psvt;
};

struct pile *ppile; //Pointe vers le sommet de la pile

/* Première chose : créer la pile  : */
ppile = NULL; // A partir de ce moment la, la pile existe mais elle est vide

/* EMPILER : */
pt->psvt = ppile;
ppile = pt;

/* DEPILER */

/* ATTENTION : On dépile si l apile n'est pas valide (ppile != NULL)*/

pt = ppile;
ppile = ppile->psvt;

free(pt);   // Si on a plus besoin de laa zone mémoire pointé par pt;


/****************************************************************************/
/*                              FONCTION EMPILER                            */
/****************************************************************************/

struct pile{
    int valeur;
    struct pile *psvt;
}:

/*PROTOTYPE */
struct *EMPILER(int, struct pile*);     //Passage par valeur. Donc on doit retourner apres modification.
void Empile(int, struct pile **);       // Passage par addresse

/*Par valeur */

struct pile *empiler(int nbre, struct pile*ppile)
{
    struct pile *pt = NULL;
    pt = (struct pile *)malloc(sizeof(struct pile));
    if (pt != NULL)
    {
        pt->valeur = nbre;
        pt->psvt = ppile;
        ppile = pt;
    }
    else
    {
        printf("Erreur d'allocation\n");
    }

    return ppile;
}

/* Par addresse */

void empiler(int nbre, struct pile**ptppile)
{
    struct pile *pt = NULL;
    pt = (struct pile *)malloc(sizeof(struct pile));
    if (pt != NULL)
    {
        pt->valeur = nbre;
        pt->psvt = *ptppile;
       *ptppile = pt;
    }
    else
    {
        printf("Erreur d'allocation\n");
    }

}

void main()
{
    struct pile *ppile = NULL;
    int nbre;
    scanf("%d", &nbre);
    /* Par valeur */
    ppile = empiler(nbre, ppile);
    /* Par référence */
    empiler(nbre, &ppile);


}
