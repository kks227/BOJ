#include <iostream>
#include <queue>
using namespace std;

int riped;
int riped_this_time;
int map[102][102][102];
queue<int> Node;

void BFS(int p, int q, int r, int t, bool sub){
	if(sub){
		if(map[p][q][r] == 0){
			map[p][q][r] = t+2;
			riped_this_time++;
			riped++;
			Node.push(p*1000000 + q*1000 + r);
		}
		return;
	}
    BFS(p-1, q, r, t, true);
    BFS(p+1, q, r, t, true);
    BFS(p, q-1, r, t, true);
    BFS(p, q+1, r, t, true);
    BFS(p, q, r-1, t, true);
    BFS(p, q, r+1, t, true);
}

int main(){

	int M, N, H, tomato=0;
	cin >> M >> N >> H;
	for(int i=1; i<=H; i++){
		for(int j=1; j<=N; j++){
			for(int k=1; k<=M; k++){
				cin >> map[i][j][k];
				if(map[i][j][k] == 1){
					riped++;
					tomato++;
					Node.push(i*1000000 + j*1000 + k);
				}
				if(map[i][j][k] == 0) tomato++;
			}
		}
	}
	for(int i=0; i<=H+1; i++){
		for(int j=0; j<=N+1; j++)
			map[i][j][0] = map[i][j][M+1] = -1;
		for(int j=0; j<=M+1; j++)
			map[i][0][j] = map[i][N+1][j] = -1;
	}
	for(int i=0; i<=N+1; i++)
		for(int j=0; j<=M+1; j++)
			map[0][i][j] = map[H+1][i][j] = -1;

	int t = 0, present_queue_size, current_dest;
	int p, q, r;
	if(riped < tomato){
		while(riped < tomato){
			riped_this_time = 0;
			present_queue_size = Node.size();
			for(int i=0; i<present_queue_size; i++){
				current_dest = Node.front();
				Node.pop();
				p = current_dest/1000000;
				q = current_dest%1000000;
				r = q%1000;
				q /= 1000;
				BFS(p, q, r, t, false);
			}
			if(riped_this_time == 0) break;
			t++;
		}
		if(riped_this_time == 0) cout << -1 << endl;
		else cout << t << endl;
	}
	else cout << 0 << endl;

	return 0;
}