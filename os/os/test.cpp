/*ע�⣺1.������ʵ����ͼ�λ����棬��ʹ��EasyXΪVS��װ��Ӧ��EasyX�⣬����VS����
		2.��VS���Ϸ��˵��������Ŀ�����ԣ����������еĸ߼����ԣ����ַ�����Ϊʹ�ö��ֽ��ַ���
		3.���������������������*/
#include <graphics.h>              // ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <stdio.h>
#include<windows.h>
int RAM = 0;//���������
int RS[20];//������ʴ�
int skey1() {
	//��ȡ����������������ӡ
	settextstyle(20, 0, "����");
	settextcolor(BLACK);
	char key = _getch();
	RAM = key - 48;
	outtextxy(200, 120, key);
	return RAM;//�����������Ŀ
}
int skey(int i, int j) {
	//��ȡ����ķ��ʴ�����ӡ	
	char key = _getch();
	switch (key)//�ж���������ֲ����뵽RS��
	{
	case '1':outtextxy(i, 70, key);  RS[j] = 1; return 2;//��Ϊ�Ϸ������򷵻�2
	case '2':outtextxy(i, 70, key); RS[j] = 2; return 2;
	case'3':outtextxy(i, 70, key); RS[j] = 3; return 2;
	case '4':outtextxy(i, 70, key); RS[j] = 4; return 2;
	case '5':outtextxy(i, 70, key); RS[j] = 5; return 2;
	case'6':outtextxy(i, 70, key);  RS[j] = 6; return 2;
	case '7':outtextxy(i, 70, key); RS[j] = 7; return 2;
	case '8':outtextxy(i, 70, key); RS[j] = 8; return 2;
	case'9':outtextxy(i, 70, key); RS[j] = 9; return 2;
	case'0':outtextxy(i, 70, key); RS[j] = 0; return 2;
	default:return 1;//��Ϊ�����Ƿ��ַ��򷵻�1
		//case 13: return;		
	}
}
int mouse() {
	char c[10];
	int i = 150;
	int j = 0;
	settextstyle(20, 0, "����");
	settextcolor(BLACK);
	while (1) {	//ʹ��һֱѭ������������̵�ֵ
		if (MouseHit()) {//�������
			MOUSEMSG mou = GetMouseMsg();
			if (mou.uMsg == WM_LBUTTONDOWN) {//�����������
				if (mou.x > 100 && mou.x < 250 && mou.y>550 && mou.y < 600) {//�����������Ϊ��ȷ�ϡ�
					return j;//���ط��ʴ��ĳ��Ȳ�����������ʴ�
				}
				else if (mou.x > 1000 && mou.x < 1150 && mou.y>550 && mou.y < 600) {
					closegraph();
					return 0;
				}
			}
		}if (_kbhit()) {//����������
			int t = skey(i, j);//���ݷ���ֵ�ж��Ƿ�Ϊ�Ƿ��ַ�
			if (t == 2) {//��Ϊ�Ϸ�������������У��Ƿ������
				i = i + 20;
				j++;
			}
		}
	}
}
void button() {
	//���ð�ť��ʽ
	setfillcolor(YELLOW);
	rectangle(100, 550, 160, 600);
	fillrectangle(100, 550, 250, 600);
	fillrectangle(1000, 550, 1150, 600);
	//��ӡȷ�� ȡ����ť
	settextstyle(30, 0, "����");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	outtextxy(120, 560, "ȷ   ��");
	outtextxy(1020, 560, "ȡ   ��");
}
void guiOPT() {
	//�������壬��ӡClockҳ���û��㷨"
	settextstyle(50, 0, "����");
	settextcolor(BLUE);
	setbkmode(TRANSPARENT);
	outtextxy(400, 0, "OPTҳ���û��㷨");
	//����button(),��ӡȷ�ϣ�ȡ����ť
	button();
	//�������壬��ӡ"������������С��"
	settextstyle(20, 0, "����");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	outtextxy(10, 120, "������������С��");
	//��ӡ"��������ʴ���"
	settextstyle(20, 0, "����");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	outtextxy(10, 70, "��������ʴ���");
}
void guiFIFO() {
	//�������壬��ӡ"FIFOҳ���û��㷨"
	settextstyle(50, 0, "����");
	settextcolor(BLUE);
	setbkmode(TRANSPARENT);
	outtextxy(400, 0, "FIFOҳ���û��㷨");
	//����button(),��ӡȷ�ϣ�ȡ����ť
	button();
	//�������壬��ӡ"������������С��"
	settextstyle(20, 0, "����");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	outtextxy(10, 120, "������������С��");
	//��ӡ"��������ʴ���"
	settextstyle(20, 0, "����");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	outtextxy(10, 70, "��������ʴ���");
}
void guiRAMOPT(int length2, int length1) {
	//����������ʽ
	settextstyle(20, 0, "����");
	settextcolor(BLACK);
	int a[10] = { -1 };//ģ�������
	int x = 80;
	int u = 0;//���ó�ʼȱҳ�жϴ���Ϊ��
	int o = 0;//���ó�ʼҳ���û�����Ϊ��
	//�����ʴ�С���������Ŀ
	if (length2 <= length1) {
		for (int i = 0; i < length2; i++) {


			char c[10];

			a[i] = RS[i];
			u++;
			int y = 170;
			for (int g = 0; g <= i; g++) {
				snprintf(c, 10, "%d", a[g]);
				outtextxy(x, y, c);
				y = y + 30;
			}



			x = x + 60;
		}
		//��ӡС�ڵ����������Ŀ��ǰ����


	}
	else {
		//��ӡǰ����
		for (int i = 0; i < length1; i++) {
			u++;
			char c[10];
			a[i] = RS[i];
			int y = 170;
			for (int g = 0; g < i; g++) {
				snprintf(c, 10, "%d", a[g]);
				outtextxy(x, y, c);
				y = y + 30;
			}
			x = x + 60;
		}
		//��ӡ�󼸸�
		for (int i = length1; i < length2; i++) {
			int k = 0;

			for (int j = 0; j < length1; j++) {
				if (a[j] != RS[i]) {
					k++;
				}
			}
			//������ȱҳ�ж�
			if (k == length1) {
				u++;
				int y = 170;
				int c[10];
				//�ж��ĸ�ҳ�����÷���
				for (int g = 0; g < length1; g++) {
					for (int j = length1 + 1; j < length2; j++) {
						if (a[g] == RS[j]) {
							c[g] = j - length1;
							break;
						}
						else {
							c[g] = 100;
						}
					}
				}
				//�Ƚ��������ֵ
				int max = 0;
				int t = 0;
				for (int h = 0; h < length1; h++) {
					if (c[h] > max) {
						max = c[h];
						t = h;
					}
				}
				//��ӡ������е�ҳ��
				char d[10];
				snprintf(d, 10, "%d", a[t]);
				outtextxy(x, 70, d);
				a[t] = RS[i];
				o++;
				for (int g = 0; g < length1; g++) {
					char c[10];
					snprintf(c, 10, "%d", a[g]);
					outtextxy(x, y, c);
					y = y + 30;
				}
				x = x + 60;
			}
			else {
				x = x + 60;
			}
		}
	}
	//��ӡȱҳ�жϴ�����ҳ���û�����
	char d[5];
	snprintf(d, 5, "%d", u);
	outtextxy(160, 580, d);
	char f[5];
	snprintf(f, 5, "%d", o);
	outtextxy(1150, 580, f);
}
void guiRAMFIFO(int length2, int length1) {
	//����������ʽ
	settextstyle(20, 0, "����");
	settextcolor(BLACK);
	//��ӡ�ڴ���е�����
	int a[10];//ģ���ڴ��
	int b[20];//ģ���ж��Ⱥ�˳��
	int x = 80;
	int u = 0;//���ó�ʼȱҳ�жϴ���Ϊ��
	int p = 0;//���ó�ʼҳ���û�����Ϊ��
	//�����ʴ�С���������Ŀ
	if (length2 <= length1) {

		//��ӡС�ڵ����������Ŀ��ǰ����
		for (int i = 0; i < length2; i++) {
			int g = 0;
			for (int j = 0; j < i; j++) {
				if (RS[i] != a[j]) {
					g++;
				}
			}
			if (g == i) {


				a[u] = RS[i];
				b[u] = a[i];
				int y = 170;
				u++;
				for (int g = 0; g < u; g++) {
					char c[10];
					snprintf(c, 10, "%d", a[g]);
					outtextxy(x, y, c);
					y = y + 30;
				}
			}
			else {

			}

			x = x + 40;
		}
	}
	//�����ʴ������������Ŀ
	else {
		int l1 = length1;
		for (int i = 0; i < l1; i++) {
			int g = 0;
			for (int j = 0; j < i; j++) {
				if (RS[i] != a[j]) {
					g++;
				}
			}
			if (g == i) {

				char c[10];
				a[u] = RS[i];
				b[u] = a[i];
				int y = 170;
				u++;
				for (int g = 0; g < u; g++) {
					snprintf(c, 10, "%d", a[g]);
					outtextxy(x, y, c);
					y = y + 30;
				}
			}
			else {
				l1++;
			}
			x = x + 40;
		}
		int o = 0;
		int m = length1;
		//��ӡ�󼸸�
		for (int i = l1; i < length2; i++) {
			int t = 0;
			//�жϵ�ǰ����ҳ���Ƿ����ڴ����
			for (int j = 0; j < length1; j++) {
				if (RS[i] == a[j]) {}
				else {
					t++;
				}
			}
			if (t == length1) {//�������ڴ����
				u++;
				p++;
				for (int j = 0; j < length1; j++) {
					//�����Ⱥ�˳��ѡ������ҳ���û���
					if (a[j] == b[o]) {
						//��ӡ���û���ҳ��
						char c[10];
						snprintf(c, 10, "%d", a[j]);
						outtextxy(x, 70, c);
						//��ӡ������е�ҳ��
						a[j] = RS[i];
						b[m] = RS[i];
						m++;
						int y = 170;
						for (int g = 0; g < length1; g++) {
							char c[10];
							snprintf(c, 10, "%d", a[g]);
							outtextxy(x, y, c);
							y = y + 30;
						}
						o++;
						break;
					}
				}
			}
			x = x + 40;
		}
	}
	//��ӡȱҳ�жϴ�����ҳ���û�����
	char d[5];
	snprintf(d, 5, "%d", u);
	outtextxy(160, 580, d);
	char f[5];
	snprintf(f, 5, "%d", p);
	outtextxy(1150, 580, f);
}
void gui2OPT(int length2, int length1) {
	//�������壬��ӡ
	settextstyle(50, 0, "����");
	settextcolor(BLUE);
	setbkmode(TRANSPARENT);
	outtextxy(400, 0, "OPTҳ���û��㷨");
	//��ӡ����
	settextstyle(20, 0, "����");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	outtextxy(10, 70, "PR");
	outtextxy(10, 120, "RS");
	outtextxy(10, 170, "RAM");
	outtextxy(20, 580, "ȱҳ�жϴ�����");
	outtextxy(1000, 580, "ҳ���û�������");
	//��ӡRS��
	settextstyle(20, 0, "����");
	int j = 80;
	char c[10];
	for (int i = 0; i < length2; i++) {
		snprintf(c, 10, "%d", RS[i]);
		outtextxy(j, 120, c);

		j = j + 60;
	}
	//��ӡRAM�ͱ��û���ҳ��
	guiRAMOPT(length2, length1);
}
void gui2FIFO(int length2, int length1) {
	//�������壬��ӡ
	settextstyle(50, 0, "����");
	settextcolor(BLUE);
	setbkmode(TRANSPARENT);
	outtextxy(400, 0, "FIFOҳ���û��㷨");
	//��ӡ����
	settextstyle(20, 0, "����");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	outtextxy(10, 70, "PR");
	outtextxy(10, 120, "RS");
	outtextxy(10, 170, "RAM");
	outtextxy(20, 580, "ȱҳ�жϴ�����");
	outtextxy(1000, 580, "ҳ���û�������");
	//��ӡRS��
	settextstyle(20, 0, "����");
	int j = 80;
	char c[10];
	for (int i = 0; i < length2; i++) {
		snprintf(c, 10, "%d", RS[i]);
		outtextxy(j, 120, c);
		j = j + 40;
	}
	//��ӡRAM�ͱ��û���ҳ��
	guiRAMFIFO(length2, length1);
}
int choose() {
	//���ñ���
	initgraph(1280, 640, SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	settextstyle(50, 0, "����");
	settextcolor(BLUE);
	setbkmode(TRANSPARENT);
	outtextxy(380, 50, "��ѡ��ҳ���û��㷨");

	//���ð�ť��ʽ
	setfillcolor(YELLOW);
	rectangle(100, 550, 160, 600);
	fillrectangle(100, 550, 250, 600);
	fillrectangle(1000, 550, 1150, 600);
	//��ӡȷ�� ȡ����ť
	settextstyle(30, 0, "����");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	outtextxy(120, 560, "FIFO");
	outtextxy(1020, 560, "OPT");
	outtextxy(360, 0, "�����ҳ�洢����ϵͳ�������ʵ��");
	while (1) {
		if (MouseHit()) {//�������
			MOUSEMSG mou = GetMouseMsg();
			if (mou.uMsg == WM_LBUTTONDOWN) {//�����������
				if (mou.x > 100 && mou.x < 250 && mou.y>550 && mou.y < 600) {//�����������Ϊ��FIFO��
					return 1;
				}
				else if (mou.x > 1000 && mou.x < 1150 && mou.y>550 && mou.y < 600) {//�����������Ϊ��OPT��
					return 2;
				}
			}
		}
	}
}
int main() {
	int ch = choose();//��ʾ��ʼѡ�����
	cleardevice();
	if (ch == 2) {
		guiOPT();//��ʾOPT�ĳ�ʼ������
		int length1 = skey1();//�õ�skey1()�����ķ���ֵ���������Ŀ
		int length2 = mouse();//�õ�mouse()�����ķ���ֵ�����ʴ��ĳ���
		cleardevice();//���ȷ�Ϻ���ո�ҳ��
		gui2OPT(length2, length1);//��ʾ���ȷ�Ϻ�Ľ���
	}
	else if (ch == 1) {
		guiFIFO();//��ʾFIFO�ĳ�ʼ������
		int length1 = skey1();//�õ�skey1()�����ķ���ֵ���������Ŀ
		int length2 = mouse();//�õ�mouse()�����ķ���ֵ�����ʴ��ĳ���
		cleardevice();//���ȷ�Ϻ���ո�ҳ��
		gui2FIFO(length2, length1);//��ʾ���ȷ�Ϻ�Ľ���
	}
	getchar();
	return 0;
}