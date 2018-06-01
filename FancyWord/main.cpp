#include <QtWidgets/QApplication>
#include <FancyWord.h>
#include <qtextcodec.h>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FancyWord w;
	//Document d1("C:\\Users\\hasee\\Desktop\\sample.fcw");
	//d1.Init(d1.getaddress());
	//TextPara * passage;
	//passage = d1.decode();
	//QMessageBox b;
	//b.setText(passage->getStartCtr()->getStartCh()->getChar());
	//b.show();
	w.show();
	return a.exec();
} 
