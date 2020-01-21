#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //String Notation
    connect(ui->stringSlider, SIGNAL(valueChanged(int)), ui->stringBar, SLOT(setValue(int)));

    //Functor Notation
    connect(ui->functorSlider, &QSlider::valueChanged, ui->functorbar, &QProgressBar::setValue);

    //Lambda Notation
    connect(ui->lambdaSlider, &QSlider::valueChanged, [=](){
        ui->lambdaBar->setValue(ui->lambdaSlider->value());
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

