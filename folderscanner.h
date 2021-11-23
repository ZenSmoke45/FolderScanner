#ifndef FOLDERSCANNER_H
#define FOLDERSCANNER_H
#include <QObject>
#include <QtCore>
#include <QDir>
#include <QDebug>
#include <QFileInfo>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>

class FolderScanner: public QObject
{
    Q_OBJECT

    QString p_path;

public:
    explicit FolderScanner();

signals:
    void updated(QString path);

public slots:
    void setPath(QString path);
    void scan(QString path);

private:
    int performScan(QString path);
    qint64 m_count;

};

#endif // FOLDERSCANNER_H
