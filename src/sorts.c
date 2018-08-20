#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void merge(int *v, int l_index, int r_index){
  if(l_index >= r_index){
    return ;
  }
  int l, r, key_t, aux;
  l = l_index;
  r = r_index;
  key_t = v[(l_index + r_index)/2];
  while(l <= r){
    while(v[l] < key_t) ++l;
    while(v[r] > key_t) --r;
    if(l <= r){
      aux = v[r];
      v[r] = v[l];
      v[l] = aux;
      ++l; --r;
    }
  }
  merge(v, l_index, r);
  merge(v, l, r_index);
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
  int *v;
  v = malloc(sizeof(int)* 6);
  int i, size;
  size = 6;

  for(i=0;i<size;++i){
    scanf("%d", &v[i]);
  }


  if( strcmp(argv[1], "merge") == 0){
    merge(v, 0, size-1);    
  }
  else{
    insertion(v, size);    
  }
  for(i=0;i<size;++i){
    printf("%d ", v[i]);
  }
}
