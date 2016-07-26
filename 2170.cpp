#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int main(){

	int N, A, B;
	scanf("%d", &N);
	map<int, int> line;
	map<int, int>::iterator finder1, finder2;
	for(int i=0; i<N; i++){
		scanf("%d %d", &A, &B);
		if(A>B) swap(A, B);
		if(A==B) continue;

		if(line.find(A) == line.end() || line[A] < B) line[A] = B;
		else continue;
		finder1 = finder2 = line.find(A);
		finder1++;
		if(finder1 != line.end() && B >= finder1->first){
			line[A] = max(B, finder1->second);
			line.erase(finder1);
		}
		if(finder2 != line.begin()){
			finder1 = finder2;
			finder2--;
			if(A <= finder2->second){
				finder2->second = max(B, finder2->second);
				line.erase(finder1);
			}
		}
	}
	int result = 0;
	for(finder1=line.begin(); finder1!=line.end(); finder1++)
		result += finder1->second - finder1->first;
	printf("%d\n", result);

    return 0;
}