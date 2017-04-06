#include <cstdio>
using namespace std;

int main(){
	char W[11];
	int N, result = 0;
	scanf("%s %d", W, &N);
	for(int i=0; i<N; i++){
		bool found = false;
		char R[11];
		scanf("%s", R);
		for(int i=0; i<10; i++){
			found = true;
			for(int j=0; W[j]; j++){
				if(R[(i+j)%10] != W[j]){
					found = false;
					break;
				}
			}
			if(found){
				result++;
				break;
			}
		}
	}
	printf("%d\n", result);
}