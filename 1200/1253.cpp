#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int main(){
	int N, A[2000], cnt0 = 0;
	set<int> S;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", A+i);
		if(A[i] == 0){
			cnt0++;
			N--;
			i--;
		}
		else{
			for(int j=0; j<i; j++)
				S.insert(A[i]+A[j]);
		}
	}

	int result = 0;
	bool good[2000] = {0};
	sort(A, A+N);
	for(int i=0; i<N; i++)
		if(S.find(A[i]) != S.end()) good[i] = true;
	if(cnt0 > 0){
		for(int i=1; i<N; i++)
			if(A[i] == A[i-1]) good[i-1] = good[i] = true;
		if(cnt0 > 2) result += cnt0;
		else{
			for(int i=0; i<N; i++){
				if(cnt0 && binary_search(A, A+N, -A[i])){
					result += cnt0;
					break;
				}
			}
		}
	}
	for(int i=0; i<N; i++)
		if(good[i]) result++;
	printf("%d\n", result);
}