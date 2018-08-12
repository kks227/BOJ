#include <cstdio>
using namespace std;

int main(){
	int Q;
	scanf("%d", &Q);
	for(int i=0; i<Q; i++){
		int a;
		scanf("%d", &a);
		bool result = true;
		while(a > 1){
			if(a%2){
				result = false;
				break;
			}
			a /= 2;
		}
		printf("%d\n", result);
	}
}