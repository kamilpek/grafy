#include <stdio.h>

int main(){

	int i, j, k;
	int v, e;						// v - wierzchołki, e - krawędzie,
	int graf[10][10];
	int ciag[10];					// ciag stopni,

	// zerowanie macierzy
	for (i=0; i<10; i++) {
		for (j=0; j<10; j++) {
			graf[i][j] = 0; } 
	}

	// zerowanie tabeli
	for (k=0; k<10; k++) {
		ciag[k] = 0; }

	printf("Proszę podać ilość wierzchołków.\n");
	scanf("%d", &v);
	
	printf("Proszę podać ilość krawędzi\n");
	scanf("%d", &e);


	// wyswietlanie na ekranie
	for (i=0; i<10; i++) {
		for (j=0; j<10; j++) {
			printf("%d,", graf[i][j]); }
		printf("\b \n");
	}

return 0;

}
