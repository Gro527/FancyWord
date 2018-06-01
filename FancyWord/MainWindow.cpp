#include "FancyWord.h"
#include "qfiledialog.h"

int widthOfWindow;

FancyWord::FancyWord(QWidget *parent)			//��������һЩ��������
	: QMainWindow(parent)
{
	ui->setupUi(this);
	this->setMinimumSize(800, 600);
	widthOfWindow = ui->centralWidget->geometry().width();
	ui->mdiArea->setViewMode(QMdiArea::TabbedView);
	ui->mdiArea->setTabsMovable(true);
}
/*
void FancyWord::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	QFont font("SimHei");
	font.setPointSize(20);
	QPen pe;
	pe.setColor(QColor(0xff0000));
	painter.setPen(pe);
	painter.setFont(font);
	painter.drawText(100, 100, "hello world");
	addPaper();
}


void FancyWord::addPaper()
{

	Paper *p = new Paper(this);
	p->setStyleSheet("background-color:white;");
	p->setGeometry(0, 0, 500, 500);
	p->show();
}
*/



void FancyWord::on_actionnew_triggered()
{
	Paper * p = new Paper();
	p->newFile();
	ui->mdiArea->addSubWindow(p);
	p->show();
}


//slots

void FancyWord::resizeEvent(QResizeEvent * size)			
{
	ui->mdiArea->resize(frameGeometry().size());
	widthOfWindow = ui->centralWidget->geometry().width();
}


QMdiSubWindow * FancyWord::FindSubWindow(QString fileName)
{
	QString canonicalFilePath = QFileInfo(fileName).canonicalFilePath();

	// ����foreach�������Ӵ����б�������ļ�·����Ҫ���ҵ�·����ͬ���򷵻ظô���
	foreach(QMdiSubWindow *window, ui->mdiArea->subWindowList()) {
		Paper * p = qobject_cast<Paper *>(window->widget());
		if (p->getFileLoc() == canonicalFilePath)
			return window;
	}
	return 0;
}

Paper * FancyWord::activePaper()
{
	//����л���ڣ��򷵻����ڵ�Paperָ��
	if (QMdiSubWindow * activeSubWindow = ui->mdiArea->activeSubWindow())
		return qobject_cast<Paper *>(activeSubWindow->widget());
	return 0;
}

int FancyWord::file_opened(QString filename)		//����ļ��Ѵ򿪹� ����1.
{
	using namespace std;
	vector<QString>::iterator it;
	for (it = openFiles.begin(); it != openFiles.end(); it++)
		if (!filename.compare(*it))
			return 1;
	return 0;
}


void FancyWord::on_actionopen_triggered()
{
	QString fileName = QFileDialog::getOpenFileName(this);  //ͨ���Ի�����ļ�
	if (file_opened(fileName)) {				//�ж��ļ��Ƿ��Ѵ�
		ui->mdiArea->setActiveSubWindow(FindSubWindow(fileName));				//****�Ҳ���
		return;
	}
	Paper * p = new Paper();
	p->openFile(fileName);
	openFiles.push_back(fileName);
	ui->statusBar->showMessage("�ļ��򿪳ɹ�", 2000);
	ui->mdiArea->addSubWindow(p);
	p->refreshScreen();
	p->show();
}

void FancyWord::on_actionClose_C_triggered()
{
	ui->mdiArea->closeActiveSubWindow();
}

void FancyWord::on_actionSave_S_triggered()
{
	if (activePaper()->save())	ui->statusBar->showMessage("Save Successfully", 2000);
}

void FancyWord::on_actionSave_As_A_triggered()
{
	if (activePaper()->saveas())	ui->statusBar->showMessage("Save Successfully", 2000);
}

void FancyWord::on_actionQuit_Q_triggered()
{
	//if (activePaper()->textChanged())
}

void FancyWord::on_actionUndo_U_Ctrl_U_triggered()
{
}

void FancyWord::on_actionRecover_R_Ctrl_R_triggered()
{
}

void FancyWord::on_actionCopy_C_Ctrl_C_triggered()
{
}

void FancyWord::on_actionCut_X_Ctrl_X_triggered()
{
}

void FancyWord::on_actionPaste_P_triggered()
{
}

void FancyWord::on_actionDelete_D_triggered()
{
}

void FancyWord::on_actionSelect_All_A_triggered()
{
}

void FancyWord::on_actionFloat_DesignBar_triggered()
{
}

void FancyWord::on_actionInsert_Toolbar_triggered()
{
}

void FancyWord::on_actionReview_ToolBar_triggered()
{
}

void FancyWord::on_actionTranslate_triggered()
{
}

void FancyWord::on_actionCount_triggered()
{
}

void FancyWord::on_actionAbout_triggered()
{
}

void FancyWord::on_actionVersion_triggered()
{
}
