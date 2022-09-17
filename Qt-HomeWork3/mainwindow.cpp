#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_open_button_clicked()
{
    QString s = QFileDialog::getOpenFileName(this, "window", QDir::current().path(), "Text(*.txt)");
    int index = s.indexOf(".txt");

    if (s.length()!=0){
        if(index != -1 && s.length()-4 == index){
            QFile file(s);
            if(file.open(QFile::ReadOnly | QFile::ExistingOnly))
            {
                QTextStream stream(&file);
                ui->plainTextEdit->setPlainText(stream.readAll());
                file.close();
            }
        }
    }
}


void MainWindow::on_save_button_clicked()
{
    QString s = QFileDialog::getSaveFileName(this, "window", QDir::current().path(), "Text(*.txt)");
    if(s.length() > 0){
        QString ext = QString(&(s.data()[s.length() - 4]));
        if(ext==".txt"){
            QFile file(s);
            if(file.open(QFile::WriteOnly | QFile::NewOnly))
            {
                QTextStream stream(&file);
                stream << ui->plainTextEdit->toPlainText();
                file.close();
            }
        }
    }
}


void MainWindow::on_ref_button_clicked()
{
    QFile file (":/res/referance.txt");
    if(file.open(QFile::ReadOnly | QFile::ExistingOnly))
    {
        QTextStream stream(&file);
        ui->ref_label->setText(stream.readAll());
        file.close();
    }

}
