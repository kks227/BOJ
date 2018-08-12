#include <cstdio>
using namespace std;

int main(){
	int N, status = 0;
	bool way = true, jotMang = false;
	scanf("%d\n", &N);
	for(int i=0; i<N; i++){
		char c = getchar();
		if(c == 'P'){
			if(status == 1) jotMang = true;
			else if(status == 0) way = !way;
		}
		else{
			if(status < 2) status++;
		}
	}

	int result = 0;
	if(status == 2){
		if(jotMang) result = 6;
		else result = (way ? 5 : 1);
	}
	printf("%d\n", result);
}