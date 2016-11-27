#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
typedef map<string, int> MapSI;
const int INF = 1e9;

struct Edge{
	string type;
	int to, d;
	Edge(): Edge("", -1, 0){}
	Edge(string type1, int to1, int d1): type(type1), to(to1), d(d1){}
};

int main(){
	int N, M, K, R, path[200];
	vector<Edge> adj[100];
	cin >> N >> R;
	MapSI S2N;
	for(int i=0; i<N; i++){
		string town;
		cin >> town;
		S2N[town] = i;
	}
	cin >> M;
	for(int i=0; i<M; i++){
		string town;
		cin >> town;
		path[i] = S2N[town];
	}
	cin >> K;
	for(int i=0; i<K; i++){
		string type, from, to;
		int cost;
		cin >> type >> from >> to >> cost;
		adj[S2N[from]].push_back(Edge(type, S2N[to], cost));
	}

	int d1[100][100], d2[100][100], result1 = 0, result2 = R*2;
	for(int i=0; i<N; i++){
		fill(d1[i], d1[i]+N, INF);
		fill(d2[i], d2[i]+N, INF);
		d1[i][i] = d2[i][i] = 0;
	}
	for(int i=0; i<N; i++){
		for(auto& e: adj[i]){
			int cost = e.d*2;
			d1[i][e.to] = d1[e.to][i] = min(d1[i][e.to], cost);
			if(e.type == "Mugunghwa" || e.type == "ITX-Saemaeul" || e.type == "ITX-Cheongchun") cost = 0;
			else if(e.type == "S-Train" || e.type == "V-Train") cost /= 2;
			d2[i][e.to] = d2[e.to][i] = min(d2[i][e.to], cost);
		}
	}
	for(int k=0; k<N; k++){
		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				d1[i][j] = min(d1[i][j], d1[i][k]+d1[k][j]);
				d2[i][j] = min(d2[i][j], d2[i][k]+d2[k][j]);
			}
		}
	}
	for(int i=0; i<M-1; i++){
		result1 += d1[path[i]][path[i+1]];
		result2 += d2[path[i]][path[i+1]];
	}
	puts(result2<result1 ? "Yes" : "No");
}