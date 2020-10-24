#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _view      = new View();
    _presenter = new Presenter(_view);

    // connect
    connect(ui->tabWidget, &QTabWidget::currentChanged, &Settings::instance(), &Settings::setTab);
    connect(_view, &View::showCesarBrute, ui->cesar_plainTextEdit, &QPlainTextEdit::setPlainText);
    connect(_presenter, &Presenter::statusChanged, this, &MainWindow::setStatus);
    connect(_presenter, &Presenter::readyViewGibbersin, ui->gibberishCrypto_lineEdit, &QLineEdit::setText);
    connect(_presenter, &Presenter::readyViewCesar, ui->cesarCrypto_lineEdit, &QLineEdit::setText);
    connect(_presenter, &Presenter::readyViewBruteCesar, _view, &View::viewCesarBrute);
    connect(_presenter, &Presenter::readyViewVigener, ui->vigenerCrypto_lineEdit, &QLineEdit::setText);
    connect(_presenter, &Presenter::readyViewPolybiusSquare, ui->polybiusSquareCrypto_lineEdit, &QLineEdit::setText);

    // set
    Settings::instance().load();
    ui->tabWidget->setCurrentIndex(Settings::instance().getTab());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setStatus(const QString &msg, Status status)
{
    QString style = "color: ";
    switch (status)
    {
        case SUCCESS:
            style += "green";
            break;
        case INFO:
            style += "black";
            break;
        case WARNING:
            style += "yellow";
            break;
        case ERROR:
            style += "red";
    }
    ui->statusbar->setStyleSheet(style);
    ui->statusbar->showMessage(msg, 5000);
}

void MainWindow::on_swap_pushButton_clicked()
{
    ui->gibberishOpenText_lineEdit->setText(ui->gibberishCrypto_lineEdit->text());
}

void MainWindow::on_gibberishOpenText_lineEdit_textChanged(const QString &text)
{
    _presenter->runGibberish(text);
}

void MainWindow::on_cesarOpenText_lineEdit_textChanged(const QString &text)
{
    _presenter->runCesar(ui->cesarHasYo_checkBox->isChecked(), ui->cesar_spinBox->value(), text);
}

void MainWindow::on_cesar_spinBox_valueChanged(int shift)
{
    _presenter->runCesar(ui->cesarHasYo_checkBox->isChecked(), shift, ui->cesarOpenText_lineEdit->text());
}

void MainWindow::on_cesarHasYo_checkBox_clicked(bool checked)
{
    _presenter->runCesar(checked, ui->cesar_spinBox->value(), ui->cesarOpenText_lineEdit->text());
}

void MainWindow::on_cesarBrute_pushButton_clicked()
{
    _presenter->runCesarBrute(ui->cesarHasYo_checkBox->isChecked(), ui->cesarOpenText_lineEdit->text());
}

void MainWindow::on_vigenerOpenText_lineEdit_textChanged(const QString &text)
{
    _presenter->runVigener(ui->vigenerHasYo_checkBox->isChecked(), text, ui->vigenerKey_lineEdit->text());
}

void MainWindow::on_vigenerKey_lineEdit_textChanged(const QString &text)
{
    _presenter->runVigener(ui->vigenerHasYo_checkBox->isChecked(), ui->vigenerOpenText_lineEdit->text(), text);
}

void MainWindow::on_vigenerHasYo_checkBox_clicked(bool checked)
{
    _presenter->runVigener(checked, ui->vigenerOpenText_lineEdit->text(), ui->vigenerKey_lineEdit->text());
}

void MainWindow::on_vigenerDecrypt_pushButton_clicked()
{
    _presenter->runVigenerDecrypt(ui->vigenerHasYo_checkBox->isChecked(),
                                  ui->vigenerOpenText_lineEdit->text(),
                                  ui->vigenerKey_lineEdit->text());
}

void MainWindow::on_polybiusSquareOpenText_lineEdit_textChanged(const QString &text)
{
    _presenter->runPolybiusSquare(text);
}

void MainWindow::on_polybiusSquareDecrypt_pushButton_clicked()
{
    _presenter->runPolybiusSquareDecrypt(ui->polybiusSquareOpenText_lineEdit->text());
}
