#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, result = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int val[4];
		for(int j=0; j<4; j++)
			scanf("%d", val+j);
		sort(val, val+4);
		int temp;
		if(val[0]==val[1] && val[1]==val[2] && val[2]==val[3]) temp = 50000 + val[0]*5000;
		else if(val[1]==val[2] && (val[0]==val[1] || val[2]==val[3])) temp = 10000 + val[1]*1000;
		else if(val[0]==val[1] && val[2]==val[3]) temp = 2000 + (val[0]+val[2])*500;
		else if(val[0]==val[1] || val[1]==val[2]) temp = 1000 + val[1]*100;
		else if(val[2]==val[3]) temp = 1000 + val[2]*100;
		else temp = val[3]*100;
		result = max(result, temp);
	}
	printf("%d\n", result);
}