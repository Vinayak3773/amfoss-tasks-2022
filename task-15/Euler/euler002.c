#include <stdio.h>

int main() 
{
    int t;
    scanf("%d", &t);

    while(t--) {
        long n, sum = 0;
        scanf("%ld", &n);

        long a = 0, b = 2;
        while(b <= n) {
            sum += b;
            long c = 4*b + a;
            a = b;
            b = c;
        }
        printf("%ld\n", sum);
    }
    return 0;
