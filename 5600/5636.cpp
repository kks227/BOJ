#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
 
#define MAX 100000

string input;

int partInteger(int start, int len){
	int result = 0;
	for(int i=start; i<start+len; i++){
		result *= 10;
		result += (input[i] - '0');
	}
	return result;
}
 
int main(){
 
    bool prime[MAX+1];
    memset(prime, 1, MAX+1);
    for(int i=2; i<=MAX; i++){
        if(!prime[i]) continue;
        for(int j=i*2; j<=MAX; j+=i)
            prime[j] = false;
    }

	int len, temp, result;
	while(1){
		cin >> input;
		if(input == "0") break;

		len = input.length();
		result = 0;
		for(int numlen=5; numlen>0; numlen--){
			for(int i=0; i+numlen<len; i++){
				temp = partInteger(i, numlen);
				if(!prime[temp]) continue;
				result = max(result, temp);
			}
			if(result) break;
		}
		cout << result << endl;
	}

    return 0;
}