#include <cstdio>
using namespace std;
  
int preorder[1000], inorder[1000], inPos[1000];
int rootPos;
  
void postorder(int start, int end){
    if(start == end) return;
    int root = preorder[rootPos++];
    int pivot = inPos[root];
    postorder(start, pivot);
    postorder(pivot+1, end);
    printf("%d ", root+1);
}
  
int main(){
  
    int T, N;
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        scanf("%d", &N);
        for(int j=0; j<N; j++){
            scanf("%d", preorder+j);
            preorder[j]--;
        }
        for(int j=0; j<N; j++){
            scanf("%d", inorder+j);
            inorder[j]--;
            inPos[inorder[j]] = j;
        }
        rootPos = 0;
        postorder(0, N);
        putchar('\n');
    }
  
    return 0;
}