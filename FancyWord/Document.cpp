#include "FancyWord.h"


/*
Document::Document(char * filename)
{
	using namespace std;
	fstream In;
	char buffer[256];
	In.open(filename, ios::in | ios::out);
	while (!In.eof())
	{
		In.getline(buffer, 100);
		for (int i = 0; i < 100; i++)
		{
			if (buffer[i] == 'd'&&buffer[i + 1] == ' '&&buffer[i + 2] == '=')
			{
				read = buffer[i + 4] - '0';
			}
			if (buffer[i] == 'e'&&buffer[i + 1] == ' '&&buffer[i + 2] == '=')
			{
				read = buffer[i + 4] - '0';
			}
		}
	}

	if (read == 0 && write == 0)
	{
		cout << "No Authority" << endl;
	}
	else if (read == 1 && write == 0)
	{
		address = filename;
		cout << "It's an Read Only file" << endl;
	}
	else if (read == 1 && write == 1)
	{
		address = filename;
	}
	In.close();
}
*/

int Document::Init(QString filename)
{
	QMessageBox b1;
	b1.setStandardButtons(QMessageBox::Yes);
	QFile f(filename);
	if (f.open(QIODevice::ReadWrite) == false)
	{
		b1.setText("Warning: Cannot open file!");
		b1.show();
		b1.exec();
	}
	QTextStream tsin(&f);
	QString info = tsin.readLine();
	return 0;
}

Document::Document()
{
	isUntitled = 1;
	read = 1;
	write = 1;
	address = "";
}

Document::Document(QString filename)
{
	QMessageBox b1;
	b1.setStandardButtons(QMessageBox::Yes);
	//FancyWord w;
	QFile f(filename);
	if (f.open(QIODevice::ReadWrite) == false) 
	{
		b1.setText("Warning: Cannot open file!");
		b1.show();
		b1.exec();
	}
	else
	{
		b1.setText("Open file successfully.");
		b1.show();
		b1.exec();
	}
	address = filename;
	f.close();

}

int Document::changeFont(QString info1)
{
	FancyFont font0;
	std::string info = info1.toStdString();
	int changed = 0;
	int loc = 0;
	//要确保文本中font size color严格排序
	if (info.find("font:"))
	{
		loc = info.find("font:");
		std::string font = info.substr(loc + 6, info.find(">"));
		info.erase(0, info.find(">") + 1);
		font0.setFamily(QString::fromStdString(font));
		changed++;
	}
	if (info.find("size:")) {
		loc = info.find("size:");
		std::string size = info.substr(loc + 6, info.find(">"));
		int sizei = std::stoi(size, 0, 10);
		info.erase(0, info.find(">") + 1);
		font0.setPointSize(sizei);
		changed++;
	}
	if (info.find("color:")) {
		loc = info.find("color:");
		std::string colorr = info.substr(loc + 7, 2);
		std::string colorg = info.substr(loc + 9, 2);
		std::string colorb = info.substr(loc + 11, 2);
		int colorri = std::stoi(colorr, 0, 16);
		int colorgi = std::stoi(colorg, 0, 16);
		int colorbi = std::stoi(colorb, 0, 16);

		info.erase(0, info.find(">") + 1);
		font0.setColor(QColor(colorri, colorgi, colorbi));
		changed++;
	}
	return changed;
}

QString Document::getaddress()
{
	return address;
}

void Document::showLine(QString line, QPainter painter)
{
	
}

TextPara * Document::decode()
{
	FancyFont font0;
	QFile f(address);
	f.open(QIODevice::ReadWrite);
	QTextStream tsin(&f);
	QString psg = tsin.readAll();
	TextPara * begin = new TextPara;
	TextPara * end = begin;
	QStringList paralist = psg.split("/par/");
	for (int i = 0; i < paralist.size(); i++) {//for each para
		QStringList ctrlist = paralist[i].split("||", QString::SkipEmptyParts);
		TextContainer *finalCtr, *startCtr;
		startCtr = new TextContainer;
		finalCtr = startCtr;
		for (int j = 0; j < ctrlist.size(); j++) {//for each "||"
			if (fontChanged(ctrlist[j])) {
				if (j != 0) {
					TextContainer * tempCtr = new TextContainer;
					finalCtr->setNextCtr(tempCtr);
					finalCtr = finalCtr->getNextCtr();
				}
				finalCtr->setFont(font0);
			}
			else {
				//生成Char链表
				TextChar * finalCh, *startCh;
				startCh = new TextChar;
				finalCh = startCh;
				QString str = ctrlist[j];
				for (int k = 0; k < str.length(); k++) {
					QString _str = str[k];
					QByteArray ba = _str.toLatin1();
					char *ch = ba.data();
					if (ch[0] == '\r')
						k += 2;
					if (str[k] == "/")
						k++;
					else if (str[k] == "{") {
						SpecialFont(str, k, finalCh);
					}
					if (k >= str.length())
						break;
					finalCh->putChar(str[k]);
					putIntoTempFile(finalCh);
					TextChar * tempCh = new TextChar;
					finalCh->setNext(tempCh);
					finalCh = finalCh->getNext();
				}
				finalCtr->setFinalCh(finalCh);
				finalCtr->setStartCh(startCh);
				finalCtr->setFont(font0);
			}
		}
		TextContainer * tempCtr = new TextContainer;
		finalCtr->setNextCtr(tempCtr);
		finalCtr = finalCtr->getNextCtr();
		putIntoTempFile("\n");
		end->setFinalCtr(finalCtr);
		end->setStartCtr(startCtr);
		TextPara * tempPara = new TextPara;
		end->setNextPara(tempPara);
		end = end->getNextPara();
	}
	end->setAsEnd();
	return begin;
}

void Document::save(TextPara * begin)
{
	std::ofstream file;
	std::string address_t = address.toStdString();
	FancyFont curFont;
	TextPara * para = begin;
	file.open(address_t, std::ios::out || std::ios::trunc);
	while (!para->isEnd()) {
		TextContainer * ctr = para->getStartCtr();
		FancyFont font = ctr->getFont();
		if (isDifferent(font, curFont)) {
			std::string info = getChangedFontInfo(font, curFont);
			file << info << "\n";
		}
		while (ctr->getNextCtr() != NULL) {
			TextChar * ch = ctr->getStartCh();
			while (ch->getNext() != NULL) {
				QChar qch = ch->getChar();
				char chr = qch.unicode();
				file << chr;
				ch = ch->getNext();
			}
			file << "\n";
			ctr = ctr->getNextCtr();
		}
		file << "/par/";
		para = para->getNextPara();
	}
}

void Document::save(TextPara * begin, QString address)
{
	std::ofstream file;
	std::string address_t = address.toStdString();
	FancyFont curFont;
	TextPara * para = begin;
	file.open(address_t, std::ios::out || std::ios::trunc);
	while (!para->isEnd()) {
		TextContainer * ctr = para->getStartCtr();
		FancyFont font = ctr->getFont();
		if (isDifferent(font, curFont)) {
			std::string info = getChangedFontInfo(font, curFont);
			file << info << "\n";
		}
		while (ctr->getNextCtr() != NULL) {
			TextChar * ch = ctr->getStartCh();
			while (ch->getNext() != NULL) {
				QChar qch = ch->getChar();
				char chr = qch.unicode();
				file << chr;
				ch = ch->getNext();
			}
			file << "\n";
			ctr = ctr->getNextCtr();
		}
		file << "/par/";
		para = para->getNextPara();
	}
}

int Document::SpecialFont(QString str, int & j, TextChar *& finalCh)
{
	int end = str.indexOf("}", j);
	int posb = str.indexOf("/b", j);
	int posu = str.indexOf("/u", j);
	int posi = str.indexOf("/i", j);
	if (posb > end) posb = -1;
	if (posu > end) posu = -1;
	if (posi > end) posi = -1;
	int changed = max3(posb, posu, posi);
	if (changed) {
		for (int i = changed + 3; i < end; i++) {
			finalCh->putChar(str[i]);
			putIntoTempFile(finalCh);
			TextChar * tempCh = new TextChar;
			finalCh->setNext(tempCh);
			finalCh = finalCh->getNext();
		}
		j = end + 1;
		return 1;
	}
	else {
		QMessageBox b1;
		b1.setText("Warning: The file is broken!");
		b1.show();
		b1.exec();
		return -1;
	}
}

void Document::changeFont(int posb, int posu, int posi, TextChar * final)
{
	if (posb > 0)
		final->changeBold();
	if (posu > 0)
		final->changeUnderline();
	if (posi > 0)
		final->changeItalic();
}

int Document::max3(int a, int b, int c)
{
	int max = a;
	if (b > max)
		max = b;
	if (c > max)
		max = c;
	return max;
}

int Document::fontChanged(QString str)
{
	int posft = str.indexOf("font:<");
	int possz = str.indexOf("size:<");
	int posclr = str.indexOf("color:<");
	int changed = 0;
	if (posft >= 0) {
		QString font = str.mid(posft + 6, str.indexOf(">", posft));
		font0.setFamily(font);
		changed++;
	}
	if (possz >= 0) {
		int length = str.indexOf(">", possz) - possz - 6;
		QString sizestr = str.mid(possz + 6, length);
		int size = sizestr.toInt();
		if (size > 0) {
			font0.setPixelSize(size);
			changed++;
		}
	}
	if (posclr >= 0) {
		QString clr = str.mid(posclr + 7, 7);
		if (QString::compare("#FFFFFF", clr, Qt::CaseInsensitive) >= 0 && QString::compare("#000000", clr, Qt::CaseInsensitive) <= 0) {
			font0.setColor(QColor(clr));
			changed++;
		}
	}
	if (changed)
		return 1;
	return 0;
}

void Document::putIntoTempFile(TextChar * a)
{
	using namespace std;
	ofstream file;
	string address_t = address.toStdString();
	address_t.insert(address_t.find(".fcw") + 1, "~");
	file.open(address_t, std::ios::app | std::ios::out);
	QChar qch = a->getChar();
	char ch = qch.unicode();
	file << ch;
	file.close();
}

void Document::putIntoTempFile(std::string a)
{
	using namespace std;
	ofstream file;
	string address_t = address.toStdString();
	address_t.insert(address_t.find(".fcw") + 1, "~");
	file.open(address_t, std::ios::app | std::ios::out);
	file << a;
	file.close();
}

int Document::isDifferent(FancyFont font, FancyFont curFont)
{
	QFontInfo info(font);
	QFontInfo infoc(curFont);
	if (font.getColor() == curFont.getColor() && info.family().toStdString() == infoc.family().toStdString() && info.pixelSize() == infoc.pixelSize())
		return 0;
	return 1;
}

std::string Document::getChangedFontInfo(FancyFont font, FancyFont & curFont)
{
	QFontInfo info(font);
	QFontInfo infoc(curFont);
	std::string information;
	information += "||";
	int changed = 0;
	if (info.family().toStdString() != infoc.family().toStdString()) {
		information = information + "font:<" + info.family().toStdString() + "> ";
		changed++;
	}
	if (info.pixelSize() != infoc.pixelSize()) {
		information = information + "size:<" + std::to_string(info.pixelSize()) + "> ";
		changed++;
	}
	if (font.getColor() != curFont.getColor()) {
		QColor color = font.getColor();
		QString clr_q;
		clr_q.sprintf("#%1%02X%02X%02X", color.red(), color.green(), color.blue()).arg(color.alpha() != 255 ? QString().sprintf("%02X", color.alpha()) : QString());
		std::string clr = clr_q.toStdString();
		information = information + "color:<" + clr + ">";
	}
	information += "||";
	if (changed) {
		curFont = font;
	}
	return information;
}



