#include <stdio.h>

int main(){

	int a, b;
	int i, j, k;
	int v, e;						// v - wierzchołki, e - krawędzie,
	int graf[10][10];
	
	printf("Proszę podać ilość wierzchołków.\n");
	scanf("%d", &v);
	
	printf("Proszę podać ilość krawędzi\n");
	scanf("%d", &e);

	// zerowanie macierzy
	for (i=0; i<v; i++) {
		for (j=0; j<v; j++) {
			graf[i][j] = 0; } }

	for (k=1; k<v; k++) {
		printf("Prosże wprowadzić wierzchołki dla krawędzi numer %d\n", k);
		scanf("%d %d", &a, &b);
	}

return 0;

}
