#include <iostream>
#include <queue>
using namespace std;

int riped;
int riped_this_time;
int map[1002][1002];
queue<int> Node;

void BFS(int p, int q, int t, bool sub){
	if(sub){
		if(map[p][q] == 0){
			map[p][q] = t+2;
			riped_this_time++;
			riped++;
			Node.push(p*1000 + q);
		}
		return;
	}
    BFS(p-1, q, t, true);
    BFS(p, q-1, t, true);
    BFS(p, q+1, t, true);
    BFS(p+1, q, t, true);
}

int main(){

	int M, N, tomato=0;
	cin >> M >> N;
	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){
			cin >> map[i][j];
			if(map[i][j] == 1){
				riped++;
				tomato++;
				Node.push(i*1000 + j);
			}
			if(map[i][j] == 0) tomato++;
		}
	}
	for(int i=0; i<=N+1; i++)
		map[i][0] = map[i][M+1] = -1;
	for(int j=0; j<=M+1; j++)
		map[0][j] = map[N+1][j] = -1;

	int t = 0, present_queue_size, current_dest;
	int p, q;
	if(riped < tomato){
		while(riped < tomato){
			riped_this_time = 0;
			present_queue_size = Node.size();
			for(int i=0; i<present_queue_size; i++){
				current_dest = Node.front();
				Node.pop();
				p = current_dest/1000;
				q = current_dest%1000;
				if(q==0) q = 1000;
				BFS(p, q, t, false);
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