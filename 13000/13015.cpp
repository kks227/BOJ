#include <cstdio>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) putchar('*');
	for(int i = 0; i < N*2-3; ++i) putchar(' ');
	for(int i = 0; i < N; ++i) putchar('*');
	puts("");
	for(int i = 0, j = N-2; i < N-2; ++i, --j){
		for(int k = 0; k < i+1; ++k) putchar(' ');
		putchar('*');
		for(int k = 0; k < N-2; ++k) putchar(' ');
		putchar('*');
		for(int k = 0; k < j*2-1; ++k) putchar(' ');
		putchar('*');
		for(int k = 0; k < N-2; ++k) putchar(' ');
		puts("*");
	}
	for(int k = 0; k < N-1; ++k) putchar(' ');
	putchar('*');
	for(int k = 0; k < N-2; ++k) putchar(' ');
	putchar('*');
	for(int k = 0; k < N-2; ++k) putchar(' ');
	puts("*");
	for(int i = N-3, j = 1; i >= 0; --i, ++j){
		for(int k = 0; k < i+1; ++k) putchar(' ');
		putchar('*');
		for(int k = 0; k < N-2; ++k) putchar(' ');
		putchar('*');
		for(int k = 0; k < j*2-1; ++k) putchar(' ');
		putchar('*');
		for(int k = 0; k < N-2; ++k) putchar(' ');
		puts("*");
	}
	for(int i = 0; i < N; ++i) putchar('*');
	for(int i = 0; i < N*2-3; ++i) putchar(' ');
	for(int i = 0; i < N; ++i) putchar('*');
	puts("");
}