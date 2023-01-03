#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element {
    int nombre;
    Element *suivant;
};

typedef struct Liste Liste;
struct Liste {
    Element *premier;
};

Liste *initialisation(void)
{
    Liste *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL) {
        exit(84);
    }
    element->nombre = 0;
    element->suivant = NULL;
    liste->premier = element;
    return liste;
}

void insertion(Liste *liste, int nvNombre)
{
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(84);
    }
    nouveau->nombre = nvNombre;
    nouveau->suivant = liste->premier;
    liste->premier = nouveau;
}

void suppression(Liste *liste)
{
    if (liste == NULL)
    {
        exit(84);
    }
    if (liste->premier != NULL)
    {
        Element *aSupprimer = liste->premier;
        liste->premier = liste->premier->suivant;
        free(aSupprimer);
    }
}

void afficherListe(Liste *liste)
{
    if (liste == NULL)
    {
        exit(84);
    }

    Element *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("%d -> ", actuel->nombre);
        actuel = actuel->suivant;
    }
    printf("NULL\n");
}

void remplir_liste(int list[], int size, Liste *liste)
{
    char str[3];
    for (int x = 0; x != size; ++x) {
        sprintf(str, "%d", list[x]);
        insertion(liste, atoi(str));
    }
}

int main(void)
{
    int list[] = {1, 2, 3};
    int size = sizeof(list) / sizeof(int);
    file_info_t *infos;
    Liste *maListe = initialisation();
    remplir_liste(list, size, maListe);
    afficherListe(maListe);
    return 0;
}
