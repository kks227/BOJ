#include <cstdio>
using namespace std;

int main(){
	int dest[6] = {1, 1, 2, 2, 2, 8};
	for(int i=0; i<6; i++){
		int val;
		scanf("%d", &val);
		printf("%d ", dest[i]-val);
	}
}