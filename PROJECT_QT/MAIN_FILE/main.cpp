#include "mainwindow.h"

#include <QApplication>

#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile styleSheetFile(":/nothing/Fibrary.qss");
    styleSheetFile.open(QFile::ReadOnly);
    QString styleSheet;
    styleSheet = QLatin1String(styleSheetFile.readAll());
    a.setStyleSheet(styleSheet);
    MainWindow w;
    w.show();
    return a.exec();
}
