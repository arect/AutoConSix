#pragma once
#include<vector>

#define BLACK 0
#define WHITE 1
#define EMPTY 2

//������
class Point {
public:
	int x = -1;
	int y = -1;
};
//����
class Step {
public:
	Point first;
	Point second;
};
std::vector<std::vector<int>> Board;
int computerSide = EMPTY;//����������ɫ
Step step;//��������
std::string Message;//������Ϣ
bool start = false;//�Ծֿ�ʼ���
int whichStep = 1;
int DIR[][2] = { 1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,-1,-1,1 };
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