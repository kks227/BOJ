#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int val[10], cnt[8][10], result;
bool used[10];

void backtrack(int pos){
	if(pos == 10){
		int temp = 0;
		for(int i=0; i<8; i++){
			temp *= 10;
			for(int j=0; j<10; j++)
				temp += cnt[i][j] * val[j];
		}
		result = max(result, temp);
		return;
	}

	int temp = 0;
	for(int i=0; i<8; i++){
		temp *= 10;
		for(int j=0; j<10; j++)
			temp += cnt[i][j] * (val[j] == -1 ? 9 : val[j]);
	}
	if(temp <= result) return;

	for(int i=9; i>=0; i--){
		if(used[i]) continue;
		used[i] = true;
		val[pos] = i;
		backtrack(pos+1);
		used[i] = false;
		val[pos] = -1;
	}
}

int main(){
	int N, m = 0;
	cin >> N;
	string S[10];
	for(int i=0; i<N; i++){
		cin >> S[i];
		if(S[i].size() < 8) S[i] = string(8-S[i].size(), '0') + S[i];
	}
	sort(S, S+N);
	for(int i=0; i<8; i++){
		for(int j=N-1; j>=0; j--){
			if(S[j][i] >= 'A'){
				char c = S[j][i];
				for(int k=0; k<N; k++){
					for(int l=0; l<S[k].size(); l++){
						if(S[k][l] == c){
							cnt[8-S[k].size()+l][m]++;
							S[k][l] = '0'+m;
						}
					}
				}
				m++;
			}
		}
	}
	fill(val, val+10, -1);
	backtrack(0);
	printf("%d\n", result);
}
