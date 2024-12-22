#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour représenter une absence
typedef struct
{
    int idEnseignant;
    char date[15];
    char motif[100];
} Absence;

// Fonction pour afficher les absences d'un enseignant spécifique
void afficherAbsencesEnseignant()
{
    int idEnseignant, trouve = 0;
    printf("Entrez votre ID d'enseignant : ");
    scanf("%d", &idEnseignant);

    FILE *file = fopen("absences.txt", "r");
    if (file == NULL)
    {
        printf("Aucune absence enregistrée pour le moment.\n");
        return;
    }

    Absence absence;
    printf("\n---- Vos absences ----\n");
    printf("Date        | Motif\n");
    printf("------------------------------\n");
    char ligne[200];
    while (fgets(ligne, sizeof(ligne), file))
    {
        sscanf(ligne, "%d|%[^|]|%[^\n]", &absence.idEnseignant, absence.date, absence.motif);
        if (absence.idEnseignant == idEnseignant)
        {
            trouve = 1;
            printf("%-12s | %s\n", absence.date, absence.motif);
        }
    }
    fclose(file);

    if (!trouve)
    {
        printf("Aucune absence trouvée pour votre ID.\n");
    }
}
