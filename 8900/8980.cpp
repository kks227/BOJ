#include <cstdio>
#include <algorithm>
using namespace std;

struct Delivery{
	int s, e, b;
	Delivery(): Delivery(0, 0, 0){}
	Delivery(int s1, int e1, int b1): s(s1), e(e1), b(b1){}
	bool operator <(const Delivery &O)const{
		if(e != O.e) return e < O.e;
		return s > O.s;
	}
};

int main(){
	int N, C, M;
	scanf("%d %d %d", &N, &C, &M);
	Delivery dest[10000];
	for(int i=0; i<M; i++){
		int S, E, B;
		scanf("%d %d %d", &S, &E, &B);
		dest[i] = Delivery(S-1, E-1, B);
	}
	sort(dest, dest+M);

	int result = 0, load[2000] = {0};
	for(int i=0; i<M; i++){
		int S = dest[i].s, E = dest[i].e, B = dest[i].b;
		int maxLoad = *max_element(load+S, load+E);
		int temp = min(B, C-maxLoad);
		result += temp;
		for(int i=S; i<E; i++)
			load[i] += temp;
	}
	printf("%d\n", result);
}