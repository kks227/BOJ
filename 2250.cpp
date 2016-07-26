#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int leftest[10000], rightest[10000], leftChild[10000], rightChild[10000], parent[10000];

int width(int current, int leftmost, int level){
	int result = 0;
	if(leftChild[current] != -1) result += width(leftChild[current], leftmost, level+1);
	leftest[level] = min(leftest[level], leftmost + result);
	rightest[level] = max(rightest[level], leftmost + result);
	result++;
	if(rightChild[current] != -1) result += width(rightChild[current], leftmost+result, level+1);
	return result;
}

int main(){

	int N, node, leftC, rightC;
	scanf("%d", &N);
	memset(parent, -1, sizeof(int)*N);
	for(int i=0; i<N; i++){
		scanf("%d %d %d", &node, &leftC, &rightC);
		if(leftC == -1) leftChild[node-1] = -1;
		else{
			leftChild[node-1] = leftC-1;
			parent[leftC-1] = node-1;
		}
		if(rightC == -1) rightChild[node-1] = -1;
		else{
			rightChild[node-1] = rightC-1;
			parent[rightC-1] = node-1;
		}
		leftest[i] = N;
		rightest[i] = -1;
	}
	int root = -1;
	for(int i=0; i<N; i++){
		if(parent[i] == -1){
			root = i;
			break;
		}
	}

	width(root, 0, 0);
	int resultWidth = 0, resultLevel = 0;
	for(int i=0; i<N; i++){
		if(leftest[i] == N) break;
		if(resultWidth < rightest[i]-leftest[i]){
			resultWidth = rightest[i]-leftest[i];
			resultLevel = i;
		}
	}
	printf("%d %d\n", resultLevel+1, resultWidth+1);
	
	return 0;
}