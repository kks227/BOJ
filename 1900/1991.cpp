#include <cstdio>
#include <cstring>
using namespace std;
 
bool visited[26];
int leftChild[26], rightChild[26];
 
void preorder(int current){
    if(current == -1) return;
    printf("%c", current+'A');
    preorder(leftChild[current]);
    preorder(rightChild[current]);
}
 
void inorder(int current){
    if(current == -1) return;
    inorder(leftChild[current]);
    printf("%c", current+'A');
    inorder(rightChild[current]);
}
 
void postorder(int current){
    if(current == -1) return;
    postorder(leftChild[current]);
    postorder(rightChild[current]);
    printf("%c", current+'A');
}
 
int main(){
 
    int N;
    scanf("%d", &N);
    int current;
	char c;
    for(int i=0; i<N; i++){
        getchar();
        current = getchar()-'A';
		getchar();
		c = getchar();
        leftChild[current] = (c=='.')?-1:c-'A';
		getchar();
		c = getchar();
        rightChild[current] = (c=='.')?-1:c-'A';
    }
 
    memset(visited, 0, 26);
    preorder(0);
	putchar('\n');
    memset(visited, 0, 26);
    inorder(0);
	putchar('\n');
    memset(visited, 0, 26);
    postorder(0);
	putchar('\n');
 
    return 0;
}