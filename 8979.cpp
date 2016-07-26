#include <iostream>
#include <algorithm>
using namespace std;

class Country{
public:
	int number, gold, silver, bronze;
	Country():number(0),gold(0),silver(0),bronze(0){}
	Country(int n, int g, int s, int b):number(n),gold(g),silver(s),bronze(b){}
	bool operator <(Country& other){
		if(gold < other.gold) return true;
		if(gold > other.gold) return false;
		if(silver < other.silver) return true;
		if(silver > other.silver) return false;
		if(bronze < other.bronze) return true;
		return false;
	}
	bool operator >(Country& other){
		if(gold > other.gold) return true;
		if(gold < other.gold) return false;
		if(silver > other.silver) return true;
		if(silver < other.silver) return false;
		if(bronze > other.bronze) return true;
		return false;
	}
	bool operator ==(Country& other){
		return (gold==other.gold && silver==other.silver && bronze==other.bronze);
	}
};

int main(){

	int N, K, A, G, S, B;
	Country ct[1000];
	cin >> N >> K;
	int target;
	for(int i=0; i<N; i++){
		cin >> A >> G >> S >> B;
		ct[i] = Country(A, G, S, B);
		if(A == K) target = i;
	}

	int rank = 1;
	for(int i=0; i<N; i++){
		if(i == target) continue;
		if(ct[i] > ct[target]) rank++;
	}
	cout << rank << endl;

    return 0;
}