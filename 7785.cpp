#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){

	int N;
	cin >> N;
	string name, flag;
	set<string> employee;
	for(int i=0; i<N; i++){
		cin >> name >> flag;
		if(flag == "enter") employee.insert(name);
		else employee.erase(name);
	}
	for(set<string>::reverse_iterator iter=employee.rbegin(); iter!=employee.rend(); iter++)
		cout << *iter << endl;

    return 0;
}