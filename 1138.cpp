#include <cstdio>
using namespace std;
 
int main(){
 
    int N;
	scanf("%d", &N);
    int left, cnt, i, j;
    int pos[10] = {0};
    for(i=0; i<N; i++){
		scanf("%d", &left);
        cnt = j = 0;
        while(1){
            if(pos[j]){
                j++;
                continue;
            }
            if(cnt == left) break;
            j++;
            cnt++;
        }
        pos[j] = i+1;
    }
    for(int i=0; i<N; i++)
		printf("%d ", pos[i]);
 
    return 0;
}