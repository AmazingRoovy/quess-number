#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wordgameclass.h"
#include <ctime>
#include <time.h>
#include <QDebug>

WordGameClass wgc;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
        ui->setupUi(this);
        srand(time(NULL));
        wgc.tar = rand() % 10 + 1;
        QObject::connect(&wgc, SIGNAL(on_newgame()), &wgc, SLOT(new_game()));
        QObject::connect(&wgc, SIGNAL(on_quessed()), &wgc, SLOT(quessed()));
        QObject::connect(&wgc, SIGNAL(win()), &wgc, SLOT(on_win()));
        QObject::connect(&wgc, SIGNAL(less()), &wgc, SLOT(on_less()));
        QObject::connect(&wgc, SIGNAL(more()), &wgc, SLOT(on_more()));
    }

MainWindow::~MainWindow() {
    qDebug() << "Program is closed!" << endl;
    delete ui;
}

void MainWindow::on_quessButton_clicked() {
    wgc.cur = ui->lineEdit->text().toInt();
    emit wgc.on_quessed();
    ui->resultLabel->setText(wgc.mes);
}

void MainWindow::on_newGameButton_clicked() {
    //srand(time(NULL));
    wgc.tar = rand() % 10 + 1;
    ui->lineEdit->setText("");
    ui->resultLabel->setText("");
    emit wgc.on_newgame();
}
