#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sistemafacade.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      sistema(new SistemaFacade())
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete sistema;
    delete ui;
}
