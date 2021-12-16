#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new QGraphicsScene)
    , grid_(new Grid(23,31))
    , source_(nullptr)
    , dest_(nullptr)
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
            connect(grid_->get_cell(j,i), &Cell::cell_selected, this, &MainWindow::on_cell_selected);
        }
}

MainWindow::~MainWindow()
{
    delete ui;
    //delete grid_;
}


void MainWindow::on_cell_selected(Cell& c)
{
    if(!source_){
        source_ = &c;
    }
    else if(!dest_){
        dest_ = &c;
    }
    else if(source_ && dest_){
        source_ = &c;
        dest_ = nullptr;
    }

    for(const auto &i : grid_->get_neighbors(c))
        qDebug() << "Neighbor: " << i->get_x() << "," << i->get_y();
}


void MainWindow::on_pushButton_clicked()
{
    if(!source_ || !dest_)
    {
        QMessageBox error;
        error.setText("Must have both a source and destination cell selected");
        error.exec();
        return;
    }

    grid_->depth_first_search(*source_, *dest_);
}

