#include <cstdio>
using namespace std;

int main(){
	while(1){
		bool check[26] = {0};
		while(1){
			char c = getchar();
			if(c == '*') return 0;
			if(c == '\n') break;
			if(c != ' ') check[c-'a'] = true;
		}
		bool success = true;
		for(int i=0; i<26; i++)
			if(!check[i]) success = false;
		puts(success ? "Y" : "N");
	}
}