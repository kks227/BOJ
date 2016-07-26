#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
	pair<int, int> A[8];
	for(int i=0; i<8; i++){
		int score;
		scanf("%d", &score);
		A[i] = pair<int, int>(score, i+1);
	}
	sort(A, A+8);
	int sum = 0, result[5], j = 0;
	for(int i=3; i<8; i++){
		sum += A[i].first;
		result[j++] = A[i].second;
	}
	printf("%d\n", sum);
	sort(result, result+5);
	for(int i=0; i<5; i++)
		printf("%d ", result[i]);
}