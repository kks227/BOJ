#include <cstdio>
#include <cctype>
using namespace std;

int main(){
	char line[101];
	while(gets(line)){
		int cnt[4] = {0};
		for(int i=0; line[i]; i++){
			if(islower(line[i])) cnt[0]++;
			else if(isupper(line[i])) cnt[1]++;
			else if(isdigit(line[i])) cnt[2]++;
			else cnt[3]++;
		}
		for(int i=0; i<4; i++)
			printf("%d ", cnt[i]);
		puts("");
	}
}