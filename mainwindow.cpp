#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QFontDialog>
#include <QColorDialog>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //to expand the text and eliminate gaps in corners
    setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//function to open files
void MainWindow::on_actionOpen_triggered()
{
    QFile file;
    QTextStream io;
    QString filename;

    filename = QFileDialog::getOpenFileName(this, "Open");
    file.setFileName(filename);
    //check if name of file is not empty
    if (filename.isEmpty()) {
        return;
    }
    //open
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    //check if file was not opened
    if (!file.isOpen()) {
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }

    io.setDevice(&file);
    ui->textEdit->setPlaceholderText(io.readAll());

    //close the file
    file.close();

}

//function to save
void MainWindow::on_actionSave_as_triggered()
{
    QFile file;
    QTextStream io;
    QString filename;
    filename = QFileDialog::getSaveFileName(this, "Save");
    //check if name of file is not empty
    if (filename.isEmpty()) {
        return;
    }
    file.setFileName(filename);
    //open
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    //check for error
    if (!file.isOpen()) {
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }

    //set the device file.
    io.setDevice(&file);
    //we write on it all the contenct of plain text
    io << ui->textEdit->toPlainText();

    //clean
    file.flush();
    file.close();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionMore_Info_triggered()
{
    QMessageBox::aboutQt(this, "Qt");
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

//function to display more info about developer
void MainWindow::on_actionAbout_Developer_triggered()
{
    QString txt;
    txt = "Author: Gonzalo Carrasco\n";
    txt += "Date : 6/15/2018\n";
    txt += "Software : Notepad\n";
    QMessageBox::about(this, "Notepad",txt);

}

//function to change font color
void MainWindow::on_actionColor_2_triggered()
{
    QColor color;
    QColorDialog::getColor(Qt::white, this);
    //we set the text color passing our color variable
    ui->textEdit->setTextColor(color);
}
//function to change font style in text
void MainWindow::on_actionType_triggered()
{
    bool isFont;
    QFont font;
    font = QFontDialog::getFont(&isFont,this);
    if (!isFont) {
        return;
    }

    ui->textEdit->setFontPointSize(font.pointSizeF());
    ui->textEdit->setFontFamily(font.family());
}

void MainWindow::on_actionBackground_Color_triggered()
{
    QColor color;
    QColorDialog::getColor(Qt::white, this);
    //we set the text color passing our color variable
    ui->textEdit->setPalette(QPalette(color));
}

//function to print, needed to add "printsupport" in notepad.pro
void MainWindow::on_actionPrint_triggered()
{
    QPrinter *printerMachine;
    QPrintDialog pd(this);
    //check
    if (pd.exec() == QDialog::Rejected) {
        return;
    }

    printerMachine = pd.printer();
    ui->textEdit->print(printerMachine);

}















