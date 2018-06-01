
#pragma once
#include "FancyWord.h"

class TextChar;
class TextContainer;
class TextPara;

class Line {
public:
	Line(TextContainer * ctr, TextChar * ch);

	void setStartChar(TextChar * ch);//设置起始Textchar位置

	void setStartContainer(TextContainer * tc);//设置起始TextCtr位置

	TextChar * getStartChar();

	TextContainer * getstartCtr();

	int getLen();

	void setLen(int Length);

	int getRestLen();

	void setRestLen(int decrement);

	void setNxtLine(Line * nxtline);

	Line * getNxtLine();

	int getNum_Char();
private:
	int len;//Line的
	TextChar * start;//起始Char位置
	TextContainer * startCtr;//其实容器位置
	int restLen;//Line剩余可用长度
	int Num_Char;
	Line * nextLine;//指向下一Line
	Ui::FancyWordClass * ui;
};

