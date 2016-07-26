#include <cstdio>
using namespace std;
 
int main(){
 
    int N;
	scanf("%d", &N);
    long long fact5 = 1, power5;
    int temp;
 
    for(int i=2; i<=N; i++){
        power5 = i;
        while(power5 % 5 == 0){
            power5 /= 5;
            fact5 /= 2;
        }
        fact5 *= power5;
        fact5 %= 100000000000000;
    }
 
    fact5 %= 100000;
    temp = fact5;
    for(int i=0; i<5; i++){
        if(temp == 0) putchar('0');
        temp /= 10;
    }
    printf("%lld\n", fact5);
 
    return 0;
}