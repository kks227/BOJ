#include <cstdio>
#include <cstring>
using namespace std;
 
int main(){
 
    bool map[100][100] = {0};
    int N, x, y;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d %d", &x, &y);
        for(int i=0; i<10; i++)
            memset(&map[y+i][x], 1, 10);
    }
    int result = 0;
    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(i<99 && map[i][j] != map[i+1][j]) result++;
            if(j<99 && map[i][j] != map[i][j+1]) result++;
		}
	}
	for(int i=0; i<100; i++)
		result += map[i][0] + map[i][99];
	for(int j=0; j<100; j++)
		result += map[0][j] + map[99][j];
    printf("%d\n", result);
  
    return 0;
}