#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

int dist[10][10] = { {-1,5,-1,-1,-1,-1},{5,-1,-1,4,6,-1,3},{-1,4,-1,-1,7,-1},{-1,6,-1,-1,5,3},{-1,-1,7,5,-1,-1},{-1,3,-1,2,-1,-1} };// TABLEAU globale des distance entre les noeuds 
char adressChar;

int SOMMET_SELECTION;
int a;

int findMinNodes(int); //chercher sommet le plus proche 

//char* pathInChar(int); // Créer une chaine de caractère du style abcdef qui donne la suite des sommets à emprunter pour être le plus rapide



int main() {

	int currentNode, endNode;
	
	printf("\nAlgo de Djisktra en C par Victor !");
	printf("\nSommet de départ : ");
	scanf("%d", &currentNode);						// Bla bla conventionnel pour	Depart et arrivée . 
	printf("\nSommet d'arrivée : ");
	scanf("%d", &endNode);

	a = currentNode;
	//printf("Le chemin le plus rapide entre %d et %d est de",);
	printf("0 -> A | 1 -> B | 2 -> C | 3 -> D | 4 -> E | 5 -> F");
}

int findMinNodes(int currentNode) {
	
	int j;
	int DistMini;
	//int tmpTab[6];
	// TABLEAU ICI ET PAS EN VARIABLE GLOBALE 	
	for ( j = 0; j < 6; j++)
	{
		if (dist[currentNode][j] != -1 && dist[currentNode][j] < distMini && dist[currentNode][j] != INT_MAX) //si y'a un lien vers le somet suivant + si la d[s] < mini = a LONG_MAX (valeur d'un long)
		{
			distMini = dist[sommetStart][j]; // la distance la plus petite vers le prochain sommet = distMini
			SOMMET_SELECTION = j; // index du sommet selectionné
			dist[current][j] = INT_MAX;
		}	
	}
	return distMini;
}

int dijsktra(int current, int endNode){	
	int dist_Current_Test, Dist_Mini,Dist_Mini;
	int MAX_LENGHT_PATH = INT_MAX; 
	
	while (SOMMET_SELECTION != sommetFin && dist_Total < MAX_LENGHT_PATH)
	{
		if (dist_Current_Test > MAX_LENGHT_PATH)
		{
				break; 
				currentNode = a;
		}	
		
		dist_Mini += findMinNodes(SOMMET_SELECTION);
		SOMMET_SELECTION++;
	}
	
if ( dist_Current_Test < Dist_Mini){
			
			Dist_Mini = dist_Current_Test;
		}
	return Dist_Mini;
}
