#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int P, arr[20], result = 0;
		scanf("%d %d", &P, arr);
		for(int i=1; i<20; i++){
			scanf("%d", arr+i);
			for(int j=i-1; j>=0; j--){
				if(arr[j] < arr[j+1]) break;
				swap(arr[j], arr[j+1]);
				result++;
			}
		}
		printf("%d %d\n", P, result);
	}
}