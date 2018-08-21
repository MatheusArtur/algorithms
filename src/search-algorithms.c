#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int linear_search(int *v, int size, int item){
  int i;
  for(i=0;i<size;i++){
    if(v[i] == item){
      printf("Linear search found %d with %d interactions!\n\n", item, i);
      return i;
    }
  }
  return 0;
}

int binary_search(int *v, int bottom, int top, int item, int *i){
  int middle = floor((top + bottom) * pow(2, -1));
  printf("Binary search at %d\n", middle);
  *i += 1;
  if(v[middle] < item){
    binary_search(v, middle, top, item, i);
  }
  else if (v[middle] > item){
    binary_search(v, bottom, middle, item, i);
  }
  return middle;    
}

int main(void){
  int size = 100;
  int *v = malloc(size * sizeof(int));
  int i, j, item;
  item = 73;
  for(i=0;i<size;i++){
    v[i] = i;
  }
  j = 0;
  linear_search(v, size, item);
  binary_search(v, 0, size, item, &j);
  printf("\nBinary search found %d with %d interactions!\n", item, j);
}
