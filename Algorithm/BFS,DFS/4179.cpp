#include <iostream>
#include <queue>

using namespace std;

#define IMPOSSIBLE 100000000

int r, c;
char board[1000][1000]; 
int f_dist[1000][1000]; 
int j_dist[1000][1000];

int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,1,0,-1 };

queue<pair<int, int>> Q; 

void f_BFS() {
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop(); 

		for (int d = 0; d < 4; d++) {
			int nr = cur.first + dr[d];
			int nc = cur.second + dc[d];

			if (nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
			if (board[nr][nc] == '#' || f_dist[nr][nc] != -1) continue;

			f_dist[nr][nc] = f_dist[cur.first][cur.second] + 1;
			Q.push({ nr, nc });
		}
	}
}

void find_j() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == 'J') {
				Q.push({ i,j });
				j_dist[i][j] = 0;
				return;
			}
		}
	}
}

void j_BFS() {
	find_j();
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		for (int d = 0; d < 4; d++) {
			int nr = cur.first + dr[d];
			int nc = cur.second + dc[d];

			if (nr < 0 || nr >= r || nc < 0 || nc >= c) continue;
			if (board[nr][nc] == '#' || j_dist[nr][nc] != -1) continue;
			if (f_dist[nr][nc] != -1 && f_dist[nr][nc] <= j_dist[cur.first][cur.second] + 1) continue;

			j_dist[nr][nc] = j_dist[cur.first][cur.second] + 1;
			Q.push({ nr, nc });
		}
	}
}

int get_min_time() {
	int min_time = IMPOSSIBLE;  
	for (int i = 0; i < r; i++) {
		if (j_dist[i][0] != -1 && j_dist[i][0] < min_time) {
			min_time = j_dist[i][0];
		}
		if (j_dist[i][c-1] != -1&& j_dist[i][c-1] < min_time) {
			min_time = j_dist[i][c - 1];
		}
	}
	for (int j = 0; j < c; j++) {
		if (j_dist[0][j] != -1 && j_dist[0][j] < min_time) {
			min_time = j_dist[0][j];
		}
		if (j_dist[r-1][j] != -1 && j_dist[r-1][j] < min_time) {
			min_time = j_dist[r - 1][j]; 
		}
	}
	return min_time; 
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> board[i][j];
			f_dist[i][j] = -1; 
			j_dist[i][j] = -1;
			if (board[i][j] == 'F') {
				Q.push({ i,j });
				f_dist[i][j] = 0;
			}
		}
	}
	
	f_BFS();
	j_BFS(); 

	int res = get_min_time();
	if (res == IMPOSSIBLE) {  
		cout << "IMPOSSIBLE";
	}
	else {
		cout << res+1; 
	}


	return 0;
}
