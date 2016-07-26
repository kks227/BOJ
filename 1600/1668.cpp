#include <cstdio>
#include <vector>
using namespace std;

int main(){

	int N, input, max = 0;
	vector<int> stand;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &input);
		if(max < input) max = input;
		stand.push_back(input);
	}

	int currentMax = 0, cnt = 0;
	for(int i=0; i<N; i++){
		if(currentMax < stand[i]){
			cnt++;
			currentMax = stand[i];
			if(currentMax == max) break;
		}
	}
	printf("%d\n", cnt);

	currentMax = cnt = 0;
	for(int i=N-1; i>=0; i--){
		if(currentMax < stand[i]){
			cnt++;
			currentMax = stand[i];
			if(currentMax == max) break;
		}
	}
	printf("%d\n", cnt);

	return 0;
}