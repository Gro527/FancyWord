#pragma once
#ifndef _fancyword_h_
#include "ui_FancyWord.h"
#include "MainWindow.h"
#include <fstream>
#include <iostream>
#include <qdir.h>
#include <qtextstream.h>
#include <qmessagebox.h>
#include <qstring.h>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <Line.h>

//集成颜色属性
class FancyFont : public QFont {
public:
	void setColor(QColor);
	QColor getColor();
	QPen getPen();
private:
	QPen pen;			//大小
	QColor color;
};
extern FancyFont font0;

//作为信号传入TextContainer类
class SpecialFontInfo { 
public:
	int bold;
	int underline;
	int italic;
};

class Loc {
public:
	Loc();
	int x;
	int y;
	void move2Right(int a);
	void moveDown(int a);
};

class TextElement;
class TextChar;
class TextContainer;
class TextPara;


class Document {				//该类的生命周期与Paper类相同
public:
	int getReadinfo();
	int getWriteinfo();
	int Init(QString filename);
	Document();				//程序中新建文档时调用此生成函数
	Document(QString filename);		//读取已存在的文档时调用此生成函数
	int changeFont(QString newFont);
	QString getaddress();
	void showLine(QString line, QPainter painter);
	TextPara * decode();		//解码文件，并返回第一个段落的指针
	void save(TextPara * begin);
	void save(TextPara * begin, QString address);
private:
	int isUntitled;			//若为程序中新建的文档，则该项为1.
	int read;
	int write;
	QString address;	
	int SpecialFont(QString str, int &j, TextChar * &final);
	void changeFont(int posb, int posu, int posi, TextChar * final);
	int max3(int a, int b, int c);
	int fontChanged(QString str);
	void putIntoTempFile(TextChar * a);
	void putIntoTempFile(std::string a);
	int isDifferent(FancyFont font, FancyFont curFont);
	std::string getChangedFontInfo(FancyFont font, FancyFont & curFont);
};

class TextElement {

protected:
	TextElement Copy(TextElement);
	TextElement Paste(TextElement);
};

class TextChar : public TextElement {
public:
	TextChar();
	Loc getLoc();
	TextChar * getNext();
	QChar getChar();
	void putChar(QChar chr);
	void setNext(TextChar * ch);
	void newNext();
	void setch(QChar ah);
	QChar getch();
	void changeBold();
	void changeItalic();
	void changeUnderline();
	int getbolded();
	int getitaliced();
	int getunderlined();
private:
	QChar ch;
	TextChar* next;
	Loc location;
	int bold;
	int underline;
	int italic;
};

class TextContainer : public TextElement {
public:
	TextContainer(TextContainer * TC);//根据TC的特性生成一个容器
	TextContainer();
	QColor getColor();
	FancyFont getFont();
	void setFont(SpecialFontInfo);
	void setFont(FancyFont);
	TextChar * getStartCh();//++
	TextChar * getFinalCh();//++
	void setStartCh(TextChar * a);
	void setFinalCh(TextChar * a);
	TextContainer * getNextCtr();
	void setNextCtr(TextContainer * a);
	int getLength();
	void setLength();
	TextContainer * seperateContainer(TextContainer * TC, TextChar * ch);
private:
	TextChar * startCh;
	TextChar * finalCh;
	QColor color;
	FancyFont font;
	TextContainer * nextCtr;
	int len;
protected:
};

class TextPara : public TextContainer {
public:
	TextPara();
	TextPara * getNextPara();
	TextContainer * getStartCtr();
	TextContainer * getFinalCtr();
	void setStartCtr(TextContainer * a);
	void setFinalCtr(TextContainer * a);
	void paintPara();
	void setNextPara(TextPara * para);
	int isEnd();
	void setAsEnd();
	Line * getStartLine();
	void setStartLine(Line * L);
	void newStartLine(TextContainer * ctr, TextChar * ch);
private:
	Line * startLine;
	TextPara * nextPara;
	TextContainer * startCtr;
	TextContainer * finalCtr;
	int interval;
	int end;

protected:
};
class cursor {
public:
	TextChar * getPosition();
	TextChar * setPosition();
	TextContainer getChosenText();
private:
	//TextChar * position;
	TextContainer Chosen;
};


#endif // !fancyword_h_
