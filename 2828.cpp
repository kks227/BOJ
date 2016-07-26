#include <cstdio>
using namespace std;

int main(){
	int N, M, J, result = 0, pos = 0;
	scanf("%d %d %d", &N, &M, &J);
	for(int i=0; i<J; i++){
		int c;
		scanf("%d", &c);
		c--;
		if(c < pos){
			result += pos-c;
			pos = c;
		}
		else if(c >= pos+M){
			result += c-pos-M+1;
			pos = c-M+1;
		}
	}
	printf("%d\n", result);
}