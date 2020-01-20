#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <ctime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(nullptr));

    initApplication();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_guessButton_clicked()
{
    int guessedNumber = ui->guessNumberText->value();
    if(guessedNumber == secreteNumber) {
        ui->messageText->setText("Congratualations...The Screte Number: " + QString::number(secreteNumber));
        ui->guessButton->setEnabled(false);
        ui->startoverButton->setEnabled(true);
    }
    else if(guessedNumber > secreteNumber) {
        ui->messageText->setText("The number is smaller than that.");
    }
    else {
        ui->messageText->setText("The number is greater than that.");
    }
}

void MainWindow::on_startoverButton_clicked()
{
    initApplication();
}

void MainWindow::initApplication()
{
    secreteNumber = rand() % 10 + 1;
    ui->startoverButton->setEnabled(false);
    ui->guessButton->setEnabled(true);
    ui->messageText->setText("");
    ui->guessNumberText->setValue(1);
}
