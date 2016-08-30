#include <cstdio>
#include <vector>
using namespace std;

int main(){
	vector<int> fibo(1, 0);
	fibo.push_back(1);
	while(1){
		int next = fibo[fibo.size()-2] + fibo.back();
		if(next > 1000000000) break;
		fibo.push_back(next);
	}
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N;
		scanf("%d", &N);
		vector<int> result;
		for(int i=fibo.size()-1; N>0; i--){
			if(N >= fibo[i]){
				N -= fibo[i];
				result.push_back(fibo[i]);
			}
		}
		for(int i=result.size()-1; i>=0; i--)
			printf("%d ", result[i]);
		puts("");
	}
}