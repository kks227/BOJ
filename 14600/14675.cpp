#include <cstdio>
using namespace std;

int main(){
	int N, Q, cnt[100000] = {0};
	scanf("%d", &N);
	for(int i=0; i<N-1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		cnt[a-1]++; cnt[b-1]++;
	}
	scanf("%d", &Q);
	for(int i=0; i<Q; i++){
		int t, k;
		scanf("%d %d", &t, &k);
		puts(t==2 || t==1 && cnt[k-1]>1 ? "yes" : "no");
	}
}