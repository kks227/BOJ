#include <cstdio>
#include <cstring>
#include <cctype>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 102;

int main(){
	char E[2][MAX+1] = {0};
	int L[2];
	for(int k = 0; k < 2; ++k){
		int scnt = 0;
		bool flag = false;
		scanf("%s", E[k]);
		L[k] = strlen(E[k]);
		for(int i = 0; E[k][i]; ++i){
			char c = E[k][i];
			if(c == '(') ++scnt;
			else if(c == ')') --scnt;
			else if(c == '|'){
				if(scnt == 0){
					flag = true;
					break;
				}
			}
		}
		if(flag){
			copy(E[k], E[k]+L[k], E[k]+1);
			L[k] += 2;
			E[k][0] = '(';
			E[k][L[k]-1] = ')';
		}
	}

	vector<int> eps[2][MAX];
	for(int k = 0; k < 2; ++k){
		for(int i = 0; E[k][i]; ++i){
			if(E[k][i] == '('){
				eps[k][i].push_back(i+1);
				int scnt = 0;
				vector<int> bar;
				for(int j = i+1; ; ++j){
					if(E[k][j] == '(') ++scnt;
					else if(E[k][j] == ')'){
						if(scnt-- == 0){
							for(int b: bar){
								eps[k][b].push_back(j);
								eps[k][i].push_back(b+1);
							}
							if(E[k][j+1] == '*'){
								eps[k][i].push_back(j+2);
								eps[k][j].push_back(j+2);
								eps[k][j].push_back(i);
							}
							else eps[k][j].push_back(j+1);
							break;
						}
					}
					else if(E[k][j] == '|'){
						if(scnt == 0) bar.push_back(j);
					}
				}
			}
			else if(E[k][i] == '*'){
				if(E[k][i-1] != ')'){
					eps[k][i-1].push_back(i+1);
					eps[k][i].push_back(i+1);
					eps[k][i].push_back(i-1);
				}
			}
		}
	}

	queue<int> Q;
	bool visited[MAX][MAX] = {true,}, result = true;
	Q.push(0);
	int prev[MAX][MAX], r[2];
	char pc[MAX][MAX] = {'\0'};
	while(!Q.empty()){
		int q[2] = {Q.front()/1000, Q.front()%1000};
		Q.pop();

		vector<int> nq[2];
		bool ev[2][MAX] = {false,};
		for(int k = 0; k < 2; ++k){
			nq[k].push_back(q[k]);

			queue<int> eQ;
			eQ.push(q[k]);
			ev[k][q[k]] = true;
			while(!eQ.empty()){
				int curr = eQ.front(); eQ.pop();
				for(int next: eps[k][curr]){
					if(!ev[k][next]){
						ev[k][next] = true;
						eQ.push(next);
						nq[k].push_back(next);
					}
				}
			}
		}
		if((q[0] != 0 || q[1] != 0) && ev[0][L[0]] && ev[1][L[1]]){
			result = false;
			r[0] = q[0];
			r[1] = q[1];
			break;
		}

		for(int qa: nq[0]){
			for(int qb: nq[1]){
				if(!visited[qa][qb]){
					prev[qa][qb] = q[0]*1000 + q[1];
					pc[qa][qb] = ' ';
				}
				for(char c = 'a'; c <= 'z'; ++c){
					if(E[0][qa] == c && E[1][qb] == c && !visited[qa+1][qb+1]){
						visited[qa+1][qb+1] = true;
						Q.push((qa+1)*1000 + qb+1);
						pc[qa+1][qb+1] = c;
						prev[qa+1][qb+1] = q[0]*1000 + q[1];
					}
				}
			}
		}
	}

	if(result) puts("Correct");
	else{
		puts("Wrong");
		vector<char> trace;
		for(int i = r[0], j = r[1]; i != 0; ){
			if(pc[i][j] != ' ') trace.push_back(pc[i][j]);
			int temp = prev[i][j];
			i = temp / 1000;
			j = temp % 1000;
		}
		for(int i = trace.size()-1; i >= 0; --i)
			putchar(trace[i]);
	}
}