#include <cstdio>
using namespace std;

int treeCnt[20] = {1};
char ch[20] = "abcdefghijklmnopqrs";

void encode(int index, int start, int end){
	/*
	printf("\n%d %d %d\n", index, start, end);
	for(int i=start; i<end; i++)
		printf("%c ", ch[i]);
	puts("");
	*/
	if(end-start == 1){
		putchar(ch[start]);
		return;
	}
	if(end == start) return;

	int rangeSum = 0, tempSum, nextIndex;
	bool breaker;
	for(int i=start; i<end; i++){
	//	printf("RS: %d\n", rangeSum);
		if(index < rangeSum + treeCnt[i-start]*treeCnt[end-i-1]){
			putchar(ch[i]);
			tempSum = 0;
			nextIndex = 0;
			breaker = false;
			for(int j=0; j<i-start; j++){
				for(int k=0; k<treeCnt[j]*treeCnt[i-start-1-j]; k++){
					if(index < rangeSum + tempSum + treeCnt[end-i-1]){
						breaker = true;
						break;
					}
					tempSum += treeCnt[end-i-1];
					nextIndex++;
				}
				if(breaker) break;
			}
			encode(nextIndex, start, i);
			encode(index-rangeSum-tempSum, i+1, end);
			return;
		}
		rangeSum += treeCnt[i-start]*treeCnt[end-i-1];
	}
}

int main(){

	int N, index;
	scanf("%d %d", &N, &index);
	for(int i=1; i<=N; i++){
		for(int j=0; j<i; j++)
			treeCnt[i] += treeCnt[j]*treeCnt[i-j-1];
	}/*
	for(int i=0; i<=N; i++)
		printf("%02d: %d\n", i, treeCnt[i]);*/
	if(index > treeCnt[N]){
		printf("-1\n");
		return 0;
	}

	encode(index-1, 0, N);
	putchar('\n');

	return 0;
}