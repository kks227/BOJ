#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAX_A = 100;
const int MAX_B = MAX_A*20;

class Solver{
public:
    void input(){
        cin >> N;
        K[0] = K[1] = K[2] = 0;
        for(int i = 0; i < N; ++i){
            for(int g = 0; g < 3; ++g){
                int W;
                cin >> W;
                for(int j = 0; j < W; ++j){
                    string S;
                    cin >> S;
                    if(S2I[g].find(S) == S2I[g].end()) S2I[g][S] = K[g]++;
                    adj[g][i].push_back(S2I[g][S]*2);
                    adj[g][i].push_back(S2I[g][S]*2+1);
                }
            }
        }
    }

    int solve(){
        for(int g = 0; g < 3; ++g){
            K[g] *= 2;
            fill(A[g], A[g] + N, -1);
            fill(B[g], B[g] + K[g], -1);
        }
        for(int i = 0; i < N; ++i){
            for(int g = 0; g < 3; ++g){
                fill(visited[g], visited[g] + N, false);
                if(!dfs(g, i)) return i;
            }
        }
        return N;;
    }

private:
    int N, K[3], A[3][MAX_A], B[3][MAX_B];
    vector<int> adj[3][MAX_A];
    unordered_map<string, int> S2I[3];
    bool visited[3][MAX_A];

    bool dfs(int g, int a){
        visited[g][a] = true;
        for(int b: adj[g][a]){
            if(B[g][b] == -1 || !visited[g][B[g][b]] && dfs(g, B[g][b])){
                A[g][a] = b;
                B[g][b] = a;
                return true;
            }
        }
        return false;
    }
};

int main(){
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t){
        Solver solver;
        solver.input();
        cout << solver.solve() << '\n';
    }
}