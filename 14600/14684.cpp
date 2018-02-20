#include <cstdio>
using namespace std;

int main(){
	int D, result = 0, d[4];
	scanf("%d", &D);
	for(int i=0; i<12; i++){
		d[0] = (i?i:12)/10;
		d[1] = (i?i:12)%10;
		for(int j=0; j<60; j++){
			d[2] = j/10;
			d[3] = j%10;
			bool flag = true;
			for(int k=!d[0]; k<2; k++)
				if(d[k+1]-d[k] != d[k+2]-d[k+1]) flag = false;
			if(flag) result += D/720 + (i*60+j <= D%720);
		}
	}
	printf("%d\n", result);
}