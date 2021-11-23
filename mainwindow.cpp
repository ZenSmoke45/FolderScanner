#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "folderscanner.h"
#include <QDebug>
#include <QFileInfo>
#include <QTextStream>
#include <QThread>

QString getPath()
{
    QTextStream stream(stdin);

    qInfo() << "Введите путь: ";
    QString value = stream.readLine();
    QFileInfo fi(value);
    if(!fi.exists()){
        qWarning() << "Файл либо удалён, либо имеет недействительный путь";
        value.clear();
    }
    return value;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->enterPath->text();
    connect(&foldthread, &QThread::started, &fs, &FolderScanner::scan);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_fixbtn_clicked()
{
    fs.setPath(ui->enterPath->text());
}

void MainWindow::on_scanbtn_clicked()
{
    QThread::currentThread()->setObjectName("Главный поток");
    QString path = getPath();
    while (!path.isEmpty()) path = getPath();
    qInfo() << path;
    fs.scan(path);
    foldthread.start();
}





