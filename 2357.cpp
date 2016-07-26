#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int minST[262144], maxST[262144];

int main(){
	int N, M, start = 2;
	scanf("%d %d", &N, &M);
	for(int i=0; i<262144; i++)
		minST[i] = 0x7FFFFFFF;
	while(start <= N) start *= 2;

	for(int i=0; i<N; i++){
		int val, cur = start+i;
		scanf("%d", &val);
		while(cur){
			minST[cur] = min(minST[cur], val);
			maxST[cur] = max(maxST[cur], val);
			cur /= 2;
		}
	}
	for(int i=0; i<M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a += start-1;
		b += start-1;
		if(a == b){
			printf("%d %d\n", minST[a], maxST[a]);
			continue;
		}
		int minR = 0x7FFFFFFF, maxR = 0;
		while(a != b){
			if(a%2){
				minR = min(minR, minST[a]);
				maxR = max(maxR, maxST[a]);
				a = a/2+1;
			}
			else a /= 2;
			if(b%2 == 0){
				minR = min(minR, minST[b]);
				maxR = max(maxR, maxST[b]);
				b = b/2-1;
			}
			else b /= 2;
			if(a >= b){
				if(a == b){
					minR = min(minR, minST[b]);
					maxR = max(maxR, maxST[b]);
				}
				break;
			}
		}
		printf("%d %d\n", minR, maxR);
	}
}