#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int isPrime(int n){
  int i;
  // printf("%lld \n", n);
  if (n < 2 || !(n % 2)){
    return 0;
  }
  int max = floor(sqrt(n));
  for (i = 2; i < max; i++){
    if ((n % i) == 0){
      //printf("found factor\n");
      return 0;
    }
  }
  return 1;
}

int nextPrime(int prime){
  int i;
  for (i = prime + 1; ; i++){
    if (isPrime(i)){
      return i;
    }
  }
  return 0;
}

int partition(int a[], int l, int r);

void quickSort(int a[], int l, int r)
{
  int j;
  
  if( l < r )
  {
   	// divide and conquer
    j = partition(a, l, r);
    quickSort(a, l, j-1);
    quickSort(a, j+1, r);
  }
	
}

int partition(int a[], int l, int r) {
  int i, j;
  int pivot;
  int t;
  pivot = a[l];
  i = l; j = r+1;
  
  while(1)
  {
   	do ++i; while(a[i] <= pivot && i <= r);
   	do --j; while(a[j] > pivot);
   	if( i >= j ) break;
   	t = a[i];
    a[i] = a[j];
    a[j] = t;
  }
  t = a[l];
  a[l] = a[j];
  a[j] = t;
  return j;
}

int main(int argc, char* argv[]){
  
  // This array size was found by first running the program without
  // setting the array
  int *array = calloc(sizeof(int), 1696039);
  int index = 0;
  long long int add;
  long long int i, j, k;
  int size = 0;
  for (i = 2; i * i < 50000000; i = nextPrime(i)){
    for (j = 2; j * j * j < 50000000; j = nextPrime(j)){
      for (k = 2; k * k * k * k < 50000000; k = nextPrime(k)){
        add = i * i + j * j * j + k * k * k * k;
        if (add < 50000000){
          array[index] = add;
          index++;
          size++;
        }
      }
    }
  }
  
  quickSort(array, 0, 1696038);
  int result = 1;
  int test = 0;
  for (i = 1; i < 1696038; i++){
    if (array[i] != array[i-1]){
      result++;
    } else {
      test++;
    }
  }
  
  printf("%d %d\n", result, test);
  return 0;
}
