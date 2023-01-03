#include<stdio.h>
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        
        int n;
        scanf("%d",&n);
        int i,sum=0;
        for(i=3;i<n;i++)
        {
            if((i%3==0)||(i%5==0))
            {
                sum=sum+i;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
