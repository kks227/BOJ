#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, K, arr[1<<20], t[1<<20];

void mergeSort(int s, int e, int l){
	if(s+1 == e) return;
	int mid = (s+e)/2;
	mergeSort(s, mid, l*2);
	mergeSort(mid, e, l*2);
	if(l < K) return;
	for(int i=s, j=mid, k=0; k<e-s; k++){
		if(j == e || i < mid && arr[i] < arr[j]) t[k] = arr[i++];
		else t[k] = arr[j++];
	}
	memcpy(arr+s, t, (e-s)*sizeof(int));
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", arr+i);
	scanf("%d", &K);
	mergeSort(0, N, 1);
	for(int i=0; i<N; i++)
		printf("%d ", arr[i]);
}