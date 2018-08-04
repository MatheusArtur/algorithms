  #include <stdio.h>
  #include <stdlib.h>

int map(int (*f)(int x), int j, int i, int array[]){
  if(i == j){
    return 0;
  }
  array[i] = (*f)(i);

  map((*f), j, i+1, array);
}

int fatorial(int x){
  if(x <= 1){
    return 1;
  }
  return x * fatorial(x-1);
}

int square(int x){
  return x*x*x;
}

int main(){
  int size, i;
  scanf("%d", &size);
  size = size+1;

  int array[size];

  for(i = 1; i < size; i++){
    array[i] = i+1;
  }

  map(square, size, 0, array);
  for(i = 1; i < size; i++){
    printf("%d^3 = %d\n", i, array[i]);
  }
  
  map(fatorial, size, 0, array);
  for(i = 1; i < size; i++){
    printf("%d! = %d\n", i, array[i]);
  }
}
