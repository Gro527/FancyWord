#pragma once

#include <QtWidgets/QMainWindow>
#include <qpainter.h>
#include <qfont.h>
#include "ui_FancyWord.h"
#include <qpalette.h>
#include <qlabel.h>
#include <QtWidgets\qwidget.h>
#include <qmdisubwindow.h>
#include <qmdiarea.h>
#include <MainWindow.h>
#include <FancyWord.h>

class Document;
class TextContainer;
class TextChar;
class TextPara;
class Line;


class Paper : public QMdiSubWindow			//�Ӵ����ֱ࣬�Ӷ������������ã��ĵ����Ա�����Doc��
{
	Q_OBJECT
public:
	Paper(QWidget * parent = 0);
	void newFile();
	void openFile(QString filename);			//����filenameΪ�ⲿ�ӿ�
	int save();
	int saveas();
	void initScreen();
	void refreshScreen();
	void CreateLine(TextPara * Para);
	QString getFileLoc();
	Document * getDoc();
signals:
	void textChanged();
public slots:
	void showTextChanged();
protected:
	void paintEvent(QPaintEvent *);
private:
	Document * Doc;
	TextPara * DocHead;
	bool isChanged;
	QString FileLoc;
};




