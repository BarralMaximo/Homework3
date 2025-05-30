#include "../include/Posicion.hpp"

#include <fstream>
#include <iostream>

Posicion::Posicion(float latitud, float longitud, float altitud, float t):
    MedicionBase(t), latitud(latitud), longitud(longitud), altitud(altitud) {}

void Posicion::imprimir() const {
    std::cout << "Posición registrada en tiempo = " << getTiempo() << std::endl << std::endl << "DATOS:"<< std::endl << std::endl;
    std::cout << "LATITUD = " << latitud << std::endl;
    std::cout << "LONGITUD = " << longitud << std::endl;
    std::cout << "ALTITUD = " << altitud << std::endl << std::endl;;
}

void Posicion::serializar(std::ofstream& out) const {
    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*>(&latitud), sizeof(latitud));
    out.write(reinterpret_cast<const char*>(&longitud), sizeof(longitud));
    out.write(reinterpret_cast<const char*>(&altitud), sizeof(altitud));

    if (!out) {
        throw std::runtime_error("ERROR: Falla al serializar datos de Posicion");
    }
}

void Posicion::deserializar(std::ifstream& in) {
    MedicionBase::deserializar(in);
    in.read(reinterpret_cast<char*>(&latitud), sizeof(latitud));
    in.read(reinterpret_cast<char*>(&longitud), sizeof(longitud));
    in.read(reinterpret_cast<char*>(&altitud), sizeof(altitud));

    if (!in) {
        throw std::runtime_error("ERROR: Falla al deserializar datos de Posicion");
    }
}
