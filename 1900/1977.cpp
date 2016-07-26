#include <cstdio>
#include <set>
using namespace std;

int main(){

	int M, N;
	scanf("%d %d", &M, &N);
	set<int> square;
	int cur = 1, cnt = 1;
	while(cur <= 10000){
		square.insert(cur);
		cur += 1 + 2*cnt++;
	}
	int min = -1, sum = 0;
	for(set<int>::iterator iter = square.lower_bound(M); iter != square.end(); iter++){
		if(*iter > N) break;
		if(min == -1) min = *iter;
		sum += *iter;
	}
	if(min == -1) printf("-1\n");
	else printf("%d\n%d\n", sum, min);

	return 0;
}