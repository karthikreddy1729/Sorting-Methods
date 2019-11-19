#include<stdio.h>
#include<stdlib.h>

void merge(int a[],int l,int m,int h)
{
    int k,k1;
    k=h-m;
    k1=m-l+1;
    int b[k1],c[k];
    for(int i=0;i<k1;i++)
    {
        b[i]=a[l+i];
    }
    for(int i=0;i<k;i++)
    {
        c[i]=a[i+m+1];
    }
    int j1=0,j2=0,l1=l;
    while(j1<k1 && j2<k)
    {
        if(b[j1]<c[j2])
        {
            a[l1]=b[j1];
            l1++;
            j1++;
        }
        else
        {
            a[l1]=c[j2];
            l1++;
            j2++;
        }
    }
    for(;j1<k1;j1++)
    {
        a[l1]=b[j1];
        l1++;
    }
    for (;j2<k;j2++)
    {
        a[l1]=c[j2];
        l1++;
    }
}
void mergesort(int a[],int l,int h)
{
    if(l<h)
    {
        int m;
        m=(l+h)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,h);
        merge(a,l,m,h);
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
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}


