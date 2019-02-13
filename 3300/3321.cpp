#include <cstdio>
#include <list>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX_R = 15000;
const int MAX_C = 1500;
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
    int R, C, result = 0, H[MAX_C] = {0,};
    scanf("%d %d", &R, &C);
    list<P> cnt;
    cnt.push_back(P(0, C+1));
    list<P>::iterator ptr[MAX_C];
    fill(ptr, ptr+C, cnt.begin());

    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            int val;
            scanf("%1d", &val);

            if(val){
                auto tempPtr = ptr[j]++;
                if(ptr[j] == cnt.end() || ptr[j]->first > H[j]+1){
                    if(tempPtr->second == 1) ++((--ptr[j])->first);
                    else{
                        cnt.insert(ptr[j], P(H[j]+1, 1));
                        --ptr[j];
                        if(--(tempPtr->second) == 0) cnt.erase(tempPtr);
                    }
                }
                else{
                    ++(ptr[j]->second);
                    if(--(tempPtr->second) == 0) cnt.erase(tempPtr);
                }
                ++H[j];
            }
            else if(H[j] > 0){
                if(--(ptr[j]->second) == 0) cnt.erase(ptr[j]);
                H[j] = 0;
                ptr[j] = cnt.begin();
                ++(ptr[j]->second);
            }
        }

        int width = 0;
        for(auto rIter = cnt.rbegin(); rIter != cnt.rend(); ++rIter){
            width += rIter->second;
            result = max(width * rIter->first, result);
        }
    }
    printf("%d\n", result);
}