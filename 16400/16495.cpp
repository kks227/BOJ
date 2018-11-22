#include <cstdio>
using namespace std;

int main(){
	char S[11];
    scanf("%s", S);
    long long result = 0;
    for(int i = 0; S[i]; ++i)
        result = result*26 + S[i]-'A'+1;
    printf("%lld\n", result);
}