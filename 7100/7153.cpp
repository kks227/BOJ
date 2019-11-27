#include <cstdio>
#include <cmath>
#include <cassert>
#include <set>
#include <algorithm>
using namespace std;
const int MAX_N = 50;
const int MAX_M = MAX_N*(MAX_N-1)/2;
const int MAX = MAX_N + MAX_M + 1;

int main(){
	while(1){
		int N;
		scanf("%d", &N);
		if(N == 0) break;

		int M = N*(N-1)/2, x[MAX_N], y[MAX_N];
		for(int i = 0; i < N; ++i)
			scanf("%d %d", x+i, y+i);

		double obj[MAX] = {0,}, A[MAX][MAX] = {0,};
		fill(obj, obj+N, 1);
		for(int i = 0, h = N; i < N; ++i){
			for(int j = i+1; j < N; ++j){
				for(int k = 0; k < N; ++k)
					A[h][k] = (i == k || j == k ? -1 : 0);
				A[h++][N+M] = sqrt(pow(x[i]-x[j], 2.0) + pow(y[i]-y[j], 2.0));
			}
		}

		set<int> NB, B;
		for(int i = 0; i < N; ++i)
			NB.insert(i);
		for(int i = 0; i < M; ++i)
			B.insert(N+i);
		bool unbounded = false;
		double result = 0;
		while(1){
			int e = -1, l = -1;
			for(int nb: NB)
				if(obj[nb] > 0 && (e == -1 || obj[e] < obj[nb])) e = nb;
			if(e == -1) break;

			double coeff = 1, limit = -1;
			for(int b: B){
				double *a = A[b];
				if(a[e] >= 0) continue;
				double temp = -a[N+M] / a[e];
				if(limit == -1 || temp < limit){
					limit = temp;
					l = b;
					coeff = a[e];
				}
			}
			if(limit == -1){
				unbounded = true;
				break;
			}

			NB.erase(e);
			B.erase(l);
			double sw[MAX] = {0,};
			sw[N+M] = -A[l][N+M] / coeff;
			sw[l] = 1 / coeff;
			for(int nb: NB)
				sw[nb] = -A[l][nb] / coeff;
			fill(A[l], A[l]+MAX, 0);
			copy(sw, sw+MAX, A[e]);
			NB.insert(l);

			double lcoeff = obj[e];
			obj[e] = 0;
			obj[N+M] += sw[N+M] * lcoeff;
			for(int nb: NB)
				obj[nb] += sw[nb] * lcoeff;

			for(int b: B){
				double *a = A[b];
				lcoeff = A[b][e];
				a[e] = 0;
				a[N+M] += sw[N+M] * lcoeff;
				for(int nb: NB)
					a[nb] += sw[nb] * lcoeff;
			}

			B.insert(e);
			result = obj[N+M];
		}
		assert(!unbounded);
		printf("%.2lf\n", round(result*100)/100.0);
	}
}