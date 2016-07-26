#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int W, P;
	scanf("%d %d", &W, &P);
	vector<int> range, result;
	result.push_back(W);
	int prevL = 0;
	for(int i=0; i<P; i++){
		int L, sum;
		scanf("%d", &L);
		range.push_back(L-prevL);
		result.push_back(W-L);
		sum = range.back();
		for(int j=i-1; j>=0; j--)
			result.push_back(sum+=range[j]);
		prevL = L;
	}
	result.insert(result.end(), range.begin(), range.end());
	sort(result.begin(), result.end());
	int size = unique(result.begin(), result.end()) - result.begin();
	for(int i=0; i<size; i++)
		printf("%d ", result[i]);
}