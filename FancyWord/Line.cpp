#include "Line.h"
#include "ui_FancyWord.h"


Line::Line(TextContainer * ctr, TextChar * ch)
{
	Num_Char = 0;
	setLen(widthOfWindow);
	setStartChar(ch);
	setStartContainer(ctr);
	nextLine = NULL;
}


void Line::setStartChar(TextChar * ch)
{
	start = ch;
}

void Line::setStartContainer(TextContainer * tc)
{
	startCtr = tc;
}

TextChar * Line::getStartChar()
{
	return start;
}

TextContainer * Line::getstartCtr()
{
	return startCtr;
}

int Line::getLen()
{
	return len;
}

void Line::setLen(int Length)
{
	len = Length;
	restLen = Length;
}

int Line::getRestLen()
{
	return restLen;
}

void Line::setRestLen(int decrement)
{
	restLen -= decrement;
	Num_Char++;
}



void Line::setNxtLine(Line *Nxtline)
{
	nextLine = Nxtline;
}

Line* Line::getNxtLine()
{
	return nextLine;
}

int Line::getNum_Char()
{
	return Num_Char;
}
