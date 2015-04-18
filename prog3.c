/*
* Algorytmiczna Teroia Grafow.
* Implementacja grafu w komputerze.
* (C)2015 Kamil Pek
* Ver. 3.4 (final release)
* http://github.com/kamilpek/grafy 
*/

/*
 * Duzy for - wprowadzanie grafu.
 * Maly for - obliczanie stopnia grafu.
 * Trzeci for - sprawdzanie cyklu eulera w grafie.
*/

#include <stdio.h>

	int v, e;								// liczba wierzchołków i krawędzi
	int i, j, x, y;							// operatory pętli for
	int start = 0, stop = 0, status = 0;	// zmienne z duzego fora
	int max = 0, degree = 0;				// zmienne z malego fora
	int wiersz = 0, kolumna = 0;			// zmienne z trzeciego fora
	int pa=0, ne=0;								// zmienne sprawdzajace cykl eulera
	int graf[1][1];							// deklaracja macierzy sasiedztwa grafu
	
int main(){

	printf("Proszę podać liczbę wierzchołków: \t");
	scanf("%d", &v);
	
	printf("Proszę podać liczbę krawędzi: \t\t");
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
		if(degree%2==0){
			pa+=1; }
		else {
			ne=1; }			
		                        
		printf("\t Wierzcholek o numerze %d ma stopien %d. \n", x+1, degree);
		if ( degree > max ){ 
			max = degree;
		}
       		degree=0; 
	}	// koniec malego fora
	
	printf(" \n");
	printf("\t Stopien grafu wynosi: %d\n", max);	// Stopien grafu
	
	printf("\n\t Macierz sasiedztwa ma nastepujaca postac :\n");
	for(x=0; x<v; x++){
   	for(y=0; y<v-1; y++){     
		printf("\t %d",graf[x][y]);} 
        printf("\t %d\n",graf[x][y]);}
		
//Trzeci for
	for(x=0;x<v;x++){    
		for(y=0;y<=v-1;y++){
			if(v%2==0){
				if(graf[y][x]==1){
				wiersz=1; }
				if(graf[y][x]==0){
				kolumna=1; }
            }    
			else{
			if(graf[y][x]==1){
            wiersz=1; }
			if(graf[y][x]==0){
			kolumna=1; }
			}
		} 
	}	//koniec trzeciego fora
	
	printf(" \n");
	
//	printf("pa= %d, max= %d, wiersz= %d, kolumna= %d, ne= %d.\n", pa, max, wiersz, kolumna, ne); 
	
	if(v>e){
		printf("\t Niestety. Graf nieeulerowski. \n"); }
		else {
			if((pa>=1) & (max%2==0) & (wiersz==kolumna) & (ne==0)){
			printf("\t Graf eulerowski!! \n"); }
				else{
					printf("\t Niestety. Graf nieeulerowski.\n"); }
		}

return 0;
}
