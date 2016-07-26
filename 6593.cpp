#include <cstdio>
#include <queue>
using namespace std;

int L, R, C, offset[6][3] = {
	-1, 0, 0, 1, 0, 0,
	0, -1, 0, 0, 1, 0,
	0, 0, -1, 0, 0, 1
};

bool invalid(int i, int j, int k){
	return i<0 || i>=L || j<0 || j>=R || k<0 || k>=C;
}

int main(){
	while(1){
		scanf("%d %d %d", &L, &R, &C);
		if(L==0) break;
		int S[3], E[3];
		bool map[30][30][30];
		for(int i=0; i<L; i++){
			for(int j=0; j<R; j++){
				getchar();
				for(int k=0; k<C; k++){
					char c = getchar();
					map[i][j][k] = (c=='#');
					if(c=='S'){
						S[0] = i;
						S[1] = j;
						S[2] = k;
					}
					else if(c=='E'){
						E[0] = i;
						E[1] = j;
						E[2] = k;
					}
				}
			}
			getchar();
		}
		queue<int> q;
		q.push(S[0]*10000+S[1]*100+S[2]);
		int result = 0;
		while(!q.empty()){
			int qSize = q.size();
			for(int t=0; t<qSize; t++){
				int i = q.front()/10000;
				int j = q.front()%10000/100;
				int k = q.front()%100;
				q.pop();
				if(map[i][j][k]) continue;
				map[i][j][k] = true;
				for(int d=0; d<6; d++){
					int nextI = i+offset[d][0];
					int nextJ = j+offset[d][1];
					int nextK = k+offset[d][2];
					if(invalid(nextI, nextJ, nextK)) continue;
					if(!map[nextI][nextJ][nextK]) q.push(nextI*10000+nextJ*100+nextK);
				}
			}
			if(map[E[0]][E[1]][E[2]]) break;
			result++;
		}
		if(map[E[0]][E[1]][E[2]]) printf("Escaped in %d minute(s).\n", result);
		else puts("Trapped!");
	}
}