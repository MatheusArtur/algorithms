#include <stdio.h>
#define DEBUG if(1)

int
min(int x, int y)
{
  if (x >= y)
    return y;
  else
    return x;
}

int
main()
{
  int n, i, j, t;
  t=0;
  
  while(1)
    {
      scanf("%d", &n);

      if(n == 0)
	break;

      int grafo[n][3];

      for (i = 0; i < n; ++i)
	  scanf("%d %d %d",
		&grafo[i][0], &grafo[i][1], &grafo[i][2]);

      grafo[0][0] = 999999;
      grafo[0][2] += grafo[0][1];

      int custo[n][3];

      for (i = 0; i < 3; ++i)
	custo[0][i] = grafo[0][i];

      for (i = 1; i < n; ++i)
	{
	  for (j = 0; j < 3; ++j)
	    {
	      
	      if(j == 0)
		custo[i][j] = min(custo[i-1][j], custo[i-1][j+1]) + grafo[i][j];

	      if(j == 1)
		custo[i][j] = min(
				  min(custo[i-1][j-1], custo[i][j-1]),
				  min(custo[i-1][j], custo[i-1][j+1]))+grafo[i][j];
	      if(j == 2)
		custo[i][j] = min(
				  min(custo[i][j-1], custo[i-1][j-1]),
				  custo[i-1][j]) + grafo[i][j];
	    }

	}
      ++t;

      DEBUG
	for (i = 0; i < n; ++i)
	  {
	    for (j = 0; j < 3; ++j)
	      printf("%d ", custo[i][j]);
	    printf("\n");
	  }
      
      printf("%d. %d\n",t, custo[n-1][1]);
    }
  


  return 0;
}
