#include <cstdio>
#include <vector>
using namespace std;

int main(){
	while(1){
		int N, T;
		scanf("%d", &N);
		if(N == 0) break;
		scanf("%d", &T);
		vector<int> arr(N, 0);

		int k = 0, p = N;
		while(1){
			for(int i=0; i<T; i++){
				if(i) k = (k+1) % p;
				arr[k]++;
			}
			arr.erase(arr.begin() + k);
			k %= --p;
			bool success = true;
			for(int i=1; i<p; i++)
				if(arr[i-1] != arr[i]){
					success = false;
					break;
				}
			if(success) break;
		}
		printf("%d %d\n", p, arr[0]);
	}
}