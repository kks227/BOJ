#include <cstdio>
using namespace std;

int main(){
	int sum = 0;
	bool even;
	for(int i=0; i<13; i++){
		char c = getchar();
		if(c == '*') even = i%2;
		else sum += (c-'0')*(i%2?3:1);
	}
	for(int i=0; i<10; i++){
		if((sum + i*(even?3:1)) % 10 == 0){
			printf("%d\n", i);
			break;
		}
	}
}