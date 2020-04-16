#include<iostream>
#include<vector>
#include<string>

/*Module.h*/
#define BLACK 0
#define WHITE 1
#define EMPTY 2
//坐标类
class Point {
public:
	int x = -1;
	int y = -1;
};
//步类
class Step {
public:
	Point first;
	Point second;
};
std::vector<std::vector<int>> Board;
int computerSide = EMPTY;//己方持子颜色
Step step;//己方步类
std::string Message;//接受消息
bool start = false;//对局开始标记
int whichStep = 1;
int DIR[][2] = { 1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,-1,-1,1 };
//初始化Board
void iniBoard() {
	for (unsigned int i = 0; i < Board.size(); i++) {
		Board[i].clear();
	}
	Board.clear();
	std::vector<int> temp(19, EMPTY);
	for (int i = 0; i < 19; i++) {
		Board.push_back(temp);
	}
	temp.clear();
}

/*Tools.h*/
class Tool {
protected:
	std::vector<std::vector<int>> EveryStep;
	int BlackStep = 1;
	int WhiteStep = -1;
public:
	Tool() {
		std::vector<int> temp(19, 0);
		for (int i = 0; i < 19; i++) {
			EveryStep.push_back(temp);
		}
		temp.clear();
		//initializeLib();
	}
	~Tool() {
		clearEveryStep();
		//		clearLibAndFra();
	}
	void reset() {
		clearEveryStep();
		BlackStep = 1;
		WhiteStep = -1;
		std::vector<int> temp(19, 0);
		for (int i = 0; i < 19; i++) {
			EveryStep.push_back(temp);
		}
		temp.clear();
	}
	void clearEveryStep() {
		for (unsigned int i = 0; i < EveryStep.size(); i++) {
			EveryStep[i].clear();
		}
		EveryStep.clear();
	}
	//返回值为下了几次了，一回合两方各算一次
	int whichGame() {
		if (BlackStep > (-1 * WhiteStep)) {
			return -1 * (WhiteStep + 1) + 1;
		}
		else {
			return -1 * (WhiteStep + 1);
		}
	}
	//第几次下棋的位置
	//返回值为color方第times下子的坐标，x*100+y
	int locOfChess(int color, int times) {
		if (color == BLACK) {
			for (unsigned int i = 0; i < EveryStep.size(); i++) {
				for (unsigned int ii = 0; ii < EveryStep[i].size(); ii++) {
					if (EveryStep[i][ii] == times) {
						return i * 100 + ii;
					}
				}
			}
		}
		else if (color == WHITE) {
			times *= -1;
			for (unsigned int i = 0; i < EveryStep.size(); i++) {
				for (unsigned int ii = 0; ii < EveryStep[i].size(); ii++) {
					if (EveryStep[i][ii] == times) {
						return i * 100 + ii;
					}
				}
			}
		}
		return 0;
	}
	//记录下子
	void playChess(int color, int x, int y) {
		if (color == BLACK) {
			EveryStep[x][y] = BlackStep++;
		}
		else if (color == WHITE) {
			EveryStep[x][y] = WhiteStep--;
		}
	}
	//如果在x,y下子将会形成……返回值正数为活，负数为眠，十位为方向
	//例：13，左上到右下形成了活连三
	//例：-35，右上到左下形成了眠连五
	int if_(int color, int x, int y) {
		int sum = 1;
		int sleep = 1;
		//1，左上到右下
		for (int i = 1; i <= 6; i++) {
			if (x + i >= 0 && y + i >= 0 && x + i < 19 && y + i < 19) {
				if (Board[x + i][y + i] == color) {
					sum++;
				}
				else if (Board[x + i][y + i] == 1 - color) {
					sleep = -1;
					break;
				}
				else {
					break;
				}
			}
		}
		for (int i = -1; i >= -6; i--) {
			if (x + i >= 0 && y + i >= 0 && x + i < 19 && y + i < 19) {
				if (Board[x + i][y + i] == color) {
					sum++;
				}
				else if (Board[x + i][y + i] == 1 - color) {
					sleep = -1;
					break;
				}
				else {
					break;
				}
			}
		}
		return sum * sleep;
	}
	//返回x,y这个点layers层内有多少color的子
	int howManyPiece(int color, int x, int y, int layers = 2) {
		int sum = 0;
		for (int i = (-1 * layers); i < (layers + 1); i++) {
			for (int ii = (-1 * layers); ii < (layers + 1); ii++) {
				if (x + i >= 0 && x + i < 19 && y + ii >= 0 && y + ii < 19) {
					if (Board[x + i][y + ii] == color) {
						sum++;
					}
				}
			}
		}
		return sum;
	}
};
Tool tool;
//输出己方结果，x、y是坐标，step是这局游戏的第1步还是第2步
void move(int x, int y, int step) {
	Board[x][y] = computerSide;
	if (step == 1) {
		std::cout << "move " << (char)(x + 'A') << (char)(y + 'A');
	}
	else if (step == 2) {
		std::cout << (char)(x + 'A') << (char)(y + 'A') << std::endl;
	}
	else if (step == 3) {
		std::cout << "move " << (char)(x + 'A') << (char)(y + 'A') << "@@" << std::endl;
	}
	tool.playChess(computerSide, x, y);
}
void move(std::string a) {
	Board[a[0] - 'A'][a[1] - 'A'] = 1 - computerSide;
	tool.playChess(1 - computerSide, a[0] - 'A', a[1] - 'A');
	if (a.size() == 4) {
		if (a[2] != '@' && a[3] != '@') {
			Board[a[2] - 'A'][a[3] - 'A'] = 1 - computerSide;
			tool.playChess(1 - computerSide, a[2] - 'A', a[3] - 'A');
		}
	}
}
void move(Step step) {
	move(step.first.x, step.first.y, 1);
	move(step.second.x, step.second.y, 2);
}

/*Score.h*/
//形成/防止{活四，眠四，活五，眠五}双组合
//参数：X,Y,己方第一步形成活四赋值X=1
//对方第一步形成活四赋值Y=1
//第二步己方形成眠四/眠五且X==1，该棋形得分仅比六连低
//第二步对方形成眠四/眠五且Y==1，该棋形得分仅比六连/活五/活四低
class Chess {
public:
	Point me;
	int data = 0;
	int score = 0;
	Chess() { score = 0; }
	void set(int x_, int y_, int data_) {
		me.x = x_;
		me.y = y_;
		data = data_;
		score = 0;
	}
	void set_score(int m) { score = m; }
	int get_score() { return score; }
	Point get_location() { return me; }
	void set(Chess a) {
		me.x = a.me.x;
		me.y = a.me.y;
		data = a.data;
		score = a.score;
	}
}transcript[19][19];
//打分比对表，用来比对棋形，返回该棋形得分
int score_table(int size, std::string a, bool isme, int step) {
	//将a倒置赋值给b。
	std::string b(a);
	for (int i = 0; i < size; i++) {
		b[size - i - 1] = a[i];
	}
	//将a倒置赋值给b。
	if (size == 6) {
		if (a == "111111" || b == "111111") { if (isme && step == 1) return 10000; if (isme && step == 2)return 10000; if (!isme && step == 1) return 7000; if (!isme && step == 2)return 7000; }
		if (a == "111112" || b == "111112") { if (isme && step == 1) return 7800;  if (isme && step == 2)return 2000; if (!isme && step == 1) return 6300; if (!isme && step == 2)return 6300; }
		if (a == "111121" || b == "111121") { if (isme && step == 1) return 7800;  if (isme && step == 2)return 2000; if (!isme && step == 1) return 6300; if (!isme && step == 2)return 6300; }
		if (a == "111122" || b == "111122") { if (isme && step == 1) return 4600;  if (isme && step == 2)return 1200; if (!isme && step == 1) return 4000; if (!isme && step == 2)return 4000; }
		if (a == "111211" || b == "111211") { if (isme && step == 1) return 7800;  if (isme && step == 2)return 2000; if (!isme && step == 1) return 6300; if (!isme && step == 2)return 6300; }
		if (a == "111212" || b == "111212") { if (isme && step == 1) return 4000;  if (isme && step == 2)return 1100; if (!isme && step == 1) return 3500; if (!isme && step == 2)return 3500; }
		if (a == "111221" || b == "111221") { if (isme && step == 1) return 3000;  if (isme && step == 2)return 800; if (!isme && step == 1) return 2500; if (!isme && step == 2)return 2500; }
		if (a == "111222" || b == "111222") { if (isme && step == 1) return 120; if (isme && step == 2)return 120; if (!isme && step == 1) return 100; if (!isme && step == 2)return 100; }
		if (a == "112112" || b == "112112") { if (isme && step == 1) return 4000;  if (isme && step == 2)return 1100; if (!isme && step == 1) return 3500; if (!isme && step == 2)return 3500; }
		if (a == "112121" || b == "112121") { if (isme && step == 1) return 3000;  if (isme && step == 2)return 800; if (!isme && step == 1) return 2500; if (!isme && step == 2)return 2500; }
		if (a == "112122" || b == "112122") { if (isme && step == 1) return 115; if (isme && step == 2)return 115; if (!isme && step == 1) return 100; if (!isme && step == 2)return 100; }
		if (a == "112211" || b == "112211") { if (isme && step == 1) return 3000;  if (isme && step == 2)return 800; if (!isme && step == 1) return 2500; if (!isme && step == 2)return 2500; }
		if (a == "112212" || b == "112212") { if (isme && step == 1) return 80; if (isme && step == 2)return 80; if (!isme && step == 1) return 60; if (!isme && step == 2)return 60; }
		if (a == "112221" || b == "112221") { if (isme && step == 1) return 60; if (isme && step == 2)return 60; if (!isme && step == 1) return 40; if (!isme && step == 2)return 40; }
		if (a == "112222" || b == "112222") { if (isme && step == 1) return 30; if (isme && step == 2)return 30; if (!isme && step == 1) return 20; if (!isme && step == 2)return 20; }
		if (a == "121112" || b == "121112") { if (isme && step == 1) return 3000;  if (isme && step == 2)return 1100; if (!isme && step == 1) return 2500; if (!isme && step == 2)return 2500; }
		if (a == "121121" || b == "121121") { if (isme && step == 1) return 3000;  if (isme && step == 2)return 800; if (!isme && step == 1) return 2500; if (!isme && step == 2)return 2500; }
		if (a == "121122" || b == "121122") { if (isme && step == 1) return 115; if (isme && step == 2)return 115; if (!isme && step == 1) return 100; if (!isme && step == 2)return 100; }
		if (a == "121212" || b == "121212") { if (isme && step == 1) return 80; if (isme && step == 2)return 80; if (!isme && step == 1) return 60; if (!isme && step == 2)return 60; }
		if (a == "121221" || b == "121221") { if (isme && step == 1) return 65; if (isme && step == 2)return 60; if (!isme && step == 1) return 50; if (!isme && step == 2)return 50; }
		if (a == "121222" || b == "121222") { if (isme && step == 1) return 28; if (isme && step == 2)return 28; if (!isme && step == 1) return 20; if (!isme && step == 2)return 20; }
		if (a == "122112" || b == "122112") { if (isme && step == 1) return 80; if (isme && step == 2)return 80; if (!isme && step == 1) return 60; if (!isme && step == 2)return 60; }
		if (a == "122122" || b == "122122") { if (isme && step == 1) return 25; if (isme && step == 2)return 25; if (!isme && step == 1) return 20; if (!isme && step == 2)return 20; }
		if (a == "122212" || b == "122212") { if (isme && step == 1) return 20; if (isme && step == 2)return 20; if (!isme && step == 1) return 10; if (!isme && step == 2)return 10; }
		if (a == "122221" || b == "122221") { if (isme && step == 1) return 15; if (isme && step == 2)return 15; if (!isme && step == 1) return 5; if (!isme && step == 2)return 5; }
		if (a == "122222" || b == "122222") { if (isme && step == 1) return 2; if (isme && step == 2)return 2; if (!isme && step == 1) return 2; if (!isme && step == 2)return 2; }
		if (a == "211112" || b == "211112") { if (isme && step == 1) return 6000;  if (isme && step == 2)return 4000; if (!isme && step == 1) return 4500; if (!isme && step == 2)return 4500; }
		if (a == "211122" || b == "211122") { if (isme && step == 1) return 500; if (isme && step == 2)return 500; if (!isme && step == 1) return 400; if (!isme && step == 2)return 400; }
		if (a == "211212" || b == "211212") { if (isme && step == 1) return 480; if (isme && step == 2)return 480; if (!isme && step == 1) return 400; if (!isme && step == 2)return 400; }
		if (a == "211222" || b == "211222") { if (isme && step == 1) return 50; if (isme && step == 2)return 50; if (!isme && step == 1) return 30; if (!isme && step == 2)return 30; }
		if (a == "212122" || b == "212122") { if (isme && step == 1) return 48; if (isme && step == 2)return 48; if (!isme && step == 1) return 30; if (!isme && step == 2)return 30; }
		if (a == "212212" || b == "212212") { if (isme && step == 1) return 45; if (isme && step == 2)return 40; if (!isme && step == 1) return 30; if (!isme && step == 2)return 30; }
		if (a == "212222" || b == "212222") { if (isme && step == 1) return 5; if (isme && step == 2)return 5; if (!isme && step == 1) return 5; if (!isme && step == 2)return 5; }
		if (a == "221122" || b == "221122") { if (isme && step == 1) return 50; if (isme && step == 2)return 50; if (!isme && step == 1) return 30; if (!isme && step == 2)return 30; }
		if (a == "221222" || b == "221222") { if (isme && step == 1) return 5; if (isme && step == 2)return 5; if (!isme && step == 1) return 5; if (!isme && step == 2)return 5; }
		if (a == "222222" || b == "222222") { if (isme && step == 1) return 0; if (isme && step == 2)return 0; if (!isme && step == 1) return 0; if (!isme && step == 2)return 0; }

	}
	if (size == 7) {
		if (a == "1111111" || b == "1111111") { if (isme && step == 1) return 10000; if (isme && step == 2)return 10000; if (!isme && step == 1) return 7000; if (!isme && step == 2)return 7000; }
		if (a == "1111112" || b == "1111112") { if (isme && step == 1) return 10000; if (isme && step == 2)return 10000; if (!isme && step == 1) return 7000; if (!isme && step == 2)return 7000; }
		if (a == "1111121" || b == "1111121") { if (isme && step == 1) return 9999;  if (isme && step == 2)return 2500; if (!isme && step == 1) return 6999; if (!isme && step == 2)return 6999; }
		if (a == "1111122" || b == "1111122") { if (isme && step == 1) return 7800;  if (isme && step == 2)return 2600; if (!isme && step == 1) return 6300; if (!isme && step == 2)return 6300; }
		if (a == "1111211" || b == "1111211") { if (isme && step == 1) return 9999;  if (isme && step == 2)return 2500; if (!isme && step == 1) return 6999; if (!isme && step == 2)return 6999; }
		if (a == "1111212" || b == "1111212") { if (isme && step == 1) return 7200;   if (isme && step == 2)return 2000; if (!isme && step == 1) return 5700; if (!isme && step == 2)return 5700; }
		if (a == "1111221" || b == "1111221") { if (isme && step == 1) return 6500;  if (isme && step == 2)return 1600; if (!isme && step == 1) return 5000; if (!isme && step == 2)return 5000; }
		if (a == "1111222" || b == "1111222") { if (isme && step == 1) return 3600;  if (isme && step == 2)return 1200; if (!isme && step == 1) return 3000; if (!isme && step == 2)return 3000; }
		if (a == "1112111" || b == "1112111") { if (isme && step == 1) return 9999;  if (isme && step == 2)return 2500; if (!isme && step == 1) return 6999; if (!isme && step == 2)return 6999; }
		if (a == "1112112" || b == "1112112") { if (isme && step == 1) return 7200;  if (isme && step == 2)return 2000; if (!isme && step == 1) return 5700; if (!isme && step == 2)return 5700; }
		if (a == "1112121" || b == "1112121") { if (isme && step == 1) return 6500;  if (isme && step == 2)return 1600; if (!isme && step == 1) return 5000; if (!isme && step == 2)return 5000; }
		if (a == "1112122" || b == "1112122") { if (isme && step == 1) return 3500;  if (isme && step == 2)return 1100; if (!isme && step == 1) return 3000; if (!isme && step == 2)return 3000; }
		if (a == "1112211" || b == "1112211") { if (isme && step == 1) return 6500;  if (isme && step == 2)return 1600; if (!isme && step == 1) return 5000; if (!isme && step == 2)return 5000; }
		if (a == "1112212" || b == "1112212") { if (isme && step == 1) return 2500;  if (isme && step == 2)return 800; if (!isme && step == 1) return 2000; if (!isme && step == 2)return 2000; }
		if (a == "1112221" || b == "1112221") { if (isme && step == 1) return 1500; if (isme && step == 2)return 600; if (!isme && step == 1) return 1300; if (!isme && step == 2)return 1300; }
		if (a == "1112222" || b == "1112222") { if (isme && step == 1) return 120; if (isme && step == 2)return 120; if (!isme && step == 1) return 100; if (!isme && step == 2)return 100; }
		if (a == "1121112" || b == "1121112") { if (isme && step == 1) return 7200;  if (isme && step == 2)return 2000; if (!isme && step == 1) return 5700; if (!isme && step == 2)return 5700; }
		if (a == "1121121" || b == "1121121") { if (isme && step == 1) return 6500;  if (isme && step == 2)return 1600; if (!isme && step == 1) return 5000; if (!isme && step == 2)return 5000; }
		if (a == "1121122" || b == "1121122") { if (isme && step == 1) return 2700;  if (isme && step == 2)return 1100; if (!isme && step == 1) return 2500; if (!isme && step == 2)return 2500; }
		if (a == "1121211" || b == "1121211") { if (isme && step == 1) return 6500; if (isme && step == 2)return 1600; if (!isme && step == 1) return 5000; if (!isme && step == 2)return 5000; }
		if (a == "1121212" || b == "1121212") { if (isme && step == 1) return 2500; if (isme && step == 2)return 800; if (!isme && step == 1) return 2200; if (!isme && step == 2)return 2200; }
		if (a == "1121221" || b == "1121221") { if (isme && step == 1) return 1500; if (isme && step == 2)return 600; if (!isme && step == 1) return 1300; if (!isme && step == 2)return 1300; }
		if (a == "1121222" || b == "1121222") { if (isme && step == 1) return 115; if (isme && step == 2)return 115; if (!isme && step == 1) return 100; if (!isme && step == 2)return 100; }
		if (a == "1122112" || b == "1122112") { if (isme && step == 1) return 2500;  if (isme && step == 2)return 800; if (!isme && step == 1) return 2400; if (!isme && step == 2)return 2400; }
		if (a == "1122121" || b == "1122121") { if (isme && step == 1) return 2500; if (isme && step == 2)return 600; if (!isme && step == 1) return 2400; if (!isme && step == 2)return 2400; }
		if (a == "1122122" || b == "1122122") { if (isme && step == 1) return 80; if (isme && step == 2)return 80; if (!isme && step == 1) return 60; if (!isme && step == 2)return 60; }
		if (a == "1122211" || b == "1122211") { if (isme && step == 1) return 2500; if (isme && step == 2)return 600; if (!isme && step == 1) return 2400; if (!isme && step == 2)return 2400; }
		if (a == "1122212" || b == "1122212") { if (isme && step == 1) return 70; if (isme && step == 2)return 70; if (!isme && step == 1) return 45; if (!isme && step == 2)return 45; }
		if (a == "1122221" || b == "1122221") { if (isme && step == 1) return 65; if (isme && step == 2)return 60; if (!isme && step == 1) return 40; if (!isme && step == 2)return 40; }
		if (a == "1122222" || b == "1122222") { if (isme && step == 1) return 30; if (isme && step == 2)return 30; if (!isme && step == 1) return 25; if (!isme && step == 2)return 25; }
		if (a == "1211112" || b == "1211112") { if (isme && step == 1) return 7200;  if (isme && step == 2)return 2000; if (!isme && step == 1) return 5700; if (!isme && step == 2)return 5700; }
		if (a == "1211121" || b == "1211121") { if (isme && step == 1) return 6500;  if (isme && step == 2)return 1600; if (!isme && step == 1) return 5000; if (!isme && step == 2)return 5000; }
		if (a == "1211122" || b == "1211122") { if (isme && step == 1) return 3000;  if (isme && step == 2)return 1100; if (!isme && step == 1) return 2600; if (!isme && step == 2)return 2600; }
		if (a == "1211212" || b == "1211212") { if (isme && step == 1) return 2500;  if (isme && step == 2)return 800; if (!isme && step == 1) return 2400; if (!isme && step == 2)return 2400; }
		if (a == "1211221" || b == "1211221") { if (isme && step == 1) return 1200; if (isme && step == 2)return 600; if (!isme && step == 1) return 1100; if (!isme && step == 2)return 1100; }
		if (a == "1211222" || b == "1211222") { if (isme && step == 1) return 120; if (isme && step == 2)return 120; if (!isme && step == 1) return 110; if (!isme && step == 2)return 110; }
		if (a == "1212112" || b == "1212112") { if (isme && step == 1) return 2000;  if (isme && step == 2)return 800; if (!isme && step == 1) return 1900; if (!isme && step == 2)return 1900; }
		if (a == "1212121" || b == "1212121") { if (isme && step == 1) return 1600; if (isme && step == 2)return 600; if (!isme && step == 1) return 1500; if (!isme && step == 2)return 1500; }
		if (a == "1212122" || b == "1212122") { if (isme && step == 1) return 500; if (isme && step == 2)return 80; if (!isme && step == 1) return 450; if (!isme && step == 2)return 450; }
		if (a == "1212212" || b == "1212212") { if (isme && step == 1) return 300; if (isme && step == 2)return 60; if (!isme && step == 1) return 270; if (!isme && step == 2)return 270; }
		if (a == "1212221" || b == "1212221") { if (isme && step == 1) return 60; if (isme && step == 2)return 55; if (!isme && step == 1) return 55; if (!isme && step == 2)return 55; }
		if (a == "1212222" || b == "1212222") { if (isme && step == 1) return 28; if (isme && step == 2)return 28; if (!isme && step == 1) return 25; if (!isme && step == 2)return 25; }
		if (a == "1221112" || b == "1221112") { if (isme && step == 1) return 2500;  if (isme && step == 2)return 800; if (!isme && step == 1) return 2400; if (!isme && step == 2)return 2400; }
		if (a == "1221122" || b == "1221122") { if (isme && step == 1) return 80; if (isme && step == 2)return 80; if (!isme && step == 1) return 70; if (!isme && step == 2)return 70; }
		if (a == "1221212" || b == "1221212") { if (isme && step == 1) return 65; if (isme && step == 2)return 60; if (!isme && step == 1) return 55; if (!isme && step == 2)return 55; }
		if (a == "1221221" || b == "1221221") { if (isme && step == 1) return 60; if (isme && step == 2)return 55; if (!isme && step == 1) return 40; if (!isme && step == 2)return 40; }
		if (a == "1221222" || b == "1221222") { if (isme && step == 1) return 25; if (isme && step == 2)return 25; if (!isme && step == 1) return 20; if (!isme && step == 2)return 20; }
		if (a == "1222112" || b == "1222112") { if (isme && step == 1) return 300; if (isme && step == 2)return 60; if (!isme && step == 1) return 250; if (!isme && step == 2)return 250; }
		if (a == "1222122" || b == "1222122") { if (isme && step == 1) return 20; if (isme && step == 2)return 20; if (!isme && step == 1) return 20; if (!isme && step == 2)return 20; }
		if (a == "1222212" || b == "1222212") { if (isme && step == 1) return 15; if (isme && step == 2)return 15; if (!isme && step == 1) return 15; if (!isme && step == 2)return 15; }
		if (a == "1222221" || b == "1222221") { if (isme && step == 1) return 10; if (isme && step == 2)return 10; if (!isme && step == 1) return 10; if (!isme && step == 2)return 10; }
		if (a == "1222222" || b == "1222222") { if (isme && step == 1) return 2; if (isme && step == 2)return 2; if (!isme && step == 1) return 2; if (!isme && step == 2)return 2; }
		if (a == "2111112" || b == "2111112") { if (isme && step == 1) return 9999;  if (isme && step == 2)return 6000; if (!isme && step == 1) return 6999; if (!isme && step == 2)return 6999; }
		if (a == "2111122" || b == "2111122") { if (isme && step == 1) return 4000;  if (isme && step == 2)return 3000; if (!isme && step == 1) return 3700; if (!isme && step == 2)return 3700; }
		if (a == "2111212" || b == "2111212") { if (isme && step == 1) return 3000;  if (isme && step == 2)return 1500; if (!isme && step == 1) return 2600; if (!isme && step == 2)return 2600; }
		if (a == "2111222" || b == "2111222") { if (isme && step == 1) return 500; if (isme && step == 2)return 500; if (!isme && step == 1) return 450; if (!isme && step == 2)return 450; }
		if (a == "2112112" || b == "2112112") { if (isme && step == 1) return 2500;  if (isme && step == 2)return 1500; if (!isme && step == 1) return 2000; if (!isme && step == 2)return 2000; }
		if (a == "2112122" || b == "2112122") { if (isme && step == 1) return 480; if (isme && step == 2)return 480; if (!isme && step == 1) return 420; if (!isme && step == 2)return 420; }
		if (a == "2112212" || b == "2112212") { if (isme && step == 1) return 400; if (isme && step == 2)return 400; if (!isme && step == 1) return 350; if (!isme && step == 2)return 350; }
		if (a == "2112222" || b == "2112222") { if (isme && step == 1) return 50; if (isme && step == 2)return 50; if (!isme && step == 1) return 45; if (!isme && step == 2)return 45; }
		if (a == "2121122" || b == "2121122") { if (isme && step == 1) return 480; if (isme && step == 2)return 480; if (!isme && step == 1) return 400; if (!isme && step == 2)return 400; }
		if (a == "2121212" || b == "2121212") { if (isme && step == 1) return 300; if (isme && step == 2)return 300; if (!isme && step == 1) return 250; if (!isme && step == 2)return 250; }
		if (a == "2121222" || b == "2121222") { if (isme && step == 1) return 48; if (isme && step == 2)return 48; if (!isme && step == 1) return 40; if (!isme && step == 2)return 40; }
		if (a == "2122122" || b == "2122122") { if (isme && step == 1) return 45; if (isme && step == 2)return 40; if (!isme && step == 1) return 40; if (!isme && step == 2)return 40; }
		if (a == "2122212" || b == "2122212") { if (isme && step == 1) return 20; if (isme && step == 2)return 20; if (!isme && step == 1) return 20; if (!isme && step == 2)return 20; }
		if (a == "2122222" || b == "2122222") { if (isme && step == 1) return 5; if (isme && step == 2)return 5; if (!isme && step == 1) return 5; if (!isme && step == 2)return 5; }
		if (a == "2211122" || b == "2211122") { if (isme && step == 1) return 500; if (isme && step == 2)return 500; if (!isme && step == 1) return 450; if (!isme && step == 2)return 450; }
		if (a == "2211222" || b == "2211222") { if (isme && step == 1) return 50; if (isme && step == 2)return 50; if (!isme && step == 1) return 45; if (!isme && step == 2)return 45; }
		if (a == "2212122" || b == "2212122") { if (isme && step == 1) return 48; if (isme && step == 2)return 48; if (!isme && step == 1) return 40; if (!isme && step == 2)return 40; }
		if (a == "2212222" || b == "2212222") { if (isme && step == 1) return 5; if (isme && step == 2)return 5; if (!isme && step == 1) return 5; if (!isme && step == 2)return 5; }
		if (a == "2221222" || b == "2221222") { if (isme && step == 1) return 5; if (isme && step == 2)return 5; if (!isme && step == 1) return 5; if (!isme && step == 2)return 5; }
		if (a == "2222222" || b == "2222222") { if (isme && step == 1) return 0; if (isme && step == 2)return 0; if (!isme && step == 1) return 0; if (!isme && step == 2)return 0; }

	}
	return 0;
}
//用来挑出一个点周围得分最大的棋形的得分
int get_max(int a[], int size) {
	int temp = a[0];
	for (int i = 1; i < size; i++) {
		if (temp < a[i])
			temp = a[i];
	}
	return temp;
}
//用于提取棋形，该棋形是检测点已经填充上对应colour的情况
int calculate_score_step_1(Point p, int colour, int score_) {
	std::string a = "2222222";
	int left_size = 0;
	int right_size = 0;
	int size = 0;
	int score[7] = { 0 ,0,0,0,0,0,0 };
	int score1 = 0, score2 = 0, score3 = 0, score4 = 0;
	//横
	for (int i = 1; i < 8; i++) {//该点是该模型的第i位，最大是第7位
		left_size = 0, right_size = 0, size = 0;
		a[i - 1] = colour + '0';
		for (int j = 1; j < i; j++) {//j是从i开始向左检索的位数
			if (p.y - j < 0)//越界
				break;
			if (Board[p.x][p.y - j] == 1 - colour)//被堵住
				break;
			a[i - 1 - j] = Board[p.x][p.y - j] + '0';
			left_size++;
		}
		for (int j = 1; j < 8 - i; j++) {//向右检索
			if (p.y + j > 18)//越界
				break;
			if (Board[p.x][p.y + j] == 1 - colour)
				break;
			a[i - 1 + j] = Board[p.x][p.y + j] + '0';
			right_size++;
		}
		std::string temp(a, i - left_size - 1, left_size + right_size + 1);//截取有效部分
		size = temp.size();
		if (colour == BLACK) {//如果是0，将0转换为1，方便比对。
			for (int k = 0; k < size; k++) {
				if (temp[k] == '0')
					temp[k] = '1';
			}
		}
		score[i - 1] = score_table(size, temp, computerSide == colour, whichStep);//得到棋形得分，存入得分数组
	}
	score1 = get_max(score, 7);//默认每个模型都有打分
/*考虑棋形不匹配的得分情况，那么应该在每次换方向时将得分数组初始化0*/
	//竖
	for (int i = 1; i < 8; i++) {//是该模型的第i位
		left_size = 0, right_size = 0, size = 0;
		a[i - 1] = colour + '0';
		for (int j = 1; j < i; j++) {//j是从i开始向上检索的位数
			if (p.x - j < 0)//越界
				break;
			if (Board[p.x - j][p.y] == 1 - colour)
				break;
			a[i - 1 - j] = Board[p.x - j][p.y] + '0';
			left_size++;
		}
		for (int j = 1; j < 8 - i; j++) {//向下检索
			if (p.x + j > 18)//越界
				break;
			if (Board[p.x + j][p.y] == 1 - colour)
				break;
			a[i - 1 + j] = Board[p.x + j][p.y] + '0';
			right_size++;
		}
		std::string temp(a, i - left_size - 1, left_size + right_size + 1);
		size = temp.size();
		if (colour == BLACK) {//将0转换为1，方便比对。
			for (int k = 0; k < size; k++) {
				if (temp[k] == '0')
					temp[k] = '1';
			}
		}
		score[i - 1] = score_table(size, temp, computerSide == colour, whichStep);
	}
	score2 = get_max(score, 7);
	//撇
	for (int i = 1; i < 8; i++) {//是该模型的第i位
		left_size = 0, right_size = 0, size = 0;
		a[i - 1] = colour + '0';
		for (int j = 1; j < i; j++) {//j是从i开始向左下检索的位数
			if (p.y - j < 0 || p.x + j> 18)//越界
				break;
			if (Board[p.x + j][p.y - j] == 1 - colour)
				break;
			a[i - 1 - j] = Board[p.x + j][p.y - j] + '0';
			left_size++;
		}
		for (int j = 1; j < 8 - i; j++) {//向右上检索
			if (p.y + j > 18 || p.x - j < 0)//越界
				break;
			if (Board[p.x - j][p.y + j] == 1 - colour)
				break;
			a[i - 1 + j] = Board[p.x - j][p.y + j] + '0';
			right_size++;
		}
		std::string temp(a, i - left_size - 1, left_size + right_size + 1);
		size = temp.size();
		if (colour == BLACK) {//将0转换为1，方便比对。
			for (int k = 0; k < size; k++) {
				if (temp[k] == '0')
					temp[k] = '1';
			}
		}
		score[i - 1] = score_table(size, temp, computerSide == colour, whichStep);
	}
	score3 = get_max(score, 7);
	//捺
	for (int i = 1; i < 8; i++) {//是该模型的第i位
		left_size = 0, right_size = 0, size = 0;
		a[i - 1] = colour + '0';
		for (int j = 1; j < i; j++) {//j是从i开始向左上检索的位数
			if (p.y - j < 0 || p.x - j < 0)//越界
				break;
			if (Board[p.x - j][p.y - j] == 1 - colour)
				break;
			a[i - 1 - j] = Board[p.x - j][p.y - j] + '0';
			left_size++;
		}
		for (int j = 1; j < 8 - i; j++) {//向右下检索
			if (p.y + j > 18 || p.x + j > 18)//越界
				break;
			if (Board[p.x + j][p.y + j] == 1 - colour)
				break;
			a[i - 1 + j] = Board[p.x + j][p.y + j] + '0';
			right_size++;
		}
		std::string temp(a, i - left_size - 1, left_size + right_size + 1);
		size = temp.size();
		if (colour == BLACK) {//将0转换为1，方便比对。
			for (int k = 0; k < size; k++) {
				if (temp[k] == '0')
					temp[k] = '1';
			}
		}
		score[i - 1] = score_table(size, temp, computerSide == colour, whichStep);
	}
	score4 = get_max(score, 7);
	return score1 + score2 + score3 + score4;
}
//用于计算该点总得分
int calculate_score_step_2(Point p) {
	int score_x = 0, score_y = 0, score_z = 0;//x:仅考虑己方得分，y:该点对方下时仅考虑对方得分，z:该点己方下时仅考虑对方得分
	int X = 0, Y = 0;//用于标记{活四，眠四，活五，眠五}双组合
	score_x = calculate_score_step_1(p, computerSide, score_x);
	score_y = calculate_score_step_1(p, 1 - computerSide, score_y);
	return score_x > score_y ? score_x : score_y;
}
//功能函数，调用以上函数得到最大得分点，返回。
Point Choose_Point() {
	Chess temp;
	//根据Board初始化副本类
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			transcript[i][j].set(i, j, Board[i][j]);
		}
	}
	//计算每个空的得分
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (Board[i][j] == 2) {
				transcript[i][j].set_score(calculate_score_step_2(transcript[i][j].get_location()));
			}
		}
	}
	//得到最大得分点，返回
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (temp.get_score() < transcript[i][j].get_score())
				temp.set(transcript[i][j]);
		}
	}
	return temp.get_location();
};

/*main*/
int main() {
	while (true) {
		fflush(stdout);
		std::cin >> Message;
		//分析命令
		//发送队名
		if (Message.compare("name?") == 0) {
			fflush(stdin);
			std::cout << "name Alpha佛" << std::endl;
		}
		//新的一次
		else if (Message.compare("new") == 0) {
			std::cin >> Message;//获取己方颜色
			fflush(stdin);
			if (Message.compare("black") == 0) {
				computerSide = BLACK;
			}
			else if (Message.compare("white") == 0) {
				computerSide = WHITE;
			}
			iniBoard();
			tool.reset();
			start = true;
			if (computerSide == BLACK) {
				step.first.x = 9;
				step.first.y = 9;
				Board[step.first.x][step.first.y] = computerSide;//处理己方行棋
				move(step.first.x, step.first.y, 3);
			}
		}
		//下棋
		else if (Message.compare("move") == 0) {
			std::cin >> Message;
			fflush(stdin);
			move(Message);
			switch (tool.whichGame())
			{
				//如果我们是白方，下第一次
			case 1: {
				if (computerSide == WHITE) {
					int FirstStepOfBLACK = tool.locOfChess(BLACK, 1);
					step.first.x = -1, step.second.x = -1;
					step.first.y = -1, step.second.y = -1;
					int x_ = FirstStepOfBLACK / 100, y_ = FirstStepOfBLACK % 100;
					for (int i = 4; i < 8; i++) {
						if (x_ + DIR[i][0] >= 0 && x_ + DIR[i][0] < 19 && y_ + DIR[i][1] >= 0 && y_ + DIR[i][1] < 19) {
							if (step.first.x == -1 && step.first.y == -1) {
								step.first.x = x_ + DIR[i][0];
								step.first.y = y_ + DIR[i][1];
								continue;
							}
							if (step.second.x == -1 && step.second.y == -1) {
								step.second.x = x_ + DIR[i][0];
								step.second.y = y_ + DIR[i][1];
								break;
							}
						}
					}
					for (int i = 0; i < 4; i++) {
						if (x_ + DIR[i][0] >= 0 && x_ + DIR[i][0] < 19 && y_ + DIR[i][1] >= 0 && y_ + DIR[i][1] < 19) {
							if (step.first.x == -1 && step.first.y == -1) {
								step.first.x = x_ + DIR[i][0];
								step.first.y = y_ + DIR[i][1];
								continue;
							}
							if (step.second.x == -1 && step.second.y == -1) {
								step.second.x = x_ + DIR[i][0];
								step.second.y = y_ + DIR[i][1];
								break;
							}
						}
					}
				}
				break;
			}
				//如果我们是黑方，下第二次
			case 2: {
				if (computerSide == BLACK) {
					int temp = tool.locOfChess(BLACK, 1);
					Point FirstStepOfBLACK;
					FirstStepOfBLACK.x = temp / 100;
					FirstStepOfBLACK.y = temp % 100;
					temp = tool.locOfChess(WHITE, 1);
					Point FirstStepOfWHITE;
					FirstStepOfWHITE.x = temp / 100;
					FirstStepOfWHITE.y = temp % 100;
					temp = tool.locOfChess(WHITE, 2);
					Point SecondStepOfWHITE;
					SecondStepOfWHITE.x = temp / 100;
					SecondStepOfWHITE.y = temp % 100;
					//开始了……
					if (Board[FirstStepOfBLACK.x + 1][FirstStepOfBLACK.y + 1] == EMPTY && Board[FirstStepOfBLACK.x - 1][FirstStepOfBLACK.y - 1] == EMPTY) {
						if (tool.if_(1 - computerSide, FirstStepOfBLACK.x + 2, FirstStepOfBLACK.y + 2) == 3 || tool.if_(1 - computerSide, FirstStepOfBLACK.x - 2, FirstStepOfBLACK.y - 2) == 3) {
							//另外想办法吧……
						}
						else {
							step.first.x = FirstStepOfBLACK.x + 1;
							step.first.y = FirstStepOfBLACK.y + 1;
							step.second.x = FirstStepOfBLACK.x - 1;
							step.second.y = FirstStepOfBLACK.y - 1;
							break;
						}
					}
					if (Board[FirstStepOfBLACK.x + 1][FirstStepOfBLACK.y - 1] == EMPTY && Board[FirstStepOfBLACK.x - 1][FirstStepOfBLACK.y + 1] == EMPTY) {
						if (tool.if_(1 - computerSide, FirstStepOfBLACK.x + 2, FirstStepOfBLACK.y - 2) == 3 || tool.if_(1 - computerSide, FirstStepOfBLACK.x - 2, FirstStepOfBLACK.y + 2) == 3) {
							//另外想办法吧……
						}
						else {
							step.first.x = FirstStepOfBLACK.x + 1;
							step.first.y = FirstStepOfBLACK.y - 1;
							step.second.x = FirstStepOfBLACK.x - 1;
							step.second.y = FirstStepOfBLACK.y + 1;
							break;
						}
					}
					if (Board[FirstStepOfBLACK.x + 1][FirstStepOfBLACK.y + 1] == EMPTY && Board[FirstStepOfBLACK.x + 2][FirstStepOfBLACK.y + 2] == EMPTY) {
						if (tool.if_(1 - computerSide, FirstStepOfBLACK.x + 3, FirstStepOfBLACK.y + 3) == 3 || tool.if_(1 - computerSide, FirstStepOfBLACK.x - 1, FirstStepOfBLACK.y - 1) == 3) {
							//另外想办法吧……
						}
						else {
							step.first.x = FirstStepOfBLACK.x + 1;
							step.first.y = FirstStepOfBLACK.y + 1;
							step.second.x = FirstStepOfBLACK.x + 2;
							step.second.y = FirstStepOfBLACK.y + 2;
							break;
						}
					}
					if (Board[FirstStepOfBLACK.x - 1][FirstStepOfBLACK.y - 1] == EMPTY && Board[FirstStepOfBLACK.x - 2][FirstStepOfBLACK.y - 2] == EMPTY) {
						if (tool.if_(1 - computerSide, FirstStepOfBLACK.x - 3, FirstStepOfBLACK.y - 3) == 3 || tool.if_(1 - computerSide, FirstStepOfBLACK.x + 1, FirstStepOfBLACK.y + 1) == 3) {
							//另外想办法吧……
						}
						else {
							step.first.x = FirstStepOfBLACK.x - 1;
							step.first.y = FirstStepOfBLACK.y - 1;
							step.second.x = FirstStepOfBLACK.x - 2;
							step.second.y = FirstStepOfBLACK.y - 2;
							break;
						}
					}
					if (Board[FirstStepOfBLACK.x + 1][FirstStepOfBLACK.y - 1] == EMPTY && Board[FirstStepOfBLACK.x + 2][FirstStepOfBLACK.y - 2] == EMPTY) {
						if (tool.if_(1 - computerSide, FirstStepOfBLACK.x + 3, FirstStepOfBLACK.y - 3) == 3 || tool.if_(1 - computerSide, FirstStepOfBLACK.x - 1, FirstStepOfBLACK.y + 1) == 3) {
							//另外想办法吧……
						}
						else {
							step.first.x = FirstStepOfBLACK.x + 1;
							step.first.y = FirstStepOfBLACK.y - 1;
							step.second.x = FirstStepOfBLACK.x + 2;
							step.second.y = FirstStepOfBLACK.y - 2;
							break;
						}
					}
					if (Board[FirstStepOfBLACK.x - 1][FirstStepOfBLACK.y + 1] == EMPTY && Board[FirstStepOfBLACK.x - 2][FirstStepOfBLACK.y + 2] == EMPTY) {
						if (tool.if_(1 - computerSide, FirstStepOfBLACK.x - 3, FirstStepOfBLACK.y + 3) == 3 || tool.if_(1 - computerSide, FirstStepOfBLACK.x + 1, FirstStepOfBLACK.y - 1) == 3) {
							//另外想办法吧……
						}
						else {
							step.first.x = FirstStepOfBLACK.x - 1;
							step.first.y = FirstStepOfBLACK.y + 1;
							step.second.x = FirstStepOfBLACK.x - 2;
							step.second.y = FirstStepOfBLACK.y + 2;
							break;
						}
					}
					//放弃了
				}
				break;
			}
			default: {
				whichStep = 1;
				Point Loc = Choose_Point();
				step.first.x = Loc.x;
				step.first.y = Loc.y;
				if (step.first.x < 0 || step.first.x>18 || step.first.y < 0 || step.first.y > 18) {
					break;
				}
				Board[step.first.x][step.first.y] = computerSide;
				whichStep = 2;
				Loc = Choose_Point();
				step.second.x = Loc.x;
				step.second.y = Loc.y;
				Board[step.first.x][step.first.y] = EMPTY;
				break;
			}
			}
			//出现错误，下在了非空白的地方
			if (step.first.x < 0 || step.first.x>18 || step.first.y < 0 || step.first.y > 18) {
				int Max = 0;
				int temp = 0;
				int Loc = 0;
				for (unsigned int i = 0; i < Board.size(); i++) {
					for (unsigned int ii = 0; ii < Board[i].size(); ii++) {
						if (Board[i][ii] == EMPTY) {
							temp = tool.howManyPiece(1 - computerSide, i, ii);
							if (temp > Max) {
								Max = temp;
								Loc = i * 100 + ii;
							}
						}
					}
				}
				step.first.x = Loc / 100;
				step.first.y = Loc % 100;
			}
			if (step.second.x < 0 || step.second.x>18 || step.second.y < 0 || step.second.y > 18) {
				int Max = 0;
				int temp = 0;
				int Loc = 0;
				for (unsigned int i = 0; i < Board.size(); i++) {
					for (unsigned int ii = 0; ii < Board[i].size(); ii++) {
						if (Board[i][ii] == EMPTY) {
							temp = tool.howManyPiece(1 - computerSide, i, ii);
							if (temp > Max) {
								Max = temp;
								Loc = i * 100 + ii;
							}
						}
					}
				}
				step.second.x = Loc / 100;
				step.second.y = Loc % 100;
			}
			if ((Board[step.first.x][step.first.y] != EMPTY || Board[step.second.x][step.second.y] != EMPTY) || (step.first.x == step.second.x && step.first.y == step.second.y)) {
				if (Board[step.first.x][step.first.y] != EMPTY) {
					int Max = 0;
					int temp = 0;
					int Loc = 0;
					for (unsigned int i = 0; i < Board.size(); i++) {
						for (unsigned int ii = 0; ii < Board[i].size(); ii++) {
							if (Board[i][ii] == EMPTY) {
								temp = tool.howManyPiece(1 - computerSide, i, ii);
								if (temp > Max) {
									Max = temp;
									Loc = i * 100 + ii;
								}
							}
						}
					}
					step.first.x = Loc / 100;
					step.first.y = Loc % 100;
				}
				move(step.first.x, step.first.y, 1);
				if (Board[step.second.x][step.second.y] != EMPTY) {
					int Max = 0;
					int temp = 0;
					int Loc = 0;
					for (unsigned int i = 0; i < Board.size(); i++) {
						for (unsigned int ii = 0; ii < Board[i].size(); ii++) {
							if (Board[i][ii] == EMPTY) {
								temp = tool.howManyPiece(1 - computerSide, i, ii);
								if (temp > Max) {
									Max = temp;
									Loc = i * 100 + ii;
								}
							}
						}
					}
					step.second.x = Loc / 100;
					step.second.y = Loc % 100;
				}
				move(step.second.x, step.second.y, 2);
			}
			else {
				move(step);
			}
		}
		//下棋错误
		else if (Message.compare("error") == 0) {
			fflush(stdin);
		}
		//结束游戏
		else if (Message.compare("end") == 0) {
			fflush(stdin);
			start = false;
		}
		//退出程序
		else if (Message.compare("quit") == 0) {
			fflush(stdin);
			std::cout << "Quit!" << std::endl;
			break;
		}
		//hello
		else if (Message.compare("hello") == 0 || Message.compare("Hello") == 0) {
			fflush(stdin);
			std::cout << "Hi";
		}
		else if (Message.compare("hi") == 0 || Message.compare("Hi") == 0) {
			fflush(stdin);
			std::cout << "Hey";
		}
		else if (Message.compare("hey") == 0 || Message.compare("Hey") == 0) {
			fflush(stdin);
			std::cout << "Hello";
		}
	}
	return 0;
}