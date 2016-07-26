#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
#include <map>
using namespace std;

typedef set<int> intSet;
typedef intSet::iterator setIter;
typedef map<int, int> intMap;

int main(){

	int T, P = 0;
	scanf("%d", &T);

	bool isP[10000];
	memset(isP, 1, 10000);
	isP[0] = isP[1] = false;
	for(int i=4; i<10000; i+=2)
		isP[i] = false;
	for(int i=3; i<10000; i+=2){
		if(!isP[i]) continue;
		if(i>1000) P++;
		for(int j=i*i; j<10000; j+=i)
			isP[j] = false;
	}

	int *NtoP = new int[P];
	intSet *adj = new intSet[P];
	intMap PtoN;
	int cnt = 0;
	for(int i=1001; i<10000; i+=2){
		if(!isP[i]) continue;
		NtoP[cnt] = i;
		PtoN[i] = cnt++;
	}

	int pow10, dn, n2;
	for(int i=0; i<P; i++){
		pow10 = 1;
		for(int d=0; d<4; d++){
			dn = NtoP[i]%(pow10*10)/pow10;
			for(int k=1; dn+k<10; k++){
				n2 = NtoP[i]+k*pow10;
				if(isP[n2]){
					adj[i].insert(PtoN[n2]);
					adj[PtoN[n2]].insert(i);
				}
			}
			pow10 *= 10;
		}
	}

	int A, B, nA, nB, cur, qSize;
	bool *visited = new bool[P];
	queue<int> BFSQ;
	for(int t=0; t<T; t++){
		scanf("%d %d", &A, &B);
		nA = PtoN[A];
		nB = PtoN[B];
		memset(visited, 0, P);
		cnt = 0;
		BFSQ.push(nA);
		while(!BFSQ.empty()){
			qSize = BFSQ.size();
			for(int i=0; i<qSize; i++){
				cur = BFSQ.front();
				BFSQ.pop();
				if(visited[cur]) continue;
				visited[cur] = true;
				if(cur == nB) break;
				for(setIter iter=adj[cur].begin(); iter!=adj[cur].end(); iter++)
					if(!visited[*iter]) BFSQ.push(*iter);
			}
			if(visited[nB]) break;
			cnt++;
		}
		while(!BFSQ.empty()) BFSQ.pop();
		if(!visited[nB]) printf("Impossible\n");
		else printf("%d\n", cnt);
	}

	delete[] NtoP;
	delete[] adj;
	delete[] visited;
	return 0;
}