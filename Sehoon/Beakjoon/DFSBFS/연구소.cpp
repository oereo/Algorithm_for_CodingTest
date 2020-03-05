#include <iostream>
#include <vector>
#include <algorithm>
//bfs
#include <queue>

using namespace std;

struct vertex {
	int row;
	int col;
};
int dR[4] = { -1, 0, 1, 0 };
int dC[4] = { 0, 1, 0, -1 };

int N = 0;
int M = 0;
vector<vector<int>> map, tmap;
vector<vector<bool>> visit;
vector<vertex> virus, room;
vector<int> pickedRoom;
int virusCount;
int roomCount;
int nowRoomCount;
//bfs
queue<vertex> bomb;


bool isOutOfRange(vertex ver) {
	return ver.row < 0 || ver.row >= N || ver.col < 0 || ver.col >= M;
}

bool isNotRoom(vertex ver) {
	return tmap[ver.row][ver.col] != 0;
}

bool isVisited(vertex ver) {
	return visit[ver.row][ver.col];
}

bool isMaintainRoom(int idx) {
	return pickedRoom[idx] == 1;
}

void pickThreeRooms() {
	pickedRoom[0] = pickedRoom[1] = pickedRoom[2] = 0;
}


void input() {
	cin >> N >> M;
	map.assign(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				room.push_back({ i, j });
				pickedRoom.push_back(1);
				roomCount++;
			}
			else if (map[i][j] == 2) {
				virus.push_back({ i, j });
				virusCount++;
			}
		}
	pickThreeRooms();
}

void goBfs(vertex ver) {
	tmap[ver.row][ver.col] = 2;
	for (int i = 0; i < 4; i++) {
		vertex nowVer = { ver.row + dR[i], ver.col + dC[i] };
		if (isOutOfRange(nowVer)) continue;
		if (isNotRoom(nowVer)) continue;
		if (isVisited(nowVer)) continue;
		nowRoomCount--;
		bomb.push(nowVer);
		visit[nowVer.row][nowVer.col] = true;
	}
}

void init() {
	tmap = map;
	visit.assign(N, vector<bool>(M, false));
	nowRoomCount = roomCount;
}

void makeNewWall() {
	int cnt = 0;
	for (int i = 0; i < roomCount; i++) {
		//if (cnt == 3) break;
		if (isMaintainRoom(i)) continue;
		vertex nowVer = { room[i].row, room[i].col };
		tmap[nowVer.row][nowVer.col] = 1;
		nowRoomCount--;
		//cnt++;
	}
}


void spreadVirusBfs() {
	for (int i = 0; i < virusCount; i++) {
		vertex nowVer = { virus[i].row, virus[i].col };
		bomb.push(nowVer);
		visit[nowVer.row][nowVer.col] = true;
	}
	while (!bomb.empty()) {
		vertex nowVer = bomb.front();
		goBfs(nowVer);
		bomb.pop();
	}
}

int safeZone() {
	int ans = 0;
	do {
		init();
		makeNewWall();
		//spreadVirusDfs();
		spreadVirusBfs();
		ans = max(ans, nowRoomCount);
	} while (next_permutation(pickedRoom.begin(), pickedRoom.end()));
	return ans;
}

void output() {
	cout << safeZone() << '\n';
}

int main() {

	input();
	output();
}