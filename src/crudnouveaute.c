#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction pour afficher les nouveautés lors de la connexion de l'admin
void afficherNouveautes()
{
    FILE *file = fopen("nouveautes.txt", "r"); // Ouvrir le fichier contenant les nouveautés
    if (file == NULL)
    {
        printf("Erreur d'ouverture du fichier des nouveautés.\n");
        return;
    }

    char ligne[500]; // Buffer pour lire chaque ligne
    printf("\n--- Nouveautés de l'école ---\n");
    while (fgets(ligne, sizeof(ligne), file))
    {                        // Lire ligne par ligne
        printf("%s", ligne); // Afficher chaque nouveauté
    }

    fclose(file); // Fermer le fichier
}

// Fonction pour ajouter une nouveauté (gérée par l'admin)
void ajouterNouveaute()
{
    char nouveaute[500];
    FILE *file = fopen("nouveautes.txt", "a"); // Ouvrir en mode ajout (append)

    if (file == NULL)
    {
        printf("Erreur d'ouverture du fichier des nouveautés.\n");
        return;
    }

    printf("Entrez la nouveauté à ajouter :\n");
    getchar();                                  // Pour vider le buffer après un scanf
    fgets(nouveaute, sizeof(nouveaute), stdin); // Lire la nouveauté

    fprintf(file, "%s\n", nouveaute); // Ajouter la nouveauté au fichier
    fclose(file);

    printf("Nouveauté ajoutée avec succès.\n");
}
