#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton* btn = new QPushButton("Button", this);
    setCentralWidget(btn);

    statusBar()->showMessage("Processing for 3000 ms", 3000);

    QAction *quitAction = new QAction("Quit", this);
    connect(quitAction, &QAction::triggered, [=](){
        QApplication::quit();
    });

    auto filemenu = menuBar()->addMenu("File");
    filemenu->addAction(quitAction);
    menuBar()->addMenu("Edit");
    menuBar()->addMenu("Window");
    menuBar()->addMenu("Settings");
    menuBar()->addMenu("Help");
}

MainWindow::~MainWindow()
{
    delete ui;
}

