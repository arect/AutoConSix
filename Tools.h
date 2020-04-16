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
	//����ֵΪ���˼����ˣ�һ�غ���������һ��
	int whichGame() {
		if (BlackStep > (-1 * WhiteStep)) {
			return -1 * (WhiteStep + 1) + 1;
		}
		else {
			return -1 * (WhiteStep + 1);
		}
	}
	//�ڼ��������λ��
	//����ֵΪcolor����times���ӵ����꣬x*100+y
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
	//��¼����
	void playChess(int color, int x, int y) {
		if (color == BLACK) {
			EveryStep[x][y] = BlackStep++;
		}
		else if (color == WHITE) {
			EveryStep[x][y] = WhiteStep--;
		}
	}
	//�����x,y���ӽ����γɡ�������ֵ����Ϊ�����Ϊ�ߣ�ʮλΪ����
	//����13�����ϵ������γ��˻�����
	//����-35�����ϵ������γ���������
	int if_(int color, int x, int y) {
		int sum = 1;
		int sleep = 1;
		//1�����ϵ�����
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
	//����x,y�����layers�����ж���color����
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

//������������x��y�����꣬step�������Ϸ�ĵ�1�����ǵ�2��
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