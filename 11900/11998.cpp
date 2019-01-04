#include <cstdio>
#include <cmath>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX = 100;
typedef tuple<bool, bool, int> Node;

int main(){
	int A, B, K, M;
	scanf("%d %d %d %d", &A, &B, &K, &M);

	bool visited[2][2][MAX+1] = {true};
	queue<Node> Q;
	Q.push(Node(false, false, 0));
	int result = MAX*2;
	for(int l = 0; l <= K; ++l){
		int qSize = Q.size();
		for(int i = 0; i < qSize; ++i){
			int a, b, z;
			bool x, y;
			tie(x, y, z) = Q.front(); Q.pop();
			if(x){
				b = (y ? B : 0);
				a = z;
			}
			else{
				a = (y ? A : 0);
				b = z;
			}
			result = min(abs(a+b-M), result);
			if(l == K) continue;

			for(int j = 0; j < 2; ++j){
				for(int k = 0; k < 2; ++k){
					z = (j ? a : b);
					if(!visited[j][k][z]){
						visited[j][k][z] = true;
						Q.push(Node(j, k, z));
					}
				}
				int Z = (j ? A : B);
				if(Z < a + b){
					z = a + b - Z;
					if(!visited[!j][true][z]){
						visited[!j][true][z] = true;
						Q.push(Node(!j, true, z));
					}
				}
				else{
					z = a + b;
					if(!visited[j][false][z]){
						visited[j][false][z] = true;
						Q.push(Node(j, false, z));
					}
				}
			}
		}
	}
	printf("%d\n", result);
}