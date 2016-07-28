#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 500000;
const int ST_MAX = 1048576;
const int INF = 1000000000;

struct SegTree{
	int size, start;
	int arr[ST_MAX];
	SegTree(int n){
		size = n;
		start = 1;
		while(start < size) start *= 2;
		fill(arr, arr+ST_MAX, INF);
	}
	void update(int i, int val){
		i += start;
		arr[i] = val;
		while(i > 1){
			i /= 2;
			arr[i] = min(arr[i*2], arr[i*2+1]);
		}
	}
	int minval(int s, int e){ return minval(s, e, 1, 0, start); }
	int minval(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return INF;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return min(minval(s, e, node*2, ns, mid), minval(s, e, node*2+1, mid, ne));
	}
};

int main(){
	int N;
	scanf("%d", &N);
	vector<vector<int>> rank(N, vector<int>(3));
	SegTree ST(N);
	for(int i=0; i<3; i++){
		for(int j=0; j<N; j++){
			int val;
			scanf("%d", &val);
			rank[val-1][i] = j;
		}
	}
	// 1번째 시험 등수 기준으로 정렬
	sort(rank.begin(), rank.end());

	int result = 0;
	// 1번째 시험 등수가 높은 학생부터 훑는다.
	// 뒤의 학생들은 어차피 1번째 시험 등수가 더 낮으므로 절대 이 학생보다 못 대단하다
	// 앞의 학생들 중 3번째 시험 등수가 높은 녀석들 중 2번째 시험 최고등수와 비교하면 된다
	for(int i=0; i<N; i++){
		if(ST.minval(0, rank[i][2]) > rank[i][1]) result++;
		ST.update(rank[i][2], rank[i][1]);
	}
	printf("%d\n", result);
}