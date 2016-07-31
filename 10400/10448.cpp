#include <cstdio>
#include <vector>
using namespace std;

int main(){
	// 1000 이하의 삼각수를 모두 구하고 시작
	vector<int> tri(1, 1);
	for(int i=2; ; i++){
		int next = tri.back() + i;
		if(next > 1000) break;
		tri.push_back(next);
	}

	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int K;
		scanf("%d", &K);
		bool result = 0;
		// 가능한 3개의 조합을 다 시도해 봄
		for(int i: tri){
			for(int j: tri){
				for(int k: tri)
					if(K == i+j+k){
						result = true;
						break;
					}
				if(result) true;
			}
			if(result) true;
		}
		printf("%d\n", result);
	}
}