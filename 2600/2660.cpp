#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
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

myQueue mq(50);

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
	void print1st(){
		int *score = new int[size];
		int minScore = 50;

		for(int i=0; i<size; i++){
			score[i] = BFS(i);
			minScore = min(minScore, score[i]);
		}
		printf("%d ", minScore);
		intSet cand;
		for(int i=0; i<size; i++)
			if(minScore == score[i]) cand.insert(i+1);
		printf("%d\n", cand.size());
		for(intSet::iterator iter=cand.begin(); iter!=cand.end(); iter++)
			printf("%d ", *iter);

		delete[] score;
	}
private:
	int size;
	intSet *adj;
	bool *visited;
	
	int BFS(int start){
		mq.clear();
		mq.push(start);
		memset(visited, 0, size);
		visited[start] = true;

		int result = 0;
		int tSize, current;
		while(!mq.empty()){
			result++;
			tSize = mq.size();
			for(int i=0; i<tSize; i++){
				current = mq.pop();
				for(intSet::iterator iter=adj[current].begin(); iter!=adj[current].end(); iter++){
					if(!visited[*iter]){
						mq.push(*iter);
						visited[*iter] = true;
					}
				}
			}
		}

		return result-1;
	}
};

int main(){

	int N, u, v;
	scanf("%d", &N);
	graph gp(N);
	while(1){
		scanf("%d %d", &u, &v);
		if(u == -1) break;
		gp.addEdge(u-1, v-1);
	}
	gp.print1st();

	return 0;
}