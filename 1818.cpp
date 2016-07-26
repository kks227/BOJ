#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N, arr[200000] = {0};
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", arr+i);
	vector<int> last(1, 0);
	for(int i=0; i<N; i++){
		if(last.back() < arr[i]) last.push_back(arr[i]);
		else *lower_bound(last.begin(), last.end(), arr[i]) = arr[i];
	}
	printf("%d\n", N-last.size()+1);
}