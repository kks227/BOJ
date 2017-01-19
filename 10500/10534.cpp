#include <cstdio>
#include <algorithm>
using namespace std;

struct Line{
	int p, q1, q2, n;
	bool type; // false: begin, true: end
	Line(): Line(0, 0, 0, false, -1){}
	Line(int r, int s1, int s2, bool t, int num): p(r), q1(s1), q2(s2), type(t), n(num){}
	bool operator <(const Line& O){
		if(p != O.p) return p < O.p;
		return q1 < O.q1;
	}
};

int uf[50000];

int uf_find(int p){
	if(uf[p] < 0) return p;
	return uf[p] = uf_find(uf[p]);
}

void uf_union(int p, int q){
	p = uf_find(p);
	q = uf_find(q);
	if(p != q){
		uf[p] += uf[q];
		uf[q] = p;
	}
}

inline bool intersect(int l1, int r1, int l2, int r2){
	return (l1 <= r2 && l2 <= r1);
}



int main(){
	int N;
	scanf("%d", &N);
	Line L[2][100000];
	for(int i=0; i<N; i++){
		int x, y, w, h;
		scanf("%d %d %d %d", &x, &y, &w, &h);
		L[0][i*2] = Line(x, y, y+h, false, i);
		L[0][i*2+1] = Line(x+w, y, y+h, true, i);
		L[1][i*2] = Line(y, x, x+w, false, i);
		L[1][i*2+1] = Line(y+h, x, x+w, true, i);
		uf[i] = -w*h;
	}

	for(int l=0; l<2; l++){
		sort(L[l], L[l]+N*2);
		int recent[2] = {-1, -1};
		for(int i=0; i<N*2; i++){
			recent[L[l][i].type] = i;
			int j = recent[!L[l][i].type];
			if(j != -1 && L[l][i].p == L[l][j].p && intersect(L[l][i].q1, L[l][i].q2, L[l][j].q1, L[l][j].q2))
				uf_union(L[l][i].n, L[l][j].n);
		}
	}
	int result = 0;
	for(int i=0; i<N; i++)
		result = max(result, -uf[uf_find(i)]);
	printf("%d\n", result);
}