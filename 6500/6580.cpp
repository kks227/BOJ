#include <cstdio>
using namespace std;

int N;
bool tree[512][512];

void quadTree(int r, int c, int size){
	if(size == 1){
		putchar(tree[r][c] ? 'B' : 'W');
		return;
	}
	bool exist[2] = {0};
	for(int i=r; i<r+size; i++)
		for(int j=c; j<c+size; j++)
			exist[tree[i][j]] = true;
	if(exist[0] && exist[1]){
		putchar('Q');
		quadTree(r, c, size/2);
		quadTree(r, c+size/2, size/2);
		quadTree(r+size/2, c, size/2);
		quadTree(r+size/2, c+size/2, size/2);
	}
	else putchar(tree[r][c] ? 'B' : 'W');
}

int main(){
	scanf("#define quadtree_width %d\n", &N);
	scanf("#define quadtree_height %d\n", &N);
	scanf("static char quadtree_bits[] = {\n");
	for(int i=0; i<N; i++){
		for(int j=0; j<N/8; j++){
			int val;
			scanf("0x%x,", &val);
			for(int k=0; k<8; k++){
				tree[i][j*8+k] = val%2;
				val /= 2;
			}
		}
		scanf("\n");
	}
	scanf("};\n");
	printf("%d\n", N);
	quadTree(0, 0, N);
}