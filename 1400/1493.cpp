#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// limit: 현재 사용할 수 있는 큐브 수, need: 현재 필요한 큐브 수
long long limit[20], need[20];

// 쉽게 말하면 넓이, 길이, 높이
vector<int> v3(int a, int b, int c){
	vector<int> V(3);
	V[0] = a;
	V[1] = b;
	V[2] = c;
	return V;
}

// 크기 s1인 직육면체를 2^i 크기의 큐브를 최대한 사용하여 채워나감(재귀 함수)
void setMinCubes(vector<int> s1, int i){
	// 어차피 큐브로 체울 거라서 각 사이즈 순서는 상관없다
	sort(s1.begin(), s1.end());

	int cSize = 1<<i;
	// 직육면체 부피가 0. 즉 다 채움
	if(s1[0] == 0) return;
	// base case: 최소 크기 큐브, 즉 size 1
	else if(i == 0){
		need[0] += 1LL * s1[0] * s1[1] * s1[2];
		return;
	}
	// 현재 큐브를 사용할 수 없음(직육면체의 변 길이가 더 작음)
	else if(s1[0] < cSize) setMinCubes(s1, i-1);
	// 그 외 일반적인 경우
	else{
		need[i] += 1LL * (s1[0]/cSize) * (s1[1]/cSize) * (s1[2]/cSize);
		vector<int> s2(3);
		for(int i=0; i<3; i++)
			s2[i] = s1[i] % cSize;
		// 한쪽에 큐브를 몰아서 채우고 남은 공간을 3개로 나눠 각각 재귀 호출
		setMinCubes(v3(s1[0], s1[1], s2[2]), i-1);
		setMinCubes(v3(s2[0], s1[1], s1[2]-s2[2]), i-1);
		setMinCubes(v3(s1[0]-s2[0], s2[1], s1[2]-s2[2]), i-1);
	}
}



int main(){
	int L, W, H, N;
	scanf("%d %d %d %d", &L, &W, &H, &N);
	vector<int> S = v3(L, W, H);
	for(int i=0; i<N; i++){
		int p, q;
		scanf("%d %d", &p, &q);
		limit[p] += q;
	}
	setMinCubes(S, 19);

	// 주어진 큐브들로 해당 직육면체를 채울 수 있는지 검사
	long long result = 0;
	for(int i=19; i>0; i--){
		// 만약 큐브가 부족하다면 바로 밑 큐브들을 8개 써서 채우는 수밖에
		if(limit[i] < need[i]){
			need[i-1] += (need[i]-limit[i])*8;
			need[i] = limit[i];
		}
		result += need[i];
	}

	// 못 채우는 경우
	if(limit[0] < need[0]) result = -1;
	// 채우는 경우
	else result += need[0];
	printf("%lld\n", result);
}