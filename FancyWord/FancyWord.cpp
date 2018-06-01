#include "FancyWord.h"

FancyFont font0;

TextContainer::TextContainer(TextContainer * TC) {
	this->setFont(TC->getFont());


}

TextContainer::TextContainer() {
	nextCtr = NULL;
}

QColor TextContainer::getColor()
{
	return color;
}

FancyFont TextContainer::getFont()
{
	return font;
}

void TextContainer::setFont(SpecialFontInfo sfi)
{
	FancyFont font0;
	FancyFont font = font0;
	font.setBold(sfi.bold);
	font.setUnderline(sfi.underline);
	font.setItalic(sfi.italic);
}

void TextContainer::setFont(FancyFont)
{
	font = font0;
}

TextChar * TextContainer::getStartCh()
{
	return startCh;
}

TextChar * TextContainer::getFinalCh()
{
	return finalCh;
}

void TextContainer::setStartCh(TextChar * a)
{
	startCh = a;
}

void TextContainer::setFinalCh(TextChar * a)
{
	finalCh = a;
}

TextContainer * TextContainer::getNextCtr()
{
	return nextCtr;
}

void TextContainer::setNextCtr(TextContainer *a)
{
	nextCtr = a;
}

int TextContainer::getLength()
{
	return len;
}

void TextContainer::setLength()
{
	len = (finalCh - startCh + 1);//????
}

TextContainer* TextContainer::seperateContainer(TextContainer * TC, TextChar * ch)
{
	TextContainer * ctr = new TextContainer(TC);
	ctr->setFont(TC->getFont());
	TextContainer * tmp = TC->nextCtr;
	TextChar * ptr = ch;
	TextChar * str = new TextChar;
	TextChar * cur = str;
	str->setch(ptr->getch());
	ptr = ptr->getNext();
	while (ptr)
	{
		str->newNext();
		str = str->getNext();
		str->setch(ptr->getch());

		ptr = ptr->getNext();
	}
	str->setNext(NULL);
	TC->setStartCh(cur);


	ptr = TC->getStartCh();
	while (ptr->getNext() != ch)
	{
		ptr = ptr->getNext();
	}
	ptr->setNext(NULL);

	TC->nextCtr = ctr;
	ctr->nextCtr = tmp;
	return ctr;
}








void FancyFont::setColor(QColor c)
{
	color = c;
	pen.setColor(c);
}

QColor FancyFont::getColor()
{
	return color;
}

QPen FancyFont::getPen()
{
	return pen;
}

TextChar * TextChar::getNext()
{
	return next;
}

QChar TextChar::getChar()
{
	return ch;
}

void TextChar::putChar(QChar chr)
{
	ch = chr;
}

void TextChar::setNext(TextChar * ch)
{
	next = ch;
}

void TextChar::newNext()
{
		next = new TextChar;
}

void TextChar::setch(QChar ah)
{
	ch = ah;
}

QChar TextChar::getch()
{
	return ch;
}

void TextChar::changeBold()
{
	bold = (bold == 1) ? 0 : 1;
}

void TextChar::changeItalic()
{
	italic = (italic == 1) ? 0 : 1;
}

void TextChar::changeUnderline()
{
	underline = (underline == 1) ? 0 : 1;
}

int TextChar::getbolded()
{
	return bold;
}

int TextChar::getitaliced()
{
	return italic;
}

int TextChar::getunderlined()
{
	return underline;
}

TextChar::TextChar()
{
	ch = NULL;
	bold = 0;
	underline = 0;
	italic = 0;
	next = NULL;
}

Loc TextChar::getLoc()
{
	return location;
}

TextPara::TextPara()
{
	startLine = NULL;
	end = 0;
	interval = 0;
	nextPara = NULL;
}


Line* TextPara::getStartLine()
{
	return startLine;
}

void TextPara::newStartLine(TextContainer * ctr, TextChar * ch)
{
	startLine = new Line(ctr, ch);
}

void TextPara::setStartLine(Line * L)
{
	startLine = L;
}

TextPara * TextPara::getNextPara()
{
	return nextPara;
}

TextContainer * TextPara::getStartCtr()
{
	return startCtr;
}

TextContainer * TextPara::getFinalCtr()
{
	return finalCtr;
}

void TextPara::setStartCtr(TextContainer * a)
{
	startCtr = a;
}

void TextPara::setFinalCtr(TextContainer * a)
{
	finalCtr = a;
}

void TextPara::paintPara()
{
	TextContainer * ctr = startCtr;
	Loc location;
	while (ctr != finalCtr) {
		TextChar * ch = ctr->getStartCh();
		int size = (ctr->getFont()).pointSize();
		QPen pe;
		QPainter painter;
		pe.setColor((ctr->getFont()).getColor());
		painter.setFont(ctr->getFont());
		painter.setPen(pe);
		while (ch->getChar() != NULL) {
			painter.drawText(location.x, location.y, ch->getChar());
			location.x += size;
			ch = ch->getNext();
		}
		location.y += size;
		location.x = 0;
		ctr = ctr->getNextCtr();
	}
}

void TextPara::setNextPara(TextPara * para)
{
	nextPara = para;
}

int TextPara::isEnd()
{
	return end;
}

void TextPara::setAsEnd()
{
	end = 1;
}

Loc::Loc()
{
	x = 0;
	y = 0;
}

void Loc::move2Right(int a)
{
	x += a;
}

void Loc::moveDown(int a)
{
	y += a;
}
