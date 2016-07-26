#include <cstdio>
using namespace std;

int main(){
	int result = 0;
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++)
			if(getchar()=='F' && (i+j)%2==0) result++;
		getchar();
	}
	printf("%d\n", result);
}