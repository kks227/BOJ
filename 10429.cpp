#include <cstdio>
#include <vector>
using namespace std;

bool invalid(int r, int c){
	return r<0 || c<0 || r>2 || c>2;
}

int N, M;
char map[3][3];
int roff[4] = {-1, 1, 0, 0};
int coff[4] = {0, 0, -1, 1};
bool possible, visited[9];
vector<int> result;

bool DFS(int remain, int r, int c){
	if(possible) return true;
	visited[r*3+c] = true;
	result.push_back(r*3+c);
	if(remain == 1){
		int temp = map[result[0]/3][result[0]%3]-'0';
		for(int i=1; i<M; i++){
			char op = map[result[i*2-1]/3][result[i*2-1]%3];
			int val = map[result[i*2]/3][result[i*2]%3]-'0';
			if(op == '+') temp += val;
			else temp -= val;
		}
		if(temp == N) return true;
		else{
			result.pop_back();
			visited[r*3+c] = false;
			return false;
		}
	}
	else{
		for(int d=0; d<4; d++){
			int rn = r+roff[d];
			int cn = c+coff[d];
			if(invalid(rn, cn)) continue;
			if(visited[rn*3+cn]) continue;
			if(DFS(remain-1, rn, cn)) return true;
		}
	}
	result.pop_back();
	visited[r*3+c] = false;
	return false;
}

int main(){
	scanf("%d %d\n", &N, &M);
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++)
			map[i][j] = getchar();
		getchar();
	}

	for(int init=0; init<9; init+=2){
		int r = init/3;
		int c = init%3;
		if(DFS(M*2-1, r, c)){
			possible = true;
			break;
		}
	}
	printf("%d\n", possible);
	if(possible){
		for(int d: result)
			printf("%d %d\n", d/3, d%3);
	}
}