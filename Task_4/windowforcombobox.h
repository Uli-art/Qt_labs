#ifndef WINDOWFORCOMBOBOX_H
#define WINDOWFORCOMBOBOX_H

#include <QMainWindow>
#include <QString>
namespace Ui {
class WindowForComboBox;
}

class WindowForComboBox : public QMainWindow
{
    Q_OBJECT

public:
    WindowForComboBox(QWidget *parent = nullptr);
    void setText(QString text);

    void setComboBox(QStringList employeeList);
    ~WindowForComboBox();

private slots:
    int on_NewWinComboBox_activated(int index);

    void on_pushButton_clicked();
signals:
    void returnActiveIndex(int index);
private:
    Ui::WindowForComboBox *ui;
};

#endif // WINDOWFORCOMBOBOX_H
