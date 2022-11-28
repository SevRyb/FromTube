#include "mainwindow.h"
//#include <Python.h>
//#include <pybind11/embed.h>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{

    resize(600, 600);

    m_mainVBoxLay = new QVBoxLayout();
    //m_mainVBoxLay->setMargin(0);
    setLayout(m_mainVBoxLay);

    /* Media Area */
    m_videoWidget = new QVideoWidget(this);
    m_videoHBoxLay = new QHBoxLayout();
    m_videoHBoxLay->setMargin(0);
    m_videoHBoxLay->addWidget(m_videoWidget);
    m_videoFrame = new QFrame(this);
    m_videoFrame->setLayout(m_videoHBoxLay);

    /* Page Url Area */
    m_pageUrlLEdit = new QLineEdit(this);
    m_findBtn = new QPushButton("Find", this);
    m_pageUrlHBoxLay = new QHBoxLayout();
    m_pageUrlHBoxLay->setMargin(0);
    m_pageUrlHBoxLay->addWidget(m_pageUrlLEdit);
    m_pageUrlHBoxLay->addWidget(m_findBtn);
    m_pageUrlFrame = new QFrame(this);
    m_pageUrlFrame->setLayout(m_pageUrlHBoxLay);

    /* Direct Url Area */
    m_directUrlLEdit = new QLineEdit(this);
    m_copyBtn = new QPushButton("Copy", this);
    m_directUrlHBoxLay = new QHBoxLayout();
    m_directUrlHBoxLay->setMargin(0);
    m_directUrlHBoxLay->addWidget(m_directUrlLEdit);
    m_directUrlHBoxLay->addWidget(m_copyBtn);
    m_directUrlFrame = new QFrame(this);
    m_directUrlFrame->setLayout(m_directUrlHBoxLay);

    /* Format Area */
    m_audioFormatComboBox = new QComboBox(this);
    m_videoFormatComboBox = new QComboBox(this);
    m_outFormatComboBox = new QComboBox(this);
    m_mediaFormatGridLay = new QGridLayout();
    m_mediaFormatGridLay->setMargin(0);
    m_mediaFormatGridLay->setColumnStretch(0, 1);
    m_mediaFormatGridLay->setColumnStretch(2, 1);
    m_mediaFormatGridLay->setColumnStretch(4, 1);
    m_mediaFormatGridLay->addWidget(new QLabel("Audio", this), 0, 0);
    m_mediaFormatGridLay->addWidget(new QLabel("Video", this), 0, 2);
    m_mediaFormatGridLay->addWidget(new QLabel("Out", this), 0, 4);
    m_mediaFormatGridLay->addWidget(m_audioFormatComboBox, 1, 0);
    m_mediaFormatGridLay->addWidget(new QLabel("+", this), 1, 1, Qt::AlignCenter);
    m_mediaFormatGridLay->addWidget(m_videoFormatComboBox, 1, 2);
    m_mediaFormatGridLay->addWidget(new QLabel("=", this), 1, 3, Qt::AlignCenter);
    m_mediaFormatGridLay->addWidget(m_outFormatComboBox, 1, 4);
    m_mediaFormatFrame = new QFrame(this);
    m_mediaFormatFrame->setLayout(m_mediaFormatGridLay);

    /* File Name */
    m_fileNameLEdit = new QLineEdit(this);

    /* Download Dir Area */
    m_downloadDirLEdit = new QLineEdit(this);
    m_openBtn = new QPushButton("Open", this);
    m_downloadDirHBoxLay = new QHBoxLayout();
    m_downloadDirHBoxLay->setMargin(0);
    m_downloadDirHBoxLay->addWidget(m_downloadDirLEdit);
    m_downloadDirHBoxLay->addWidget(m_openBtn);
    m_downloadDirFrame = new QFrame(this);
    m_downloadDirFrame->setLayout(m_downloadDirHBoxLay);

    /* Log Text */
    m_logTextEdit = new QTextEdit(this);

    /* Download Button */
    m_downloadBtn = new QPushButton("Download", this);
    m_downloadBtn->setFixedSize(80, 40);


    /* Layouts */
    m_mainVBoxLay->addWidget(m_videoFrame);
    m_mainVBoxLay->addWidget(new QLabel("Page url", this));
    m_mainVBoxLay->addWidget(m_pageUrlFrame);
    m_mainVBoxLay->addWidget(new QLabel("Direct url", this));
    m_mainVBoxLay->addWidget(m_directUrlFrame);
    //m_mainVBoxLay->addWidget(new QLabel("Format", this));
    m_mainVBoxLay->addWidget(m_mediaFormatFrame);
    m_mainVBoxLay->addWidget(new QLabel("Name", this));
    m_mainVBoxLay->addWidget(m_fileNameLEdit);
    m_mainVBoxLay->addWidget(new QLabel("Download directory", this));
    m_mainVBoxLay->addWidget(m_downloadDirFrame);
    m_mainVBoxLay->addWidget(m_downloadBtn, 0, Qt::AlignRight);
    m_mainVBoxLay->addWidget(new QLabel("Log", this));
    m_mainVBoxLay->addWidget(m_logTextEdit);


    //connect(btn, &QPushButton::pressed, this, &MainWindow::findUrl);
}


void MainWindow::findUrl()
{
    qDebug() << "Some data";
}


MainWindow::~MainWindow()
{
}

