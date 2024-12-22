#include "include/crudetudant.h"
#include "include/crudclasse.h"
#include "include/crudnouveaute.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menuadmin()
{
    char tabchoix[4][15] = {"Etudiant", "Classe", "Nouveauté", "Profile"};
    int choix;

    do
    {
        // Afficher le menu
        printf("Sélectionnez votre choix : \n");
        for (int i = 0; i < 4; i++)
        {
            printf("%d - Gérer %s \n", i + 1, tabchoix[i]);
        }
        printf("0 - QUITTER\n");

        // Vérifier l'entrée utilisateur
        if (scanf("%d", &choix) != 1)
        {
            // Gérer les entrées invalides
            printf("Entrée invalide, veuillez entrer un numéro valide.\n");
            while (getchar() != '\n')
                ; // Vider le buffer
        }
    } while (choix < 0 || choix > 4); // Valider le choix

    // Effectuer l'action selon le choix de l'utilisateur
    switch (choix)
    {
    case 1:
        crudEtudiant(); // Gérer les étudiants
        break;

    case 2:
        crudClasse(); // Gérer les classes
        break;

    case 3:
        crudNouveaute(); // Gérer les nouveautés
        break;

    case 4:
        printf("Gestion du profil non implémentée.\n"); // Placeholder pour le profil
        break;

    case 0:
        printf("Au revoir.\n"); // Quitter
        break;

    default:
        break;
    }
}
