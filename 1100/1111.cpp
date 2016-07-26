#include <cstdio>
using namespace std;

int main(){
	int N, val[50], a, b;
	scanf("%d", &N);
	bool isFlagB;
	for(int i=0; i<N; i++)
		scanf("%d", val+i);

	if(N == 1) puts("A");
	else if(N == 2){
		if(val[0] == val[1]) printf("%d\n", val[0]);
		else puts("A");
	}
	else{
		isFlagB = false;

		if(val[0] == val[1]){
			for(int i=2; i<N; i++){
				if(val[i] != val[0]) isFlagB = true;
			}
			if(isFlagB) puts("B");
			else printf("%d\n", val[0]);
		}
		else{
			if(val[1] == val[2]){
				a = 0;
				b = val[1];
			}
			else{
				if((val[1]-val[2])%(val[0]-val[1]) != 0) isFlagB = true;
				else{
					a = (val[1]-val[2])/(val[0]-val[1]);
					b = val[1]-a*val[0];
				}
			}
			if(isFlagB == false){
				for(int i=3; i<N; i++){
					if(val[i] != val[i-1]*a+b) isFlagB = true;
				}
			}
			if(isFlagB) puts("B");
			else printf("%d\n", val[N-1]*a+b);
		}
	}
}