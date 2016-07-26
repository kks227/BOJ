#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, M, card[100][100], score[100] = {0};
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++)
			scanf("%d", &card[i][j]);
		sort(card[i], card[i]+M);
	}
	for(int i=M-1; i>=0; i--){
		int t = 0;
		for(int j=0; j<N; j++)
			t = max(t, card[j][i]);
		for(int j=0; j<N; j++)
			if(t == card[j][i]) score[j]++;
	}
	int maxScore = -1;
	for(int i=0; i<N; i++)
		maxScore = max(maxScore, score[i]);
	for(int i=0; i<N; i++)
		if(maxScore == score[i]) printf("%d ", i+1);
}