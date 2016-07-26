#include <cstdio>
using namespace std;

int main(){
	bool submit[30] = {0};
	for(int i=0; i<28; i++){
		int n;
		scanf("%d", &n);
		submit[n-1] = true;
	}
	for(int i=0; i<30; i++)
		if(!submit[i]) printf("%d\n", i+1);
}