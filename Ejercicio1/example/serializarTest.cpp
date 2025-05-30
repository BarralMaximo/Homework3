#include "../include/SaveFlightSystem.hpp"

#include <iostream>
#include <fstream>

int main() {
    Posicion posicion(-34.6f, -58.4f, 950.0f, 5.3f);
    Presion presion(101.3f, 5.8f, 6.1f);

    SaveFlightData FlightData(posicion, presion);

    std::cout << "SERIALIZANDO EL SIGUIENTE REGISTRO:" << std::endl;

    FlightData.imprimir();

    std::ofstream out("FlightData_serial.bin", std::ios::binary);
    if(out.is_open()){
        FlightData.serializar(out);
        out.close();
    }

    std::cout << "SERIALIZACIÓN EXITOSA";
}