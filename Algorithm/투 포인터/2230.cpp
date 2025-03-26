#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


int main(void) {
	ios::sync_with_stdio(0); 
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	int tail = 0, head = 0;
	int min_dif = INT_MAX;
	while (tail < N && head < N) {
		int dif = v[head] - v[tail];
		if (dif >= M) {
			if (dif < min_dif) {
				min_dif = dif;
			}
			tail++;
		}
		else {
			head++;
		}
	}

	cout << min_dif;

	return 0;
}