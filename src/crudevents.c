#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour représenter un événement
typedef struct
{
    int id;
    char titre[50];
    char date[15];
    char description[200];
} Evenement;

// Fonction pour créer un événement
void creerEvenement()
{
    Evenement event;
    FILE *file = fopen("evenements.txt", "a");
    if (file == NULL)
    {
        printf("Erreur : Impossible d'ouvrir le fichier des événements.\n");
        return;
    }

    printf("Entrez l'ID de l'événement : ");
    scanf("%d", &event.id);
    printf("Entrez le titre de l'événement : ");
    getchar(); // Consommer le caractère '\n' résiduel
    fgets(event.titre, sizeof(event.titre), stdin);
    strtok(event.titre, "\n"); // Supprimer le saut de ligne
    printf("Entrez la date de l'événement (format JJ/MM/AAAA) : ");
    scanf("%s", event.date);
    printf("Entrez une description de l'événement : ");
    getchar(); // Consommer le caractère '\n' résiduel
    fgets(event.description, sizeof(event.description), stdin);
    strtok(event.description, "\n"); // Supprimer le saut de ligne

    fprintf(file, "%d|%s|%s|%s\n", event.id, event.titre, event.date, event.description);
    fclose(file);

    printf("Événement ajouté avec succès.\n");
}

// Fonction pour afficher tous les événements
void afficherEvenements()
{
    FILE *file = fopen("evenements.txt", "r");
    if (file == NULL)
    {
        printf("Aucun événement à afficher pour le moment.\n");
        return;
    }

    Evenement event;
    printf("---- Liste des événements ----\n");
    printf("ID | Titre              | Date       | Description\n");
    printf("----------------------------------------------------\n");
    char ligne[300];
    while (fgets(ligne, sizeof(ligne), file))
    {
        sscanf(ligne, "%d|%[^|]|%[^|]|%[^\n]", &event.id, event.titre, event.date, event.description);
        printf("%d  | %-18s | %-10s | %s\n", event.id, event.titre, event.date, event.description);
    }
    fclose(file);
}

// Fonction pour supprimer un événement
void supprimerEvenement()
{
    int id, trouve = 0;
    printf("Entrez l'ID de l'événement à supprimer : ");
    scanf("%d", &id);

    FILE *file = fopen("evenements.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (file == NULL || temp == NULL)
    {
        printf("Erreur : Impossible d'ouvrir le fichier.\n");
        return;
    }

    Evenement event;
    char ligne[300];
    while (fgets(ligne, sizeof(ligne), file))
    {
        sscanf(ligne, "%d|%[^|]|%[^|]|%[^\n]", &event.id, event.titre, event.date, event.description);
        if (event.id == id)
        {
            trouve = 1;
        }
        else
        {
            fprintf(temp, "%s", ligne);
        }
    }
    fclose(file);
    fclose(temp);

    remove("evenements.txt");
    rename("temp.txt", "evenements.txt");

    if (trouve)
    {
        printf("Événement supprimé avec succès.\n");
    }
    else
    {
        printf("Aucun événement trouvé avec l'ID donné.\n");
    }
}
