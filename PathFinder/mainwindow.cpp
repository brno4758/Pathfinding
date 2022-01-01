#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new QGraphicsScene)
    , grid_(new Grid(28,48)) //Size of the grid set here
    , source_(nullptr)
    , dest_(nullptr)
{
    ui->setupUi(this);
    QGraphicsView *gridView = ui->graphicsView;

    //Set up the scene that the playing field will be displayed on
    gridView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gridView->verticalScrollBar()->blockSignals(true);
    gridView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    gridView->horizontalScrollBar()->blockSignals(true);
    gridView->setScene(scene);
    gridView->setSceneRect(0,0,gridView->frameSize().width(),gridView->frameSize().height());

    for(short i = 0; i < grid_->get_num_rows(); i++)
        for(short j = 0; j < grid_->get_num_cols(); j++)
        {
            scene->addItem(grid_->get_cell(j,i));
            connect(grid_->get_cell(j,i), &Cell::cell_selected, this, &MainWindow::on_cell_selected);
        }
    srand(time(NULL));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_cell_selected(Cell& c)
{
    if(!source_){
        source_ = &c;
        source_->set_cell_type(CellType::Source);
        source_->update();
    }
    else if(!dest_){
        dest_ = &c;
        dest_->set_cell_type(CellType::Destination);
        dest_->update();
    }
    else if(source_ && dest_){
        source_->set_cell_type(CellType::Unvisited);
        dest_->set_cell_type(CellType::Unvisited);
        source_->update();
        dest_->update();

        source_ = &c;
        source_->set_cell_type(CellType::Source);
        source_->update();
        dest_ = nullptr;
    }
    qDebug() << c.get_dest_distance();
}

void MainWindow::on_DFSButton_clicked()
{
    if(!source_ || !dest_)
    {
        QMessageBox error;
        error.setText("Must have both a source and destination cell selected");
        error.exec();
        return;
    }
    ui->resetButton->setEnabled(false);
    grid_->depth_first_search(*source_, *dest_);
    ui->resetButton->setEnabled(true);
    Cell* crawler = dest_;
    while(crawler != nullptr)
    {
        Sleep(50);
        crawler->set_and_draw(CellType::Path);
        crawler = crawler->get_prev();
    }
}

void MainWindow::on_BFSButton_clicked()
{
    if(!source_ || !dest_)
    {
        QMessageBox error;
        error.setText("Must have both a source and destination cell selected");
        error.exec();
        return;
    }
    ui->resetButton->setEnabled(false);
    grid_->breadth_first_search(*source_, *dest_);
    ui->resetButton->setEnabled(true);
    Cell* crawler = dest_;
    while(crawler != nullptr)
    {
        Sleep(50);
        crawler->set_and_draw(CellType::Path);
        crawler = crawler->get_prev();
    }
}

void MainWindow::on_resetButton_clicked()
{
    source_ = nullptr;
    dest_ = nullptr;
    Cell* c = nullptr;
    short rows = grid_->get_num_rows();
    short cols = grid_->get_num_cols();
    for(short i = 0; i < rows; i++)
        for(short j = 0; j < cols; j++)
        {
            c = grid_->get_cell(j,i);
            c->set_cell_type(CellType::Unvisited);
            c->set_prev(c);
            c->set_distance(SHRT_MAX);
            c->set_dest_distance(0);
        }
    scene->update();
}


void MainWindow::on_DijkstraButton_clicked()
{
    if(!source_ || !dest_)
    {
        QMessageBox error;
        error.setText("Must have both a source and destination cell selected");
        error.exec();
        return;
    }
    grid_->dijkstras(*source_, *dest_);
    Cell* crawler = dest_;
    while(crawler != nullptr)
    {
        Sleep(50);
        crawler->set_and_draw(CellType::Path);
        crawler = crawler->get_prev();
    }
}

void MainWindow::on_AStarButton_clicked()
{
    if(!source_ || !dest_)
    {
        QMessageBox error;
        error.setText("Must have both a source and destination cell selected");
        error.exec();
        return;
    }
    grid_->Astar(*source_, *dest_);
    Cell* crawler = dest_;
    while(crawler != nullptr)
    {
        Sleep(50);
        crawler->set_and_draw(CellType::Path);
        crawler = crawler->get_prev();
    }
}

void MainWindow::on_greedyButton_clicked()
{
    if(!source_ || !dest_)
    {
        QMessageBox error;
        error.setText("Must have both a source and destination cell selected");
        error.exec();
        return;
    }
    grid_->greedy(*source_, *dest_);
    Cell* crawler = dest_;
    while(crawler != nullptr)
    {
        Sleep(50);
        crawler->set_and_draw(CellType::Path);
        crawler = crawler->get_prev();
    }
}


void MainWindow::on_randomButton_clicked()
{
    short rows = grid_->get_num_rows();
    short cols = grid_->get_num_cols();
    for(short i = 0; i < rows; i++)
        for(short j = 0; j < cols; j++)
            if(rand() % 4 == 1)
            {
                grid_->get_cell(j,i)->set_cell_type(CellType::Wall);
            }
    scene->update();
}

