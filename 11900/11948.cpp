#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int val[6];
	for(int i=0; i<6; i++)
		scanf("%d", val+i);
	sort(val, val+4);
	sort(val+4, val+6);
	printf("%d\n", val[1]+val[2]+val[3]+val[5]);
}