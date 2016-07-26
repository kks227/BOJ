#include <cstdio>
using namespace std;
const int START = 1048576;
const int SIZE = START * 2;

int ST[SIZE];

void update(int node, int k){
	if(node == 0) return;
	ST[node] += k;
	update(node/2, k);
}

int kth(int node, int k){
	if(node >= START) return node-START;

	int pivot = ST[node*2];
	if(k < pivot) return kth(node*2, k);
	else return kth(node*2+1, k-pivot);
}

int main(){
	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int A, B;
		scanf("%d %d", &A, &B);
		if(A == 1){
			int result = kth(1, B-1);
			printf("%d\n", result);
			update(START+result, -1);
		}
		else{
			int C;
			scanf("%d", &C);
			update(START+B, C);
		}
	}
}