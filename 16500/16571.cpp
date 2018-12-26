#include <cstdio>
#include <algorithm>
using namespace std;
const char UNDEF = -128;

char dp[19683];

char tictactoe(int curr){
    char &ret = dp[curr];
    if(ret != UNDEF) return ret;

    ret = -1;
    int map[3][3] = {0,}, next = 0, cnt = 0;
    for(int i = 8; i >= 0; --i){
        map[i/3][i%3] = curr % 3;
        if(map[i/3][i%3] > 0) ++cnt;
        curr /= 3;
    }
    for(int k = 1; k <= 2; ++k){
        bool flag;
        for(int r = 0; r < 3; ++r){
            flag = true;
            for(int c = 0; c < 3; ++c)
                if(map[r][c] != k) flag = false;
            if(flag) return ret = (k == 1 ? 1 : -1);
        }
        for(int c = 0; c < 3; ++c){
            flag = true;
            for(int r = 0; r < 3; ++r)
                if(map[r][c] != k) flag = false;
            if(flag) return ret = (k == 1 ? 1 : -1);
        }
        flag = true;
        for(int i = 0; i < 3; ++i)
            if(map[i][i] != k) flag = false;
        if(flag) return ret = (k == 1 ? 1 : -1);
        flag = true;
        for(int i = 0; i < 3; ++i)
            if(map[i][2-i] != k) flag = false;
        if(flag) return ret = (k == 1 ? 1 : -1);
    }
    if(cnt == 9) return ret = 0;

    for(int i = 0; i < 9; ++i)
        next = next*3 + (3-map[i/3][i%3])%3;
    int mul = 6561;
    for(int r = 0; r < 3; ++r){
        for(int c = 0; c < 3; ++c){
            if(map[r][c] == 0){
                char temp = tictactoe(next + 2*mul);
                if(temp < 0) return ret = 1;
                if(temp == 0) ret = 0;
            }
            mul /= 3;
        }
    }
    return ret;
}

int main(){
    fill(dp, dp+19683, UNDEF);
    int map[3][3] = {0,}, cnt[2] = {0,}, s = 0;
    for(int i = 0; i < 9; ++i){
        scanf("%d", &map[i/3][i%3]);
        if(map[i/3][i%3] > 0) ++cnt[map[i/3][i%3]-1];
    }
    for(int i = 0; i < 9; ++i){
        s *= 3;
        if(map[i/3][i%3] == 0) continue;
        s += (cnt[0] == cnt[1] ? map[i/3][i%3] : 3-map[i/3][i%3]);
    }
    char result = tictactoe(s);
    putchar(result == 0 ? 'D' : (result > 0 ? 'W' : 'L'));
}