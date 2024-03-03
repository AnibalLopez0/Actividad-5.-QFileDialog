#ifndef NEURON_H
#define NEURON_H
#include <iostream>
#include <list>
#include <Qstring>

/*class Neuron
{
public:
    Neuron();
};*/

class Neurona {
private:
    int id;
    float voltaje;
    int posX;
    int posY;
    int red;
    int green;
    int blue;

public:
    Neurona(int _id, float _voltaje, int _posX, int _posY, int _red, int _green, int _blue)
        : id(_id), voltaje(_voltaje), posX(_posX), posY(_posY), red(_red), green(_green), blue(_blue) {}

    QString obtenerInformacion() const {
        QString informacion;
        informacion += "ID: " + QString::number(id) + "\n";
        informacion += "Voltaje: " + QString::number(voltaje) + "\n";
        informacion += "Posición X: " + QString::number(posX) + "\n";
        informacion += "Posición Y: " + QString::number(posY) + "\n";
        informacion += "Red: " + QString::number(red) + "\n";
        informacion += "Green: " + QString::number(green) + "\n";
        informacion += "Blue: " + QString::number(blue) + "\n";
        return informacion;
    }

    QString InfoArchivo() const {
        QString informacion;
        informacion +=  QString::number(id) + "|";
        informacion +=  QString::number(voltaje) + "|";
        informacion +=  QString::number(posX) + "|";
        informacion +=  QString::number(posY) + "|";
        informacion +=  QString::number(red) + "|";
        informacion +=  QString::number(green) + "|";
        informacion +=  QString::number(blue) + "/";
        return informacion;
    }

    void print() const {
        std::cout << "ID: " << id << "\n"
                  << "Voltaje: " << voltaje << "\n"
                  << "Posición X: " << posX << "\n"
                  << "Posición Y: " << posY << "\n"
                  << "Red: " << red << "\n"
                  << "Green: " << green << "\n"
                  << "Blue: " << blue << "\n";
    }
};

class AdministradorNeuronas {
private:
    std::list<Neurona> listaNeuronas;

public:
    void agregarInicio(const Neurona& neurona) {
        listaNeuronas.push_front(neurona);
    }

    void agregarFinal(const Neurona& neurona) {
        listaNeuronas.push_back(neurona);
    }

    void mostrar() const {
        for (const auto& neurona : listaNeuronas) {
            neurona.print();
            std::cout << "------------------------\n";
        }
    }

    QString obtenerInformacion() const {
        QString informacion;
        for (const auto& neurona : listaNeuronas) {
            informacion += neurona.obtenerInformacion();
            informacion += "------------------------\n";
        }
        return informacion;
    }

    QString archivoSeparado() const {
        QString informacion;
        for (const auto& neurona : listaNeuronas) {
            informacion += neurona.InfoArchivo();

        }
        return informacion;
    }

    int numeroDeNeuronas() const {
        return listaNeuronas.size();
    }


};

#endif // NEURON_H
