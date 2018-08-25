#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
/* #define MAX_SIZE 100; */

void sort(int *v, int l, int m, int r){
  int nl = m-l+1;
  int nr = r-m;
  int i, j, k;
  int L[nl];
  int R[nr];

  for(i=0;i<nl;++i){
    L[i] = v[l+i];
  }
  for(j=0;j<nr;++j){
    R[j] = v[m+j+1];
  }

  i = 0;
  j = 0;

  
  k = l;  
  while(i<nl && j<nr){
    if(L[i] <= R[j]){
      v[k] = L[i];
      ++i;
    }
    else{
      v[k] = R[j];
      ++j;
    }
    ++k;
  }

  while(i<nl){
    v[k] = L[i];
    ++i;
    ++k;
  }
  while(j<nr){
    v[k] = R[j];
    ++j;
    ++k;
  }

  /* L[nl] = MAX_SIZE; */
  /* R[nr] = MAX_SIZE; */
  /* i = 0; */
  /* j = 0; */

  /* for(k=l;k<=r;++k){ */
  /*   if(L[i] <= R[j]){ */
  /*     v[k] = L[i]; */
  /*     ++i; */
  /*   } */
  /*   else{ */
  /*     v[k] = R[j]; */
  /*     ++j; */
  /*   } */
  /* } */
}
 
void merge(int *v, int l, int r){
  if(l<r){
    int m = floor((l+r) * pow(2, -1));
    merge(v, l, m);
    merge(v, m+1, r);
    sort(v, l, m, r);
  }
}

void quick(int *v, int l_index, int r_index){
  if(l_index >= r_index){
    return ;
  }
  int l, r, pivot, aux;
  l = l_index;
  r = r_index;
  pivot = v[(l_index + r_index)/2];
  while(l <= r){
    while(v[l] < pivot) ++l;
    while(v[r] > pivot) --r;
    if(l <= r){
      aux = v[r];
      v[r] = v[l];
      v[l] = aux;
      ++l; --r;
    }
  }
  quick(v, l_index, r);
  quick(v, l, r_index);
}

void insertion(int *v, int size){
  int key_t, i, j;
  for(j=1;j<size;++j){
    key_t = v[j];
    i = j - 1;
    while(i>=0 && v[i] > key_t){
      v[i+1] = v[i];
      v[i] = key_t;
      --i;
    }
  }
}

void main(int argc, char *argv[], char *envp[]){
  int i, size;
  size = 9;
  
  int *v;
  v = malloc(sizeof(int)* size);

  for(i=0;i<size;++i){
    scanf("%d", &v[i]);
  }

  if( strcmp(argv[1], "quick") == 0){
    printf("Quick sort it is!\n");
    quick(v, 0, size-1);    
  }
  else if( strcmp(argv[1], "insertion") == 0){
    printf("Insertion it is!\n");    
    insertion(v, size);    
  }
  else if( strcmp(argv[1], "merge") == 0){
    printf("Merge sort it is!\n");
    merge(v, 0, size-1);
  }
  else{
    printf("Invalid parameter\n");
  }
  
  for(i=0;i<size;++i){
    printf("%d ", v[i]);
  }
}
