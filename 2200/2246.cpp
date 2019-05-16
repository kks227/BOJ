#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 10000;
typedef pair<int, int> P;

int main(){
    int N;
    P p[MAX];
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d %d", &p[i].first, &p[i].second);
    sort(p, p+N);
    int result = 1, minD = p[0].second;
    for(int i = 1; i < N; ++i){
        if(minD > p[i].second){
            ++result;
            minD = p[i].second;
        }
    }
    printf("%d\n", result);
}