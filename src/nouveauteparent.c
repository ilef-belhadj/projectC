#include <stdio.h>
#include <stdlib.h>

void afficherNouveautesParent()
{
    FILE *file = fopen("nouveautes.txt", "r");
    if (file == NULL)
    {
        printf("Erreur : Impossible d'ouvrir le fichier des nouveautés.\n");
        return;
    }

    char ligne[255];
    printf("---- Nouveautés pour les parents ----\n");
    while (fgets(ligne, sizeof(ligne), file))
    {
        printf("%s", ligne);
    }

    fclose(file);
    printf("------------------------------------\n");
}
