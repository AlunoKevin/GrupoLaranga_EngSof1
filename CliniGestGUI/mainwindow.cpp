#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../CliniGestLogic/facade/sistemafacade.h"

MainWindow::MainWindow(SistemaFacade* facade, QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      m_facade(facade)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
