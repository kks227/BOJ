#include <cstdio>
#include <vector>
using namespace std;
const int MAX_P = 2000000;

int main(){
    bool np[MAX_P] = {true, true,};
    vector<int> prime(1, 2);
    for(int i = 3; i < MAX_P; i += 2){
        if(np[i]) continue;
        prime.push_back(i);
        for(long long j = 1LL*i*i; j < MAX_P; j += i*2)
            np[j] = true;
    }

    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t){
        long long A, B;
        scanf("%lld %lld", &A, &B);
        long long N = A+B;
        bool result = false;
        if(N == 2) result = false;
        else if(N%2){
            N -= 2;
            if(N < MAX_P) result = !np[N];
            else{
                result = true;
                for(int p: prime){
                    if(1LL*p*p > N) break;
                    if(N%p == 0){
                        result = false;
                        break;
                    }
                }
            }
        }
        else result = true;
        puts(result ? "YES" : "NO");
    }
}