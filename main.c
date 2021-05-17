#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>


#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
 
#define INF 9999




void menu();

void dijsktra(float,float,int);

int main() {

	menu();

	printf(ANSI_COLOR_RED"\n\nTERMINE"ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED "\n\nDeveloppe par Victor & Ludo"ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED"\n\nAvec l'aide de James pour le debuggage et la correction de bug mineur ainsi que INTERNET"ANSI_COLOR_RESET);
	// FIN DU PROGRAMME 

}



void menu() {

	float arrivee, depart;
	int n = 16;
	// Menu de dialogue 
	printf(ANSI_COLOR_MAGENTA "\n Algoo de Djisktra en C par Victor & Ludo !");

	printf("\n\nSommet de depart : ");
	scanf("%f",&depart);


	printf("\n\nSommet d'arrivé : ");
	scanf("%f",&arrivee);


	if (arrivee == depart) {
		printf(ANSI_COLOR_RED "Ca n'existe pas ! " ANSI_COLOR_RESET);
		exit(0);
	}
		
	dijsktra(arrivee, depart,n);
}

void dijsktra(float noeudDarrivee,float noeudDeDepart,int n){

	float ville[16][16] = {
			{-1, 71.4, -1, -1, 58, -1, -1, 85.1, -1, -1, -1, -1, -1, -1, -1, -1},
			{71.4, -1, 48.4, -1, 81.3, -1, -1, 68.5, -1, -1, -1, -1, -1, -1, -1},
			{-1, 48.4, -1, 23, -1, 74.6, -1, 54.3, 138, -1, -1, -1, -1, -1, -1, -1},
			{-1, -1, 23, -1, -1, -1, -1, -1, -1, 60.5, 87.6, -1, -1, 16.1, -1, -1},
			{58, 81.3, -1, -1, -1, 116, 37.9, 50.5, 88.7, -1, 164, -1, -1, -1, -1, -1},
			{-1, -1, 74.6, -1, 116, -1, 95.4, 60.1, 66.5, 53.2, 47.9, 111, -1, 47.7, 125, -1},
			{-1, -1, -1, -1, 37.9, 95.4, -1, 60.7, 61, -1, -1, -1, -1, -1, -1, -1},
			{85.1, 68.5, 54.3, -1, 50.5, 60.1, 60.7, -1, 83.1, -1, 118, 156, -1, 65.8, -1, -1},
			{-1, -1, 138, -1, 88.7, 66.5, 61, 83.1, -1, -1, 91.5, 99.7, -1, -1, 90.3, -1},
			{-1, -1, -1, 60.5, -1, 53.2, -1, -1, -1, -1, 48.7, -1, 116, 50, -1, 62.9},
			{-1, -1, -1, 87.6, 164, 47.9, -1, 118, 91.5, 48.7, -1, 68.7, 129, 74.3, 102, 44.8},
			{-1, -1, -1, -1, -1, 111, -1, 156, 99.7, -1, 68.7, -1, 111, 141, 69.1, 66.9},
			{-1, -1, -1, -1, -1, -1, -1, -1, -1, 116, 129, 111, -1, -1, -1, 71.9},
			{-1, -1, -1, 16.1, -1, 47.7, -1, 65.8, -1, 50, 74.3, 141, -1, -1, -1, -1},
			{-1, -1, -1, -1, -1, 125, -1, -1, 90.3, -1, 102, 69.1, -1, -1, -1, -1},
			{-1, -1, -1, -1, -1, -1, -1, -1, -1, 62.9, 44.8, 66.9, 71.9, -1, -1, -1},
	};
	float coutNoeud[16][16]; // copie du tableau précedent;
	float noeudVisite[99]; //Historique des noeuds visités 
	float predecesseur[99]; //tableau prédécesseur 
	float distMini = INF; // distance Mini setup a valeur max pour première vérification pour que ça soit strictement inférieure à l'infini
	float noeudSuivant; // Noeud suivant pour opérer les tests dans les tableaux 
	int i, j; // ittérateur des tableaux (ittérateur c'est le mot exact Ludo) 
	float distance[99]; // stocke la distance entre les noeuds 
	int count; // nombre de sommet. 
	float TOTAL_CHEMIN = 0; // Longeur total ;


	/*Permet de savoir si il existe un lien entre les neouds.
	( équivalent de -1 dans le tableau )
	Sauf que pour pas que ça soit le bazar dans les tests 
	et la réecriture en INT_MAX pour marquer le passage par se chemin c'est plus pratique
	 /!\ Abandonnée en cours de route les INT_MAX un tableau des poids entre les différents noeuds sera plus simple  
	*/
	// C'est possible de sans passer à condition de réécrire la matrice mais un peu la flemme
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < n; j++)
		{
			if (ville[i][j] == -1)
				coutNoeud[i][j] = INF;
			else
				coutNoeud[i][j] = ville[i][j];
		}
	}
	//Initialisation des tableaux : prédecesseur + distance + noeudVisité.
	for (i = 0; i < n ; i++)
	{
		predecesseur[i] = noeudDeDepart;
		noeudVisite[i] = 0;
		distance[i] = coutNoeud[(int)noeudDeDepart][i];
	}

	distance[(int)noeudDeDepart] = 0;
	noeudVisite[(int)noeudDeDepart] = 1;
	count = 1;

	while (count<n-1) { // nombre de sommet c'est 16

		// tant que le noeud suivant n'est pas le noeuds d'arrivé alors : 

		for (i = 0; i < n; i++) {
			if (distance[i] < distMini&&!noeudVisite[i]&&!INF)
			{
				//Correspond au chemin le plus court 
				// si la distance est < la distance minimun ET que la distance est différente d'un noeud visité alors 
				// les variables suivantes prennent les valeurs noeuds suivant = l'index de I ET distance Mini prend la valeur 
				// de distance de i 
				distMini = distance[i];
				noeudSuivant = i;
			}


			//vérification de l'existance d'un meilleur chemin après avec le noeud suivant 
			noeudVisite[i] = 1;
			for (i = 0; i < n; i++)
				if (!noeudVisite[i]) // ! non logique 
					if (distMini + coutNoeud[(int)noeudSuivant][i] < distance[i])
					{
						// Si la distance minimun + le cout vers la suivante est < à distance[i]
						// Alors on affecte les valeurs suivante : 
						distance[i] = distMini + coutNoeud[(int)noeudSuivant][i];
						predecesseur[i] = noeudSuivant;
					}
		}
		count++;
	}
	// Affice le chemlin et la distance entre chaque noeud
	for (i = 0; i < n; i++){
		if (i != noeudDeDepart)
		{
			if (distance[i] != INF) {
				printf("\nLa distance vers le noeud %d = %.1f", i, distance[i]);
				printf("\nChemin = %d ", i);
				j = i;
				TOTAL_CHEMIN += (float)distance[i];
				do
				{
					j = predecesseur[j];
					printf(" vers %d", j);


				} while (j != noeudDeDepart);
			}
			
		}
	}
	printf("\n\nTotal = %.2lf",TOTAL_CHEMIN);
		
}
