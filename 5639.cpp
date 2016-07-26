#include <cstdio>
using namespace std;

int val[10000];

void postorder(int start, int end){
	if(start == end) return;
	if(start+1 == end){
		printf("%d\n", val[start]);
		return;
	}
	int right = start+1;
	for(; right<end && val[right]<val[start]; right++);
	postorder(start+1, right);
	postorder(right, end);
	printf("%d\n", val[start]);
}

int main(){
	int N = 0;
	for(; scanf("%d", val+N)>0; N++);
	postorder(0, N);
}