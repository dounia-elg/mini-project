#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char titres[200][100];
    char auteurs[200][100];
    float prix[200];
    int quantites[200];
    int nbr = 0;
    int choix , i , j ;
    char titreRecherche[100];
    
     while (1) {
        printf("\nMenu\n");
        printf("1. Ajouter un livre\n");
        printf("2. Afficher tous les livres\n");
        printf("3. Rechercher un livre par son titre\n");
        printf("4. Mettre à jour la quantité d'un livre\n");
        printf("5. Supprimer un livre\n");
        printf("6. Afficher le nombre total de livres en stock\n");
        printf("Choix : ");
         if (scanf("%d", &choix) != 1) {
            printf("Choix invalide. Veuillez entrer un nombre entier.\n");
            while (getchar() != '\n'); 
            continue;
        }
        getchar();
        
        switch (choix) {
            case 1:
                //Ajouter un Livre au Stock
                if (nbr >= 200) {
                    printf("Le stock est plein. Impossible d'ajouter un nouveau livre.\n");
                } else {
                    printf("Titre du livre : ");
                    fgets(titres[nbr], 100, stdin);
                    titres[nbr][strcspn(titres[nbr], "\n")] = '\0';

                    printf("Auteur du livre : ");
                    fgets(auteurs[nbr], 100, stdin);
                    auteurs[nbr][strcspn(auteurs[nbr], "\n")] = '\0';

                    printf("Prix du livre : ");
                    if (scanf("%f", &prix[nbr]) != 1 || prix[nbr] < 0) {
                        printf("entrer un nombre positif.\n");
                        while (getchar() != '\n'); 
                        break;
                    }
                    
                    printf("Quantite en stock : ");
                    if (scanf("%d", &quantites[nbr]) != 1 || quantites[nbr] < 0) {
                        printf("entrer un nombre entier positif.\n");
                        while (getchar() != '\n'); 
                        break;
                    }
                    getchar(); 

                    nbr++;
                }
                break;
                
                case 2:
                // Afficher Tous les Livres Disponibles
                if (nbr == 0) {
                    printf("Aucun livre dans le stock.\n");
                } else {
                    for (i=0; i < nbr; i++) {
                        printf("\nLivre %d\n", i + 1);
                        printf("Titre : %s\n", titres[i]);
                        printf("Auteur : %s\n", auteurs[i]);
                        printf("Prix : %.2f\n", prix[i]);
                        printf("Quantite en stock : %d\n", quantites[i]);
                    }
                }
                break;
                
                 case 3:
                // Rechercher un livre par son titre
                {
                    printf("Entrez le titre du livre à rechercher : ");
                    fgets(titreRecherche, 100, stdin);
                    titreRecherche[strcspn(titreRecherche, "\n")] = '\0'; 

                    int trouve = 0;
                    for (int i = 0; i < nbr; i++) {
                        if (strcmp(titres[i], titreRecherche) == 0) {
                            printf("\nLivre trouvé :\n");
                            printf("Titre : %s\n", titres[i]);
                            printf("Auteur : %s\n", auteurs[i]);
                            printf("Prix : %.2f\n", prix[i]);
                            printf("Quantite en stock : %d\n", quantites[i]);
                            trouve = 1;
                            break;
                        }
                    }
                    if (!trouve) {
                        printf("Livre non trouvé.\n");
                    }
                }
                break;
                
                case 4:
                //Mettre à Jour la Quantité d'un Livre
                {
                    printf("Entrez le titre du livre pour mettre à jour la quantité : ");
                    fgets(titreRecherche, 100, stdin);
                    titreRecherche[strcspn(titreRecherche, "\n")] = '\0';
                    int trouve = 0;
                    for (int i = 0; i < nbr; i++) {
                        if (strcmp(titres[i], titreRecherche) == 0) {
                            printf("Quantite actuelle : %d\n", quantites[i]);
                            printf("Entrez la nouvelle quantite : ");
                            if (scanf("%d", &quantites[i]) != 1 || quantites[i] < 0) {
                                printf("entrer un nombre entier positif.\n");
                                while (getchar() != '\n');
                            }
                            getchar();
                            trouve = 1;
                            break;
                        }
                    }
                    if (!trouve) {
                        printf("Livre non trouvé.\n");
                    }
                }
                break;
                
                case 5:
                //Supprimer un Livre du Stock
                {
                    printf("Entrez le titre du livre à supprimer : ");
                    fgets(titreRecherche, 100, stdin);
                    titreRecherche[strcspn(titreRecherche, "\n")] = '\0'; 
                    int trouve = 0;
                    for (i = 0; i < nbr; i++) {
                        if (strcmp(titres[i], titreRecherche) == 0) {
                            for (j = i; j < nbr - 1; j++) {
                                strcpy(titres[j], titres[j + 1]);
                                strcpy(auteurs[j], auteurs[j + 1]);
                                prix[j] = prix[j + 1];
                                quantites[j] = quantites[j + 1];
                            }
                            nbr--;
                            printf("Livre supprimé avec succès.\n");
                            trouve = 1;
                            break;
                        }
                    }
                    if (!trouve) {
                        printf("Livre non trouvé.\n");
                    }
                }
                break;
                
                case 6:
                //Afficher le Nombre Total de Livres en Stock
                {
                    int total = 0;
                    for (int i = 0; i < nbr; i++) {
                        total += quantites[i];
                    }
                    printf("Nombre total de livres en stock : %d\n", total);
                }
                break;
                
                default:
                    printf("Choix invalide. Veuillez réessayer.\n");
                break;
            }
        }
        return 0;
    }