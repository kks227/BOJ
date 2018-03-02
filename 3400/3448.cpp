#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
	int T;
	cin >> T;
	cin.ignore(1024, '\n');
	for(int t=0; t<T; t++){
		string line;
		int R = 0, A = 0;
		while(1){
			getline(cin, line);
			if(line.empty()) break;
			A += line.size();
			for(char c: line)
				if(c != '#') R++;
		}
		double p = 100.0*R/A;
		p = round(p*10)/10;
		cout << "Efficiency ratio is " << p << "%." << endl;
	}
}