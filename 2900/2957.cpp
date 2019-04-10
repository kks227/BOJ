#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int N;
    long long C = 0;
    scanf("%d", &N);
    map<int, int> depth;
    for(int i = 0; i < N; ++i){
        int k;
        scanf("%d", &k);
        if(i == 0) depth[k] = 1;
        else{
            int temp = 0;
            auto iter = depth.upper_bound(k);
            if(iter != depth.end()){
                temp = iter->second;
            }
            if(iter != depth.begin()){
                --iter;
                temp = max(iter->second, temp);
            }
            C += temp;
            depth[k] = temp + 1;
        }
        printf("%lld\n", C);
    }
}