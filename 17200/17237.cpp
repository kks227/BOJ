#include <cstdio>
using namespace std;

int main(){
    int N;
    scanf("%d", &N);
    double sum = 0;
    for(int i = 0; i < N; ++i){
        int val;
        scanf("%d", &val);
        sum += 1.0/(1<<val);
    }
    puts(sum >= 1 ? "A" : "B");
}