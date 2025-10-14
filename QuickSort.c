#include<stdio.h>
void QuickSort(int[] , int , int);
int Partition(int[] , int , int);
void Display(int[] , int);

void QuickSort(int arr[] , int p , int q)
{
    if(p < q)
    {
        int j = Partition(arr , p , q+1);
        QuickSort(arr , p , j-1);
        QuickSort(arr , j+1 , q);
    }
}

int Partition(int arr[] , int m, int n)
{
    int v = arr[m] , i = m , j = n;
    do
    {
        do
        {
            i++;
        }while(arr[i] <= v);
        do
        {
            j--;
        }while(arr[j] > v);
        if(i < j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }while(i<=j);
    arr[m] = arr[j];
    arr[j] = v;
    return j;
}

void Display(int arr[] , int n )
{
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d ",arr[i]);
    }
}

void main()
{
    int arr[20] , n;
    printf("\nEnter size of Array : ");
    scanf("%d",&n);
    printf("\nEnter your array elements : ");
    for(int i = 0; i < n ; i++)
    {
        printf("\nArr[%d] : ",i);
        scanf("%d",&arr[i]);
    }
    printf("\nYour Array before sorting : ");
    Display(arr , n);
    QuickSort(arr , 0 , n-1);
    printf("\nYour Array after sorting : ");
    Display(arr , n);
}
