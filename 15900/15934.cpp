#include <cstdio>
#include <cstring>
#include <utility>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;
const int MAX = 50;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
typedef pair<int, int> P;

int R, C, A[MAX][MAX], B[MAX][MAX];
bool opened[MAX][MAX], visited[MAX][MAX];

int dfs(int r, int c){
    visited[r][c] = true;
    for(int d = 0; d < 4; ++d){
        int nr = r+roff[d], nc = c+coff[d];
        if(nr < 0 || nr >= R || nc < 0 || nc >= C || !opened[nr][nc]) continue;

        int v = B[nr][nc];
        if(v == -1){
            A[r][c] = nr*MAX + nc;
            B[nr][nc] = r*MAX + c;
            return A[r][c];
        }
        if(!visited[v/MAX][v%MAX]){
            int temp = dfs(v/MAX, v%MAX);
            if(temp >= 0){
                A[r][c] = nr*MAX + nc;
                B[nr][nc] = r*MAX + c;
                return temp;
            }
        }
    }
    return -1;
}



int main(){
    int D, W, y[MAX][MAX], Z = 0, K = 0, L = 0;
    scanf("%d %d %d %d", &R, &C, &D, &W);
    P p[MAX*MAX];
    set<int> H;
    for(int i = 0; i < R; ++i){
        for(int j = 0; j < C; ++j){
            scanf("%d", &y[i][j]);
            p[i*C+j] = P(y[i][j], i*MAX + j);
            H.insert(y[i][j]);
            Z = max(y[i][j], Z);
        }
    }
    sort(p, p+R*C);

    int pos = R*C-1;
    long long result = 1LL*Z*W;
    unordered_set<int> aSet, bSet;
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
    for(auto rIter = H.rbegin(); rIter != H.rend(); ++rIter){
        for(; pos >= 0 && p[pos].first == Z; --pos){
            int temp = p[pos].second;
            int r = temp/MAX, c = temp%MAX;
            opened[r][c] = true;
            ((r+c)%2 ? bSet : aSet).insert(temp);
            ++K;
        }

        if(aSet.size() == bSet.size()){
            for(auto iter = aSet.begin(); iter != aSet.end(); ){
                memset(visited, false, sizeof(visited));
                int a = *iter;
                int b = dfs(a/MAX, a%MAX);
                if(b >= 0){
                    auto tempIter = iter;
                    ++tempIter;
                    aSet.erase(iter);
                    iter = tempIter;
                    bSet.erase(b);
                    ++L;
                }
                else break;
            }
        }

        Z = (pos < 0 ? 0 : p[pos].first);
        if(K == L*2) result = min(1LL*L*D + 1LL*Z*W, result);
    }
    printf("%lld\n", result);
}