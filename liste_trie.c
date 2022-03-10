
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