#include <cstdio>
using namespace std;

int main(){
	int N, sum = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int students, apples;
		scanf("%d %d", &students, &apples);
		sum += apples%students;
	}
	printf("%d\n", sum);
}