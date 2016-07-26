#include <cstdio>
#include <cstring>
using namespace std;
  
int main(){
 
    char input[1001];
    int jaehwan;
    scanf("%s", input);
	jaehwan = strlen(input);
    scanf("%s", input);
	printf("%s\n", (jaehwan>=strlen(input))?"go":"no");
 
    return 0;
}