#include <cstdio>
using namespace std;

int N;
bool tree[512][512];

void restore(int r, int c, int size){
	char q = getchar();
	if(q == 'B'){
		for(int i=r; i<r+size; i++)
			for(int j=c; j<c+size; j++)
				tree[i][j] = true;
	}
	else if(q == 'Q'){
		restore(r, c, size/2);
		restore(r, c+size/2, size/2);
		restore(r+size/2, c, size/2);
		restore(r+size/2, c+size/2, size/2);
	}
}

int main(){
	scanf("%d\n", &N);
	restore(0, 0, N);
	printf("#define quadtree_width %d\n", N);
	printf("#define quadtree_height %d\n", N);
	puts("static char quadtree_bits[] = {");
	for(int i=0; i<N; i++){
		for(int j=0; j<N/8; j++){
			int val = 0;
			for(int k=0; k<8; k++)
				val = val*2 + tree[i][j*8+7-k];
			printf("0x%02x,", val);
		}
		puts("");
	}
	puts("};");
}