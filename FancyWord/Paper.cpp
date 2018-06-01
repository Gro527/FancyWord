#include "FancyWord.h"

Paper::Paper(QWidget * parent) : QMdiSubWindow(parent)
{
	DocHead = NULL;
	setAttribute(Qt::WA_DeleteOnClose);
	setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
	//hide();
}

void Paper::newFile()
{
	static int winNum = 1;    //���ô��ڱ��
	Doc = new Document();
	isChanged = true;
	this->FileLoc = tr("Untitled%1.fcw").arg(winNum++); //��ʾ����Ϊδ����+���
	QWidget::setWindowTitle(FileLoc + "[*]" + tr("-FancyWord"));//���ô��ڱ���
	QObject::connect(this, SIGNAL(textChanged()), this, SLOT(showTextChanged()));   //���ı��ı�ʱ����ʾ[*����Ϊ�ı��ʶ��
}

void Paper::openFile(QString filename)
{
	Doc = new Document(filename);
	isChanged = false;
	this->FileLoc = filename;
	QWidget::setWindowTitle(FileLoc + "[*]" + tr("-FancyWord"));//���ô��ڱ���
	DocHead = Doc->decode();			//�����ļ��������ڴ�
	TextPara *	tpp = DocHead;				//����ʱָ������ڴ���������������
	while (!tpp->isEnd())
	{
		CreateLine(tpp);
		tpp = tpp->getNextPara();
	}//
	tpp = DocHead;
	QObject::connect(this, SIGNAL(textChanged()), this, SLOT(showTextChanged()));   //���ı��ı�ʱ����ʾ[*����Ϊ�ı��ʶ��
	QPainter painter(this);
	repaint();
	//update();
	/*
	Line * lp = tpp->getStartLine();
	TextContainer * tctrp = lp->getstartCtr();
	TextChar * tcp = lp->getStartChar();
	int Num_Char = 0;
	while (!tpp->isEnd())
	{
		while (lp->getNxtLine() != NULL)
		{
			while (tctrp->getNextCtr() != NULL)
			{
				while (tcp->getNext() != NULL)
				{
					painter.setPen(font0.getPen());
					painter.drawText(100, 100, tcp->getch());
					tcp = tcp->getNext();
					Num_Char++;
					if (Num_Char == lp->getNum_Char())  break;
				}
				if (Num_Char == lp->getNum_Char())  break;
				tctrp = tctrp->getNextCtr();
			}
			lp = lp->getNxtLine();
			Num_Char = 0;
		}
		tpp = tpp->getNextPara();
	}
	*/
}

int Paper::save()
{
	return 0;
}

int Paper::saveas()
{
	return 0;
}

void Paper::initScreen()
{
}

void Paper::refreshScreen()
{

}

QString Paper::getFileLoc()
{
	return FileLoc;  
}

Document * Paper::getDoc()
{
	return Doc;
}

void Paper::showTextChanged()
{

}

void Paper::CreateLine(TextPara * Para)//��Para�ο�ʼ����Line
{
	TextPara* curPara = Para;//��ǰ��
	TextContainer * curCtr;//��ǰ����
	TextChar * curCh;//��ǰ�ַ�
	while (!curPara->isEnd())
	{
		curCtr = curPara->getStartCtr();
		curCh = curCtr->getStartCh();
		curPara->newStartLine(curCtr, curCh);
		Line * currentLine = curPara->getStartLine();
		while (curCtr->getNextCtr() != NULL)
		{
			if (curCh->getch() == '\0')                                                      //curCh���ﵱǰ�����ײ�����������������û�����������
			{
				curCtr = curCtr->getNextCtr();
				if (curCtr->getNextCtr() != NULL)
				{
					curCh = curCtr->getStartCh();
					continue;
				}
				else
				{
					break;
				}
			}
			QFontInfo info1(curCtr->getFont());
			if (currentLine->getRestLen() > (0.5) * (info1.pixelSize()))//�����ǰLine�����㹻���ȣ���������
			{
				currentLine->setRestLen(info1.pixelSize());
				curCh = curCh->getNext();
			}
			else                                                           //�ռ䲻�㣬�¿�һ��
			{
				Line * newLine = new Line(curCtr, curCh);
				currentLine->setNxtLine(newLine);
				currentLine = currentLine->getNxtLine();
			}
		}
		currentLine->setNxtLine(NULL);
	//	delete currentLine;
		curPara = curPara->getNextPara();
	}
}

void Paper::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	/*
	FancyFont font0;
	
	//painter.drawLine(QLine(120, 70, 120, 90));
	painter.drawLine(QLine(100, 120, 600, 120));
	painter.setFont(font0);
	painter.setPen(font0.getPen());
	*/

	if (DocHead != NULL && DocHead->getStartLine() != NULL)
	{
		int startx = widthOfWindow / 10;
		int x = startx;
		int y = 120;
		TextPara * tpp = DocHead;
		Line * lp = tpp->getStartLine();
		TextContainer * tctrp = lp->getstartCtr();
		TextChar * tcp = lp->getStartChar();
		int Num_Char = 0;
		while (!tpp->isEnd())
		{
			lp = tpp->getStartLine();
			tctrp = lp->getstartCtr();
			tcp = lp->getStartChar();
			while (lp != NULL)
			{
				while (tctrp->getNextCtr() != NULL)
				{
					while (tcp->getNext() != NULL)
					{
						font0 = tctrp->getFont();
						font0.setBold(tcp->getbolded());
						font0.setItalic(tcp->getitaliced());
						font0.setUnderline(tcp->getunderlined());
						painter.setFont(font0);
						painter.setPen(font0.getPen());
						painter.drawText(x, y, tcp->getch());
						x += font0.pixelSize();
						tcp = tcp->getNext();
						Num_Char++;
						if (Num_Char == lp->getNum_Char())  break;
					}
					if (Num_Char == lp->getNum_Char())  break;
					if (tcp == tctrp->getFinalCh())
					{
						tctrp = tctrp->getNextCtr();
						tcp = tctrp->getStartCh();
						continue;
					}
				}
				lp = lp->getNxtLine();
				x = startx;
				y += 2 * font0.pixelSize();
				Num_Char = 0;
			}
			tpp = tpp->getNextPara();
		}
	}
}
  