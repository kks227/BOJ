#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int arr[12], N, result = 0;
		scanf("%d", &N);
		for(int i=0; i<12; i++)
			scanf("%d", arr+i);
		while(1){
			int m = 0;
			bool zero = true;
			for(int i=0; i<12; i++)
				if(arr[i]){
					zero = false;
					m = max(m, arr[i]);
				}
			if(zero) break;
			result++;
			int start, end, rep;
			for(int i=0; i<12; i++)
				if(arr[i] == m){
					start = i;
					for(int j=i+1; j<12; j++)
						if(arr[j] != m){
							end = j;
							break;
						}
					break;
				}
			rep = max(arr[start-1], arr[end]);
			for(int i=start; i<end; i++)
				arr[i] = rep;
		}
		printf("%d %d\n", N, result);
	}
}