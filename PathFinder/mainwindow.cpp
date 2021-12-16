#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new QGraphicsScene)
    , grid_(new Grid(23,31))
{
    ui->setupUi(this);
    QGraphicsView *gridView = ui->graphicsView;
    //Set up the scene that the playing field will be displayed on
    gridView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gridView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gridView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gridView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gridView->setScene(scene);
    gridView->setSceneRect(0,0,gridView->frameSize().width(),gridView->frameSize().height());


    for(short i = 0; i < grid_->get_num_rows(); i++)
        for(short j = 0; j < grid_->get_num_cols(); j++)
        {
            scene->addItem(grid_->get_cell(j,i));
        }
}

MainWindow::~MainWindow()
{
    delete ui;
    //delete grid_;
}


void MainWindow::on_cell_selected(Cell* c)
{
    qDebug() << c->get_x() << "," << c->get_y();
}

