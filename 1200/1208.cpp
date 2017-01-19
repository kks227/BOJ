#include <cstdio>
#include <map>
using namespace std;
const int PIVOT = 20;

int N, S, A[40], sum;
long long result;
map<int, int> L;

void dfs(int pos, bool side=false){
	if(side){
		if(pos >= N){
			auto iter = L.find(S-sum);
			if(iter != L.end()) result += iter->second;
		}
		else{
			sum += A[pos];
			dfs(pos+1, side);
			sum -= A[pos];
			dfs(pos+1, side);
		}
	}
	else{
		if(pos == N || pos == PIVOT){
			auto iter = L.find(sum);
			if(iter == L.end()) L[sum] = 1;
			else iter->second++;
		}
		else{
			sum += A[pos];
			dfs(pos+1, side);
			sum -= A[pos];
			dfs(pos+1, side);
		}
	}
}

int main(){
	scanf("%d %d", &N, &S);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	dfs(0);
	dfs(PIVOT, true);
	if(S == 0) result--;
	printf("%lld\n", result);
}