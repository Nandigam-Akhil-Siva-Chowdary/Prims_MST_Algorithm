#include<stdio.h>
#include<stdlib.h>

#define INF 9999
#define MAX 20

int cost[MAX][MAX];
int t[MAX][2];
int near[MAX];
int n;

//Function to find the minimum cost edge
int minCostEdge(int *u, int *v)
{
    int min = INF;
    for(int i = 1;i<=n;i++)
    {
        for(int j = i; j <= n; j++)
        {
            if(cost[i][j] < min)
            {
                min = cost[i][j];
                *u = i;
                *v = j;
            }
        }
    }
    return min;
}


//prims function
void prims()
{
    int i, j, k, l, u, v, minCost, totalCost = 0;

    //step-1 : Finding minimum cost edge
    minCost = minCostEdge(&u, &v);
    t[1][0] = u;
    t[1][1] = v;
    totalCost += minCost;


    //step-2 : Initialise nearerst array
    for(int i = 1; i<= n; i++)
    {
        if(cost[i][u] < cost[i][v])
        {
            near[i] = u;
        }
        else
        {
            near[i] = v;
        }
    }
    near[u] = 0;
    near[v] = 0;


    //Step-3 : Repeat for (n-2) edges
    for(i = 2; i <= n-1; i++)
    {
        minCost = INF;
        int k = 0;

        for(j = 1; j<= n; j++)      //Find the vertex with min cost edge
        {
            if(near[j] != 0 && cost[j][near[j]] < minCost)
            {
                minCost = cost[j][near[j]];
                k = j;
            }
        }
        //Store edge in MST
        t[i][0] = k;
        t[i][1] = near[k];

        totalCost += cost[k][near[k]];
        near[k] = 0;


        //update nearest array
        for(j = 1; j <= n; j++)
        {
            if(near[j] != 0 && cost[j][k] < cost[j][near[j]])
                near[j] = k;
        }
    }


    //step-4 : Print the MST
    printf("\nEdges in minimum Spanning Tree are : \n");
    for(i = 1; i <= n-1; i++)
    {
        printf("%d -- %d\n", t[i][0], t[i][1]);
    }

    printf("\nTotal cost of MST : %d\n",totalCost);
}


//Function to read graph
void readGraph()
{
    int edges, v1, v2, w;
    printf("\nEnter number of vertices : ");
    scanf("%d",&n);

    //init cost matrix with INF
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            cost[i][j] = INF;
        }
    }

    printf("\nEnter number of edges : ");
    scanf("%d",&edges);

    for(int i=1; i <= edges; i++)
    {
        printf("Enter edge %d(v1 v2 cost) : ",i);
        scanf("%d %d %d",&v1, &v2, &w);
        cost[v1][v2] = w;
        cost[v2][v1] = w;
    }
}

void main()
{
    readGraph();
    prims();
}
