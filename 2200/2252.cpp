#include <cstdio>
#include <set>
#include <queue>
#include <vector>
using namespace std;

typedef set<int> intSet;

class graph{
public:
	graph(int n){
		size = n;
		predecessor = new intSet[n];
		successor = new intSet[n];
	}
	~graph(){
		delete[] predecessor;
		delete[] successor;
	}
	void addEdge(int u, int v){
		successor[u].insert(v);
		predecessor[v].insert(u);
	}
	void printRow(){
		priority_queue<int, vector<int>, greater<int> > buffer;
		int current;
		intSet::iterator iter, tempIter;
		for(int i=0; i<size; i++)
			if(predecessor[i].size() == 0) buffer.push(i);

		while(!buffer.empty()){
			current = buffer.top();
			buffer.pop();
			printf("%d ", current+1);
			for(iter=successor[current].begin(); iter!=successor[current].end(); ){
				predecessor[*iter].erase(current);
				if(predecessor[*iter].size() == 0) buffer.push(*iter);
				tempIter = iter++;
				successor[current].erase(tempIter);
			}
		}
	}
private:
	int size;
	intSet *predecessor, *successor;
};

int main(){

	int N, M, A, B;
	scanf("%d %d", &N, &M);
	graph gp(N);
	for(int i=0; i<M; i++){
		scanf("%d %d", &A, &B);
		gp.addEdge(A-1, B-1);
	}
	gp.printRow();

	return 0;
}