#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 1000;

struct Edge{
    int to, cnt;
    Edge *dual;
    Edge(): Edge(-1, 0){}
    Edge(int to1, int cnt1): to(to1), cnt(cnt1), dual(nullptr){}
};

class Graph{
public:
    void input(){
        scanf("%d", &N);
        M = 0;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                int val;
                scanf("%d", &val);
                if(j > i && val > 0){
                    Edge *e1 = new Edge(j, val), *e2 = new Edge(i, val);
                    e1->dual = e2;
                    e2->dual = e1;
                    adj[i].push_back(e1);
                    adj[j].push_back(e2);
                    degree[i] += val;
                    degree[j] += val;
                    M += val;
                }
            }
        }
    }

    void Eulerian(){
        for(int i = 0; i < N; ++i){
            if(degree[i]%2 == 1){
                puts("-1");
                return;
            }
        }

        EPath.clear();
        for(int i = 0; i < N; ++i){
            if(degree[i] > 0){
                Eulerian(i);
                break;
            }
        }

        if(EPath.size() == M+1){
            for(int i: EPath)
                printf("%d ", i+1);
        }
        else puts("-1");
    }

private:
    int N, M, degree[MAX];
    vector<Edge*> adj[1000];
    vector<int> EPath;

    void Eulerian(int curr){
        for(Edge *e: adj[curr]){
            if(e->cnt > 0){
                e->cnt--;
                e->dual->cnt--;
                Eulerian(e->to);
            }
        }
        EPath.push_back(curr);
    }
};



int main(){
    Graph G;
    G.input();
    G.Eulerian();
}