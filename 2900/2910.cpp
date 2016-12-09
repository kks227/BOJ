#include <cstdio>
#include <algorithm>
using namespace std;

struct Unit{
	int n, val, cnt;
	Unit(): Unit(-1, -1){}
	Unit(int n1, int v1): n(n1), val(v1), cnt(1){}
	bool operator <(const Unit& O){
		if(cnt != O.cnt) return cnt > O.cnt;
		return n < O.n;
	}
};

int main(){
	int N, C, M = 0;
	scanf("%d %d", &N, &C);
	Unit u[1000];
	for(int i=0; i<N; i++){
		int val;
		scanf("%d", &val);
		bool found = false;
		for(int j=0; j<M; j++){
			if(val == u[j].val){
				u[j].cnt++;
				found = true;
				break;
			}
		}
		if(!found) u[M++] = Unit(i, val);
	}
	sort(u, u+M);
	for(int i=0; i<M; i++)
		for(int j=0; j<u[i].cnt; j++)
			printf("%d ", u[i].val);
}