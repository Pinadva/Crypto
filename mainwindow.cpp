#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _gibberish = new Gibberish();
    _clipboard = QGuiApplication::clipboard();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _gibberish;
    _clipboard->deleteLater();
}

void MainWindow::on_openText_lineEdit_textChanged(const QString &text)
{
    ui->cryptogram_lineEdit->setText(_gibberish->encrypt(text));
}

void MainWindow::on_swap_pushButton_clicked()
{
    ui->openText_lineEdit->setText(ui->cryptogram_lineEdit->text());
}

void MainWindow::on_copy_pushButton_clicked()
{
    _clipboard->setText(ui->cryptogram_lineEdit->text());
}
