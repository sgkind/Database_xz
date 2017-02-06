#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QPalette>
#include <QColor>
#include <QHBoxLayout>
#include <QImage>

class CustomWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CustomWidget(QWidget *parent = 0);
    ~CustomWidget();

private:
    QLabel *arrowLabel;

    QPalette defaultPalette;

    QHBoxLayout *mainLayout;

protected:
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    //void mouseDoubleClickEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

signals:
    void doubleClicked();

public slots:
};

#endif // CUSTOMWIDGET_H
