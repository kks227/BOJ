#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define MAX (52*20)
#define LIMIT 31

int main(){

	bool prime[MAX+1];
	memset(prime, 1, MAX+1);
	for(int i=4; i<=MAX; i+=2)
		prime[i] = false;
	for(int i=3; i<=LIMIT; i+=2){
		if(prime[i]){
			for(int j=i*i; j<=MAX; j+=i)
				prime[j] = false;
		}
	}

	string line;
	cin >> line;
	int result = 0;
	int len = line.length();
	for(int i=0; i<len; i++){
		if(line[i] > 'Z') result += line[i]-'a'+1;
		else result += line[i]-'A'+1;
	}
	cout << "It is ";
	if(!prime[result]) cout << "not ";
	cout << "a prime word." << endl;

	return 0;
}