#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct Tuple{
	int x, y, z, w;
	Tuple(): Tuple(0, 0, 0){}
	Tuple(int x1, int y1, int z1): Tuple(x1, y1, z1, 0){}
	Tuple(int x1, int y1, int z1, int w1): x(x1), y(y1), z(z1), w(w1){}
	bool operator <(const Tuple& A)const{
		if(x != A.x) return x < A.x;
		if(y != A.y) return y < A.y;
		if(z != A.z) return z < A.z;
		return w < A.w;
	}
};

int uf[100000];

int uf_find(int n){
	if(uf[n] < 0) return n;
	return uf[n] = uf_find(uf[n]);
}

bool uf_union(int m, int n){
	m = uf_find(m);
	n = uf_find(n);
	if(m == n) return false;
	uf[n] = m;
	return true;
}

int main(){
	int N;
	scanf("%d", &N);
	Tuple pos[100000];
	for(int i=0; i<N; i++){
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		pos[i] = Tuple(x, y, z, i);
	}

	vector<Tuple> edge;
	sort(pos, pos+N, [](const Tuple& A, const Tuple& B){ return A.x < B.x; });
	for(int i=0; i<N-1; i++)
		edge.push_back(Tuple(abs(pos[i].x - pos[i+1].x), pos[i].w, pos[i+1].w));
	sort(pos, pos+N, [](const Tuple& A, const Tuple& B){ return A.y < B.y; });
	for(int i=0; i<N-1; i++)
		edge.push_back(Tuple(abs(pos[i].y - pos[i+1].y), pos[i].w, pos[i+1].w));
	sort(pos, pos+N, [](const Tuple& A, const Tuple& B){ return A.z < B.z; });
	for(int i=0; i<N-1; i++)
		edge.push_back(Tuple(abs(pos[i].z - pos[i+1].z), pos[i].w, pos[i+1].w));
	sort(edge.begin(), edge.end());

	fill(uf, uf+N, -1);
	int cnt = 0;
	long long result = 0;
	for(auto& e: edge){
		if(uf_union(e.y, e.z)){
			result += e.x;
			if(++cnt == N-1) break;
		}
	}
	printf("%lld\n", result);
}