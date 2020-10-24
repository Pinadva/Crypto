#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "presenter.h"
#include "settings.h"
#include "status.h"

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

public slots:
    void setStatus(const QString &msg, Status status);

private slots:
    void on_swap_pushButton_clicked();
    void on_gibberishOpenText_lineEdit_textChanged(const QString &arg1);

    void on_cesarOpenText_lineEdit_textChanged(const QString &arg1);
    void on_cesar_spinBox_valueChanged(int arg1);
    void on_cesarBrute_pushButton_clicked();
    void on_cesarHasYo_checkBox_clicked(bool checked);

    void on_vigenerOpenText_lineEdit_textChanged(const QString &arg1);
    void on_vigenerKey_lineEdit_textChanged(const QString &arg1);
    void on_vigenerHasYo_checkBox_clicked(bool checked);
    void on_vigenerDecrypt_pushButton_clicked();

    void on_polybiusSquareOpenText_lineEdit_textChanged(const QString &arg1);

    void on_polybiusSquareDecrypt_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    View *_view           = nullptr;
    Presenter *_presenter = nullptr;
};
#endif // MAINWINDOW_H
