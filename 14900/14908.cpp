#include <cstdio>
#include <algorithm>
using namespace std;

struct Job{
	int t, s, n;
	bool operator <(const Job& O)const{
		if(t*O.s != s*O.t) return t*O.s < s*O.t;
		return n < O.n;
	}
};

int main(){
	int N;
	Job J[1000];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d %d", &J[i].t, &J[i].s);
		J[i].n = i+1;
	}
	sort(J, J+N);
	for(int i=0; i<N; i++)
		printf("%d ", J[i].n);
}