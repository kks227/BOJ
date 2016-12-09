#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int s[6][2] = {0, 1, 0, 2, 0, 3, 1, 2, 1, 3, 2, 3}, a[4] = {1, 0, 0, 2};
	while(1){
		int c = getchar();
		if(c < 0) break;
		swap(a[s[c-'A'][0]], a[s[c-'A'][1]]);
	}
	for(int i=1; i<=2; i++)
		for(int j=0; j<4; j++)
			if(a[j] == i) printf("%d\n", j+1);
}