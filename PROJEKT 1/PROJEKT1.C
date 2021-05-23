#include<time.h>
#include<stdlib.h>
#include<stdio.h>

void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//  QUICKSORT 
int partition (int tab[], int left, int right) 
{ 
    int pivot = tab[right];    
    int i = (left - 1); 
  	int j;
    for (j = left; j <= right-1; j++) 
    { 
        if (tab[j] < pivot) 
        { 
            i++;  
            swap(&tab[i], &tab[j]); 
        } 
    } 
    swap(&tab[i + 1], &tab[right]); 
    return (i + 1); 
} 
  
void quicksort(int tab[], int left, int right) 
{ 
    if (left < right) 
    { 
        int pi = partition(tab, left, right); 
  
        quicksort(tab, left, pi - 1); 
        quicksort(tab, pi + 1, right); 
    } 
} 

// HEAPSORT 
void heapify(int tab[], int n, int i) 
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && tab[left] > tab[largest])
      largest = left;
  
    if (right < n && tab[right] > tab[largest])
      largest = right;
  
    if (largest != i) {
      swap(&tab[i], &tab[largest]);
      heapify(tab, n, largest);
    }
  }
  
  void heapsort(int tab[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
      heapify(tab, n, i);
  
    for ( i = n - 1; i>0; i--) {
      swap(&tab[0], &tab[i]);
      
	heapify(tab, i, 0);
    }
}

// BUBBLESORT 
void bubblesort(int tab[],int n)
{
	int i;
	int j;
	for (i=0; i < n-1; i++)
		for (j=0; j < n-1; j++)
			if (tab[j] > tab[j+1])
			{
				swap(&tab[j],&tab[j+1]);
			}
}

int main()
{
// Tablica losowa
	srand( time( NULL ) );      
	int tab[500];  
	int i;              
	for (i=0; i<=500; i++)    
		tab[i] = rand() % 500;   
//Quicksort	 losowa
	clock_t start7 = clock();
	
	quicksort(tab, 0, 500 - 1);
	
	clock_t stop7 = clock();
	
	printf("\nSortowanie quicksort tablica losowa:\n"); 
    showTable(tab, 500);
	printf( "Czas wykonywania: %lu ms\n", stop7 - start7 );

//Heapsort losowa	
	clock_t start8 = clock();
	
	heapsort(tab, 500);
	
	clock_t stop8 = clock();
	printf("\nSortowanie heapsort tablica losowa:\n"); 
	printf( "Czas wykonywania: %lu ms\n", stop8 - start8 );
	
//Bubble losowa		
	clock_t start9 = clock();
	
	bubblesort(tab,500);
	
	clock_t stop9 = clock();
	printf("\nSortowanie bubblesort tablica losowa:\n"); 
	printf( "Czas wykonywania: %lu ms\n", stop9 - start9 );

//Tablica rosnąca
	int	tab2[500];
	for ( i = 0; i <= 500; i++)
		tab2[i]= i;
	
	
//Quicksort	 rosnąca
	clock_t start = clock();
	
	quicksort(tab2, 0, 500 - 1);
	
	clock_t stop = clock();
	
	printf("\nSortowanie quicksort tablica rosnaca:\n");
	printf( "Czas wykonywania: %lu ms\n", stop - start );

//Heapsort rosnąca	
	clock_t start2 = clock();
	
	heapsort(tab2, 500);
	
	clock_t stop2 = clock();
	printf("\nSortowanie heapsort tablica rosnaca:\n"); 
	printf( "Czas wykonywania: %lu ms\n", stop2 - start2 );
	
//Bubble rosnąca		
	clock_t start3 = clock();
	
	bubblesort(tab2,500);
	
	clock_t stop3 = clock();
	printf("\nSortowanie bubblesort tablica rosnaca:\n"); 
	printf( "Czas wykonywania: %lu ms\n", stop3 - start3 );
	
//Tablica odwrotna
	int tab3[500];
	for ( i = 500; i>=0; i--)
	
		tab3[i]= i;
		

//Quicksort	 odwrotna
	clock_t start4 = clock();
	
	quicksort(tab3, 0, 500 - 1);
	
	clock_t stop4 = clock();
	
	printf("\nSortowanie quicksort tablica odwrotna:\n");
	printf( "Czas wykonywania: %lu ms\n", stop4 - start4 );

//Heapsort odwrotna	
	clock_t start5 = clock();
	
	heapsort(tab3, 500);
	
	clock_t stop5 = clock();
	printf("\nSortowanie heapsort tablica odwrotna:\n");
	printf( "Czas wykonywania: %lu ms\n", stop5 - start5 );
	
//Bubble odwrotna	
	clock_t start6 = clock();
	
	bubblesort(tab3,500);
	
	clock_t stop6 = clock();
	printf("\nSortowanie bubblesort tablica odwrotna:\n");
	printf( "Czas wykonywania: %lu ms\n", stop6 - start6 );
}