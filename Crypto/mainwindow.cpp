#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _gibberish = new Gibberish();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete _gibberish;
}

void MainWindow::runCesar(const QString &openText, const int &shift, bool hasYo)
{
    Cesar cesar(shift, hasYo);
    ui->cesarCryptogram_lineEdit->setText(cesar.encrypt(openText));
}

void MainWindow::on_swap_pushButton_clicked()
{
    ui->gibberishOpenText_lineEdit->setText(ui->gibberishCryptogram_lineEdit->text());
}

void MainWindow::on_gibberishOpenText_lineEdit_textChanged(const QString &text)
{
    ui->gibberishCryptogram_lineEdit->setText(_gibberish->encrypt(text));
}

void MainWindow::on_cesarOpenText_lineEdit_textChanged(const QString &text)
{
    runCesar(text, ui->cesar_spinBox->value(), ui->cesarHasYo_checkBox->isChecked());
}

void MainWindow::on_cesar_spinBox_valueChanged(int shift)
{
    runCesar(ui->cesarOpenText_lineEdit->text(), shift, ui->cesarHasYo_checkBox->isChecked());
}

void MainWindow::on_cesarBrute_pushButton_clicked()
{
    Cesar cesar(1, ui->cesarHasYo_checkBox->isChecked());
    auto result = cesar.brute(ui->cesarOpenText_lineEdit->text());
    QString text;
    for (auto item : result)
    {
        text += QString::number(result.indexOf(item) + 1) + " " + item + "\n";
    }
    ui->cesar_plainTextEdit->clear();
    ui->cesar_plainTextEdit->insertPlainText(text);
}

void MainWindow::on_cesarHasYo_checkBox_clicked(bool checked)
{
    runCesar(ui->cesarOpenText_lineEdit->text(), ui->cesar_spinBox->value(), checked);
}
