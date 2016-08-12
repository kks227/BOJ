#include <cstdio>
using namespace std;

int main(){
	while(1){
		int M[32] = {0};
		for(int i=0; i<32; i++){
			for(int j=0; j<8; j++){
				int temp;
				if(scanf("%1d", &temp) < 0) return 0;
				M[i] = M[i]*2 + temp;
			}
		}

		int PC = 0, A = 0;
		while(1){
			int inst = M[PC], op = inst/32, val = inst%32;
			if(op == 7) break;

			PC = (PC+1)%32;
			switch(op){
			case 0: // STA
				M[val] = A;
				break;
			case 1: // LDA
				A = M[val];
				break;
			case 2: // BEQ
				if(A == 0) PC = val;
				break;
			case 4: // DEC
				A = (A+255)%256;
				break;
			case 5: // INC
				A = (A+1)%256;
				break;
			case 6: // JMP
				PC = val;
			}
		}
		for(int i=7; i>=0; i--)
			printf("%1d", (A>>i)&1);
		puts("");
	}
}