#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
	int N, A[5000];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	sort(A, A+N);
	int d = INF, c = 0;
	for(int i=0; i<N-1; i++){
		if(A[i+1]-A[i] < d){
			d = A[i+1]-A[i];
			c = 1;
		}
		else if(A[i+1]-A[i] == d) c++;
	}
	printf("%d %d\n", d, c);
}