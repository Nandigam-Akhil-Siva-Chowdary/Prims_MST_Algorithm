#include<stdio.h>
#define N 25

void MergeSort(int [], int , int);
void Merge(int[], int , int , int);
void Display(int [],int);

void MergeSort(int a[], int low , int high)
{   int mid;
    if(low < high)
    {
        mid = (low + high ) / 2;    //finding middle element
        MergeSort(a, low, mid);     //sorting first half
        MergeSort(a, mid + 1 , high);//sorting second half
        Merge(a, low, mid, high);   //merging all elements
    }
}

void Merge(int a[], int low, int mid, int high)
{
    int h = low, i = low, j = mid + 1, b[N];
    while((h <= mid) && (j <= high))
    {
        if(a[h] <= a[j])
        {
            b[i] = a[h];
            h = h + 1;
        }
        else
        {
            b[i] = a[j];
            j = j + 1;
        }
        i = i + 1;
    }
    if(h > mid)
    {
        for(int k = j ; k <= high ; k++)
        {
            b[i] = a[k];
            i = i + 1;
        }
    }
    else
    {
        for(int k = h; k <= mid; k++)
        {
            b[i] = a[k];
            i = i + 1;
        }
    }
    for(int k = low; k <= high ; k++)
    {
        a[k] = b[k];
    }
}

void Display(int a[], int n)
{
    for(int i = 0; i < n ; i ++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main()
{
    int a[N], n;
    printf("\nEnter your array size : ");
    scanf("%d",&n);
    printf("\nEnter your array elements : ");
    for(int i = 0; i < n; i ++)
    {
        printf("\na[%d] : ",i);
        scanf("%d",&a[i]);
    }
    printf("\nYour array before sorting : ");
    Display(a, n);
    MergeSort(a, 0, n-1);
    printf("\nYour array after sorting : ");
    Display(a, n);
}
