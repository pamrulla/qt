#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QToolBar>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionQuit, &QAction::triggered, [=](){
        ui->statusbar->showMessage("Application exists in 3 seconds.");
        QTimer::singleShot(3000, [=](){
            QApplication::quit();
        });
    });
    connect(ui->actionCopy, &QAction::triggered, [=](){
        ui->textEdit->copy();
    });
    connect(ui->actionCut, &QAction::triggered, [=](){
        ui->textEdit->cut();
    });
    connect(ui->actionPaste, &QAction::triggered, [=](){
        ui->textEdit->paste();
    });
    connect(ui->actionUndo, &QAction::triggered, [=](){
        ui->textEdit->undo();
    });
    connect(ui->actionRedo, &QAction::triggered, [=](){
        ui->textEdit->redo();
    });
    connect(ui->actionAbout, &QAction::triggered, [=](){
        QMessageBox::about(this, "About", "This is a simple notepad application using Qt.");
    });
    connect(ui->actionAbout_Qt, &QAction::triggered, [=](){
        QMessageBox::aboutQt(this);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

