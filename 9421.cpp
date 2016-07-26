#include <iostream>
#include <cstring>
#include <set>
using namespace std;

int next(int n){
	int temp, result = 0;
	while(n>0){
		temp = n%10;
		result += temp*temp;
		n /= 10;
	}
	return result;
}
 
int main(){
	
	int N;
	cin >> N;
	set<int> no;
	set<int> yes;
	set<int> current;
	bool *prime = new bool[N+1];
	memset(prime, 1, N+1);
	for(int i=2; i<=N; i++){
		if(!prime[i]) continue;
		for(int j=i*2; j<=N; j+=i)
			prime[j] = false;
	}

	int temp;
	for(int i=2; i<=N; i++){
		if(prime[i]){
			if(no.find(i) != no.end()) continue;
			temp = i;
			current.clear();
			while(1){
				if(no.find(temp) != no.end()) break;
				if(!current.empty() && current.find(temp) != current.end()){
					for(set<int>::iterator iter=current.begin(); iter!=current.end(); iter++)
						no.insert(*iter);
					break;
				}
				if(temp == 1 || yes.find(temp) != yes.end()){
					cout << i << endl;
					for(set<int>::iterator iter=current.begin(); iter!=current.end(); iter++){
						if(yes.find(*iter) != yes.end()) break;
						else yes.insert(*iter);
					}
					break;
				}
				current.insert(temp);
				temp = next(temp);
			}
		}
	}
	delete[] prime;

    return 0;
}