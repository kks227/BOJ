#include <cstdio>
using namespace std;

int main(){
    while(1){
        int d[16];
        bool flag = false;
        for(int i = 0; i < 16; ++i){
            scanf("%1d", d+i);
            if(d[i] > 0) flag = true;
        }
        if(!flag) break;

        int p = 0, q = 0;
        for(int i = 0; i < 8; ++i){
            int r = d[i*2] * 2;
            p += (r > 9 ? r-9 : r);
            q += d[i*2+1];
        }
        puts((p+q)%10 ? "No" : "Yes");
    }
}