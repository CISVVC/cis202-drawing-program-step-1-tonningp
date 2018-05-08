#include "mainwindow.h"
#include "imageview.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->layout()->addWidget(new ImageView(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addEllipse(bool toggled)
{
    if(toggled)
    {
        ui->actionLine->setChecked(false);
        ui->actionRectangle->setChecked(false);
    }
    emit addingEllipse(toggled);
}


void MainWindow::addLine(bool toggled)
{
//    if(toggled)
//    {
//        ui->actionEllipse->setChecked(false);
//        ui->actionRectangle->setChecked(false);
//    }
//    emit addingLine(toggled);
}

void MainWindow::addRectangle(bool toggled)
{
//    if(toggled)
//    {
//        ui->actionEllipse->setChecked(false);
//        ui->actionLine->setChecked(false);
//    }
//    emit addingRectangle(toggled);
}
