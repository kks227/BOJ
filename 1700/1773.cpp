#include <cstdio>
#include <set>
using namespace std;

int main(){

	int N, C, input;
	scanf("%d %d", &N, &C);
	set<int> petrad, period;
	for(int i=0; i<N; i++){
		scanf("%d", &input);
		if(period.find(input) != period.end()) continue;
		period.insert(input);
		for(int i=input; i<=C; i+=input)
			petrad.insert(i);
	}
	printf("%d\n", petrad.size());

	return 0;
}