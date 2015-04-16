#include <stdio.h>
int main() {
int w,k,x,y,maksim=0,poczatek=0,koniec=0,stopien=0,status=0,pa=0, wiersz=0, kolumna=0; 

printf("podaj liczbe wierzcholkow ");
  scanf("%d",&w);
printf("podaj liczbe krawedzi ");
  scanf("%d",&k);

int tablica[w][w];

/* Petla zerujaca */
    for(x=0; x<w; x++){
    for(y=0; y<w; y++){
        tablica[x][y] = 0;
        }
    } 
          
    for(x=0; x<k; x++){
     do{
     			status=1;
        		printf("podaj poczatek krawedzi o numerze : %d: ", x+1);
             	scanf("%d",&poczatek);
              	printf("podaj koniec krawedzi o numerze : %d: ", x+1);
               	scanf("%d",&koniec); 
               	
            
            if (poczatek==koniec) { 
               	printf("Blad !!! Poczatkowy i koncowy wierzcholek nie moga byc takie same \n");
            	status=0; 
            } 
               	
            if (poczatek < 1 || koniec < 1){ 
               	printf("Blad !!! Indeks Wierzcholkow nie moze byc mniejszy od 1\n");
               	status=0;
               	}

            if (poczatek > w || koniec > w){
               	printf("Blad !!! Wierzcholek nie moze byc wiekszy od  (%d)!\n", w);
               	status=0;
                } 
        }
               		     
      while (!status);

	if (tablica[poczatek-1][koniec-1]==1){
	 printf("graf nie moze byc multigrafem\n");
   return main();
	
		 }
	
tablica[poczatek-1][koniec-1]=1; //wczytywanie  do tablicy

tablica[koniec-1][poczatek-1]=1; 

}
printf("\nMacierz ma postac :\n");
for(x=0; x<w; x++){
   
	
	for(y=0; y<w-1; y++){
     
		printf("%d",tablica[x][y]);
             
        			  } 
               		      
        printf("%d\n",tablica[x][y]);
            
                }


	for(x=0;x<w;x++){
    
       	for(y=0;y<=w-1;y++){
       		   
       	   stopien+=tablica[x][y];
           if(stopien%2==0){
                  pa+=1;
                }
                }                          

       		   printf("wierzcholek nr %d ma stopien %d\n",x+1, stopien);

                 

       		   if ( stopien > maksim ){ 
       		   	maksim = stopien;
       		             			}
       		        stopien=0; 

			 }
  for(x=0;x<w;x++){
    
        for(y=0;y<=w-1;y++){
          if(w%2==0){
           if(tablica[y][x]==1){
            wiersz+=1;

          }
           if(tablica[y][x]==0){
            kolumna+=1;
           }
            }    
                else{
              
           if(tablica[y][x]==1){
            wiersz+=1;
          }
           if(tablica[y][x]==0){
            kolumna+=1;
       }
          
       }
       } 
       
}



printf("Stopien grafu wynosi: %d\n", maksim);
if(w>k){
printf("Graf nieeulerowski \n");
}
else {
  if(pa>=1 & maksim%2==0 & wiersz==kolumna){
printf("Graf eulerowski \n");

}
else{
  printf("Graf nieeulerowski\n");
}

}
}