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

int binary_search(int *v, int bottom, int top, int item){
l  int middle = floor((top + bottom) * pow(2, -1));
  printf("Binary search at %d\n", middle);
  if(v[middle] < item){
    binary_search(v, middle, top, item);
  }
  else if (v[middle] > item){
    binary_search(v, bottom, middle, item);2
  }
  return middle;    
}

int main(void){
  int size = 100;
  int *v = malloc(size * sizeof(int));
  int i;
  for(i=0;i<size;i++){
    v[i] = i;
  }
  linear_search(v, size, 73);
  binary_search(v, 0, size, 73);
}
