#include <cstdio>
#include <vector>
using namespace std;

int main(){
    while(1){
        int N;
        scanf("%d", &N);
        if(N < 0) break;

        vector<int> d;
        int sum = 1;
        for(int i = 2; i < N; ++i){
            if(N%i == 0){
                sum += i;
                d.push_back(i);
            }
        }
        if(sum == N){
            printf("%d = 1", N);
            for(int n: d) printf(" + %d", n);
            puts("");
        }
        else printf("%d is NOT perfect.\n", N);
    }
}