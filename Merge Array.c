#include<stdio.h>
void main()
{
    int i,j,n,m,temp;
    printf("enter the size of the first array");
    scanf("%d",&n);
    printf("enter the size of the second array");
    scanf("%d",&m);
    int arr1[n],arr2[m],arr3[n+m];
     printf("enter %d numbers of the first array\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr1[i]);
        arr3[i]=arr1[i];
    }
     printf("enter %d numbers of the second array\n",m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&arr2[i]);
        arr3[i+n]=arr2[i];
    }
    printf("the first array is\n");
    for(i=0;i<n;i++)
    {
        printf("%d",arr1[i]);
        
    }
    printf("the second array is\n");
    for(i=0;i<m;i++)
    {
        printf("%d",arr2[i]);
        
    }
    printf("the array elements 1 and 2 joined is\n");
    for(i=0;i<n+m;i++)
    {
        printf("%d",arr3[i]);
    }
    printf("the sorted array is");
    for(i=0;i<n+m;i++)
    {
        for(j=i+1;j<n+m;j++)
        {
            if(arr3[i]>arr3[j])
            {
                temp=arr3[i];
                arr3[i]=arr3[j];
                arr3[j]=temp;
            }
        }
    }
    for(int i=0;i<n+m;i++)
    {
        printf("%d",arr3[i]);
    }

}
       
