#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> intPair;
 
int main(){

	int N, T, S;
	intPair toDoList[1000];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d %d", &T, &S);
		toDoList[i] = intPair(S, T);
	}
	sort(toDoList, toDoList+N);

	int result = toDoList[N-1].first;
	for(int i=N-1; i>=0; i--){
		result = min(result, toDoList[i].first);
		result -= toDoList[i].second;
	}
	printf("%d\n", (result>=0)?result:-1);

	return 0;
}