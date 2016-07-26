#include <iostream>
#include <string>
#include <cctype>
#include <map>
using namespace std;

int main(){
	string M1[100000];
	map<string, int> M2;
	int N, M;
	cin >> N >> M;
	for(int i=0; i<N; i++){
		string name;
		cin >> name;
		M1[i] = name;
		M2[name] = i+1;
	}
	for(int i=0; i<M; i++){
		cin.ignore(1);
		if(isdigit(cin.peek())){
			int num;
			cin >> num;
			cout << M1[num-1] << endl;
		}
		else{
			string name;
			cin >> name;
			cout << M2[name] << endl;
		}
	}
}