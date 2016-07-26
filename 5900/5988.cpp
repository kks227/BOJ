#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d\n", &T);
	for(int t=0; t<T; t++){
		bool odd;
		char c;
		while((c=getchar()) != '\n')
			odd = (c-'0')%2;
		puts(odd ? "odd" : "even");
	}
}