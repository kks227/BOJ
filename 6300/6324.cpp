#include <iostream>
#include <string>
using namespace std;

int main(){
	int T;
	cin >> T;
	for(int t=1; t<=T; t++){
		string url;
		cin >> url;
		cout << "URL #" << t << endl;
		int i = 0, j;
		for(j=i; url[j]!=':'; j++);
		cout << "Protocol = " << url.substr(i, j-i) << endl;
		i = j + 3;
		for(j=i; j<url.size() && url[j]!=':' && url[j]!='/'; j++);
		cout << "Host     = " << url.substr(i, j-i) << endl << "Port     = ";
		if(j < url.size() && url[j]==':'){
			i = j + 1;
			for(j=i; j<url.size() && url[j]!='/'; j++);
			cout << url.substr(i, j-i) << endl;
		}
		else cout << "<default>" << endl;
		i = j + 1;
		cout << "Path     = ";
		if(j >= url.size()) cout << "<default>" << endl;
		else cout << url.substr(i) << endl;
		cout << endl;
	}
}