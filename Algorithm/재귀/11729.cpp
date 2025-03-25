#include <iostream>

using namespace std;


void h_tower(int s_tower, int d_tower, int r_tower, int size){
	if (size == 1) {
		cout << s_tower << ' ' << d_tower << '\n';
		return;
	}
	h_tower(s_tower, r_tower, d_tower, size-1); // 원반 size - 1 개를 빈 막대로 이동
	cout << s_tower << ' ' << d_tower << '\n'; // 가장 큰 원반을 원래 목적지로 이동
	h_tower(r_tower, d_tower, s_tower, size - 1); // 이동시킨 원반 size - 1개를 원래 목적지로 이동
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> k;
	cout << (1<<k) - 1 << '\n'; 
	h_tower(1, 3, 2, k); 


	return 0;
}
