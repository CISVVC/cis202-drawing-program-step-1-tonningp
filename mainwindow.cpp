#include "mainwindow.h"
#include "imageview.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->layout()->addWidget(new ImageView());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addEllipse()
{
    qDebug() << "Adding an Ellipse";
}

void MainWindow::addLine()
{
    qDebug() << "Adding a Line";
}

void MainWindow::addRectangle()
{
   qDebug() << "Adding a Rectangle";
}
