#include <stdio.h>
#include <stdlib.h>

// Fonction pour afficher les nouveautés à l'enseignant
void afficherNouveautesEnseignant()
{
    FILE *file = fopen("nouveautes.txt", "r");
    if (file == NULL)
    {
        printf("Aucune nouveauté trouvée ou erreur d'ouverture du fichier.\n");
        return;
    }

    printf("\n=== Nouveautés de l'école ===\n");
    char ligne[256];
    while (fgets(ligne, sizeof(ligne), file))
    {
        printf("- %s", ligne); // Chaque ligne représente une nouveauté
    }
    fclose(file);
    printf("\n");
}

// Fonction principale pour le profil de l'enseignant
void profilEnseignant()
{
    int choix;

    do
    {
        printf("\n=== Profil de l'enseignant ===\n");
        printf("1. Voir les nouveautés\n");
        printf("0. Quitter\n");
        printf("Entrez votre choix : ");
        if (scanf("%d", &choix) != 1)
        {
            printf("Entrée invalide, veuillez entrer un numéro valide.\n");
            while (getchar() != '\n')
                ; // Vider le buffer
            continue;
        }

        switch (choix)
        {
        case 1:
            afficherNouveautesEnseignant(); // Afficher les nouveautés
            break;

        case 0:
            printf("Retour au menu principal.\n");
            break;

        default:
            printf("Choix invalide. Réessayez.\n");
        }
    } while (choix != 0);
}
