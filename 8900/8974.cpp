#include <cstdio>
using namespace std;

int main(){
	int A, B, result = 0;
	scanf("%d %d", &A, &B);
	for(int i=1, j=0, k=1; i<=B; i++){
		if(i >= A) result += k;
		if(++j == k){
			k++;
			j = 0;
		}
	}
	printf("%d\n", result);
}