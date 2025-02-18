/*注意：1.本代码实现了图形化界面，请使用EasyX为VS安装对应的EasyX库，并用VS运行
		2.打开VS在上方菜单栏点击项目，属性，配置属性中的高级属性，将字符集改为使用多字节字符集
		3.完成上述步骤便可正常运行*/
#include <graphics.h>              // 引用图形库头文件
#include <conio.h>
#include <stdio.h>
#include<windows.h>
int RAM = 0;//定义物理块
int RS[20];//定义访问串
int skey1() {
	//读取输入的物理块数并打印
	settextstyle(20, 0, "黑体");
	settextcolor(BLACK);
	char key = _getch();
	RAM = key - 48;
	outtextxy(200, 120, key);
	return RAM;//返回物理块数目
}
int skey(int i, int j) {
	//读取输入的访问串并打印	
	char key = _getch();
	switch (key)//判断输入的数字并加入到RS中
	{
	case '1':outtextxy(i, 70, key);  RS[j] = 1; return 2;//若为合法数字则返回2
	case '2':outtextxy(i, 70, key); RS[j] = 2; return 2;
	case'3':outtextxy(i, 70, key); RS[j] = 3; return 2;
	case '4':outtextxy(i, 70, key); RS[j] = 4; return 2;
	case '5':outtextxy(i, 70, key); RS[j] = 5; return 2;
	case'6':outtextxy(i, 70, key);  RS[j] = 6; return 2;
	case '7':outtextxy(i, 70, key); RS[j] = 7; return 2;
	case '8':outtextxy(i, 70, key); RS[j] = 8; return 2;
	case'9':outtextxy(i, 70, key); RS[j] = 9; return 2;
	case'0':outtextxy(i, 70, key); RS[j] = 0; return 2;
	default:return 1;//若为其它非法字符则返回1
		//case 13: return;		
	}
}
int mouse() {
	char c[10];
	int i = 150;
	int j = 0;
	settextstyle(20, 0, "黑体");
	settextcolor(BLACK);
	while (1) {	//使其一直循环接收鼠标或键盘的值
		if (MouseHit()) {//若鼠标点击
			MOUSEMSG mou = GetMouseMsg();
			if (mou.uMsg == WM_LBUTTONDOWN) {//若鼠标左键点击
				if (mou.x > 100 && mou.x < 250 && mou.y>550 && mou.y < 600) {//若点击的区域为“确认”
					return j;//返回访问串的长度并结束输入访问串
				}
				else if (mou.x > 1000 && mou.x < 1150 && mou.y>550 && mou.y < 600) {
					closegraph();
					return 0;
				}
			}
		}if (_kbhit()) {//若键盘输入
			int t = skey(i, j);//根据返回值判断是否为非法字符
			if (t == 2) {//若为合法数字则继续运行，非法则忽略
				i = i + 20;
				j++;
			}
		}
	}
}
void button() {
	//设置按钮样式
	setfillcolor(YELLOW);
	rectangle(100, 550, 160, 600);
	fillrectangle(100, 550, 250, 600);
	fillrectangle(1000, 550, 1150, 600);
	//打印确认 取消按钮
	settextstyle(30, 0, "宋体");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	outtextxy(120, 560, "确   认");
	outtextxy(1020, 560, "取   消");
}
void guiOPT() {
	//设置字体，打印Clock页面置换算法"
	settextstyle(50, 0, "宋体");
	settextcolor(BLUE);
	setbkmode(TRANSPARENT);
	outtextxy(400, 0, "OPT页面置换算法");
	//调用button(),打印确认，取消按钮
	button();
	//设置字体，打印"请输入物理块大小："
	settextstyle(20, 0, "宋体");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	outtextxy(10, 120, "请输入物理块大小：");
	//打印"请输入访问串："
	settextstyle(20, 0, "宋体");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	outtextxy(10, 70, "请输入访问串：");
}
void guiFIFO() {
	//设置字体，打印"FIFO页面置换算法"
	settextstyle(50, 0, "宋体");
	settextcolor(BLUE);
	setbkmode(TRANSPARENT);
	outtextxy(400, 0, "FIFO页面置换算法");
	//调用button(),打印确认，取消按钮
	button();
	//设置字体，打印"请输入物理块大小："
	settextstyle(20, 0, "宋体");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	outtextxy(10, 120, "请输入物理块大小：");
	//打印"请输入访问串："
	settextstyle(20, 0, "宋体");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	outtextxy(10, 70, "请输入访问串：");
}
void guiRAMOPT(int length2, int length1) {
	//设置字体样式
	settextstyle(20, 0, "黑体");
	settextcolor(BLACK);
	int a[10] = { -1 };//模拟物理块
	int x = 80;
	int u = 0;//设置初始缺页中断次数为零
	int o = 0;//设置初始页面置换次数为零
	//若访问串小于物理块数目
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
		//打印小于等于物理块数目的前几个


	}
	else {
		//打印前几个
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
		//打印后几个
		for (int i = length1; i < length2; i++) {
			int k = 0;

			for (int j = 0; j < length1; j++) {
				if (a[j] != RS[i]) {
					k++;
				}
			}
			//若发生缺页中断
			if (k == length1) {
				u++;
				int y = 170;
				int c[10];
				//判断哪个页面会最久访问
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
				//比较数组最大值
				int max = 0;
				int t = 0;
				for (int h = 0; h < length1; h++) {
					if (c[h] > max) {
						max = c[h];
						t = h;
					}
				}
				//打印物理块中的页面
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
	//打印缺页中断次数和页面置换次数
	char d[5];
	snprintf(d, 5, "%d", u);
	outtextxy(160, 580, d);
	char f[5];
	snprintf(f, 5, "%d", o);
	outtextxy(1150, 580, f);
}
void guiRAMFIFO(int length2, int length1) {
	//设置字体样式
	settextstyle(20, 0, "黑体");
	settextcolor(BLACK);
	//打印内存块中的数据
	int a[10];//模拟内存块
	int b[20];//模拟判断先后顺序
	int x = 80;
	int u = 0;//设置初始缺页中断次数为零
	int p = 0;//设置初始页面置换次数为零
	//若访问串小于物理块数目
	if (length2 <= length1) {

		//打印小于等于物理块数目的前几个
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
	//若访问串大于物理块数目
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
		//打印后几个
		for (int i = l1; i < length2; i++) {
			int t = 0;
			//判断当前访问页面是否在内存块中
			for (int j = 0; j < length1; j++) {
				if (RS[i] == a[j]) {}
				else {
					t++;
				}
			}
			if (t == length1) {//若不在内存块中
				u++;
				p++;
				for (int j = 0; j < length1; j++) {
					//根据先后顺序选择将哪种页面置换掉
					if (a[j] == b[o]) {
						//打印被置换的页面
						char c[10];
						snprintf(c, 10, "%d", a[j]);
						outtextxy(x, 70, c);
						//打印物理块中的页面
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
	//打印缺页中断次数和页面置换次数
	char d[5];
	snprintf(d, 5, "%d", u);
	outtextxy(160, 580, d);
	char f[5];
	snprintf(f, 5, "%d", p);
	outtextxy(1150, 580, f);
}
void gui2OPT(int length2, int length1) {
	//设置字体，打印
	settextstyle(50, 0, "宋体");
	settextcolor(BLUE);
	setbkmode(TRANSPARENT);
	outtextxy(400, 0, "OPT页面置换算法");
	//打印字体
	settextstyle(20, 0, "宋体");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	outtextxy(10, 70, "PR");
	outtextxy(10, 120, "RS");
	outtextxy(10, 170, "RAM");
	outtextxy(20, 580, "缺页中断次数：");
	outtextxy(1000, 580, "页面置换次数：");
	//打印RS串
	settextstyle(20, 0, "黑体");
	int j = 80;
	char c[10];
	for (int i = 0; i < length2; i++) {
		snprintf(c, 10, "%d", RS[i]);
		outtextxy(j, 120, c);

		j = j + 60;
	}
	//打印RAM和被置换的页面
	guiRAMOPT(length2, length1);
}
void gui2FIFO(int length2, int length1) {
	//设置字体，打印
	settextstyle(50, 0, "宋体");
	settextcolor(BLUE);
	setbkmode(TRANSPARENT);
	outtextxy(400, 0, "FIFO页面置换算法");
	//打印字体
	settextstyle(20, 0, "宋体");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	outtextxy(10, 70, "PR");
	outtextxy(10, 120, "RS");
	outtextxy(10, 170, "RAM");
	outtextxy(20, 580, "缺页中断次数：");
	outtextxy(1000, 580, "页面置换次数：");
	//打印RS串
	settextstyle(20, 0, "黑体");
	int j = 80;
	char c[10];
	for (int i = 0; i < length2; i++) {
		snprintf(c, 10, "%d", RS[i]);
		outtextxy(j, 120, c);
		j = j + 40;
	}
	//打印RAM和被置换的页面
	guiRAMFIFO(length2, length1);
}
int choose() {
	//设置背景
	initgraph(1280, 640, SHOWCONSOLE);
	setbkcolor(WHITE);
	cleardevice();
	settextstyle(50, 0, "宋体");
	settextcolor(BLUE);
	setbkmode(TRANSPARENT);
	outtextxy(380, 50, "请选择页面置换算法");

	//设置按钮样式
	setfillcolor(YELLOW);
	rectangle(100, 550, 160, 600);
	fillrectangle(100, 550, 250, 600);
	fillrectangle(1000, 550, 1150, 600);
	//打印确认 取消按钮
	settextstyle(30, 0, "宋体");
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	outtextxy(120, 560, "FIFO");
	outtextxy(1020, 560, "OPT");
	outtextxy(360, 0, "请求分页存储管理系统的设计与实现");
	while (1) {
		if (MouseHit()) {//若鼠标点击
			MOUSEMSG mou = GetMouseMsg();
			if (mou.uMsg == WM_LBUTTONDOWN) {//若鼠标左键点击
				if (mou.x > 100 && mou.x < 250 && mou.y>550 && mou.y < 600) {//若点击的区域为“FIFO”
					return 1;
				}
				else if (mou.x > 1000 && mou.x < 1150 && mou.y>550 && mou.y < 600) {//若鼠标点击区域为“OPT”
					return 2;
				}
			}
		}
	}
}
int main() {
	int ch = choose();//显示初始选择界面
	cleardevice();
	if (ch == 2) {
		guiOPT();//显示OPT的初始化界面
		int length1 = skey1();//得到skey1()函数的返回值即物理块数目
		int length2 = mouse();//得到mouse()函数的返回值即访问串的长度
		cleardevice();//点击确认后清空该页面
		gui2OPT(length2, length1);//显示点击确认后的界面
	}
	else if (ch == 1) {
		guiFIFO();//显示FIFO的初始化界面
		int length1 = skey1();//得到skey1()函数的返回值即物理块数目
		int length2 = mouse();//得到mouse()函数的返回值即访问串的长度
		cleardevice();//点击确认后清空该页面
		gui2FIFO(length2, length1);//显示点击确认后的界面
	}
	getchar();
	return 0;
}