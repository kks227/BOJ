#include <iostream>
using namespace std;

int main(){

	int note[8];
	for(int i=0; i<8; i++)
		cin >> note[i];

	bool asc=true, desc=true;
	for(int i=0; i<8; i++){
		if(note[i] != i+1) asc = false;
		if(note[i] != 8-i) desc = false;
		if(!asc && !desc){
			cout << "mixed" << endl;
			break;
		}
	}
	if(asc) cout << "ascending" << endl;
	else if(desc) cout << "descending" << endl;

	return 0;
}