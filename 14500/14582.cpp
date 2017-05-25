#include <cstdio>
using namespace std;

int main(){
	int s[9], sum[2] = {0};
	for(int i=0; i<9; i++)
		scanf("%d", s+i);
	bool result = false;
	for(int i=0; i<9; i++){
		int val;
		scanf("%d", &val);
		sum[0] += s[i];
		if(sum[0] > sum[1]) result = true;
		sum[1] += val;
	}
	puts(result ? "Yes" : "No");
}