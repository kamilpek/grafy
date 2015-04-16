/*
* Algorytmiczna Teroia Grafow.
* Implementacja grafu w komputerze.
* (C)2015 Kamil Pek
* Ver. 2.0
* http://github.com/kamilpek/grafy 
*/

/*
 * Duzy for - wprowadzanie grafu.
 * Maly for - obliczanie stopnia grafu.
*/

#include <stdio.h>

int main(){

	int v, e;								// liczba wierzchołków i krawędzi
	int i, j, x, y;							// operatory pętli for
	int start = 0, stop = 0, status = 0;	// zmienne z duzego fora
	int max = 0, degree = 0;				// zmienne z malego fora
	
	printf("Proszę podać liczbę wierzchołków: \t");
	scanf("%d", &v);
	
	printf("Proszę podać liczbę krawędzi: \t \t");
	scanf("%d", &e);
	
	int graf[v][v];
	
	// zerowanie macierzy
	for (i=0; i<v; i++) {
		for (j=0; j<v; j++) {
			graf[i][j] = 0; } }

	// wczytywanie grafu	
	for(x=0; x<e; x++){				// poczatek duzego fora
		do{
			status= 1;
			printf("Prosze wprowadzic pierwszy wierzcholek krawedzi %d: \t", x+1);
			scanf("%d",&start);
			printf("Prosze wprowadzic drugi wierzcholek krawedzi %d: \t", x+1);
			scanf("%d",&stop);            
               	
            if (start < 1 || stop < 1){ 
               	printf("Error!! Indeks Wierzcholkow nie moze byc mniejszy od 1.\n");
               	status=0;	}

            if (start > v || stop > v){
               	printf("Error!! Wierzcholek nie moze byc wiekszy od liczby: (%d)!\n", v);
               	status=0;	}
        }        
		while (!status);
        
	if (graf[start-1][stop-1]==1){
		printf("Podany Graf nie moze byc multigrafem.\n");
	return main();	}
	
	// wczytywanie do macierzy dwuwymiarowej 'graf'
	graf[start-1][stop-1] += 1;
	graf[stop-1][start-1] += 1; 
	
	}	// koniec duzego fora
	
	printf(" \n");	// linia przerwy
	
	// stopien wierzcholka
	for(x=0; x<v; x++){    
		for(y=0; y<=v-1; y++){       		   
			degree += graf[x][y]; }
		                        
		printf("\t Wierzcholek o numerze %d ma stopien %d. \n", x+1, degree);
		if ( degree > max ){ 
			max = degree;
		}
       		degree=0; 
	}	// koniec malego fora
	
	printf(" \n");
	printf("\t Stopien grafu wynosi: %d\n", max);	// Stopien grafu
	
	return 0;
}
