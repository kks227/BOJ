#include <cstdio>
#include <set>
using namespace std;

int main(){

	int start;
	set<int> PR;
	while(1){
		scanf("%d", &start);
		if(start == 0) break;

		PR.insert(start);
		while(1){
			start *= start;
			start /= 100;
			start = start % 10000;
			if(PR.find(start) != PR.end()) break;
			PR.insert(start);
		}
		printf("%d\n", PR.size());
		PR.clear();
	}

	return 0;
}