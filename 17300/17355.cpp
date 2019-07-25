#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int MAX = 1e7;
const int MAX_SQRT = 3200;
const int MOD = 1000000007;

int main(){
    bool np[MAX] = {true, true, };
    vector<int> prime(1, 2);
    for(int i = 3; i < MAX; i += 2){
        if(np[i]) continue;
        prime.push_back(i);
        for(long long j = 1LL*i*i; j < MAX; j += i*2)
            np[j] = true;
    }

    int P = prime.size(), N;
    scanf("%d", &N);
    unordered_map<int, int> H;
    for(int i = 0; i < P; ++i)
        H[prime[i]] = i;
    vector<int> cnt[2];
    cnt[0].resize(P);
    cnt[1].resize(P);
    for(int i = 0; i < N; ++i){
        int val[2];
        scanf("%d %d", val, val+1);
        val[0] = val[1] - val[0];
        for(int k = 0; k < 2; ++k){
            for(int j = 0; val[k] > 1 && prime[j] < MAX_SQRT; ++j){
                while(val[k] % prime[j] == 0){
                    ++cnt[k][j];
                    val[k] /= prime[j];
                }
            }
            if(val[k] > 1) ++cnt[k][H[val[k]]];
        }
    }

    int result[2] = {1, 1};
    for(int i = 0; i < P; ++i){
        int temp = min(cnt[0][i], cnt[1][i]);
        for(int k = 0; k < 2; ++k){
            for(int j = temp; j < cnt[k][i]; ++j)
                result[k] = 1LL*result[k] * prime[i] % MOD;
        }
    }
    printf("%d %d\n", result[0], result[1]);
}