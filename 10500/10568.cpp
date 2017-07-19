#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
	int T;
	cin >> T;
	cout.setf(ios::fixed);
	cout.precision(0);
	for(int t=1; t<=T; t++){
		int N, M, x[60], y[60], z[60];
		cin >> N;
		unordered_map<string, int> S2N;
		double d[60][60];
		for(int i=0; i<N; i++){
			string S;
			cin >> S >> x[i] >> y[i] >> z[i];
			S2N[S] = i;
			for(int j=0; j<i; j++)
				d[i][j] = d[j][i] = sqrt(pow(x[i]-x[j], 2.0) + pow(y[i]-y[j], 2.0) + pow(z[i]-z[j], 2.0));
			d[i][i] = 0;
		}
		cin >> M;
		for(int i=0; i<M; i++){
			string S, T;
			cin >> S >> T;
			int u = S2N[S], v = S2N[T];
			d[u][v] = 0;
		}
		for(int k=0; k<N; k++)
			for(int i=0; i<N; i++)
				for(int j=0; j<N; j++)
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

		cout << "Case " << t << ":" << endl;
		cin >> M;
		for(int i=0; i<M; i++){
			string S, T;
			cin >> S >> T;
			int u = S2N[S], v = S2N[T];
			cout << "The distance from " << S << " to " << T << " is " << d[u][v] << " parsecs." << endl;
		}
	}
}