#include <iostream>
using namespace std;

int main(){

	int n, val=0;
	unsigned long long sum=0;
	char c;
	bool flag=false;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> c;
		if(c>='0' && c<='9'){
			if(flag){
				val *= 10;
				val += (c-'0');
			}
			else{
				flag = true;
				val = (c-'0');
			}
		}
		else{
			if(flag){
				flag = false;
				sum += val;
			}
		}
	}
	if(flag) sum += val;

	cout << sum << endl;

	return 0;
}