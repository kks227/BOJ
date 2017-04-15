#include <cstdio>
#include <queue>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const char fc[2] = {'R', 'B'};

int main(){
	int R, C, sr[2], sc[2];
	char m[10][10];
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++){
			m[i][j] = getchar();
			if(m[i][j] == 'R'){ sr[0]=i; sc[0]=j; m[i][j]='.'; }
			else if(m[i][j] == 'B'){ sr[1]=i; sc[1]=j; m[i][j]='.'; }
		}
	}

	queue<int> Q;
	Q.push(sr[0]*1000 + sc[0]*100 + sr[1]*10 + sc[1]);
	bool visited[10][10][10][10] = {0};
	visited[sr[0]][sc[0]][sr[1]][sc[1]] = true;
	for(int p=0; p<10; p++){
		int qSize = Q.size();
		for(int q=0; q<qSize; q++){
			int curr = Q.front();
			Q.pop();
			int r[2] = {curr/1000, curr%100/10}, c[2] = {curr%1000/100, curr%10};

			for(int d=0; d<4; d++){
				bool out[2] = {0}, k = false;
				if(d==0 && r[0]>r[1] || d==1 && r[0]<r[1] || d==2 && c[0]>c[1] || d==3 && c[0]<c[1]) k = true;
				int nr[2] = {r[0], r[1]}, nc[2] = {c[0], c[1]};
				for(int l=0; l<2; l++, k=!k){
					for(; m[nr[k]][nc[k]]=='.'; nr[k]+=roff[d], nc[k]+=coff[d]);
					if(m[nr[k]][nc[k]] == 'O') out[k] = true;
					else{
						nr[k] -= roff[d];
						nc[k] -= coff[d];
						m[nr[k]][nc[k]] = fc[k];
					}
				}
				if(out[0] && !out[1]){
					printf("%d\n", p+1);
					return 0;
				}
				for(int k=0; k<2; k++)
					if(!out[k]) m[nr[k]][nc[k]] = '.';
				if(!out[1]){
					if(!visited[nr[0]][nc[0]][nr[1]][nc[1]]){
						visited[nr[0]][nc[0]][nr[1]][nc[1]] = true;
						Q.push(nr[0]*1000 + nc[0]*100 + nr[1]*10 + nc[1]);
					}
				}
			}
		}
	}
	puts("-1");
}