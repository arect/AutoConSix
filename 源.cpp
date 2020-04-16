#include<iostream>
#include<vector>
#include<string>
#include<fstream>

#include"Module.h"
#include"Tools.h"
#include"Score.h"

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
			std::cout << "你好，我们是Alpha佛，一个借AlphaGo之名，又希望能佛系代码的小组合。\n我们遇到了很多困难也有很多分歧，还好，我们遇到的快乐的事情更多，开心的心情更多，很高兴能一起合作。";
		}
	}
	return 0;
}