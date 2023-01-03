#include <stdio.h>

int main(){
    int n, m, rounds = 0;
    scanf("%d %d", &n, &m);
    while(m > n){
        if(m % 2 == 0){
            m = m/2;
            rounds++;
        }
        else if(m % 3 == 0){
            m = m/3*2;
            rounds++;
        }
        else{
            printf("-1");
            return 0;
        }
    }
    if(m == n){
        printf("%d", rounds);
    }
    else{
        printf("-1");
    }
    return 0;
}
