#include <cstdio>
#include <queue>
using namespace std;

int main(){
	int N, A, B, dA, dB;
	scanf("%d %d %d %d %d", &N, &A, &B, &dA, &dB);
	A--; B--;
	bool visited[2][500][500] = {0};
	queue<int> Q;
	visited[0][A][B] = true;
	Q.push(A*500 + B);
	for(int result=0; !Q.empty(); result++){
		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			bool turn = Q.front()/250000;
			int a = Q.front()%250000/500, b = Q.front()%500;
			Q.pop();
			if(a == b){
				printf("%d\n", result);
				return 0;
			}

			if(turn){
				int nb = (b + dB) % N;
				if(!visited[0][a][nb]){
					visited[0][a][nb] = true;
					Q.push(a*500 + nb);
				}
				nb = (N + b - dB) % N;
				if(!visited[0][a][nb]){
					visited[0][a][nb] = true;
					Q.push(a*500 + nb);
				}
			}
			else{
				int na = (a + dA) % N;
				if(!visited[1][na][b]){
					visited[1][na][b] = true;
					Q.push(250000 + na*500 + b);
				}
				na = (N + a - dA) % N;
				if(!visited[1][na][b]){
					visited[1][na][b] = true;
					Q.push(250000 + na*500 + b);
				}
			}
		}
	}
	puts("Evil Galazy");
}