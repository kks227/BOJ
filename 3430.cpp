#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, M, start[1000000] = {0}, result[1000000] = {0};
		bool rain[1000000] = {0};
		scanf("%d %d", &N, &M);

		bool success = true;
		set<int> sunny;
		for(int i=0; i<M; i++){
			int val;
			scanf("%d", &val);
			if(!success) continue;

			if(val > 0){
				set<int>::iterator finder = sunny.lower_bound(start[val-1]);
				if(finder == sunny.end()){
					success = false;
					continue;
				}
				result[*finder] = val;
				sunny.erase(finder);

				start[val-1] = i+1;
				rain[i] = true;
			}
			else sunny.insert(i);
		}

		if(success){
			puts("YES");
			for(int i=0; i<M; i++)
				if(!rain[i]) printf("%d ", result[i]);
			puts("");
		}
		else puts("NO");
	}
}