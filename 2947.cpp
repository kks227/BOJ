#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int a[5];
	for(int i=0; i<5; i++)
		scanf("%d", a+i);
	while(1){
		bool s = false;
		for(int i=0; i<4; i++)
			if(a[i] > a[i+1]){
				s = true;
				swap(a[i], a[i+1]);
				for(int j=0; j<5; j++)
					printf("%d ", a[j]);
				puts("");
			}
		if(!s) break;
	}
}