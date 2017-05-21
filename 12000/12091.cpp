#include <cstdio>
#include <ctime>
using namespace std;

int main(){
	int L;
	scanf("%d", &L);
	char addr[9], result[3][9] = {"Vaporeon", "Jolteon", "Flareon"};
	for(int i=1e9+L; i>0; i--)
		L = L*2 + 1;
	puts(result[(time('\0')+L) % 3]);
}