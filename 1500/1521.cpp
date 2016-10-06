#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int N;
map<vector<int>, double> dp;

double randomSort(vector<int> S){
	auto finder = dp.find(S);
	if(finder != dp.end()) return finder->second;

	double result = 0;
	int cnt = 0;
	for(int i=0; i<N-1; i++){
		for(int j=i+1; j<N; j++){
			if(S[i] > S[j]){
				vector<int> T(S);
				swap(T[i], T[j]);
				result += randomSort(T) + 1;
				cnt++;
			}
		}
	}
	return dp[S] = (cnt>0 ? result / cnt : 0);
}

int main(){
	scanf("%d", &N);
	vector<int> A(N);
	for(int i=0; i<N; i++)
		scanf("%d", &A[i]);
	printf("%.10lf\n", randomSort(A));
}