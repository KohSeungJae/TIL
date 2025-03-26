#include <iostream>
#include <vector>

using namespace std;


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	int max_sum = 0;
	int sum = 0;
	for (int i = 0; i < K; i++) {
		max_sum += v[i];
	}
	sum = max_sum;

	int tail = 0, head = K;
	while (head < N) {
		sum = sum - v[tail++] + v[head++];
		if (sum > max_sum) {
			max_sum = sum;
		}
	}

	cout << max_sum; 

	return 0;
}