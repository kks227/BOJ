#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
const int MAX = 50;

int main(){
    int N, limit[MAX], M, maxLimit = 0, maxLoad = 0;
    multiset<int> S;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i){
        scanf("%d", limit+i);
        maxLimit = max(limit[i], maxLimit);
    }
    scanf("%d", &M);
    for(int i = 0; i < M; ++i){
        int val;
        scanf("%d", &val);
        maxLoad = max(val, maxLoad);
        S.insert(-val);
    }
    if(maxLimit < maxLoad){
        puts("-1");
        return 0;
    }

    for(int result = 0; ; ++result){
        if(S.empty()){
            printf("%d\n", result);
            return 0;
        }

        for(int i = 0; i < N; ++i){
            auto iter = S.lower_bound(-limit[i]);
            if(iter != S.end()) S.erase(iter);
        }
    }
}