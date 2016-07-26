#include <cstdio>
#include <set>
using namespace std;

int main(){

	int N, M, input;
	multiset<int> value;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		scanf("%d", &input);
		value.insert(input);
	}

	int result = 0, current;
	multiset<int>::iterator iter, iterCounter;
	while(!value.empty()){
		iter = value.begin();
		current = *iter;
		value.erase(iter);
		if((iterCounter = value.find(M-current)) != value.end()){
			value.erase(iterCounter);
			result++;
		}
	}
	printf("%d\n", result);

	return 0;
}