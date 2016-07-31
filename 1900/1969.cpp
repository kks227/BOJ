#include <cstdio>
#include <map>
using namespace std;

int main(){
	// cnt[i][j]: i열에서 j번문자가 사용된 횟수
	int N, M, cnt[50][4] = {0}, NtoC[4] = {'A', 'C', 'G', 'T'};
	map<char, int> CtoN;
	CtoN['A'] = 0;
	CtoN['C'] = 1;
	CtoN['G'] = 2;
	CtoN['T'] = 3;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		char DNA[1001];
		scanf("%s", DNA);
		for(int j=0; j<M; j++)
			cnt[j][ CtoN[DNA[j]] ]++;
	}

	int result = 0;
	for(int i=0; i<M; i++){
		// 각 열마다 가장 많이 사용된 문자를 사용한다.
		int p = 0, m = 0;
		for(int j=0; j<4; j++){
			if(cnt[i][j] > m){
				p = j;
				m = cnt[i][j];
			}
		}
		// 이번 열에서 발생하는 Hamming Distance 더해줌
		result += N-m;
		putchar(NtoC[p]);
	}
	printf("\n%d\n", result);
}