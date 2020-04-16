#pragma once
#include"Module.h"
#include<vector>
#include<string>

#define BLACK 0
#define WHITE 1
#define EMPTY 2

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
	int howManyPiece(int color, int x, int y,int layers = 2) {
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