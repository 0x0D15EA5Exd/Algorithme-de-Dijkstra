#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int dist[10][10] = { {-1,3,-1,-1,-1,-1},{3,-1,-1,4,6,-1,3},{-1,4,-1,-1,7,-1},{-1,6,-1,-1,5,3},{-1,-1,7,5,-1,-1},{-1,3,-1,3,-1,-1} };// TABLEAU globale des distance entre les noeuds 


/**/
int findMinNodes(int);

int main() {

	int sommetDebut, sommetFin;
	
	printf("\nAlgo de Djisktra en C par Victor !");
	printf("\nSommet de départ : ");
	scanf("%d", &sommetDebut);						// Bla bla conventionnel pour	Depart et arrivée . 
	printf("\Sommet d'arrivée : ");
	scanf("%d", &sommetFin);

	//printf("Le chemin le plus rapide entre %d et %d est de",);
	printf("%d", findMinNodes(sommetDebut));
}
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

int findMinNodes(int currentNode) {

	// sommet recu -> 1
	int sommetStart;
	int distMini = LONG_MAX;
	int sommetSelectione;
	int i,j;

	sommetStart = currentNode;

	for ( j = 0; j < 6; j++) {
		if (dist[sommetStart][j] != -1 && dist[sommetStart][j] < distMini && dist[sommetStart][j] != LONG_MAX) //si y'a un lien vers le somet suivant + si la d[s] < mini = a LONG_MAX (valeur d'un long)
		{
			distMini = dist[sommetStart][j]; // la distance la plus petite vers le prochain sommet = distMini
			dist[sommetStart][j] = LONG_MAX;
											 // En principe ça doit prendre la valeur de J qui donne le sommet selectionné (marche pas)
		}
		
	}

	for ( i = 0; i == 6; i++) {
		if (dist[sommetStart][i] == LONG_MAX) {
			printf("%d", i);
			sommetSelectione = i;
		}
	}
	printf("Valeur du chemin le plus cours vers le prochain noeuds %d", distMini);
	printf("\nSommet selcetionne : %d", sommetSelectione);
}
























/*
int dijsktra(int sommetDebut, int sommetFin){	

	int dist[10][10] = { {-1,3,-1,-1,-1,-1},{3,-1,-1,4,6,-1,3},{-1,4,-1,-1,7,-1},{-1,6,-1,-1,5,3},{-1,-1,7,5,-1,-1},{-1,3,-1,3,-1,-1} };// TABLEAU globale des distance entre les noeuds 
	int start;



	for (int i = 0; i < 6; i++) {
		if (dist[])
	}
	



	


	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (dist[i][j] != -1) {
				printf("%d\n", dist[i][j]);
			}
		}s
	}
	return 0;
}

*/