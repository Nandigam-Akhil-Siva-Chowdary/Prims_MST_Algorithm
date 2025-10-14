#include<stdio.h>
#include<stdio.h>
#define INF 9999

int n;
int **cost;
int *parent;

//Function to find the root parent of vertex i

int find(int i)
{
    while(parent[i] > 0)
    {
        i = parent[i];
    }
    return i;
}

//function to perform union of sets
void unionSets(int i, int j)
{
    parent[i] = j;
}

//Function to find edge of minimum cost
void minEdge(int *u, int *v, int *minCost)
{
    *minCost = INF;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n ; j++)
        {
            if(cost[i][j] < *minCost)
            {
                *minCost = cost[i][j];
                *u = i;
                *v = j;
            }
        }
    }
}

//Krushkals Algorithm Function
void Kruskal()
{
    int u, v, i , j, edges = 0, totalcosts = 0;
    for(int i = 1; i <=n; i++)
    {
        parent[i] = -1;
    }
    while(edges < n-1)
    {
        int minCost;
        minEdge(&u, &v, &minCost);
        cost[u][v] = cost[v][u] = INF;

        i = find(u);
        j = find(v);

        if(i != j)
        {
            printf("Edge %d : (%d -> %d) cost : %d\n", edges+1, u, v, minCost);
            edges++;
            totalcosts += minCost;
            unionSets(i, j);
        }
    }
    if(edges == n-1)
    {
        printf("\nMinimum spanning tree cost = %d\n", totalcosts );
    }
    else
    {
        printf("\nNo spanning tree exists...!\n");
    }
}

int main()
{
    printf("\nEnter number of vertices : ");
    scanf("%d",&n);

    cost = (int **)malloc((n+1) * sizeof(int *));
    for(int i = 0; i <= n; i++)
    {
        cost[i] = (int *)malloc((n+1)*sizeof(int));
    }
    parent = (int *)malloc((n+1)*sizeof(int));

    printf("\nEnter adjacency matrix (Enter %d for no edge) : \n", INF);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j] == 0)
            {
                cost[i][j] = INF;
            }
        }
    }

    Kruskal();
    for(int i = 0; i<= n; i++)
    {
        free(cost[i]);
    }
    free(cost);
    free(parent);

}
