#include <stdio.h>
#include <math.h>

double merge(double n){
  return  64 * (n * log(n));
}
double insertion(double n){
  return  8 * pow(2, n);
}

int main(){
  double objects, InsertValue, MergeValue;

  for(objects = 2;1>0;objects++){
    InsertValue = insertion(objects);
    MergeValue = merge(objects);
    printf("%.0lf objects:\n Insert = %.0lf\n Merge = %.0lf\n\n", objects, InsertValue, MergeValue);
    if(MergeValue < InsertValue){
      break;
    }
  }
  printf("At %.0lf objects, Merge has %.0lf instructions nedded to sort, %.0lf less than insert\n", objects, MergeValue, (InsertValue - MergeValue));


}
