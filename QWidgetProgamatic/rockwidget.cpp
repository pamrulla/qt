#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include "rockwidget.h"

RockWidget::RockWidget(QWidget *parent) : QWidget(parent)
{
    QLabel *simpleLable = new QLabel("Simple Label", this);

    QFont labelFont("Times", 15, QFont::Bold, true);
    QPalette plt;
    plt.setColor(QPalette::Window, Qt::red);
    plt.setColor(QPalette::WindowText, Qt::yellow);

    QLabel *coloredLabel = new QLabel(this);
    coloredLabel->setText("Colored Label");
    coloredLabel->move(50, 50);
    coloredLabel->setFont(labelFont);
    coloredLabel->setPalette(plt);
    coloredLabel->setAutoFillBackground(true);

    QPushButton *btn = new QPushButton(this);
    btn->setText("Push Me");
    btn->move(200, 200);
    connect(btn, &QPushButton::clicked, [=](){
        QMessageBox::information(this, "Information", "You pushed me...", QMessageBox::Yes | QMessageBox::No);
    });
}

QSize RockWidget::sizeHint() const
{
    return QSize(500, 500);
}
