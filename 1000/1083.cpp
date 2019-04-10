#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main(){
    int N, S, A[50];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", A+i);
    scanf("%d", &S);
    for(int i = 0; i < N && S > 0; ++i){
        P p[50];
        for(int j = i; j < N; ++j)
            p[j-i] = P(A[j], j);
        sort(p, p+N-i);
        for(int k = N-i-1; k >= 0; --k){
            int l = p[k].second;
            if(l-i <= S){
                S -= l-i;
                rotate(A+i, A+l, A+l+1);
                break;
            }
        }
    }
    for(int i = 0; i < N; ++i)
        printf("%d ", A[i]);
}