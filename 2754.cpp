#include <iostream>
#include <string>
using namespace std;

int main(){

	string grade;
	cin >> grade;
	if(grade == "F") cout << "0.0" << endl;
	else{
		double score = 0;
		switch(grade[0]){
		case 'A': score += 1;
		case 'B': score += 1;
		case 'C': score += 1;
		case 'D': score += 1;
		}
		switch(grade[1]){
		case '+': score += 0.3; break;
		case '-': score -= 0.3; break;
		}
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(1);
		cout << score << endl;
	}

	return 0;
}