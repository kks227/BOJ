#include <cstdio>
using namespace std;

int main(){
	char E[10];
	gets(E);
	puts(E[0]-'0'+E[4]-'0' == E[8]-'0' ? "YES" : "NO");
}