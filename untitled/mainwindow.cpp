#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , flight("FL123", "Almaty", "Nur-Sultan", "2025-01-08", 100)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_bookButton_clicked() {
    QString firstName = ui->firstNameLineEdit->text();
    QString lastName = ui->lastNameLineEdit->text();
    QString ssn = ui->idLineEdit->text();
    QString phone = ui->phoneLineEdit->text();
    QString food = ui->foodComboBox->currentText();
    int seat = ui->seatSpinBox->value();
    int reservationNumber = flight.nextReservationNumber++;

    Passenger passenger(firstName.toStdString(), lastName.toStdString(), ssn.toStdString(), phone.toStdString(), food.toStdString(), seat, reservationNumber);
    bool success = flight.bookTicket(passenger);

    if (success) {
        ui->statusLabel->setText("Reservation completed");
    } else {
        ui->statusLabel->setText("Error: Seat already booked");
    }
}