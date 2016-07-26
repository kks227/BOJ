#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int P, C, maxVal = -1;
		char result[21], name[21];
		scanf("%d", &P);
		for(int i=0; i<P; i++){
			scanf("%d %s", &C, name);
			if(maxVal < C){
				maxVal = C;
				strcpy(result, name);
			}
		}
		puts(result);
	}
}