#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	vector<int> last(1, -1001);
	int cur;
	for(int i=0; i<N; i++){
		scanf("%d", &cur);
		cur *= -1;
		if(last.back() < cur) last.push_back(cur);
		else *lower_bound(last.begin(), last.end(), cur) = cur;
	}
	printf("%d\n", last.size()-1);
}