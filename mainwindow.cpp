#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , flight("FL123", "Almaty", "Nur-Sultan", 100)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_bookButton_clicked() {
    QString firstName = ui->firstNameLineEdit->text();
    QString lastName = ui->lastNameLineEdit->text();
    QString id = ui->idLineEdit->text();
    QString phone = ui->phoneLineEdit->text();
    QString food = ui->foodComboBox->currentText();
    int seat = ui->seatSpinBox->value();
    int reservationNumber = rand() % 10000 + 1;

    Passenger passenger(firstName.toStdString(), lastName.toStdString(), id.toStdString(), phone.toStdString(), food.toStdString(), seat, reservationNumber);
    flight.bookTicket(passenger);
}