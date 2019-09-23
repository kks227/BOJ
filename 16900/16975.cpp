#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 100000;

struct FenwickTree{
	int size;
	long long arr[MAX+1];
	FenwickTree(): FenwickTree(1){}
	FenwickTree(int size1): size(size1){ fill(arr, arr+MAX+1, 0); }
	void add(int pos, int k){
		while(pos <= size){
			arr[pos] += k;
			pos += pos & -pos;
		}
	}
	void add(int s, int e, int k){
		add(e, -k);
		add(s, k);
	}
	long long getVal(int pos){
		long long result = 0;
		while(pos > 0){
			result += arr[pos];
			pos -= pos & -pos;
		}
		return result;
	}
};

int main(){
	int N, Q;
	scanf("%d", &N);
	FenwickTree FT(N);
	for(int i = 0; i < N; ++i){
		int val;
		scanf("%d", &val);
		FT.add(i+1, i+2, val);
	}
	scanf("%d", &Q);
	for(int i = 0; i < Q; ++i){
		int op;
		scanf("%d", &op);
		if(op == 1){
			int s, e, k;
			scanf("%d %d %d", &s, &e, &k);
			FT.add(s, e+1, k);
		}
		else{
			int x;
			scanf("%d", &x);
			printf("%lld\n", FT.getVal(x));
		}
	}
}