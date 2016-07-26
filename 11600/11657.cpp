#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int INF = 1000000000;

int main(){
	int N, M, d[500] = {0}, c[500];
	scanf("%d %d", &N, &M);
	for(int i=1; i<N; i++)
		d[i] = INF;
	vector<P> in[500];
	for(int i=0; i<M; i++){
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		in[B-1].push_back(P(A-1, C));
	}

	for(int i=0; i<N-1; i++)
		for(int j=0; j<N; j++)
			for(auto &p: in[j])
				d[j] = min(d[j], d[p.first]+p.second);
	memcpy(c, d, sizeof(c));
	for(int i=0; i<N; i++)
		for(auto &p: in[i])
			d[i] = min(d[i], d[p.first]+p.second);
	
	bool check = false;
	for(int i=0; i<N; i++){
		if(d[i] != c[i]){
			check = true;
			break;
		}
	}
	if(check) puts("-1");
	else{
		for(int i=1; i<N; i++)
			printf("%d\n", d[i]!=INF ? d[i] : -1);
	}
}