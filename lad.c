#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define Brest 0
#define Quimper 1
#define Quimperle 2
#define Lorient 3
#define Morlaix 4
#define Pontivy 5
#define Lannion 6
#define Carhaix_Plouguer 7
#define St_Brieux 8
#define Vannes 9
#define Ploermel 10
#define Rennes 11
#define Nantes 12
#define Hennebont 13
#define St_Malo 14
#define Redon 15


int main() {
	
	//on définit les distances entre chaques villes
	
	int i,j;
	
	float tab[16][16] = {
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
					  
	for(i=0; i<16; i++){
		for(j=0; j<16; j++){
			if(tab[i][j]==-1){
				printf("");
			}
			else printf("\nla distance est : %.1f", tab[i][j]); 
			}
		}
	
			
			
			
			
			
			
			
			
			
			
					  
					  
	//printf("Brest - Quimper = %.1f\n", tab[Brest][Quimper]);
	//printf("Brest - Quimperle = %.1f\n", tab[Brest][Quimperle]);
	//printf("Brest - Lorient = %.1f\n", tab[Brest][Lorient]);
	
	//printf("Quimper - Quimperle = %.1f\n", tab[Quimper][Quimperle]);
	//printf("Quimper - Lorient = %.1f\n", tab[Quimper][Lorient]);
	
	//printf("Quimperle - Lorient = %.1f\n", tab[Quimperle][Lorient]);
	
	
}
