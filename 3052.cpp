#include <iostream>
#include <set>
using namespace std;
 
int main(){

	set<int> mod;
	int n;
	for(int i=0; i<10; i++){
		cin >> n;
		mod.insert(n%42);
	}
	cout << mod.size() << endl;

    return 0;
}