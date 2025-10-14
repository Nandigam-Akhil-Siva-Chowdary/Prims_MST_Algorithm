#include<stdio.h>
#include<stdlib.h>

int n; //n = no.of items
float *p, *w, *u, *x, m;

// p[i] = profit of item i
// w[i]  = weight of item i
// u[i] = profit-to-weight ratio of item i
// x[i] = fraction of item i for solution vector
// m = knapsack capacity

void show()
{
    printf("Item\tWeight\tProfit\tRatio\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d\t%.2f\t%.2f\t%.2f\n", i+1, w[i], p[i], u[i]);
    }
}

void sort()
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            if(u[i] < u[j])
            {
                float temp;
                temp = u[i];
                u[i] = u[j];
                u[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;

                temp = w[i];
                w[i] = w[j];
                w[j] = temp;
            }
        }
    }
}

void find()
{
    float profit = 0.0;
    for(int i = 0; i < n; i++)
    {
        if(w[i] > m)
        {
            float t = m / w[i];
            profit += t * p[i];
            x[i] = t;
            printf("Profit = %.2f\n", profit);
            return;
        }
        profit += p[i]; //full profit if item fits
        m -= w[i];      //reduce knapsack capacity
        x[i] = 1.0;     //full item taken
    }
    printf("Profit = %.2f\n", profit);
}

//prints the solution vector
void solve()
{
    printf("Solution vector (x[]) : \n");
    for(int i = 0; i < n ; i++)
    {
        printf("x[%d] = %.2f\n", i+1, x[i]);
    }
}


int main()
{
    printf("Enter number of items : ");
    scanf("%d", &n);

    //memory allocation
    w = (float *)malloc(n * sizeof(float));
    p = (float *)malloc(n * sizeof(float));
    u = (float *)malloc(n * sizeof(float));
    x = (float *)malloc(n * sizeof(float));

    printf("Enter knapsack capacity : ");
    scanf("%f", &m);

    printf("Enter profits :\n");
    for(int i = 0; i < n; i++)
    {
        printf("p[%d] : ",i);
        scanf("%f",&p[i]);
    }

    printf("\nEnter weights  :\n");
    for(int i = 0; i < n ; i++)
    {
        printf("w[%d] : ",i);
        scanf("%f",&w[i]);
    }

    for(int i = 0; i < n; i++)
    {
        u[i] = p[i] / w[i];
        x[i] = 0.0;
    }

    show(); //display inputs
    sort();
    find();
    solve();

    free(p);
    free(w);
    free(x);
    free(u);

}
