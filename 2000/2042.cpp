#include <cstdio>
#include <cstring>
using namespace std;
const int SIZE = 2097152;

struct SegTree{
	int size, start;
	long long arr[SIZE];
	SegTree(int n): size(n){
		start = 1;
		while(start < size) start *= 2;
		memset(arr, 0, sizeof(arr));
	}
	void construct(){
		for(int i=start-1; i>0; i--)
			arr[i] = arr[i*2] + arr[i*2+1];
	}
	void add(int a, long long b){
		a += start;
		b -= arr[a];
		while(a > 0){
			arr[a] += b;
			a /= 2;
		}
	}
	long long sum(int a, int b){ return sum(a, b, 1, 0, start); }
	long long sum(int a, int b, int node, int na, int nb){
		if(b<=na || nb<=a) return 0;
		if(a<=na && nb<=b) return arr[node];
		int mid = (na+nb)/2;
		return sum(a, b, node*2, na, mid) + sum(a, b, node*2+1, mid, nb);
	}
};

int main(){
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	SegTree ST(N);
	for(int i=0; i<N; i++)
		scanf("%lld", ST.arr+ST.start+i);
	ST.construct();
	for(int i=0; i<M+K; i++){
		int a;
		scanf("%d", &a);
		if(a == 1){
			int b;
			long long c;
			scanf("%d %lld", &b, &c);
			ST.add(b-1, c);
		}
		else{
			int b, c;
			scanf("%d %d", &b, &c);
			printf("%lld\n", ST.sum(b-1, c));
		}
	}
}