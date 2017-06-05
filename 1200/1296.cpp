#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int main(){
	int N, K = -1, cnt1[4] = {0};
	char A[21], result[21];
	map<char, int> c2d;
	c2d['L'] = 0; c2d['O'] = 1; c2d['V'] = 2; c2d['E'] = 3;
	scanf("%s %d", A, &N);
	for(int i=0; A[i]; i++)
		if(c2d.find(A[i]) != c2d.end()) cnt1[c2d[A[i]]]++;
	for(int j=1; j<=N; j++){
		char B[21];
		scanf("%s", B);
		int cnt2[4] = {0};
		long long temp = 1;
		for(int i=0; B[i]; i++)
			if(c2d.find(B[i]) != c2d.end()) cnt2[c2d[B[i]]]++;
		for(int i=0; i<3; i++)
			for(int j=i+1; j<4; j++)
				temp *= (cnt1[i]+cnt2[i]) + (cnt1[j]+cnt2[j]);
		temp %= 100;
		if(K < temp || K == temp && strcmp(result, B) > 0){
			K = temp;
			strcpy(result, B);
		}
	}
	puts(result);
}