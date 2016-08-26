#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
typedef pair<int, int> P;

int main(){
	int N, M, Q, d[500][500], r[500][500], panelty[500];
	P p[500];
	scanf("%d %d %d", &N, &M, &Q);
	for(int i=0; i<N; i++){
		scanf("%d", panelty+i);
		p[i] = P(panelty[i], i);
		for(int j=0; j<N; j++){
			d[i][j] = (i==j ? 0 : INF);
			r[i][j] = INF;
		}
	}
	sort(p, p+N);
	for(int j=0; j<M; j++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--; b--;
		d[a][b] = d[b][a] = min(d[a][b], c);
	}

	for(int k=0; k<N; k++){
		int t = p[k].second;
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				d[i][j] = min(d[i][j], d[i][t]+d[t][j]);
				r[i][j] = min(r[i][j], d[i][j]+max(max(panelty[i], panelty[j]), panelty[t]));
			}
		}
	}
	for(int i=0; i<Q; i++){
		int s, t;
		scanf("%d %d", &s, &t);
		s--; t--;
		printf("%d\n", r[s][t]==INF ? -1 : r[s][t]);
	}
}