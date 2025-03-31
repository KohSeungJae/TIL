#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// 우선순위
int precedence(char op) {
	if (op == '(') return 0;
	else if (op == '+' || op == '-') return 1;
	else if (op == '*' || op == '/') return 2;
	else return -1;
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<char> s;
	string str;
	cin >> str;

	for (char ch : str) {
		if (ch == '(') {
			s.push(ch);
		}
		else if (ch == ')') {
			while (!s.empty() && s.top() != '(') {
				cout << s.top();
				s.pop(); 
			}
			s.pop();
		}
		else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			while (!s.empty() && (precedence(s.top()) >= precedence(ch))) {
				cout << s.top();
				s.pop();
			}
			s.push(ch); 
		}
		else {
			cout << ch; 
		}
	}

	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}

	return 0;
}
