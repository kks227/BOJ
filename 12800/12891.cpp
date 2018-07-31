#include <cstdio>
#include <unordered_map>
using namespace std;

int main(){
	int N, M, D[4], result = 0, cnt[4] = {0};
	char S[1000001];
	scanf("%d %d %s", &N, &M, S);
	for(int i=0; i<4; i++)
		scanf("%d", D+i);
	unordered_map<char, int> C2I;
	C2I['A'] = 0; C2I['C'] = 1; C2I['G'] = 2; C2I['T'] = 3;
	for(int i=0; i<M-1; i++)
		cnt[C2I[S[i]]]++;
	for(int i=M-1; i<N; i++){
		cnt[C2I[S[i]]]++;
		bool flag = true;
		for(int j=0; j<4; j++)
			if(cnt[j] < D[j]) flag = false;
		if(flag) result++;
		cnt[C2I[S[i-M+1]]]--;
	}
	printf("%d\n", result);
}