#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "folderscanner.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_scanbtn_clicked();

    void on_fixbtn_clicked();

private:
    Ui::MainWindow *ui;
    QThread foldthread;
    FolderScanner fs;
};
#endif // MAINWINDOW_H
