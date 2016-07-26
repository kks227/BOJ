#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char possible[15];
int maxchar;
int length;

void searchByDFS(string fixed, int n, int consonant, int vowel){
	if(consonant+vowel == length){
		if(consonant >= 2 && vowel >= 1) cout << fixed << endl;
		return;
	}
	char current_char;
	int imax = maxchar-length+consonant+vowel;
	for(int i=n; i<=imax; i++){
		current_char = possible[i];
		if(current_char == 'a' || current_char == 'e' || current_char == 'i' || current_char == 'o' || current_char == 'u')
			searchByDFS(fixed+current_char, i+1, consonant, vowel+1);
		else
			searchByDFS(fixed+current_char, i+1, consonant+1, vowel);
	}
}
 
int main(){

	int L, C;
	cin >> L >> C;
	length = L;
	maxchar = C;
	for(int i=0; i<C; i++)
		cin >> possible[i];
	sort(possible, possible+C);
	searchByDFS("", 0, 0, 0);

    return 0;
}