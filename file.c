/* La file */

/* FIFO */

struct pile 
{
    int valuer;
    struct pile *psvt;
}

struct file *ptete, *pqueue;

/* Creer la file */

ptete = NULL;
                /* La file existe et elle est vide */
pqueue = NULL;

/* EMPILER */

/* Si la file est vide */
if (ptete == NULL)
{
    ptete = pt;
    pqueue = pt;
}
/* Elle n'est pas vide */
else
{
    pqueue->psvt = pt;
    pqueue = pt;
}


/* DEFILER */
/* !!!!! On ne défile que si la file n'est pas vide */

if (ptete != NULL)
{
    pt = ptete;
    ptete = ptete->psvt OU ALORS ptete = pt->psvt;
    free(pt);
}
/* So la file est vide mettre pqueue à NULL (pqueue = NULL;)


/*Exercice */

struct file
{
    int valeur;
    struct file *psvt;
};

void enfiler(struct file **, struct file **, int);
int defiler(struct file **);

void main()
{
    struct file *ptete = NULL, *pqueue = NULL; /* a partir de ce moment la, la file existe et est vide */
    int nbre, i;

    for (i = 0; i < 5; i++)
    {
        scanf("%d", &nbre);
        enfiler(&ptete, &pqueue, int nbre);
    }
    while (ptete != NULL)
    {
        nbre = defiler(&ptete);
        printf("%d", nbre);

    }
    pqueue = NULL;
}

void enfiler(struct file **ptptete, struct file **ptpqueue, int nbre)
{
    struct file *pt = NULL;
    pt = (struct file *)malloc(sizeof(sizeof(struct file)));
    if (pt != NULL)
    {
        pt->valeur = nbre;
        pt->psvt = NULL;

        if (*ptete == NULL)
        {
            /* La file est vide */
            *ptptete = pt;
            *ptqueue = pt;

        }
        else
        {
            (*ptqueue)->psvt = pt;
            *ptpqueue = pt;
        }

    }
}

int defiler(struct file **ptptete)
{
    int val;
    struct file *pt;
    pt = *ptptete;
    val = pt->valeur;
    *ptptete = (*ptptete)->psvt OU ALORS *ptptete = pt->psvt;
    free(pt);
    return val;

}

/* Est-ce que on va voir le padding des struct ?*/
/* Pourquoi caster malloc, tout les adresses on la meme taille */
/*Pour enfile tout adresse, on peux utiliser void ? */