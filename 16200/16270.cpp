#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;
const int MAX_P = 40001;
const int LIMIT = 1e9;

vector<int> factor;
long long x[2], res[2];

void dfs(int pos){
    if(pos == factor.size()){
        if(x[0]+x[1] < res[0]+res[1]){
            res[0] = x[0];
            res[1] = x[1];
        }
        return;
    }

    x[0] *= factor[pos];
    dfs(pos+1);
    x[0] /= factor[pos];
    x[1] *= factor[pos];
    dfs(pos+1);
    x[1] /= factor[pos];
}

int main(){
    bool np[MAX_P] = {true, true,};
    vector<int> prime(1, 2);
    for(int i = 3; i < MAX_P; i += 2){
        if(np[i]) continue;
        prime.push_back(i);
        for(int j = i*i; j < MAX_P; j += i*2)
            np[j] = true;
    }

    int T;
    scanf("%d", &T);
    for(int t = 0; t < T; ++t){
        unordered_map<int, int> cnt;
        for(int i = 0; i < 2; ++i){
            int val;
            scanf("%d", &val);
            for(int p: prime){
                if(val == 1) break;
                while(val % p == 0){
                    val /= p;
                    if(cnt.find(p) == cnt.end()) cnt[p] = 1;
                    else ++cnt[p];
                }
            }
            if(val > 1){
                if(cnt.find(val) == cnt.end()) cnt[val] = 1;
                else ++cnt[val];
            }
        }

        factor.clear();
        for(auto &p: cnt)
            if(p.second%2 == 1) factor.push_back(p.first);
        x[0] = x[1] = 1;
        res[0] = res[1] = 1LL * LIMIT * LIMIT;
        dfs(0);
        printf("%lld %lld\n", res[0], res[1]);
    }
}