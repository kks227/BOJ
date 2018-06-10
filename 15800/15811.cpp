#include <cstdio>
#include <algorithm>
using namespace std;

int cnt, pick[10];
long long val[3][10], sum[3];
bool used[10];

bool backtrack(int pos){
	if(pos == cnt) return (sum[0]+sum[1] == sum[2]);

	for(int i=0; i<10; i++){
		if(used[i]) continue;
		used[i] = true;
		pick[pos] = i;
		for(int j=0; j<3; j++)
			sum[j] += val[j][pos]*i;
		if(backtrack(pos+1)) return true;
		for(int j=0; j<3; j++)
			sum[j] -= val[j][pos]*i;
		used[i] = false;
	}
	return false;
}

int main(){
	int C2N[26];
	fill(C2N, C2N+26, -1);
	bool result = true;
	for(int i=0; i<3; i++){
		char S[19];
		scanf("%s", S);
		for(int j=0; S[j]; j++){
			for(int k=0; k<10; k++)
				val[i][k] *= 10;
			int temp = S[j] - 'A';
			if(C2N[temp] == -1) C2N[temp] = cnt++;
			if(C2N[temp] < 10) val[i][C2N[temp]]++;
			else result = false;
		}
	}
	if(result) result = backtrack(0);
	puts(result ? "YES" : "NO");
}