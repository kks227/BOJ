// [SegmentTree]

#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAX = 500000;
const int ST_MAX = 1048576;

struct SegTree{
	int size, start;
	int arr[ST_MAX];
	SegTree(int n){
		size = n;
		start = 1;
		while(start < size) start *= 2;
		memset(arr, 0, sizeof(arr));
	}
	void inc(int i){
		i += start;
		while(i > 0){
			arr[i]++;
			i /= 2;
		}
	}
	int sum(int s, int e){ return sum(s, e, 1, 0, start); }
	int sum(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
	}
};

int main(){
	int N, stat[MAX];
	P temp[MAX];
	scanf("%d", &N);
	SegTree ST(N);
	for(int i=0; i<N; i++){
		int val;
		scanf("%d", &val);
		temp[i] = P(val, i);
	}

	// 1~10억까지 분포한 좌표를 0~50만으로 다시 매김 
	sort(temp, temp+N);
	for(int i=0; i<N; i++)
		stat[temp[i].second] = i;
	
	// 앞에 있는 선수부터, 자신보다 앞이고 실력이 뛰어난 선수 수 셈
	for(int i=0; i<N; i++){
		printf("%d\n", ST.sum(stat[i], MAX+1)+1);
		ST.inc(stat[i]);
	}
}