#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, K, result;
vector<int> need[50];
char c[22] = "bdefghjklmopqrsuvwxyz";
bool used[26];

void dfs(int pos, int cnt){
    if(cnt == K){
        int temp = 0;
        for(int i = 0; i < N; ++i){
            bool flag = true;
            for(int j: need[i]){
                if(!used[j]){
                    flag = false;
                    break;
                }
            }
            if(flag) ++temp;
        }
        result = max(temp, result);
        return;
    }
    if(K-cnt > 21-pos) return;

    dfs(pos+1, cnt);
    used[c[pos]-'a'] = true;
    dfs(pos+1, cnt+1);
    used[c[pos]-'a'] = false;
}

int main(){
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; ++i){
        char S[16];
        scanf("%s", S);
        int L = strlen(S);
        for(int j = 4; j < L-4; ++j)
            need[i].push_back(S[j]-'a');
    }
    if(K < 5) puts("0");
    else{
        K -= 5;
        used[0] = used[2] = used[8] = used[13] = used[19] = true;
        dfs(0, 0);
        printf("%d\n", result);
    }
}