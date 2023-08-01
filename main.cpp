/***********************************
青荷屏保(Lotus Leaf Screensavers)
版本：v1.0
源码编码：UTF-8
完成日期：2023/8/1
***********************************/
#include <graphics.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <thread>
void text(char *ch);
void getZoomImage(PIMAGE pimg, const char* fileName, int width, int height);
void Rectangle_withalpha(float x, float y, float width, float height);
int statistics();


int main(void) {

	char str[] = "屏幕保护中……";
	
	
	//初始化窗口
	initgraph(-1, -1, INIT_NOBORDER);
	setrendermode(RENDER_MANUAL);
	setcaption("青荷屏保");

	
	//声明变量
	int wi = getwidth();
	int hi = getheight();
	int n = 1;
	int num = statistics();
	int x2 = 1400;
	int y2 = 900;
	bool move = 0;
	bool is_running = 1;

	num--;
	text(str);
	setfont(hi/30, 0, "黑体");
	xyprintf(wi/10,hi*0.85,"[Esc]退出   [A]关于");

	do {
		//读取图片
		PIMAGE pimg = newimage();
		PIMAGE temps = newimage();

		char str2[100];
		if (n <= num) 
		{
			if (n == num) 
			{
				sprintf(str2, "photos//Myfile_%d.png", n);
				getZoomImage(pimg, str2, 1920, 1080);
				n++;
			} else {
				sprintf(str2, "photos//Myfile_%d.png", n++);
				getZoomImage(pimg, str2, 1920, 1080);
			}
		} 
		else 
		{
			n = 1;
			sprintf(str2, "photos//Myfile_%d.png", n);
			getZoomImage(pimg, str2, 1920, 1080);
			n++;
		}
		if (n <= num) 
		{
			if (n == num) {
				sprintf(str2, "photos//Myfile_%d.png", n);
				getZoomImage(temps, str2, 1920, 1080);
				n++;
			} else 
			{
				sprintf(str2, "photos//Myfile_%d.png", n++);
				getZoomImage(temps, str2, 1920, 1080);
			}

		} 
		else 
		{
			n = 1;
			sprintf(str2, "photos//Myfile_%d.png", n);
			getZoomImage(temps, str2, 1920, 1080);
			n++;
		}
		if (0 == strcmp(str2, "photos//Myfile_4.png")) 
		{
			sprintf(str2, "photos//Myfile_%d.png", 1);
			getZoomImage(temps, str2, 1920, 1080);
		}
		
		
		
		for (int i = 0; i <= 255 && is_running == 1; i++, delay_fps(30)) 
		{
			//图片渐变
			putimage_alphablend(pimg, temps, 0, 0, i, 0, 0, 1920, 1080);
			putimage(0, 0, pimg);
			text(str);
			setfont(hi/30, 0, "黑体");
			xyprintf(wi/10,hi*0.85,"[Esc]退出   [A]关于");
			
			
			    //move用于判断移动状态：向左(1)/向右(0)
				if(x2<=1655&&move==0)
				{
					x2 += 5;
					Rectangle_withalpha(x2,y2,75,50);
					
					
					
				}
				else
				{
					if(x2==1660&&move==0)
					{
						move = 1;
					}
					if(x2==1400&&move==1)
					{
						move = 0;
					}
					x2 -= 5;
					Rectangle_withalpha(x2,y2,50,50);
					
					
					
				}
				
			
				//按键检测
				if (keystate(key_esc)) 
				{
					is_running = 0;
					closegraph();
				}
				if (keystate(key_A)) 
				{
					//作者声明
					setfillcolor(EGEARGB(100,255,255,255));
					ege_fillrect(wi/5*2,hi*0.25,wi/5,hi/2);
					setfont(hi/25, 0, "黑体");
					xyprintf(wi/5*2+wi/60,hi*0.27,"关于");
					setfont(hi/40,0,"黑体");
					xyprintf(wi/5*2+wi/60,hi*0.375,"关于本软件");
					setfont(hi/50,0,"黑体");
					outtextrect(wi/5*2+wi/60,hi*0.4,wi/5.5,hi/3,
					"软件名称：青荷屏保\nGithub:见“README.md”\n或“帮助文档”\n复制、修改、传播本软件\n或其源码须标明原作者");
					setfont(hi/40,0,"黑体");
					xyprintf(wi/5*2+wi/60,hi*0.55,"关于作者");
					setfont(hi/50,0,"黑体");
					outtextrect(wi/5*2+wi/60,hi*0.575,wi/5.5,hi/3,
					"作者：哈士猿\nGithub:ProgramDog404");
				}
			
		
		}

		delimage(pimg);
		delimage(temps);
		n--;

	} while (is_run()&&is_running == 1);
	getch();
	return 0;
}

