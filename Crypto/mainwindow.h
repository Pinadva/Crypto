#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "cesar.h"
#include "gibberish.h"
#include "settings.h"

#include <QClipboard>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void runCesar(const QString &openText, const int &shift, bool countAllShifts = false);

private slots:
    void on_swap_pushButton_clicked();
    void on_gibberishOpenText_lineEdit_textChanged(const QString &arg1);
    void on_cesarOpenText_lineEdit_textChanged(const QString &arg1);

    void on_cesar_spinBox_valueChanged(int arg1);

    void on_cesarBrute_pushButton_clicked();

    void on_cesarHasYo_checkBox_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    Gibberish *_gibberish = nullptr;
};
#endif // MAINWINDOW_H
