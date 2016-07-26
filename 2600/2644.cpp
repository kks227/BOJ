#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

typedef set<int> intSet;

class myQueue{
public:
	myQueue(int n){
		qSize = n+1;
		data = new int[qSize];
		clear();
	}
	~myQueue(){
		delete[] data;
	}
	void clear(){
		dSize = front = rear = 0;
	}
	void push(int val){
		if((rear+1)%qSize == front) return; //full
		dSize++;
		rear = (rear+1)%qSize;
		data[rear] = val;
	}
	int pop(){
		if(front == rear) return 0; //empty
		dSize--;
		front = (front+1)%qSize;
		return data[front];
	}
	int size(){
		return dSize;
	}
	bool empty(){
		return dSize==0;
	}
private:
	int qSize, dSize;
	int front, rear;
	int *data;
};

myQueue mq1(100), mq2(100);

class graph{
public:
	graph(int n):size(n){
		adj = new intSet[n];
		visited = new bool[n];
	}
	~graph(){
		delete[] adj;
		delete[] visited;
	}
	void addEdge(int u, int v){
		adj[u].insert(v);
		adj[v].insert(u);
	}
	int degree(int start, int dest){
		mq1.clear();
		mq2.clear();
		mq1.push(start);
		mq2.push(0);
		memset(visited, 0, size);

		int currentNode, currentDegree;
		while(!mq1.empty()){
			currentNode = mq1.pop();
			currentDegree = mq2.pop();
			if(visited[currentNode]) continue;
			if(currentNode == dest) return currentDegree;
			visited[currentNode] = true;
			for(iter=adj[currentNode].begin(); iter!=adj[currentNode].end(); iter++){
				mq1.push(*iter);
				mq2.push(currentDegree+1);
			}
		}

		return -1;
	}
private:
	int size;
	intSet *adj;
	intSet::iterator iter;
	bool *visited;
};

int main(){

	int n, u, v, m, x, y;
	scanf("%d %d %d %d", &n, &u, &v, &m);
	graph gp(n);
	for(int i=0; i<m; i++){
		scanf("%d %d", &x, &y);
		gp.addEdge(x-1, y-1);
	}
	printf("%d\n", gp.degree(u-1, v-1));

	return 0;
}