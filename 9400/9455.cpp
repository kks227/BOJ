#include <cstdio>
using namespace std;

int main(){

	int T, m, n;
	bool arr[100][100];
	int blank[100];
	int result;
	scanf("%d", &T);
	for(int i=0; i<T; i++){
		scanf("%d %d", &m, &n);

		for(int j=0; j<m; j++)
			for(int k=0; k<n; k++)
				scanf("%d", &arr[j][k]);

		result = 0;
		for(int j=0; j<n; j++)
			blank[j] = 0;
		for(int j=m-1; j>=0; j--){
			for(int k=0; k<n; k++){
				if(arr[j][k]) result += blank[k];
				else blank[k]++;
			}
		}
		printf("%d\n", result);
	}

	return 0;
}