#include <stdlib.h>
#include <stdio.h>
#include <math.h>

long long int num_routes(int n, int m, long long int array[21][21]){
  if (m == 0)
    return 1;
  if (n == 0)
    return 1;
  long long int entry1 = array[n - 1][m];
  long long int entry2 = array[n][m-1];
  if (entry1 > 0 && entry2 > 0){
    array[n][m] = entry1 + entry2;
    return entry1 + entry2;
  } else {
    long long int entry = num_routes(n-1, m, array) + num_routes(n, m-1, array);
    array[n][m] = entry;
    return entry;
  }
}

int main(int argc, char* argv[]){
  long long int array[21][21];
  int i, j;
  for (i = 0; i < 21; i++){
    for (j = 0; j < 21; j++){
      array[i][j] = 0;
    }
  }
  printf("%lld\n", num_routes(20, 20, array));
  
  return 0;
}
