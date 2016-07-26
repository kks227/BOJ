#include <cstdio>
#include <cstring>
using namespace std;
const int SIZE = 2097152;

struct SegTree{
	int size, start;
	long long arr[SIZE], lazy[SIZE];
	SegTree(int n): size(n){
		start = 1;
		while(start < size) start *= 2;
		memset(arr, 0, sizeof(arr));
		memset(lazy, 0, sizeof(lazy));
	}
	void construct(){
		for(int i=start-1; i>0; i--)
			arr[i] = arr[i*2] + arr[i*2+1];
	}
	void addLazy(int node, int na, int nb){
		if(lazy[node]){
			if(node < start){
				lazy[node*2] += lazy[node];
				lazy[node*2+1] += lazy[node];
			}
			arr[node] += lazy[node] * (nb-na);
			lazy[node] = 0;
		}
	}
	void add(int a, int b, long long c){ add(a, b, c, 1, 0, start); }
	void add(int a, int b, long long c, int node, int na, int nb){
		addLazy(node, na, nb);
		if(b<=na || nb<=a) return;
		if(a<=na && nb<=b){
			if(node < start){
				lazy[node*2] += c;
				lazy[node*2+1] += c;
			}
			arr[node] += c * (nb-na);
			return;
		}
		int mid = (na+nb)/2;
		add(a, b, c, node*2, na, mid);
		add(a, b, c, node*2+1, mid, nb);
		arr[node] = arr[node*2] + arr[node*2+1];
	}
	long long sum(int a, int b){ return sum(a, b, 1, 0, start); }
	long long sum(int a, int b, int node, int na, int nb){
		addLazy(node, na, nb);
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
		int a, b, c;
		scanf("%d", &a);
		if(a == 1){
			long long d;
			scanf("%d %d %lld", &b, &c, &d);
			ST.add(b-1, c, d);
		}
		else{
			scanf("%d %d", &b, &c);
			printf("%lld\n", ST.sum(b-1, c));
		}
	}
}