#include "../include/SaveFlightSystem.hpp"

#include <iostream>
#include <fstream>

int main() {
    Posicion posInit;
    Presion presInit;
    SaveFlightData FlightData(posInit, presInit);

    std::ifstream in("FlightData_serial.bin", std::ios::binary);

    if(in.is_open()){
        FlightData.deserializar(in);
        in.close();
    }

    std::cout << "REGISTRO DESERIALIZADO:" << std::endl << std::endl;
    FlightData.imprimir();
}