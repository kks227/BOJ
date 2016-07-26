#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 317;
int arr[MAX], cache[100001][MAX];

int minSquares(int n, int pos){
	if(n == 0) return 0;
	if(pos == MAX-1) return n;
	int &ret = cache[n][pos];
	if(ret) return ret;
	ret = minSquares(n, pos+1);
	if(n >= arr[pos]) ret = min(ret, minSquares(n-arr[pos], pos)+1);
	return ret;
}

int main(){
	for(int i=1; i<=MAX; i++)
		arr[MAX-i-1] = i*i;
	int N;
	scanf("%d", &N);
	printf("%d\n", minSquares(N, 0));
}