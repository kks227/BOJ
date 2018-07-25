#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int cnt[4] = {0}, result = 0;
	while(1){
		char c = getchar();
		if(c == '\n') break;

		int k = 0;
		if(c == 'u') k = 1;
		else if(c == 'a') k = 2;
		else if(c == 'c') k = 3;
		else if(c == 'k') k = 4;
		if(k > 0){
			if(cnt[k-1] == 0){
				puts("-1");
				return 0;
			}
			cnt[k-1]--;
		}
		if(k < 4) cnt[k]++;

		int temp = 0;
		for(int i=0; i<4; i++)
			temp += cnt[i];
		result = max(temp, result);
	}

	for(int i=0; i<4; i++){
		if(cnt[i] > 0){
			puts("-1");
			return 0;
		}
	}
	printf("%d\n", result);
}