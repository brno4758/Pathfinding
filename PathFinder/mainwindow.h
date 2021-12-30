#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cell.h"
#include "grid.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    Grid* grid_;
    Cell* source_;
    Cell* dest_;

private slots:
    void on_cell_selected(Cell& c);
    void on_DFSButton_clicked();
    void on_BFSButton_clicked();
    void on_resetButton_clicked();
    void on_DijkstraButton_clicked();
    void on_AStarButton_clicked();
    void on_greedyButton_clicked();
};
#endif // MAINWINDOW_H
