#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int A, B, N, M;
	scanf("%d %d %d %d", &A, &B, &N, &M);
	queue<int> Q;
	Q.push(N);
	bool visited[100001] = {0};
	visited[N] = true;

	int result = 0;
	bool success = false;
	while(1){
		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			int p = Q.front();
			Q.pop();
			if(p == M){
				success = true;
				break;
			}

			vector<int> np;
			if(p > 0) np.push_back(p-1);
			if(p < 100000) np.push_back(p+1);
			if(p >= A) np.push_back(p-A);
			if(p <= 100000-A) np.push_back(p+A);
			if(p >= B) np.push_back(p-B);
			if(p <= 100000-B) np.push_back(p+B);
			if(p*A <= 100000) np.push_back(p*A);
			if(p*B <= 100000) np.push_back(p*B);
			for(int k: np)
				if(!visited[k]){
					visited[k] = true;
					Q.push(k);
				}
		}
		if(success) break;
		result++;
	}
	printf("%d\n", result);
}