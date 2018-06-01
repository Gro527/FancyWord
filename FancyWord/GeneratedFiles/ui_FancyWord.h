/********************************************************************************
** Form generated from reading UI file 'FancyWord.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FANCYWORD_H
#define UI_FANCYWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FancyWordClass
{
public:
    QAction *actionnew;
    QAction *actionopen;
    QAction *actionClose_C;
    QAction *actionSave_S;
    QAction *actionSave_As_A;
    QAction *actionQuit_Q;
    QAction *actionUndo_U_Ctrl_U;
    QAction *actionRecover_R_Ctrl_R;
    QAction *actionCopy_C_Ctrl_C;
    QAction *actionCut_X_Ctrl_X;
    QAction *actionPaste_P;
    QAction *actionDelete_D;
    QAction *actionSelect_All_A;
    QAction *actionFloat_DesignBar;
    QAction *actionInsert_Toolbar;
    QAction *actionReview_ToolBar;
    QAction *actionEditArea_Size;
    QAction *actionTranslate;
    QAction *actionCount;
    QAction *actionAbout;
    QAction *actionVersion;
    QAction *FontType;
    QWidget *centralWidget;
    QMdiArea *mdiArea;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menuHelp;
    QToolBar *toolBar;

    void setupUi(QMainWindow *FancyWordClass)
    {
        if (FancyWordClass->objectName().isEmpty())
            FancyWordClass->setObjectName(QStringLiteral("FancyWordClass"));
        FancyWordClass->resize(1004, 760);
        actionnew = new QAction(FancyWordClass);
        actionnew->setObjectName(QStringLiteral("actionnew"));
        actionopen = new QAction(FancyWordClass);
        actionopen->setObjectName(QStringLiteral("actionopen"));
        actionClose_C = new QAction(FancyWordClass);
        actionClose_C->setObjectName(QStringLiteral("actionClose_C"));
        actionSave_S = new QAction(FancyWordClass);
        actionSave_S->setObjectName(QStringLiteral("actionSave_S"));
        actionSave_As_A = new QAction(FancyWordClass);
        actionSave_As_A->setObjectName(QStringLiteral("actionSave_As_A"));
        actionQuit_Q = new QAction(FancyWordClass);
        actionQuit_Q->setObjectName(QStringLiteral("actionQuit_Q"));
        actionUndo_U_Ctrl_U = new QAction(FancyWordClass);
        actionUndo_U_Ctrl_U->setObjectName(QStringLiteral("actionUndo_U_Ctrl_U"));
        actionRecover_R_Ctrl_R = new QAction(FancyWordClass);
        actionRecover_R_Ctrl_R->setObjectName(QStringLiteral("actionRecover_R_Ctrl_R"));
        actionCopy_C_Ctrl_C = new QAction(FancyWordClass);
        actionCopy_C_Ctrl_C->setObjectName(QStringLiteral("actionCopy_C_Ctrl_C"));
        actionCut_X_Ctrl_X = new QAction(FancyWordClass);
        actionCut_X_Ctrl_X->setObjectName(QStringLiteral("actionCut_X_Ctrl_X"));
        actionPaste_P = new QAction(FancyWordClass);
        actionPaste_P->setObjectName(QStringLiteral("actionPaste_P"));
        actionDelete_D = new QAction(FancyWordClass);
        actionDelete_D->setObjectName(QStringLiteral("actionDelete_D"));
        actionSelect_All_A = new QAction(FancyWordClass);
        actionSelect_All_A->setObjectName(QStringLiteral("actionSelect_All_A"));
        actionFloat_DesignBar = new QAction(FancyWordClass);
        actionFloat_DesignBar->setObjectName(QStringLiteral("actionFloat_DesignBar"));
        actionInsert_Toolbar = new QAction(FancyWordClass);
        actionInsert_Toolbar->setObjectName(QStringLiteral("actionInsert_Toolbar"));
        actionReview_ToolBar = new QAction(FancyWordClass);
        actionReview_ToolBar->setObjectName(QStringLiteral("actionReview_ToolBar"));
        actionEditArea_Size = new QAction(FancyWordClass);
        actionEditArea_Size->setObjectName(QStringLiteral("actionEditArea_Size"));
        actionTranslate = new QAction(FancyWordClass);
        actionTranslate->setObjectName(QStringLiteral("actionTranslate"));
        actionCount = new QAction(FancyWordClass);
        actionCount->setObjectName(QStringLiteral("actionCount"));
        actionAbout = new QAction(FancyWordClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionVersion = new QAction(FancyWordClass);
        actionVersion->setObjectName(QStringLiteral("actionVersion"));
        FontType = new QAction(FancyWordClass);
        FontType->setObjectName(QStringLiteral("FontType"));
        FontType->setMenuRole(QAction::TextHeuristicRole);
        centralWidget = new QWidget(FancyWordClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));
        mdiArea->setGeometry(QRect(0, 0, 1011, 711));
        mdiArea->setTabsClosable(true);
        mdiArea->setTabsMovable(true);
        mdiArea->setTabShape(QTabWidget::Rounded);
        FancyWordClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(FancyWordClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FancyWordClass->setStatusBar(statusBar);
        menuBar = new QMenuBar(FancyWordClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1004, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        FancyWordClass->setMenuBar(menuBar);
        toolBar = new QToolBar(FancyWordClass);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(true);
        FancyWordClass->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionnew);
        menuFile->addAction(actionopen);
        menuFile->addAction(actionClose_C);
        menuFile->addSeparator();
        menuFile->addAction(actionSave_S);
        menuFile->addAction(actionSave_As_A);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit_Q);
        menuEdit->addAction(actionUndo_U_Ctrl_U);
        menuEdit->addAction(actionRecover_R_Ctrl_R);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCopy_C_Ctrl_C);
        menuEdit->addAction(actionCut_X_Ctrl_X);
        menuEdit->addAction(actionPaste_P);
        menuEdit->addAction(actionDelete_D);
        menuEdit->addSeparator();
        menuEdit->addAction(actionSelect_All_A);
        menuView->addAction(actionInsert_Toolbar);
        menuView->addAction(actionFloat_DesignBar);
        menuView->addAction(actionReview_ToolBar);
        menuView->addAction(actionEditArea_Size);
        menuView->addAction(actionTranslate);
        menuView->addAction(actionCount);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionVersion);
        toolBar->addAction(FontType);

        retranslateUi(FancyWordClass);

        QMetaObject::connectSlotsByName(FancyWordClass);
    } // setupUi

    void retranslateUi(QMainWindow *FancyWordClass)
    {
        FancyWordClass->setWindowTitle(QApplication::translate("FancyWordClass", "FancyWord", nullptr));
        actionnew->setText(QApplication::translate("FancyWordClass", "\346\226\260\345\273\272(N)       Ctrl+N", nullptr));
#ifndef QT_NO_TOOLTIP
        actionnew->setToolTip(QApplication::translate("FancyWordClass", "\346\226\260\345\273\272\346\226\207\344\273\266", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionnew->setShortcut(QApplication::translate("FancyWordClass", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionopen->setText(QApplication::translate("FancyWordClass", "\346\211\223\345\274\200(O)       Ctrl+O", nullptr));
#ifndef QT_NO_TOOLTIP
        actionopen->setToolTip(QApplication::translate("FancyWordClass", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionopen->setShortcut(QApplication::translate("FancyWordClass", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionClose_C->setText(QApplication::translate("FancyWordClass", "\345\205\263\351\227\255(C)", nullptr));
        actionSave_S->setText(QApplication::translate("FancyWordClass", "\344\277\235\345\255\230(S)        Ctrl+S", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSave_S->setToolTip(QApplication::translate("FancyWordClass", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionSave_S->setShortcut(QApplication::translate("FancyWordClass", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave_As_A->setText(QApplication::translate("FancyWordClass", "\345\217\246\345\255\230\344\270\272(A)       ", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSave_As_A->setToolTip(QApplication::translate("FancyWordClass", "\346\226\207\344\273\266\345\217\246\345\255\230\344\270\272", nullptr));
#endif // QT_NO_TOOLTIP
        actionQuit_Q->setText(QApplication::translate("FancyWordClass", "\351\200\200\345\207\272(Q)       ", nullptr));
        actionUndo_U_Ctrl_U->setText(QApplication::translate("FancyWordClass", "\346\222\244\351\224\200(U)       Ctrl+Z", nullptr));
#ifndef QT_NO_TOOLTIP
        actionUndo_U_Ctrl_U->setToolTip(QApplication::translate("FancyWordClass", "\346\222\244\351\224\200\346\223\215\344\275\234", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionUndo_U_Ctrl_U->setShortcut(QApplication::translate("FancyWordClass", "Ctrl+Z", nullptr));
#endif // QT_NO_SHORTCUT
        actionRecover_R_Ctrl_R->setText(QApplication::translate("FancyWordClass", "\350\277\230\345\216\237(R)       Ctrl+R", nullptr));
#ifndef QT_NO_TOOLTIP
        actionRecover_R_Ctrl_R->setToolTip(QApplication::translate("FancyWordClass", "\350\277\230\345\216\237\346\222\244\351\224\200\346\223\215\344\275\234", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionRecover_R_Ctrl_R->setShortcut(QApplication::translate("FancyWordClass", "Ctrl+R", nullptr));
#endif // QT_NO_SHORTCUT
        actionCopy_C_Ctrl_C->setText(QApplication::translate("FancyWordClass", "\345\244\215\345\210\266(C)       Ctrl+C", nullptr));
#ifndef QT_NO_TOOLTIP
        actionCopy_C_Ctrl_C->setToolTip(QApplication::translate("FancyWordClass", "\345\244\215\345\210\266\345\206\205\345\256\271", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionCopy_C_Ctrl_C->setShortcut(QApplication::translate("FancyWordClass", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionCut_X_Ctrl_X->setText(QApplication::translate("FancyWordClass", "\345\211\252\345\210\207\357\274\210X\357\274\211       Ctrl+X", nullptr));
#ifndef QT_NO_TOOLTIP
        actionCut_X_Ctrl_X->setToolTip(QApplication::translate("FancyWordClass", "\345\211\252\345\210\207\345\206\205\345\256\271", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionCut_X_Ctrl_X->setShortcut(QApplication::translate("FancyWordClass", "Ctrl+X", nullptr));
#endif // QT_NO_SHORTCUT
        actionPaste_P->setText(QApplication::translate("FancyWordClass", "\347\262\230\350\264\264(P)        Ctrl+V", nullptr));
#ifndef QT_NO_TOOLTIP
        actionPaste_P->setToolTip(QApplication::translate("FancyWordClass", "\347\262\230\350\264\264\345\206\205\345\256\271", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionPaste_P->setShortcut(QApplication::translate("FancyWordClass", "Ctrl+V", nullptr));
#endif // QT_NO_SHORTCUT
        actionDelete_D->setText(QApplication::translate("FancyWordClass", "\345\210\240\351\231\244(D)", nullptr));
#ifndef QT_NO_TOOLTIP
        actionDelete_D->setToolTip(QApplication::translate("FancyWordClass", "\345\210\240\351\231\244\345\206\205\345\256\271", nullptr));
#endif // QT_NO_TOOLTIP
        actionSelect_All_A->setText(QApplication::translate("FancyWordClass", "\345\205\250\351\200\211(A)         Ctrl+A", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSelect_All_A->setToolTip(QApplication::translate("FancyWordClass", "\345\205\250\351\200\211\345\206\205\345\256\271", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionSelect_All_A->setShortcut(QApplication::translate("FancyWordClass", "Ctrl+A", nullptr));
#endif // QT_NO_SHORTCUT
        actionFloat_DesignBar->setText(QApplication::translate("FancyWordClass", "\350\256\276\350\256\241\346\240\217", nullptr));
#ifndef QT_NO_TOOLTIP
        actionFloat_DesignBar->setToolTip(QApplication::translate("FancyWordClass", "\350\256\276\350\256\241\346\240\217", nullptr));
#endif // QT_NO_TOOLTIP
        actionInsert_Toolbar->setText(QApplication::translate("FancyWordClass", "\346\217\222\345\205\245\346\240\217", nullptr));
        actionReview_ToolBar->setText(QApplication::translate("FancyWordClass", "\345\256\241\351\230\205\346\240\217", nullptr));
        actionEditArea_Size->setText(QApplication::translate("FancyWordClass", "\347\274\226\350\276\221\345\214\272\345\244\247\345\260\217", nullptr));
        actionTranslate->setText(QApplication::translate("FancyWordClass", "\347\277\273\350\257\221", nullptr));
        actionCount->setText(QApplication::translate("FancyWordClass", "\345\255\227\346\225\260\347\273\237\350\256\241", nullptr));
        actionAbout->setText(QApplication::translate("FancyWordClass", "\345\205\263\344\272\216\346\210\221\344\273\254", nullptr));
        actionVersion->setText(QApplication::translate("FancyWordClass", "\347\211\210\346\234\254", nullptr));
        FontType->setText(QApplication::translate("FancyWordClass", "\345\255\227\344\275\223", nullptr));
        menuFile->setTitle(QApplication::translate("FancyWordClass", "\346\226\207\344\273\266", nullptr));
        menuEdit->setTitle(QApplication::translate("FancyWordClass", "\347\274\226\350\276\221", nullptr));
        menuView->setTitle(QApplication::translate("FancyWordClass", "\350\247\206\345\233\276", nullptr));
        menuHelp->setTitle(QApplication::translate("FancyWordClass", "\345\270\256\345\212\251", nullptr));
        toolBar->setWindowTitle(QApplication::translate("FancyWordClass", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FancyWordClass: public Ui_FancyWordClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FANCYWORD_H
