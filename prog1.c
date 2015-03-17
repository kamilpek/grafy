#include <stdio.h>

int main(){

	int i, j;
	int v, e;						// v - wierzchołki, e - krawędzie,
	int graf[10][10];

	// zerowanie macierzy
	for (i=0; i<10; i++) {
		for (j=0; j<10; j++) {
			graf[i][j] = 0; } 
	}
	return 0;

	printf("Proszę podać ilość wierzchołków.\n");
	scanf("%d", v);
	
	printf("Proszę podać ilość krawędzi\n");
	scanf("%d", e);


	// wyswietlanie na ekranie
	for (i=0; i<10; i++) {
		for (j=0; j<10; j++) {
			printf("%d,", graf[i][j]); }
		printf("\b \n");
	}

return 0;

}
