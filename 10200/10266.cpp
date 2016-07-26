#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 360000;

int main(){
	vector<bool> A(MAX*2, false), B(MAX, false);
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int a;
		scanf("%d", &a);
		A[a] = true;
	}
	copy(A.begin(), A.begin()+MAX, A.begin()+MAX);
	for(int i=0; i<N; i++){
		int a;
		scanf("%d", &a);
		B[a] = true;
	}

	int pi[MAX] = {0}, j = 0;
	for(int i=1; i<MAX; i++){
		while(j > 0 && B[i] != B[j]) j = pi[j-1];
		if(B[i] == B[j]) pi[i] = ++j;
	}

	bool result = false;
	j = 0;
	for(int i=0; i<MAX*2; i++){
		while(j > 0 && A[i] != B[j]) j = pi[j-1];
		if(A[i] == B[j]){
			if(j == MAX-1){
				result = true;
				break;
			}
			else j++;
		}
	}
	puts(result ? "possible" : "impossible");
}