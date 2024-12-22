
#include "crudclasse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour représenter une classe
typedef struct
{
    int id;
    char nom[50];
    char niveau[20];
} Classe;

// Fonction pour ajouter une classe
void creerClasse()
{
    FILE *file = fopen("classes.txt", "a");
    if (!file)
    {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    Classe classe;
    printf("Entrez l'ID, Nom de la classe, Niveau (séparés par espace) : ");
    scanf("%d %s %s", &classe.id, classe.nom, classe.niveau);

    fprintf(file, "%d %s %s\n", classe.id, classe.nom, classe.niveau);
    fclose(file);
    printf("Classe ajoutée avec succès.\n");
}

// Fonction pour afficher toutes les classes
void afficherClasses()
{
    FILE *file = fopen("classes.txt", "r");
    if (!file)
    {
        printf("Aucune classe trouvée.\n");
        return;
    }

    Classe classe;
    printf("ID\tNom\tNiveau\n");
    printf("-------------------------\n");
    while (fscanf(file, "%d %s %s", &classe.id, classe.nom, classe.niveau) == 3)
    {
        printf("%d\t%s\t%s\n", classe.id, classe.nom, classe.niveau);
    }
    fclose(file);
}

// Fonction pour modifier une classe
void modifierClasse()
{
    int id, trouve = 0;
    printf("Entrez l'ID de la classe à modifier : ");
    scanf("%d", &id);

    FILE *file = fopen("classes.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!file || !temp)
    {
        printf("Erreur d'ouverture des fichiers.\n");
        return;
    }

    Classe classe;
    while (fscanf(file, "%d %s %s", &classe.id, classe.nom, classe.niveau) == 3)
    {
        if (classe.id == id)
        {
            trouve = 1;
            printf("Entrez le nouveau Nom de la classe et le Niveau (séparés par espace) : ");
            scanf("%s %s", classe.nom, classe.niveau);
        }
        fprintf(temp, "%d %s %s\n", classe.id, classe.nom, classe.niveau);
    }
    fclose(file);
    fclose(temp);

    remove("classes.txt");
    rename("temp.txt", "classes.txt");

    printf(trouve ? "Classe modifiée avec succès.\n" : "Classe non trouvée.\n");
}

// Fonction pour supprimer une classe
void supprimerClasse()
{
    int id, trouve = 0;
    printf("Entrez l'ID de la classe à supprimer : ");
    scanf("%d", &id);

    FILE *file = fopen("classes.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!file || !temp)
    {
        printf("Erreur d'ouverture des fichiers.\n");
        return;
    }

    Classe classe;
    while (fscanf(file, "%d %s %s", &classe.id, classe.nom, classe.niveau) == 3)
    {
        if (classe.id != id)
        {
            fprintf(temp, "%d %s %s\n", classe.id, classe.nom, classe.niveau);
        }
        else
        {
            trouve = 1;
        }
    }
    fclose(file);
    fclose(temp);

    remove("classes.txt");
    rename("temp.txt", "classes.txt");

    printf(trouve ? "Classe supprimée avec succès.\n" : "Classe non trouvée.\n");
}
