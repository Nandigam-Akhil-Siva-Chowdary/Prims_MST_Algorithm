#include<stdio.h>
#define INF 9999
#define MAX 11

void dijkstra(int n, int cost[MAX][MAX], int source)
{
    int dist[MAX], visited[MAX], u, v, count, min;

    for(int i = 1; i<= n; i++)
    {
        dist[i] = cost[source][i];      //distance from source to each vertex
        visited[i] = 0;      //innitialy mark all vertices as unvisited
    }

    dist[source] = 0; //distance from source to source is 0
    visited[source] = 1;  //mark source as visited

    //repeat process n-1 times to update shortest paths
    for(count = 2; count <= n; count++)
    {
        min = INF;
        u = -1;     //to store the vertex with min distance


        //finding unvisited vertex with smaller distance
        for(int i = 1; i<=n; i++)
        {
            if(!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if(u == -1)
            break;
        visited[u] = 1;


        //update distances of neighbours of u
        for(v = 1; v <= n; v++)
        {
            /*update d[v] only if
            1. v is not visited
            2. there is an edge from u to v(cost[u][v] != INF)
            3. the new path is shorter */

            if(!visited[v] && cost[u][v] != INF && dist[u] + cost[u][v] < dist[v])
            {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    //print the final shortest distances from the source
    printf("\nShortest distances from source %d :\n", source);
    for(int i=1; i <= n; i++)
    {
        if(dist[i] == INF)
        {
            printf("Node %d  : unreachable \n", i);
        }
        else{
            printf("Node %d : %d \n", i, dist[i]);
        }
    }
}

void main()
{
    int n, source;
    int cost[MAX][MAX];

    printf("\nEnter number of vertices : ");
    scanf("%d",&n);


    //input code adjacency matrix
    //use 9999 if there is no edge b/w them
    printf("\nEnter cost adjacency matrix(use %d for INF) :\n",INF);
    for(int i = 1; i<= n;i++)
    {
        for(int j = 1; j<= n; j++)
        {
            scanf("%d",&cost[i][j]);
        }
    }

    printf("\nEnter your source vertex : ");
    scanf("%d",&source);

    dijkstra(n, cost, source);
}
