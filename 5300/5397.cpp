#include <cstdio>
#include <list>
using namespace std;
typedef list<char> CList;

int main(){
	int T;
	scanf("%d\n", &T);
	for(int t=0; t<T; t++){
		CList L;
		L.insert(L.begin(), '$');
		CList::iterator I = L.begin();
		char c;
		while((c=getchar()) != '\n'){
			switch(c){
			case '<':
				if(I != L.begin()) I--;
				break;
			case '>':
				if(*I != '$') I++;
				break;
			case '-':
				if(I != L.begin()){
					I--;
					I = L.erase(I);
				}
				break;
			default:
				L.insert(I, c);
			}
		}
		for(I=L.begin(); *I!='$'; I++)
			putchar(*I);
		puts("");
	}
}