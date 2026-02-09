#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class SistemaFacade;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(SistemaFacade* facade, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SistemaFacade* m_facade;
};

#endif // MAINWINDOW_H
