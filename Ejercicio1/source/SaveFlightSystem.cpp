#include "../include/SaveFlightSystem.hpp"

#include <iostream>
#include <fstream>

SaveFlightData::SaveFlightData(Posicion& pos, Presion& presion):
    posicion(pos), presion(presion){}

void SaveFlightData::serializar(std::ofstream& out) const {
    //Si hay algún fallo ya va a ser procesado por las serializaciones internas. Por tanto no es necesario chequear el ofstream
    posicion.serializar(out);
    presion.serializar(out);
}

void SaveFlightData::deserializar(std::ifstream& in) {
    //Si hay algún fallo ya va a ser procesado por las deserializaciones internas. Por tanto no es necesario chequear el ifstream
    posicion.deserializar(in);
    presion.deserializar(in);
}

void SaveFlightData::imprimir() {
    std::string linea(50, '-');

    std::cout << linea << std::endl;
    std::cout << "REGISTRO DE CAJA NEGRA" << std::endl;
    std::cout << linea << std::endl << std::endl;

    posicion.imprimir();
    std::cout << linea << std::endl << std::endl;
    presion.imprimir();
    std::cout << linea << std::endl << std::endl;
}

