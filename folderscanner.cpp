#include "folderscanner.h"
#include <QtCore>
#include <QDebug>
#include <QTextStream>

FolderScanner::FolderScanner() :
    QObject(),
    p_path("")
{

}

void FolderScanner::setPath(QString path)
{
    if(p_path == path) return;
    p_path = path;
    emit updated(path);
}

void FolderScanner::scan(QString path)
{
    qInfo() << "Сканирование... " << QThread::currentThread();
    m_count = 0;

    QFuture<int> future = QtConcurrent::run(this, &FolderScanner::performScan, path);

    qInfo() << "Главный поток свободен... ";

    qInfo() << "Результат: " << future.result();
}


int FolderScanner::performScan(QString path)
{
    int value = 0;
    QDir dir(path);
    if (!dir.exists()) return -1;
    qInfo() << "Показ сканирования..." << QThread::currentThread();

    QFileInfoList list = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Dirs); // Показ директорий, без одной и двух точек
    value = list.length();

    foreach(QFileInfo item, list) value = value + performScan(item.filePath());
    return value;

}
