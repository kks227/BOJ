#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, Q, arr[1000];
	scanf("%d %d", &N, &Q);
	for(int i=0; i<N; i++)
		scanf("%d", arr+i);
	for(int i=0; i<Q; i++){
		int op, a, b, c, d, s1 = 0, s2 = 0;
		scanf("%d %d %d", &op, &a, &b);
		a--; b--;
		for(int i=a; i<=b; i++)
			s1 += arr[i];
		if(op == 1){
			printf("%d\n", s1);
			swap(arr[a], arr[b]);
		}
		else{
			scanf("%d %d", &c, &d);
			c--; d--;
			for(int i=c; i<=d; i++)
				s2 += arr[i];
			printf("%d\n", s1-s2);
		}
	}
}