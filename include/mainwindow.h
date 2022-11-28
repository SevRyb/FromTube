#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

class MainWindow : public QWidget
{
    Q_OBJECT

    void findUrl();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QFrame *m_videoFrame;
    QVideoWidget *m_videoWidget;

    QFrame *m_pageUrlFrame;

    QFrame *m_directUrlFrame;
    QFrame *m_mediaFormatFrame;

};
#endif // MAINWINDOW_H
