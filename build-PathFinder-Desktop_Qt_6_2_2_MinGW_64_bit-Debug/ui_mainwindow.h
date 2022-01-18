/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *DFSButton;
    QPushButton *BFSButton;
    QPushButton *resetButton;
    QPushButton *DijkstraButton;
    QPushButton *AStarButton;
    QPushButton *greedyButton;
    QPushButton *randomButton;
    QSlider *delaySlider;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1031, 759);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 30, 1010, 590));
        DFSButton = new QPushButton(centralwidget);
        DFSButton->setObjectName(QString::fromUtf8("DFSButton"));
        DFSButton->setGeometry(QRect(40, 630, 150, 35));
        BFSButton = new QPushButton(centralwidget);
        BFSButton->setObjectName(QString::fromUtf8("BFSButton"));
        BFSButton->setGeometry(QRect(240, 630, 150, 35));
        resetButton = new QPushButton(centralwidget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));
        resetButton->setGeometry(QRect(10, 0, 75, 24));
        DijkstraButton = new QPushButton(centralwidget);
        DijkstraButton->setObjectName(QString::fromUtf8("DijkstraButton"));
        DijkstraButton->setGeometry(QRect(440, 630, 150, 35));
        AStarButton = new QPushButton(centralwidget);
        AStarButton->setObjectName(QString::fromUtf8("AStarButton"));
        AStarButton->setGeometry(QRect(640, 630, 150, 35));
        greedyButton = new QPushButton(centralwidget);
        greedyButton->setObjectName(QString::fromUtf8("greedyButton"));
        greedyButton->setGeometry(QRect(840, 630, 150, 35));
        randomButton = new QPushButton(centralwidget);
        randomButton->setObjectName(QString::fromUtf8("randomButton"));
        randomButton->setGeometry(QRect(950, 0, 75, 24));
        delaySlider = new QSlider(centralwidget);
        delaySlider->setObjectName(QString::fromUtf8("delaySlider"));
        delaySlider->setGeometry(QRect(340, 680, 361, 22));
        delaySlider->setSingleStep(33);
        delaySlider->setOrientation(Qt::Horizontal);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1031, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        DFSButton->setText(QCoreApplication::translate("MainWindow", "DFS", nullptr));
        BFSButton->setText(QCoreApplication::translate("MainWindow", "BFS", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        DijkstraButton->setText(QCoreApplication::translate("MainWindow", "Dijkstra", nullptr));
        AStarButton->setText(QCoreApplication::translate("MainWindow", "A*", nullptr));
        greedyButton->setText(QCoreApplication::translate("MainWindow", "Greedy", nullptr));
        randomButton->setText(QCoreApplication::translate("MainWindow", "Random", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
