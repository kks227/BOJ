#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1000;

int main(){
    int N, L, Q, pos[MAX];
    scanf("%d %d %d", &Q, &N, &L);
    for(int i = 0; i < N; ++i)
        scanf("%d", pos+i);

    int lo = 0, hi = L;
    for(int q = 0; q < Q; ++q){
        int k;
        scanf("%d", &k);
        while(lo+1 < hi){
            int mid = (lo+hi)/2, temp = 0, cnt = 0;
            bool flag = true;
            for(int i = 0; i < N; ++i){
                if(pos[i]-temp <= mid) continue;
                if(cnt == k){
                    flag = false;
                    break;
                }
                ++cnt;
                temp = pos[i];
            }
            if(L-temp > mid) flag = (cnt < k);
            (flag ? hi : lo) = mid;
        }
        printf("%d\n", hi);
        lo = 0;
    }
}