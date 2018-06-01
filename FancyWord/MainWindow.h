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
#include <Paper.h>
#include <vector>

class Paper;
namespace Ui {
	class FancyWord;
}
extern int widthOfWindow;
class FancyWord : public QMainWindow
{
	Q_OBJECT

public:
	FancyWord(QWidget *parent = Q_NULLPTR);
	//void addPaper();
	void resizeEvent(QResizeEvent * size);					//窗口大小改变时的事件
	QMdiSubWindow * FindSubWindow(QString fileName);		//根据文件路径寻找所在窗口
	Paper * activePaper();						//当前活动的页面
	int file_opened(QString filename);			//调用actionopen时调用，检查文件是否已打开。

private:
	Ui::FancyWordClass *ui;
	QMdiSubWindow * paper;
	std::vector <QString> openFiles;
private slots:
//protected:
	//Paper * createNewPaper();
	//void paintEvent(QPaintEvent *);
void on_actionnew_triggered();
void on_actionopen_triggered();
void on_actionClose_C_triggered();
void on_actionSave_S_triggered();
void on_actionSave_As_A_triggered();
void on_actionQuit_Q_triggered();
void on_actionUndo_U_Ctrl_U_triggered();
void on_actionRecover_R_Ctrl_R_triggered();
void on_actionCopy_C_Ctrl_C_triggered();
void on_actionCut_X_Ctrl_X_triggered();
void on_actionPaste_P_triggered();
void on_actionDelete_D_triggered();
void on_actionSelect_All_A_triggered();
void on_actionFloat_DesignBar_triggered();
void on_actionInsert_Toolbar_triggered();
void on_actionReview_ToolBar_triggered();
void on_actionTranslate_triggered();
void on_actionCount_triggered();
void on_actionAbout_triggered();
void on_actionVersion_triggered();
};

class MenuBar : public QWidget
{

};

class ToolBar : public QWidget
{

};

class MainBack : public QWidget
{

};
