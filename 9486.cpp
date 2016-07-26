#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int cache[262144][18], N;
char S[19];

int minPress(int status, int pos){
	if(status == (1<<N)-1) return 0;
	int &ret = cache[status][pos];
	if(ret != -1) return ret;
	ret = 0x7FFFFFFF;
	if(status == 0){
		for(int i=0; i<N; i++){
			int updown = S[i]-'A';
			if(updown > 13) updown = 26 - updown;
			ret = min(ret, minPress(1<<i, i)+1+updown);
		}
	}
	else{
		for(int i=0; i<N; i++){
			if(status & (1<<i)) continue;
			int updown = abs(S[i]-S[pos]);
			if(updown > 13) updown = 26 - updown;
			int move = 0;
			if(i < pos){
				move++;
				for(int j=i+1; j<pos; j++)
					if(status & (1<<j)) move++;
			}
			else{
				for(int j=pos+1; j<i; j++)
					if(status & (1<<j)) move++;
			}
			ret = min(ret, minPress(status | (1<<i), i)+1+updown+move);
		}
	}
	return ret;
}

int main(){
	while(1){
		scanf("%s", S);
		if(S[0] == '0') break;
		N = strlen(S);
		memset(cache, -1, sizeof(cache));
		printf("%d\n", minPress(0, 0));
	}
}