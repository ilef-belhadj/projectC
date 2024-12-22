#include "crudevent.h"
#include "absencesenseignant.h"
#include <stdio.h>
#include <stdlib.h>

void menuEnseignant()
{
    int choix;

    do
    {
        printf("\n---- Menu Enseignant ----\n");
        printf("1 - Créer un événement\n");
        printf("2 - Afficher les événements\n");
        printf("3 - Supprimer un événement\n");
        printf("4 - Consulter vos absences\n");
        printf("0 - Quitter\n");
        printf("Votre choix : ");

        if (scanf("%d", &choix) != 1)
        {
            printf("Entrée invalide. Veuillez entrer un numéro.\n");
            while (getchar() != '\n')
                ; // Vider le buffer
            continue;
        }

        switch (choix)
        {
        case 1:
            creerEvenement();
            break;
        case 2:
            afficherEvenements();
            break;
        case 3:
            supprimerEvenement();
            break;
        case 4:
            afficherAbsencesEnseignant();
            break;
        case 0:
            printf("Au revoir !\n");
            break;
        default:
            printf("Choix invalide, veuillez réessayer.\n");
        }
    } while (choix != 0);
}
