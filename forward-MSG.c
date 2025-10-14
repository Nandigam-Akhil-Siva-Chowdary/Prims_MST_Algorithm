#include<stdio.h>
#include<stdlib.h>
#define INF 9999

int n;  //where n= no.of vertices
int s;  //s= no.of stages
int **cost; //adjacency cose matrix
int *p;     //path array to store shortes
int *b;     //backtracking array
int *ns;    //no. of vertices at each stage
int **sv;   //store the vertices at each stage
int *c;     //cost array for forward approach

//function to find the minimum vertex with minimum cost

int min(int a, int b)
{
    return (a <  b) ? a : b;
}

void readGraph()
{
    int i, j, f, d, v, cst;

    printf("\nEnter number of vertices : ");
    scanf("%d",&n);
    printf("\nEnter number of stages : ");
    scanf("%d",&s);

    //allocate memory for array
    cost = (int **)malloc((n+1)*sizeof(int *));
    for(i=0; i<=n; i++)
        cost[i] = (int*)malloc((n+1)*sizeof(int));

    p = (int*)malloc((s+1)*sizeof(int));
    b = (int*)malloc((n+1)*sizeof(int));
    ns = (int*)malloc((s+1)*sizeof(int));
    sv = (int**)malloc((s+1)*sizeof(int*));
    c = (int*)malloc((n+1)*sizeof(int));

    for(i=1; i<=s; i++)
    {
        printf("\nEnter number of vertices in stage %d : ",i);
        scanf("%d",&ns[i]);
        sv[i] = (int*)malloc((ns[i]+1)*sizeof(int));
    }

    //assign vertex num,bers in each stage sequesntially , vertex numbering starts from 1
    int x=1;
    for(i = 1; i <= s; i++)
    {
        for(j = 1; j<=ns[i]; j++)
        {
            sv[i][j] = x++;
        }
    }

    //init cost matrix with INF
    for(i = 1; i<=n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            cost[i][j] = INF;
        }
    }

    //input edge costs
    printf("\nIf no edge exists enter 9999");
    for(f=1; f<= s-1; f++)
    {
        for(i = 1; i <= ns[f]; i++)
        {
            for(j = 1; j<= ns[f+1]; j++)
            {
                printf("\nEnter cost of edge from %d to %d : ", sv[f][i], sv[f+1][j]);
                scanf("%d",&cst);
                v = sv[f + 1][j];
                d = sv[f][i];
                cost[d][v] = cst;
            }
        }
    }
}


//function to compute shopetest path using forward approach
void forward()
{
    int i, j, k, v, u;
    c[1] = 0;  //cost to reach source vertex is 0

    for(j = 2; j <= n; j++)
    {
        c[j] = INF; //init cost to all other vertices as INF
    }

    //forWARD CALCULATION FROM STAGE 1 TO STAGE S
    for(j = 1; j <= s-1; j++)
    {
        for(i = 1; i <= ns[j]; i++)
        {
            v = sv[j][i];
            for(k = 1; k<= ns[j+1] ; k++)
            {
                u = sv[j+1][k];
                if(c[u] > c[v] + cost[v][u])
                {
                    c[u] = c[v] + cost[v][u];
                    b[u] = v;
                }
            }
        }
    }

    //construct path
    p[1] = 1;
    p[s] = n;
    for(j = s-1;  j > 1; j--)
    {
        p[j] = b[p[j+1]];
    }

    //print result
    printf("\nMinimum cost = %d ",c[n]);
    printf("Path : ");
    for(i = 1; i<=s; i++)
    {
        printf("%d",p[i]);
        if(i!= s)
            printf("-->");
    }
    printf("\n");
}

void main()
{
    readGraph();
    forward();
}
