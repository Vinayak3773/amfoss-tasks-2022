#include<stdio.h>
 
int main()
{
    int n,i,j,sum=0,count=0;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    while(sum!=0)
    {
        j=sum;
        if(j>=4)
        {
            j=4;
            sum-=4;
        }
        else
        {
            sum-=j;
        }
        count++;
    }
    printf("%d",count);
    return 0;
}
