#include "mainwindow.h"
#include "stdio.h"
#include "ui_mainwindow.h"
#include "neuron.h"
#include "QPlainTextEdit"
#include "QSpinBox"
#include "QFile"
#include "QTextStream"
#include "QFileDialog"

AdministradorNeuronas administrador;

//Neurona neurona1(ID, VOL, X, Y, R, G, B);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()//mostrar
{
    ui->plainTextEdit->clear();
    ui->plainTextEdit->insertPlainText(administrador.obtenerInformacion());
}


void MainWindow::on_plainTextEdit_modificationChanged(bool arg1)//muestra caja
{
    ui->plainTextEdit->setReadOnly(true);
}


void MainWindow::on_pushButton_clicked()//añadir inicio
{
    int ID;
    float VOL;
    int X, Y;
    int R, G, B;
    ID = ui->spinBox->value();
    VOL = ui->doubleSpinBox->value();
    X = ui->spinBox_2->value();
    Y = ui->spinBox_3->value();
    R = ui->spinBox_4->value();
    G = ui->spinBox_5->value();
    B = ui->spinBox_6->value();
    Neurona n(ID, VOL, X, Y, R, G, B);
    administrador.agregarInicio(n);
}


void MainWindow::on_pushButton_3_clicked()//añadir final
{
    //administrador.agregarFinal(neurona1);
    int ID;
    float VOL;
    int X, Y;
    int R, G, B;
    ID = ui->spinBox->value();
    VOL = ui->doubleSpinBox->value();
    X = ui->spinBox_2->value();
    Y = ui->spinBox_3->value();
    R = ui->spinBox_4->value();
    G = ui->spinBox_5->value();
    B = ui->spinBox_6->value();
    Neurona n(ID, VOL, X, Y, R, G, B);
    administrador.agregarFinal(n);
}


void MainWindow::on_spinBox_valueChanged(int arg1)//no borrar, no sabes que pasa
{

}


void MainWindow::on_actionAbrir_archivo_triggered()//abrir
{
    // Obtener el nombre del archivo seleccionado
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Abrir archivo", "", "Archivos de texto (*.txt)");

    if (!fileName.isEmpty()) {
        // Intentar abrir el archivo
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {

            // Crear un QTextStream para leer del archivo
            QTextStream in(&file);

            // Leer el contenido del archivo línea por línea
            while (!in.atEnd()) {
                // Leer una línea del archivo
                QString line = in.readLine();

                // Separar las neuronas utilizando el separador "/"
                QStringList neuronas = line.split("/");

                // Procesar cada neurona
                for (const QString& neuronaStr : neuronas) {
                    // Separar los valores de la neurona utilizando el separador "|"
                    QStringList valores = neuronaStr.split("|");

                    // Verificar si la neurona tiene la cantidad esperada de valores
                    if (valores.size() == 7) {
                        int id = valores[0].toInt();
                        float voltaje = valores[1].toFloat();
                        int posX = valores[2].toInt();
                        int posY = valores[3].toInt();
                        int red = valores[4].toInt();
                        int green = valores[5].toInt();
                        int blue = valores[6].toInt();

                        // Crear una neurona con los datos obtenidos y agregarla al administrador
                        Neurona neurona(id, voltaje, posX, posY, red, green, blue);
                        administrador.agregarFinal(neurona);
                    }
                }
            }

            // Cerrar el archivo después de leerlo
            file.close();

            // Aquí puedes utilizar el administrador de neuronas para realizar alguna acción,
            // como mostrar las neuronas en un QPlainTextEdit o hacer cualquier otra cosa que necesites.
        } else {
            // Mostrar un mensaje de error si no se pudo abrir el archivo
            qDebug() << "Error: no se pudo abrir el archivo para leer";
        }
    }

}




void MainWindow::on_actionGuardar_2_triggered()//guardar
{
    QString rutaArchivo = QFileDialog::getSaveFileName(this, "Guardar archivo", "", "Archivos de texto (*.txt)");

    // Verificar si el usuario canceló la selección del archivo
    if (rutaArchivo.isEmpty()) {
        return; // Salir sin hacer nada
    }

    // Crear un objeto QFile para el archivo seleccionado
    QFile archivo(rutaArchivo);

    // Intentar abrir el archivo en modo de escritura
    if (archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // Crear un objeto QTextStream para escribir en el archivo
        QTextStream out(&archivo);

        // Escribir la información en el archivo
        out << administrador.archivoSeparado();

        // Cerrar el archivo
        archivo.close();
    } else {
        // Mostrar un mensaje de error si no se pudo abrir el archivo
        qDebug() << "Error: no se pudo abrir el archivo para escribir";
    }

}

