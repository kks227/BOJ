#include <cstdio>

int main(){
	int n=0, c, sum=0;
	while((c=getchar())>0){
		if(c==','){
			sum += n;
			n = 0;
		}
		else if(c!='\n') n = n*10 + c-'0';
	}
	sum += n;
	printf("%d\n", sum);
}