#include "customwidget.h"
#include <QDebug>

CustomWidget::CustomWidget(QWidget *parent) : QWidget(parent)
{
    arrowLabel = new QLabel();

    setAutoFillBackground(true);
    defaultPalette = this->palette();

    QPixmap pixmap(":/arrow.png");
    arrowLabel->setPixmap(pixmap.scaled(10, 20));

    mainLayout = new QHBoxLayout(this);
    mainLayout->setMargin(0);
    mainLayout->addWidget(arrowLabel, Qt::AlignVCenter);

    setLayout(mainLayout);

    setFixedWidth(10);

    //允许监听鼠标进入事件
    this->setMouseTracking(true);
}

CustomWidget::~CustomWidget()
{

}

void CustomWidget::enterEvent(QEvent *event)
{
    Q_UNUSED(event);
    QPalette palette;
    palette.setColor(QPalette::Window, Qt::blue);
    this->setPalette(palette);
}

void CustomWidget::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    this->setPalette(defaultPalette);
}

/*void CustomWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    emit doubleClicked();
}*/

void CustomWidget::mousePressEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    emit doubleClicked();
}
