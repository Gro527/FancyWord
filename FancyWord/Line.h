
#pragma once
#include "FancyWord.h"

class TextChar;
class TextContainer;
class TextPara;

class Line {
public:
	Line(TextContainer * ctr, TextChar * ch);

	void setStartChar(TextChar * ch);//������ʼTextcharλ��

	void setStartContainer(TextContainer * tc);//������ʼTextCtrλ��

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
	int len;//Line��
	TextChar * start;//��ʼCharλ��
	TextContainer * startCtr;//��ʵ����λ��
	int restLen;//Lineʣ����ó���
	int Num_Char;
	Line * nextLine;//ָ����һLine
	Ui::FancyWordClass * ui;
};

