#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[25];
int matchA[25], matchB[25];
bool visited[25];

bool dfs(int a){
	if(visited[a]) return false;
	visited[a] = true;
	for(int b: adj[a]){
		if(matchB[b] == -1 || dfs(matchB[b])){
			matchA[a] = b;
			matchB[b] = a;
			return true;
		}
	}
	return false;
}

int main(){
	int N;
	scanf("%d", &N);
	vector<int> A, B;
	bool firstValIsOdd = false;
	for(int i=0; i<N; i++){
		int val;
		scanf("%d", &val);
		if(i==0 && val%2) firstValIsOdd = true;
		(val%2 ? A : B).push_back(val);
	}
	if(A.size() != B.size()){
		puts("-1");
		return 0;
	}
	int listSize = A.size();
	if(!firstValIsOdd) swap(A, B);
	bool isP[1000];
	memset(isP, 1, sizeof(isP));
	for(int i=3; i<2000; i+=2){
		if(!isP[i/2]) continue;
		for(int j=i*i; j<2000; j+=i*2)
			isP[j/2] = false;
	}
	for(int i=0; i<listSize; i++)
		for(int j=0; j<listSize; j++)
			if(isP[(A[i]+B[j])/2]) adj[i].push_back(j);
	vector<int> result;
	for(int i: adj[0]){
		memset(matchA, -1, sizeof(matchA));
		memset(matchB, -1, sizeof(matchB));
		int flow = 1;
		matchA[0] = i;
		matchB[i] = 0;
		for(int j=1; j<listSize; j++){
			memset(visited, 0, sizeof(visited));
			visited[0] = true;
			if(dfs(j)) flow++;
		}
		if(flow == listSize) result.push_back(B[i]);
	}
	if(result.empty()) puts("-1");
	else{
		sort(result.begin(), result.end());
		for(int r: result)
			printf("%d ", r);
	}
}