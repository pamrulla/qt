#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QToolBar>
#include <QTimer>
#include <QFontDialog>
#include <QFileDialog>
#include <QtGlobal>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    title = "untitled";
    isModified = false;
    setWindowTitle(title);

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
    connect(ui->actionChange_Font, &QAction::triggered, [=](){
        bool isOk;
        QFont font = QFontDialog::getFont(&isOk, this);
        if(isOk) {
            ui->textEdit->setFont(font);
        }
    });
    connect(ui->actionNew, &QAction::triggered, [=](){
        ui->textEdit->setText("");
        title = "untitled";
        setWindowTitle(title);
        isModified = false;
    });
    connect(ui->actionOpen, &QAction::triggered, [=](){
        auto name = QFileDialog::getOpenFileName(this, "Open File");
        if(!name.isEmpty()) {
            isModified = false;
            title = name;
            setWindowTitle(title);
        }
        qDebug() << name;
    });
    connect(ui->actionSave, &QAction::triggered, [=](){
        auto name = QFileDialog::getSaveFileName(this, "Save File");
        if(!name.isEmpty()) {
            isModified = false;
            title = name;
            setWindowTitle(title);
        }
        qDebug() << name;
    });
    connect(ui->textEdit, &QTextEdit::textChanged, [=](){
        if(!isModified) {
            title += "*";
            setWindowTitle(title);
        }
        isModified = true;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

