#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int cmpstringp(const void *p1, const void *p2){
  return strcmp(* (char * const *) p1, * (char * const *) p2);
}

int main(void){
  int track, size_t, slen, i, j;
  char **v;
  char aux[255];

  scanf("%d", &size_t);
  v = malloc(sizeof(char) * size_t);

  for(i=0;i<size_t;++i){
    scanf("%s", aux);
    slen = strlen(aux);
    v[i] = malloc(sizeof(char) * slen);
    for(j=0;j<slen;++j){
      v[i][j] = aux[j];
    }
  }

  qsort(&v[0], size_t, sizeof(char *), cmpstringp);
  for(i=0;i<size_t;++i){
    puts(v[i]);
  }

  exit(EXIT_SUCCESS);
}
