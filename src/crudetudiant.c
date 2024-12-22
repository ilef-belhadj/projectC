#include "crudetudant.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour représenter un étudiant
typedef struct
{
    int id;
    char nom[50];
    char prenom[50];
    int age;
    char classe[20];
} Etudiant;

// Fonction pour créer un nouvel étudiant
void creerEtudiant()
{
    Etudiant etudiant;
    FILE *file = fopen("etudiants.txt", "a");
    if (file == NULL)
    {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    printf("Entrez l'ID de l'étudiant : ");
    scanf("%d", &etudiant.id);
    printf("Entrez le nom de l'étudiant : ");
    scanf("%s", etudiant.nom);
    printf("Entrez le prénom de l'étudiant : ");
    scanf("%s", etudiant.prenom);
    printf("Entrez l'âge de l'étudiant : ");
    scanf("%d", &etudiant.age);
    printf("Entrez la classe de l'étudiant : ");
    scanf("%s", etudiant.classe);

    fprintf(file, "%d %s %s %d %s\n", etudiant.id, etudiant.nom, etudiant.prenom, etudiant.age, etudiant.classe);
    fclose(file);

    printf("Étudiant ajouté avec succès.\n");
}

// Fonction pour afficher tous les étudiants
void afficherEtudiants()
{
    FILE *file = fopen("etudiants.txt", "r");
    if (file == NULL)
    {
        printf("Erreur d'ouverture du fichier ou fichier vide.\n");
        return;
    }

    Etudiant etudiant;
    printf("Liste des étudiants :\n");
    printf("ID\tNom\tPrenom\tAge\tClasse\n");
    printf("-----------------------------------------\n");
    while (fscanf(file, "%d %s %s %d %s", &etudiant.id, etudiant.nom, etudiant.prenom, &etudiant.age, etudiant.classe) != EOF)
    {
        printf("%d\t%s\t%s\t%d\t%s\n", etudiant.id, etudiant.nom, etudiant.prenom, etudiant.age, etudiant.classe);
    }
    fclose(file);
}

// Fonction pour modifier un étudiant
void modifierEtudiant()
{
    int id, trouve = 0;
    printf("Entrez l'ID de l'étudiant à modifier : ");
    scanf("%d", &id);

    FILE *file = fopen("etudiants.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (file == NULL || temp == NULL)
    {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    Etudiant etudiant;
    while (fscanf(file, "%d %s %s %d %s", &etudiant.id, etudiant.nom, etudiant.prenom, &etudiant.age, etudiant.classe) != EOF)
    {
        if (etudiant.id == id)
        {
            trouve = 1;
            printf("Entrez les nouvelles informations :\n");
            printf("Nom : ");
            scanf("%s", etudiant.nom);
            printf("Prenom : ");
            scanf("%s", etudiant.prenom);
            printf("Age : ");
            scanf("%d", &etudiant.age);
            printf("Classe : ");
            scanf("%s", etudiant.classe);
        }
        fprintf(temp, "%d %s %s %d %s\n", etudiant.id, etudiant.nom, etudiant.prenom, etudiant.age, etudiant.classe);
    }
    fclose(file);
    fclose(temp);

    remove("etudiants.txt");
    rename("temp.txt", "etudiants.txt");

    if (trouve)
    {
        printf("Étudiant modifié avec succès.\n");
    }
    else
    {
        printf("Étudiant non trouvé.\n");
    }
}

// Fonction pour supprimer un étudiant
void supprimerEtudiant()
{
    int id, trouve = 0;
    printf("Entrez l'ID de l'étudiant à supprimer : ");
    scanf("%d", &id);

    FILE *file = fopen("etudiants.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (file == NULL || temp == NULL)
    {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    Etudiant etudiant;
    while (fscanf(file, "%d %s %s %d %s", &etudiant.id, etudiant.nom, etudiant.prenom, &etudiant.age, etudiant.classe) != EOF)
    {
        if (etudiant.id != id)
        {
            fprintf(temp, "%d %s %s %d %s\n", etudiant.id, etudiant.nom, etudiant.prenom, etudiant.age, etudiant.classe);
        }
        else
        {
            trouve = 1;
        }
    }
    fclose(file);
    fclose(temp);

    remove("etudiants.txt");
    rename("temp.txt", "etudiants.txt");

    if (trouve)
    {
        printf("Étudiant supprimé avec succès.\n");
    }
    else
    {
        printf("Étudiant non trouvé.\n");
    }
}
