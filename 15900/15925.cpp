#include <cstdio>
using namespace std;

int main(){
	int N, cnt[2][31] = {0}, map[31][31], D;
	scanf("%d %d", &N, &D);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &map[i][j]);
			if(D) map[i][j] = !map[i][j];
			cnt[0][i] += map[i][j];
			cnt[1][j] += map[i][j];
		}
	}

	bool renewed[2] = {true, true};
	while(renewed[0] || renewed[1]){
		for(int k=0; k<2; k++){
			renewed[k] = false;
			for(int i=0; i<N; i++){
				if(cnt[k][i] > 0 && cnt[k][i] <= N/2){
					renewed[k] = true;
					for(int j=0; j<N; j++){
						if(k == 0){
							if(map[i][j]){
								map[i][j] = 0;
								cnt[!k][j]--;
							}
						}
						else{
							if(map[j][i]){
								map[j][i] = 0;
								cnt[!k][j]--;
							}
						}
					}
					cnt[k][i] = 0;
				}
			}
		}
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(map[i][j]){
				puts("0");
				return 0;
			}
		}
	}
	puts("1");
}