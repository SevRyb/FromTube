#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QFrame>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QSlider>
#include <QLabel>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QDebug>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    //QVBoxLayout *m_mainVBoxLay;
    QGridLayout *m_mainGridLay;

    /* Media Area */
    QVideoWidget *m_videoWidget;
    //QHBoxLayout *m_videoHBoxLay;
    QFrame *m_videoFrame;

    //QFrame *m_controlsFrame;
    QHBoxLayout *m_controlsHBoxLay;
    QSlider *m_durationSlider;
    QPushButton *m_playBtn;

    /* Page Url Area */
    QLineEdit *m_pageUrlLEdit;
    QPushButton *m_findBtn;


    /* Direct Url Area */
//    QLineEdit *m_directUrlLEdit;
//    QPushButton *m_copyBtn;
//    QHBoxLayout *m_directUrlHBoxLay;
//    QFrame *m_directUrlFrame;

    /* Format Area */
    QPushButton *m_chooseAudioBtn;
    QPushButton *m_chooseVideoBtn;
    QPushButton *m_chooseMixedBtn;
    QComboBox *m_audioFormatComboBox;
    QComboBox *m_videoFormatComboBox;
    QComboBox *m_outFormatComboBox;
    QGridLayout *m_mediaFormatGridLay;


    /* File Name */
    QLineEdit *m_fileNameLEdit;

    /* Download Dir Area */
    QLineEdit *m_downloadDirLEdit;
    QPushButton *m_openBtn;
//    QHBoxLayout *m_downloadDirHBoxLay;
//    QFrame *m_downloadDirFrame;

    /* Download Button */
    QPushButton *m_downloadBtn;

    /* Log Text */
    QTextEdit *m_logTextEdit;

private  Q_SLOTS:
    void findUrl();


};
#endif // MAINWINDOW_H
