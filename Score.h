#pragma once
#include"Module.h"
#include<string>
//�γ�/��ֹ{���ģ����ģ����壬����}˫���
//������X,Y,������һ���γɻ��ĸ�ֵX=1
//�Է���һ���γɻ��ĸ�ֵY=1
//�ڶ��������γ�����/������X==1�������ε÷ֽ���������
//�ڶ����Է��γ�����/������Y==1�������ε÷ֽ�������/����/���ĵ�


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

//��ֱȶԱ������ȶ����Σ����ظ����ε÷�
int score_table(int size, std::string a, bool isme, int step) {
	//��a���ø�ֵ��b��
	std::string b(a);
	for (int i = 0; i < size; i++) {
		b[size - i - 1] = a[i];
	}
	//��a���ø�ֵ��b��
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

//��������һ������Χ�÷��������εĵ÷�
int get_max(int a[], int size) {
	int temp = a[0];
	for (int i = 1; i < size; i++) {
		if (temp < a[i])
			temp = a[i];
	}
	return temp;
}

//������ȡ���Σ��������Ǽ����Ѿ�����϶�Ӧcolour�����
int calculate_score_step_1(Point p, int colour, int score_) {
	std::string a = "2222222";
	int left_size = 0;
	int right_size = 0;
	int size = 0;
	int score[7] = { 0 ,0,0,0,0,0,0 };
	int score1 = 0, score2 = 0, score3 = 0, score4 = 0;
	//��
	for (int i = 1; i < 8; i++) {//�õ��Ǹ�ģ�͵ĵ�iλ������ǵ�7λ
		left_size = 0, right_size = 0, size = 0;
		a[i - 1] = colour + '0';
		for (int j = 1; j < i; j++) {//j�Ǵ�i��ʼ���������λ��
			if (p.y - j < 0)//Խ��
				break;
			if (Board[p.x][p.y - j] == 1 - colour)//����ס
				break;
			a[i - 1 - j] = Board[p.x][p.y - j] + '0';
			left_size++;
		}
		for (int j = 1; j < 8 - i; j++) {//���Ҽ���
			if (p.y + j > 18)//Խ��
				break;
			if (Board[p.x][p.y + j] == 1 - colour)
				break;
			a[i - 1 + j] = Board[p.x][p.y + j] + '0';
			right_size++;
		}
		std::string temp(a, i - left_size - 1, left_size + right_size + 1);//��ȡ��Ч����
		size = temp.size();
		if (colour == BLACK) {//�����0����0ת��Ϊ1������ȶԡ�
			for (int k = 0; k < size; k++) {
				if (temp[k] == '0')
					temp[k] = '1';
			}
		}
		score[i - 1] = score_table(size, temp, computerSide == colour, whichStep);//�õ����ε÷֣�����÷�����
	}
	score1 = get_max(score, 7);//Ĭ��ÿ��ģ�Ͷ��д��
/*�������β�ƥ��ĵ÷��������ôӦ����ÿ�λ�����ʱ���÷������ʼ��0*/
	//��
	for (int i = 1; i < 8; i++) {//�Ǹ�ģ�͵ĵ�iλ
		left_size = 0, right_size = 0, size = 0;
		a[i - 1] = colour + '0';
		for (int j = 1; j < i; j++) {//j�Ǵ�i��ʼ���ϼ�����λ��
			if (p.x - j < 0)//Խ��
				break;
			if (Board[p.x - j][p.y] == 1 - colour)
				break;
			a[i - 1 - j] = Board[p.x - j][p.y] + '0';
			left_size++;
		}
		for (int j = 1; j < 8 - i; j++) {//���¼���
			if (p.x + j > 18)//Խ��
				break;
			if (Board[p.x + j][p.y] == 1 - colour)
				break;
			a[i - 1 + j] = Board[p.x + j][p.y] + '0';
			right_size++;
		}
		std::string temp(a, i - left_size - 1, left_size + right_size + 1);
		size = temp.size();
		if (colour == BLACK) {//��0ת��Ϊ1������ȶԡ�
			for (int k = 0; k < size; k++) {
				if (temp[k] == '0')
					temp[k] = '1';
			}
		}
		score[i - 1] = score_table(size, temp, computerSide == colour, whichStep);
	}
	score2 = get_max(score, 7);
	//Ʋ
	for (int i = 1; i < 8; i++) {//�Ǹ�ģ�͵ĵ�iλ
		left_size = 0, right_size = 0, size = 0;
		a[i - 1] = colour + '0';
		for (int j = 1; j < i; j++) {//j�Ǵ�i��ʼ�����¼�����λ��
			if (p.y - j < 0 || p.x + j> 18)//Խ��
				break;
			if (Board[p.x + j][p.y - j] == 1 - colour)
				break;
			a[i - 1 - j] = Board[p.x + j][p.y - j] + '0';
			left_size++;
		}
		for (int j = 1; j < 8 - i; j++) {//�����ϼ���
			if (p.y + j > 18 || p.x - j < 0)//Խ��
				break;
			if (Board[p.x - j][p.y + j] == 1 - colour)
				break;
			a[i - 1 + j] = Board[p.x - j][p.y + j] + '0';
			right_size++;
		}
		std::string temp(a, i - left_size - 1, left_size + right_size + 1);
		size = temp.size();
		if (colour == BLACK) {//��0ת��Ϊ1������ȶԡ�
			for (int k = 0; k < size; k++) {
				if (temp[k] == '0')
					temp[k] = '1';
			}
		}
		score[i - 1] = score_table(size, temp, computerSide == colour, whichStep);
	}
	score3 = get_max(score, 7);
	//��
	for (int i = 1; i < 8; i++) {//�Ǹ�ģ�͵ĵ�iλ
		left_size = 0, right_size = 0, size = 0;
		a[i - 1] = colour + '0';
		for (int j = 1; j < i; j++) {//j�Ǵ�i��ʼ�����ϼ�����λ��
			if (p.y - j < 0 || p.x - j < 0)//Խ��
				break;
			if (Board[p.x - j][p.y - j] == 1 - colour)
				break;
			a[i - 1 - j] = Board[p.x - j][p.y - j] + '0';
			left_size++;
		}
		for (int j = 1; j < 8 - i; j++) {//�����¼���
			if (p.y + j > 18 || p.x + j > 18)//Խ��
				break;
			if (Board[p.x + j][p.y + j] == 1 - colour)
				break;
			a[i - 1 + j] = Board[p.x + j][p.y + j] + '0';
			right_size++;
		}
		std::string temp(a, i - left_size - 1, left_size + right_size + 1);
		size = temp.size();
		if (colour == BLACK) {//��0ת��Ϊ1������ȶԡ�
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

/*���ڼ��㼺������ԶԷ���ɵĸ���Ӱ��������⽫���뼺���¸õ�ĵ÷֡�
int calculate_score_z(Point p, int colour, int score_z) {
	std::string a = "2222222";
	int size = 0;
	int score[7] = { 0,0,0,0,0,0,0 };
	//��
	//��
	for (int i = 1; i < 8; i++) {
		if (p.y - i < 0)
			break;
		if (Board[p.x][p.y - i] == 1 - colour)
			break;
		for (int j = 1; j <= i; j++) {
			a[j - 1] = Board[p.x][p.y - j] + '0';
			size++;
		}
		std::string temp(a, 0, size);
		if (colour == BLACK) {//��0ת��Ϊ1������ȶԡ�
			for (int k = 0; k < size; k++) {
				if (temp[k] == '0')
					temp[k] = '1';
			}
		}
		score[i - 1] = score_table(size, temp, true, whichStep);//ismeֵ����
		size = 0;
	}
	score_z = get_max(score, 7);//Ĭ��ÿ�����ζ��д�֣������Ҫ���ǲ�ƥ�������ô���
	//��
	for (int i = 1; i < 8; i++) {
		if (p.y + i > 18)
			break;
		if (Board[p.x][p.y + i] == 1 - colour)
			break;
		for (int j = 1; j <= i; j++) {
			a[j - 1] = Board[p.x][p.y + j] + '0';
			size++;
		}
		std::string temp(a, 0, size);
		if (colour == BLACK) {//��0ת��Ϊ1������ȶԡ�
			for (int k = 0; k < size; k++) {
				if (temp[k] == '0')
					temp[k] = '1';
			}
		}
		score[i - 1] = score_table(size, temp, true, whichStep);//ismeֵ����
		size = 0;
	}
	score_z += get_max(score, 7);
	//��
	//��
	for (int i = 1; i < 8; i++) {
		if (p.x - i < 0)
			break;
		if (Board[p.x - i][p.y] == 1 - colour)
			break;
		for (int j = 1; j <= i; j++) {
			a[j - 1] = Board[p.x - j][p.y] + '0';
			size++;
		}
		std::string temp(a, 0, size);
		if (colour == BLACK) {//��0ת��Ϊ1������ȶԡ�
			for (int k = 0; k < size; k++) {
				if (temp[k] == '0')
					temp[k] = '1';
			}
		}
		score[i - 1] = score_table(size, temp, true, whichStep);//ismeֵ����
		size = 0;
	}
	score_z += get_max(score, 7);
	//��
	for (int i = 1; i < 8; i++) {
		if (p.x + i > 18)
			break;
		if (Board[p.x + i][p.y] == 1 - colour)
			break;
		for (int j = 1; j <= i; j++) {
			a[j - 1] = Board[p.x + i][p.y] + '0';
			size++;
		}
		std::string temp(a, 0, size);
		if (colour == BLACK) {//��0ת��Ϊ1������ȶԡ�
			for (int k = 0; k < size; k++) {
				if (temp[k] == '0')
					temp[k] = '1';
			}
		}
		score[i - 1] = score_table(size, temp, true, whichStep);//ismeֵ����
		size = 0;
	}
	score_z += get_max(score, 7);
	//Ʋ
	//����
	for (int i = 1; i < 8; i++) {
		if (p.y + i > 18 || p.x - i < 0)
			break;
		if (Board[p.x - i][p.y + i] == 1 - colour)
			break;
		for (int j = 1; j <= i; j++) {
			a[j - 1] = Board[p.x - j][p.y + j] + '0';
			size++;
		}
		std::string temp(a, 0, size);
		if (colour == BLACK) {//��0ת��Ϊ1������ȶԡ�
			for (int k = 0; k < size; k++) {
				if (temp[k] == '0')
					temp[k] = '1';
			}
		}
		score[i - 1] = score_table(size, temp, true, whichStep);//ismeֵ����
		size = 0;
	}
	score_z += get_max(score, 7);
	//����
	for (int i = 1; i < 8; i++) {
		if (p.x + i > 18 || p.y - i < 0)
			break;
		if (Board[p.x + i][p.y - i] == 1 - colour)
			break;
		for (int j = 1; j <= i; j++) {
			a[j - 1] = Board[p.x + j][p.y - j] + '0';
			size++;
		}
		std::string temp(a, 0, size);
		if (colour == BLACK) {//��0ת��Ϊ1������ȶԡ�
			for (int k = 0; k < size; k++) {
				if (temp[k] == '0')
					temp[k] = '1';
			}
		}
		score[i - 1] = score_table(size, temp, true, whichStep);//ismeֵ����
		size = 0;
	}
	score_z += get_max(score, 7);
	//��
	//����
	for (int i = 1; i < 8; i++) {
		if (p.y - i < 0 || p.x - i < 0)
			break;
		if (Board[p.x - i][p.y - i] == 1 - colour)
			break;
		for (int j = 1; j <= i; j++) {
			a[j - 1] = Board[p.x - j][p.y - j] + '0';
			size++;
		}
		std::string temp(a, 0, size);
		if (colour == BLACK) {//��0ת��Ϊ1������ȶԡ�
			for (int k = 0; k < size; k++) {
				if (temp[k] == '0')
					temp[k] = '1';
			}
		}
		score[i - 1] = score_table(size, temp, true, whichStep);//ismeֵ����
		size = 0;
	}
	score_z += get_max(score, 7);
	//����
	for (int i = 1; i < 8; i++) {
		if (p.x + i > 18 || p.y + i > 18)
			break;
		if (Board[p.x + i][p.y + i] == 1 - colour)
			break;
		for (int j = 1; j <= i; j++) {
			a[j - 1] = Board[p.x + j][p.y + j] + '0';
			size++;
		}
		std::string temp(a, 0, size);
		if (colour == BLACK) {//��0ת��Ϊ1������ȶԡ�
			for (int k = 0; k < size; k++) {
				if (temp[k] == '0')
					temp[k] = '1';
			}
		}
		score[i - 1] = score_table(size, temp, true, whichStep);//ismeֵ����
		size = 0;
	}
	score_z += get_max(score, 7);
	return score_z;
}
*/
//���ڼ���õ��ܵ÷�
int calculate_score_step_2(Point p) {
	int score_x = 0, score_y = 0, score_z = 0;//x:�����Ǽ����÷֣�y:�õ�Է���ʱ�����ǶԷ��÷֣�z:�õ㼺����ʱ�����ǶԷ��÷�
	int X = 0, Y = 0;//���ڱ��{���ģ����ģ����壬����}˫���
	score_x = calculate_score_step_1(p, computerSide, score_x);
	score_y = calculate_score_step_1(p, 1 - computerSide, score_y);
	//score_z = calculate_score_z(p, 1 - computerSide, score_z);
	//return score_x + score_y - score_z;
	return score_x > score_y ? score_x : score_y;
}

//���ܺ������������Ϻ����õ����÷ֵ㣬���ء�
Point Choose_Point() {
	Chess temp;
	//����Board��ʼ��������
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			transcript[i][j].set(i, j, Board[i][j]);
		}
	}
	//����ÿ���յĵ÷�
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (Board[i][j] == 2) {
				transcript[i][j].set_score(calculate_score_step_2(transcript[i][j].get_location()));
			}
		}
	}
	//�õ����÷ֵ㣬����
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (temp.get_score() < transcript[i][j].get_score())
				temp.set(transcript[i][j]);
		}
	}
	return temp.get_location();
};