#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N, arr[501] = {0};
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int A, B;
		scanf("%d %d", &A, &B);
		arr[B] = A;
	}
	vector<int> last(1, 0);
	for(int i=0; i<=500; i++){
		if(arr[i] == 0) continue;
		if(last.back() < arr[i]) last.push_back(arr[i]);
		else *lower_bound(last.begin(), last.end(), arr[i]) = arr[i];
	}
	printf("%d\n", N-last.size()+1);
}