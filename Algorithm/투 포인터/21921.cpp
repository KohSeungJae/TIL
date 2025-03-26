#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, X;
	vector<int> v;
	cin >> N >> X;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	
	int max_sum = 0; 
	for (int i = 0; i < X; i++) {
		max_sum += v[i];
	}
	int sum = max_sum;
	int cnt = 1;

	int tail = 0, head = X;
	while (head < N) {
		sum = sum - v[tail++] + v[head++];
		if (sum > max_sum) {
			cnt = 1;
			max_sum = sum;
		}
		else if (sum == max_sum) {
			cnt++;
		}
	}

	if (max_sum == 0) {
		cout << "SAD";
	}
	else {
		cout << max_sum << '\n' << cnt;
	}

	return 0;
}
