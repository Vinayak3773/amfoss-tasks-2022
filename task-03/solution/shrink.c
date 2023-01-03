#include <stdio.h>

int main()
    
{
    int repeat=0;
    int s=-1;
    int n, sum = 0, m;
    scanf("%d", &n);
    while(s!=0)
    {
         while (n > 0)
       {
        m = n % 10;
        sum = sum + m;
        n = n / 10;
       }
       if(sum>=0 && sum<=9)
       {
        repeat++;
        s=0;
       }
       else
       {
        repeat++;
        n=sum;
        sum=0;
       }
    }
    printf("%d\n",repeat);
    return 0;
}

