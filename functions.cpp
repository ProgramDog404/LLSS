#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>


void getZoomImage(PIMAGE pimg, const char* fileName, int width, int height) { 
	/*来自依稀_yixy的CSDN博客
	https://blog.csdn.net/qq_39151563/article/details/104342530*/
	if (pimg == NULL)
		return;

	PIMAGE temp = newimage();
	getimage(temp, fileName);

	if ((getwidth(pimg) != width) || (getheight(pimg) != height))
		resize(pimg, width, height);

	putimage(pimg, 0, 0, width, height, temp, 0, 0, getwidth(temp), getheight(temp));
	delimage(temp);

}
int statistics() {	//来自聪明绝顶的ChatGPT
	char folderPath[100] = "photos";
	DIR *folder;
	struct dirent *entry;
	int count = 0;
	folder = opendir(folderPath);
	if (folder == NULL) {
		printf("无法打开文件夹\n");
		return 1;
	}

	while ((entry = readdir(folder)) != NULL) {
		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
			continue;
		}
		count++;
	}
	closedir(folder);
	return count;
}
void text(char* ch) {
	int H = getheight();
	int W = getwidth();
	setfont(H / 12, 0, "黑体");
	setcolor(WHITE);
	setbkmode(TRANSPARENT);			//设置文字背景色为透明
	settextjustify(LEFT_TEXT, TOP_TEXT);
	xyprintf(W / 10, H * 0.75, ch);
}
void Rectangle_withalpha(float x, float y, float width, float height) {
  setfillcolor(EGEACOLOR(100, WHITE));
  ege_fillrect(x, y, width, height);
  return;
}
