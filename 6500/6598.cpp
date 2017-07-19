#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
	for(int t=1; ; t++){
		int N, M;
		cin >> N;
		if(N == 0) break;

		unordered_map<string, int> S2N;
		vector<vector<double>> d(N, vector<double>(N, INF));
		for(int i=0; i<N; i++){
			string S;
			cin >> S;
			S2N[S] = i;
			d[i][i] = 1;
		}
		cin >> M;
		for(int i=0; i<M; i++){
			string S, T;
			double r;
			cin >> S >> r >> T;
			int a = S2N[S], b = S2N[T];
			d[a][b] = min(d[a][b], 1/r);
		}
		for(int k=0; k<N; k++)
			for(int i=0; i<N; i++)
				for(int j=0; j<N; j++)
					d[i][j] = min(d[i][j], d[i][k]*d[k][j]);
		bool result = false;
		for(int i=0; i<N; i++)
			if(d[i][i] < 1) result = true;
		cout << "Case " << t << ": " << (result ? "Yes" : "No") << endl;
	}
}