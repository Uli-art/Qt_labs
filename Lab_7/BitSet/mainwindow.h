#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bitset.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onValueChanged();
    void onSetPushButtonClicked();
    void onResetPushButtonClicked();
    void onFlipPushButtonClicked();
    void onTestPushButtonClicked();
    void onModifyPushButtonClicked();
    void onAndPushButtonClicked();
    void onOrPushButtonClicked();
    void onXorPushButtonClicked();
    void onNotPushButtonClicked();
    void onLeftShitPushButtonClicked();
    void onRightShitPushButtonClicked();

private:
    void refreshStatistics();
    void refreshConversions();
    void updateValue();

private:
    Ui::MainWindow *ui;
    BitSet<64> _bitSet;
};
#endif // MAINWINDOW_H
