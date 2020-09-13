#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gibberish.h"

#include <QMainWindow>
#include <QClipboard>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_openText_lineEdit_textChanged(const QString &arg1);
    void on_swap_pushButton_clicked();

    void on_copy_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Gibberish *_gibberish = nullptr;
    QClipboard *_clipboard = nullptr;

};
#endif // MAINWINDOW_H
