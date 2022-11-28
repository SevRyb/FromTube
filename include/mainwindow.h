#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QLabel>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QDebug>

class MainWindow : public QWidget
{
    Q_OBJECT

    void findUrl();
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QVBoxLayout *m_mainVBoxLay;

    /* Media Area */
    QVideoWidget *m_videoWidget;
    QHBoxLayout *m_videoHBoxLay;
    QFrame *m_videoFrame;

    /* Page Url Area */
    QLineEdit *m_pageUrlLEdit;
    QPushButton *m_findBtn;
    QHBoxLayout *m_pageUrlHBoxLay;
    QFrame *m_pageUrlFrame;

    /* Direct Url Area */
    QLineEdit *m_directUrlLEdit;
    QPushButton *m_copyBtn;
    QHBoxLayout *m_directUrlHBoxLay;
    QFrame *m_directUrlFrame;

    /* Format Area */
    QComboBox *m_audioFormatComboBox;
    QComboBox *m_videoFormatComboBox;
    QComboBox *m_outFormatComboBox;
    //QHBoxLayout *m_mediaFormatHBoxLay;
    QGridLayout *m_mediaFormatGridLay;
    QFrame *m_mediaFormatFrame;

    /* File Name */
    QLineEdit *m_fileNameLEdit;

    /* Download Dir Area */
    QLineEdit *m_downloadDirLEdit;
    QPushButton *m_openBtn;
    QHBoxLayout *m_downloadDirHBoxLay;
    QFrame *m_downloadDirFrame;

    /* Download Button */
    QPushButton *m_downloadBtn;

    /* Log Text */
    QTextEdit *m_logTextEdit;


};
#endif // MAINWINDOW_H
