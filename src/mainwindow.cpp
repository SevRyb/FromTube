#include "mainwindow.h"
//#include <Python.h>
//#include <pybind11/embed.h>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{

    resize(600, 600);

    QTextEdit* text_edit = new QTextEdit(this);

    QPushButton* btn = new QPushButton(this);
    btn->setText(tr("Hello world! %1").arg(100));

    QVBoxLayout* main_lay = new QVBoxLayout();
    main_lay->addWidget(text_edit);
    main_lay->addWidget(btn);

    setLayout(main_lay);

    connect(btn, &QPushButton::pressed, this, &MainWindow::findUrl);
}


void MainWindow::findUrl()
{
    qDebug() << "Some data";
}


MainWindow::~MainWindow()
{
}

