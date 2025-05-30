#include "../include/Mediciones.hpp"

#include <fstream>
#include <memory>

MedicionBase::MedicionBase(float t):
    tiempoMedicion (std::make_unique<float> (t)){}

float MedicionBase::getTiempo() const{
    return *tiempoMedicion;
}

void MedicionBase::serializar(std::ofstream& out) const {
    out.write(reinterpret_cast<const char*> (tiempoMedicion.get()), sizeof(*tiempoMedicion));    
}

void MedicionBase::deserializar(std::ifstream& in) {
    in.read(reinterpret_cast<char*> (tiempoMedicion.get()), sizeof(*tiempoMedicion));
}

