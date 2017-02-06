#include "mydelegate.h"
#include <QCheckBox>
#include <QComboBox>
#include <QCalendarWidget>
#include <QCursor>
#include <QLineEdit>
#include <QApplication>
#include <QRect>
#include <QMouseEvent>
#include <QEvent>
#include <QPoint>

ReadOnlyDelegate::ReadOnlyDelegate( QObject *parent)
    : QStyledItemDelegate(parent)
{

}

QWidget *ReadOnlyDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return NULL;
}

ComboBoxDelegate::ComboBoxDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

QWidget *ComboBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QComboBox *editor = new QComboBox(parent);
    editor->addItem("否");
    editor->addItem("是");

    return editor;
}

void ComboBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString text = index.model()->data(index, Qt::EditRole).toString();

    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    comboBox->setCurrentText(text);
}

void ComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    QString text = comboBox->currentText();

    model->setData(index, text, Qt::EditRole);
}

void ComboBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

CheckBoxDelegate::CheckBoxDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void CheckBoxDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int column = index.column();
    if (column > 7 && column < 27 && column % 2 == 0) {
        //获取值
        bool checked = index.model()->data(index, Qt::DisplayRole).toBool();
        //按钮的风格选项
        QStyleOptionButton *checkBoxOption = new QStyleOptionButton();

        checkBoxOption->state |= QStyle::State_Enabled;
        //根据值判断是否选中
        if (checked) {
            checkBoxOption->state |= QStyle::State_On;
        }
        else {
            checkBoxOption->state |= QStyle::State_Off;
        }
        //返回QCheckBox几何形状
        checkBoxOption->rect = CheckBoxRect(option);
        //绘制QCheckBox
        QApplication::style()->drawControl(QStyle::CE_CheckBox, checkBoxOption, painter);
    }
    else {
        QStyledItemDelegate::paint(painter, option, index);
    }
}

bool CheckBoxDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    int column = index.column();
    if (!(column > 7 && column < 27 && column % 2 == 0))
        return false;

    int m_nSpacing = 5, m_nWidth = 25, m_nHeight = 20;

    int nHalf = option.rect.width() - m_nWidth;
    int nTop = (option.rect.height() - m_nHeight) / 2;

    QApplication::restoreOverrideCursor();

    QStyleOptionButton button;
    button.rect = QRect(option.rect.left() + nHalf + m_nWidth + m_nSpacing,
                                        option.rect.top() + nTop,  m_nWidth, m_nHeight);

    switch (event->type())
    {
    case QEvent::MouseMove: {
        QApplication::setOverrideCursor(Qt::PointingHandCursor);
        break;
    }
    case QEvent::MouseButtonPress: {
        break;
    }
    case QEvent::MouseButtonRelease: {
        setModelData(NULL, model, index);
        return true;
    }
    }
    return false;
}

QRect CheckBoxDelegate::CheckBoxRect(const QStyleOptionViewItem &viewItemStyleOptions) const
{
    //绘制按钮所需要的参数
    QStyleOptionButton checkBoxStyleOption;
    //按照给定的风格参数 返回元素子区域
    QRect checkBoxRect = QApplication::style()->subElementRect( QStyle::SE_CheckBoxIndicator, &checkBoxStyleOption);
    //返回QCheckBox坐标
    QPoint checkBoxPoint(viewItemStyleOptions.rect.x() + viewItemStyleOptions.rect.width() / 2 - checkBoxRect.width() / 2,
                             viewItemStyleOptions.rect.y() + viewItemStyleOptions.rect.height() / 2 - checkBoxRect.height() / 2);
    //返回QCheckBox几何形状
    return QRect(checkBoxPoint, checkBoxRect.size());
}

void CheckBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    Q_UNUSED(editor);
    int value = model->data(index).toInt();

    value = value ? 0 : 1;

    model->setData(index, value, Qt::EditRole);
}

CalendarDelegate::CalendarDelegate(QObject *parent) : QStyledItemDelegate(parent)
{

}

QWidget *CalendarDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QCalendarWidget *editor = new QCalendarWidget();
    connect(editor, SIGNAL(clicked(QDate)), editor, SLOT(close()));

    return editor;
}

void CalendarDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QDate  date;
    if(index.model()->data(index, Qt::EditRole).isValid())
        date = index.model()->data(index, Qt::EditRole).toDate();
    else
        date = QDate::currentDate();

    QCalendarWidget *calendarWidget = static_cast<QCalendarWidget*>(editor);
    calendarWidget->setSelectedDate(date);
}

void CalendarDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QCalendarWidget *calendarWidget = static_cast<QCalendarWidget*>(editor);
    QDate date = calendarWidget->selectedDate();

    model->setData(index, date, Qt::EditRole);
}

void CalendarDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QPoint point = option.rect.topLeft();
    editor->move(point);
    editor->show();
}
/*
CheckBoxDelegate::CheckBoxDelegate(QObject *parent) : QStyledItemDelegate(parent)
{

}

QWidget *CheckBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QCheckBox *editor = new QCheckBox(parent);

    return editor;
}

void CheckBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.model()->data(index, Qt::EditRole).toInt();

    QCheckBox *checkBox = static_cast<QCheckBox*>(editor);
    if (value == 0)
        checkBox->setChecked(false);
    else
        checkBox->setChecked(true);
}

void CheckBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QCheckBox *checkBox = static_cast<QCheckBox*>(editor);
    int value = 0;
    if (checkBox->checkState())
        value = 1;

    model->setData(index, value, Qt::EditRole);
}


void CheckBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

*/

CheckBoxDelegateNoEditor::CheckBoxDelegateNoEditor(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

void CheckBoxDelegateNoEditor::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int column = index.column();
    if (column > 7 && column < 27 && column % 2 == 0) {
        //获取值
        bool checked = index.model()->data(index, Qt::DisplayRole).toBool();
        //按钮的风格选项
        QStyleOptionButton *checkBoxOption = new QStyleOptionButton();

        checkBoxOption->state |= QStyle::State_Enabled;
        //根据值判断是否选中
        if (checked) {
            checkBoxOption->state |= QStyle::State_On;
        }
        else {
            checkBoxOption->state |= QStyle::State_Off;
        }
        //返回QCheckBox几何形状
        checkBoxOption->rect = CheckBoxRect(option);
        //绘制QCheckBox
        QApplication::style()->drawControl(QStyle::CE_CheckBox, checkBoxOption, painter);
    }
    else {
        QStyledItemDelegate::paint(painter, option, index);
    }
}

QRect CheckBoxDelegateNoEditor::CheckBoxRect(const QStyleOptionViewItem &viewItemStyleOptions) const
{
    //绘制按钮所需要的参数
    QStyleOptionButton checkBoxStyleOption;
    //按照给定的风格参数 返回元素子区域
    QRect checkBoxRect = QApplication::style()->subElementRect( QStyle::SE_CheckBoxIndicator, &checkBoxStyleOption);
    //返回QCheckBox坐标
    QPoint checkBoxPoint(viewItemStyleOptions.rect.x() + viewItemStyleOptions.rect.width() / 2 - checkBoxRect.width() / 2,
                             viewItemStyleOptions.rect.y() + viewItemStyleOptions.rect.height() / 2 - checkBoxRect.height() / 2);
    //返回QCheckBox几何形状
    return QRect(checkBoxPoint, checkBoxRect.size());
}
