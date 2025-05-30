#include "../include/Presion.hpp"

#include <fstream>
#include <iostream>

Presion::Presion(float p, float q, float t):
    MedicionBase(t), presionEstatica(p), presionDinamica(q){}

void Presion::imprimir() const {
    std::cout << "Presion registrada en tiempo = " << getTiempo() << std::endl << std::endl << "DATOS:"<< std::endl << std::endl;
    std::cout << "PRESIÓN ESTÁTICA = " << presionEstatica << std::endl;
    std::cout << "PRESIÓN DINÁMICA = " << presionDinamica << std::endl << std::endl;;
}

void Presion::serializar(std::ofstream& out) const {
    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*> (&presionDinamica), sizeof(presionDinamica));
    out.write(reinterpret_cast<const char*> (&presionEstatica), sizeof(presionEstatica));

    if(!out){
        throw std::runtime_error("ERROR: Falla al serializar la presión");
    }
}

void Presion::deserializar(std::ifstream& in) {
    MedicionBase::deserializar(in);
    in.read(reinterpret_cast<char*> (&presionDinamica), sizeof(presionDinamica));
    in.read(reinterpret_cast<char*> (&presionEstatica), sizeof(presionEstatica));

    if (!in){
        throw std::runtime_error("ERROR: Falla al deserializar la presión");
    }
}

