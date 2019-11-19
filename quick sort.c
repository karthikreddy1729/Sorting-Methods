#include<stdio.h>
#include<stdlib.h>

int partation(int a[],int l,int h)
{
    int i,j,p;
    i=l;
    j=h;
    p=a[l];
    while(i<j)
    {
        do
        {
            i++;
        }while(a[i]<=p);
        do
        {
            j--;
        }while(a[j]>p);
        int temp;
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    int m;
    m=a[j];
    a[j]=a[l];
    a[l]=m;
    return j;
}
void quicksort(int a[],int l,int h)
{
    if(l<h)
    {
        int m;
        m=partation(a,l,h);
        quicksort(a,l,m);
        quicksort(a,m+1,h);
    }
}
int main()
{
    int n;
    int a[100];
    printf("enter the number of elements in the array :");
    scanf("%d",&n);
    printf("enter the elements in the array : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}


