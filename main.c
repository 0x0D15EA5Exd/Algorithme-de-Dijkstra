#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int dist[10][10] = { {-1,5,-1,-1,-1,-1},{5,-1,-1,4,6,-1,3},{-1,4,-1,-1,7,-1},{-1,6,-1,-1,5,3},{-1,-1,7,5,-1,-1},{-1,3,-1,2,-1,-1} };// TABLEAU globale des distance entre les noeuds 
char adressChar;

int sommetSelectione;

int findMinNodes(int); //chercher sommet le plus proche 

//char* pathInChar(int); // Créer une chaine de caractère du style abcdef qui donne la suite des sommets à emprunter pour être le plus rapide



int main() {

	int sommetDebut, sommetFin;
	
	printf("\nAlgo de Djisktra en C par Victor !");
	printf("\nSommet de départ : ");
	scanf("%d", &sommetDebut);						// Bla bla conventionnel pour	Depart et arrivée . 
	printf("\nSommet d'arrivée : ");
	scanf("%d", &sommetFin);

	//printf("Le chemin le plus rapide entre %d et %d est de",);
	printf("Distance Mini = %d, sommet seletionné = %c", findMinNodes(sommetDebut));
}

int findMinNodes(int currentNode) {

	/*
Trouve_min(Q)
1 mini : = infini
2 sommet : = -1
3 pour chaque sommet s de Q
4    si distanceSommet	< mini
	5    alors
	6        mini : = distance sommet
	7        sommet : = s
	8 renvoyer sommet
	*/

	// sommet recu -> 1
	int sommetStart;
	int distMini = 150;
	int sommetSelectione;
	int j;
	//int tmpTab[6];

	sommetStart = currentNode;

	for ( j = 0; j < 6; j++)
	{
		if (dist[sommetStart][j] != -1 && dist[sommetStart][j] < distMini) //si y'a un lien vers le somet suivant + si la d[s] < mini = a LONG_MAX (valeur d'un long)
		{
			distMini = dist[sommetStart][j]; // la distance la plus petite vers le prochain sommet = distMini
			sommetSelectione = j; // index du sommet selectionné*
			
			break;	
		}	
	}
	return distMini;
}




int dijsktra(int sommetDebut, int sommetFin){	
		
