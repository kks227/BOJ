#include <cstdio>
using namespace std;

int postorder[100000], inorder[100000], inPos[100000];

void preorder(int start, int end, int rootPos){
    if(start == end) return;
    int root = postorder[rootPos];
	printf("%d ", root+1);
    int pivot = inPos[root];
    preorder(start, pivot, rootPos-end+pivot);
    preorder(pivot+1, end, rootPos-1);
}
 
int main(){

	int N;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", inorder+i);
		inorder[i]--;
		inPos[inorder[i]] = i;
	}
	for(int i=0; i<N; i++){
		scanf("%d", postorder+i);
		postorder[i]--;
	}
	preorder(0, N, N-1);

    return 0;
}