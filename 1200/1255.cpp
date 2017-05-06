#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double INF = 1e9;

inline int cross(int x1, int y1, int x2, int y2){
	return x1*y2 - x2*y1;
}

inline int sign(int n){
	if(n == 0) return 0;
	return (n > 0 ? 1 : -1);
}

inline bool intersection(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
	int c1, c2;
	c1 = sign(cross(x2-x1, y2-y1, x3-x1, y3-y1));
	c2 = sign(cross(x2-x1, y2-y1, x4-x1, y4-y1));
	if(c1 == 0 || c2 == 0 || c1 == c2) return false;
	c1 = sign(cross(x4-x3, y4-y3, x1-x3, y1-y3));
	c2 = sign(cross(x4-x3, y4-y3, x2-x3, y2-y3));
	if(c1 == 0 || c2 == 0 || c1 == c2) return false;
	return true;
}

inline double distance(int x1, int y1, int x2, int y2){
	return sqrt(pow(x2-x1, 2.0) + pow(y2-y1, 2.0));
}



int main(){
	int N, M, x[200], y[200], v[50];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		scanf("\n(%d,%d) %d", x+i*2, y+i*2, v+i);
		x[i*2+1] = x[i*2];
		y[i*2+1] = y[i*2];
	}
	for(int i=0; i<M; i++)
		scanf("\n(%d,%d) - (%d,%d)", x+(N+i)*2, y+(N+i)*2, x+(N+i)*2+1, y+(N+i)*2+1);

	int K = 2*(N+M) + 1; // node K: the 'x axis'
	double dist[201][201] = {0};
	for(int i=0; i<K-1; i++){
		bool collision = false;
		for(int k=0; k<K-1; k+=2){
			if(intersection(x[i], y[i], x[i], -1, x[k], y[k], x[k+1], y[k+1])){
				collision = true;
				break;
			}
		}
		dist[i][K-1] = dist[K-1][i] = collision ? INF : y[i];

		for(int j=i+1; j<K-1; j++){
			if(i/2 == j/2) dist[i][j] = dist[j][i] = distance(x[i], y[i], x[j], y[j]);
			else{
				collision = false;
				for(int k=0; k<K-1; k+=2){
					if(intersection(x[i], y[i], x[j], y[j], x[k], y[k], x[k+1], y[k+1])){
						collision = true;
						break;
					}
				}
				dist[i][j] = dist[j][i] = collision ? INF : distance(x[i], y[i], x[j], y[j]);
			}
		}
	}

	for(int k=0; k<K; k++)
		for(int i=0; i<K; i++)
			for(int j=0; j<K; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	double result = 0;
	for(int i=0; i<N; i++)
		result = max(result, dist[i*2][K-1] / v[i]);
	printf("%.1lf\n", result);
}