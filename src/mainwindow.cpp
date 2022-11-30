#include "mainwindow.h"
//#include <Python.h>
//#include <pybind11/embed.h>
#include <QMediaPlayer>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{

    QFont f = font();
    f.setPointSize(10);
    setFont(f);

    resize(700, 600);

    //m_mainVBoxLay = new QVBoxLayout();
    m_mainGridLay = new QGridLayout();
    //m_mainGridLay->setColumnMinimumWidth(0, 165);
    //m_mainGridLay->setColumnMinimumWidth(1, 165);
    //m_mainGridLay->setColumnMinimumWidth(2, 21);
    m_mainGridLay->setColumnStretch(0, 1);
    m_mainGridLay->setColumnStretch(1, 1);
    m_mainGridLay->setColumnStretch(2, 0);
    m_mainGridLay->setColumnStretch(3, 1);
    m_mainGridLay->setColumnStretch(4, 1);
    m_mainGridLay->setColumnStretch(5, 1);

    //m_mainVBoxLay->setMargin(0);
    setLayout(m_mainGridLay);



    /* Media Area */
    m_videoWidget = new QVideoWidget(this);
    m_videoWidget->setFixedSize(width(), 300);
    //m_videoWidget->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

//    m_videoHBoxLay = new QHBoxLayout();
//    m_videoHBoxLay->setMargin(0);
//    m_videoHBoxLay->setSpacing(0);
//    m_videoHBoxLay->addWidget(m_videoWidget, 1, Qt::AlignCenter);
//    m_videoHBoxLay->addWidget(new QPushButton("▶", this));

    //m_videoFrame = new QFrame(this);
    //m_videoFrame->setLayout(m_videoHBoxLay);

    m_durationSlider = new QSlider(Qt::Horizontal, this);
    //m_durationSlider->setTickInterval(1);
    m_playBtn = new QPushButton("▶", this);
    m_playBtn->setFixedWidth(30);

    /* Page Url Area */
    m_pageUrlLEdit = new QLineEdit(this);
    m_findBtn = new QPushButton("Find", this);
//    m_pageUrlHBoxLay = new QHBoxLayout();
//    m_pageUrlHBoxLay->setMargin(0);
//    m_pageUrlHBoxLay->addWidget(m_pageUrlLEdit);
//    m_pageUrlHBoxLay->addWidget(m_findBtn);
//    m_pageUrlFrame = new QFrame(this);
//    m_pageUrlFrame->setLayout(m_pageUrlHBoxLay);

    /* Direct Url Area */
//    m_directUrlLEdit = new QLineEdit(this);
//    m_copyBtn = new QPushButton("Copy", this);
//    m_directUrlHBoxLay = new QHBoxLayout();
//    m_directUrlHBoxLay->setMargin(0);
//    m_directUrlHBoxLay->addWidget(m_directUrlLEdit);
//    m_directUrlHBoxLay->addWidget(m_copyBtn);
//    m_directUrlFrame = new QFrame(this);
//    m_directUrlFrame->setLayout(m_directUrlHBoxLay);

    /* Format Area */
    m_chooseAudioBtn = new QPushButton("Audio", this);
    m_chooseVideoBtn = new QPushButton("Video", this);
    m_chooseMixedBtn = new QPushButton("Mixed", this);

    m_audioFormatComboBox = new QComboBox(this);
    m_videoFormatComboBox = new QComboBox(this);
    m_mediaFormatGridLay = new QGridLayout();
    m_mediaFormatGridLay->setColumnStretch(2, 0);
    m_mediaFormatGridLay->setColumnStretch(2, 0);
    m_mediaFormatGridLay->setColumnStretch(2, 0);
    m_mediaFormatGridLay->setMargin(0);
    m_mediaFormatGridLay->addWidget(m_audioFormatComboBox, 0, 0, 1, 2);
    m_mediaFormatGridLay->addWidget(new QLabel("+", this), 0, 2, 1, 1);
    m_mediaFormatGridLay->addWidget(m_videoFormatComboBox, 0, 3, 1, 2);

    m_outFormatComboBox = new QComboBox(this);


//    m_mediaFormatGridLay->addWidget(new QLabel("Audio", this), 0, 0);
//    m_mediaFormatGridLay->addWidget(new QLabel("Video", this), 0, 2);
    //m_mediaFormatGridLay->addWidget(new QLabel("Out", this), 0, 4);
//    m_mediaFormatGridLay->addWidget(m_audioFormatComboBox, 1, 0);
//    m_mediaFormatGridLay->addWidget(new QLabel("+", this), 1, 1, Qt::AlignCenter);
//    m_mediaFormatGridLay->addWidget(m_videoFormatComboBox, 1, 2);
//    m_mediaFormatGridLay->addWidget(new QLabel("=", this), 1, 3, Qt::AlignCenter);
//    m_mediaFormatGridLay->addWidget(new QLabel("Mixed", this), 2, 0);
//    m_mediaFormatGridLay->addWidget(m_outFormatComboBox, 3, 0);
//    m_mediaFormatFrame = new QFrame(this);
//    m_mediaFormatFrame->setLayout(m_mediaFormatGridLay);

    /* File Name */
    m_fileNameLEdit = new QLineEdit(this);

    /* Download Dir Area */
    m_downloadDirLEdit = new QLineEdit(this);
    m_openBtn = new QPushButton("Open", this);
//    m_downloadDirHBoxLay = new QHBoxLayout();
//    m_downloadDirHBoxLay->setMargin(0);
//    m_downloadDirHBoxLay->addWidget(m_downloadDirLEdit);
//    m_downloadDirHBoxLay->addWidget(m_openBtn);
//    m_downloadDirFrame = new QFrame(this);
//    m_downloadDirFrame->setLayout(m_downloadDirHBoxLay);

    /* Log Text */
    m_logTextEdit = new QTextEdit(this);

    /* Download Button */
    m_downloadBtn = new QPushButton("Download", this);
    //m_downloadBtn->setFixedSize(100, 40);


    /* Layouts */
    m_mainGridLay->addWidget(m_videoWidget, 0, 0, 1, 6);

    m_mainGridLay->addWidget(m_durationSlider, 1, 0, 1, 5);
    m_mainGridLay->addWidget(m_playBtn, 1, 5, 1, 1);

    m_mainGridLay->addWidget(new QLabel("Page url", this), 2, 0, 1, 6);

    m_mainGridLay->addWidget(m_pageUrlLEdit, 3, 0, 1, 5);
    m_mainGridLay->addWidget(m_findBtn, 3, 5, 1, 1);

    m_mainGridLay->addWidget(m_chooseAudioBtn, 4, 0, 1, 1);
    m_mainGridLay->addWidget(m_chooseVideoBtn, 4, 3, 1, 1);

    m_mainGridLay->addLayout(m_mediaFormatGridLay, 5, 0, 1, 6);

    m_mainGridLay->addWidget(m_chooseMixedBtn, 6, 0, 1, 1);

    m_mainGridLay->addWidget(m_outFormatComboBox, 7, 0, 1, 6);

    m_mainGridLay->addWidget(new QLabel("Name", this), 8, 0, 1, 6);

    m_mainGridLay->addWidget(m_fileNameLEdit, 9, 0, 1, 6);

    m_mainGridLay->addWidget(new QLabel("Download directory", this), 10, 0, 1, 6);

    m_mainGridLay->addWidget(m_downloadDirLEdit, 11, 0, 1, 5);
    m_mainGridLay->addWidget(m_openBtn, 11, 5, 1, 1);

    m_mainGridLay->addWidget(new QLabel("Log", this), 12, 0, 1, 5);

    m_mainGridLay->addWidget(m_logTextEdit, 13, 0, 1, 5);
    m_mainGridLay->addWidget(m_downloadBtn, 13, 5, 1, 1);


//    m_mainVBoxLay->addWidget(m_downloadBtn, 0, Qt::AlignRight);
//    m_mainVBoxLay->addWidget(new QLabel("Log", this));
//    m_mainVBoxLay->addWidget(m_logTextEdit);

//    QMediaPlayer *media_player = new QMediaPlayer(this);
//    media_player->setMedia(QUrl::fromLocalFile("S:\\MyWork\\Programming\\Python\\Projects\\FromTube_cmd\\Segmented Displays-RTB5XhjbgZA.webm"));
//    media_player->setVideoOutput(m_videoWidget);
//    media_player->play();

    //connect(btn, &QPushButton::pressed, this, &MainWindow::findUrl);
}


void MainWindow::findUrl()
{
    qDebug() << "Some data";
}


MainWindow::~MainWindow()
{
}

