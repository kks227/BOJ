#include <cstdio>
#include <cstring>
using namespace std;
 
#define MODULA 1000000000
 
char path[301];
int cache[301][301];
 
int countTree(int start, int end){
    int &ret = cache[start][end];
    if(ret != -1) return ret;
    if((start-end)%2 == 0) return ret = 0;
    if(start == end-1) return ret = 1;
    if(path[start] != path[end-1]) return ret = 0;
 
    ret = 0;
    for(int i=start+2; i<end; i+=2){
        if(path[start] != path[i]) continue;
        ret += ((long long)countTree(start+1, i) * countTree(i, end)) % MODULA;
        ret %= MODULA;
    }
    return ret;
}
 
int main(){
     
    scanf("%s", path);
    memset(cache, -1, sizeof(int)*301*301);
    printf("%d\n", countTree(0, strlen(path)));
 
    return 0;
}