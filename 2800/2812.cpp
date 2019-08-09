#include <cstdio>
#include <deque>
using namespace std;

int main(){
    int N, K;
    deque<char> D;
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i){
        int d;
        scanf("%1d", &d);
        while(K > 0 && !D.empty() && D.back() < d){
            D.pop_back();
            --K;
        }
        D.push_back(d);
    }
    for(int i = D.size()-K; i > 0; --i){
        printf("%1d", D.front());
        D.pop_front();
    }
}