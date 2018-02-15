#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;
typedef tuple<bool, bool, int> Node;

int main(){
	int A, B, da, db;
	scanf("%d %d %d %d", &A, &B, &da, &db);
	if(0 < da && da < A && 0 < db && db < B){
		puts("-1");
		return 0;
	}

	bool visited[2][2][100001] = {true};
	queue<Node> Q;
	Q.push(Node(false, false, 0));
	for(int result=0; !Q.empty(); result++){
		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
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
			if(a == da && b == db){
				printf("%d\n", result);
				return 0;
			}

			for(int j=0; j<2; j++){
				for(int k=0; k<2; k++){
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
	puts("-1");
}