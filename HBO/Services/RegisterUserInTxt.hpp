#pragma once
#include "IUserRegister.hpp"
#include <fstream>
#include <iostream>

class RegisterUserInTxt : public IUserRegister
{
private:
    static inline std::string fileName = "RegistrosUsuarios.txt";

public:
    void registerUser(const User& newUser) override;
};


void RegisterUserInTxt::registerUser(const User& newUser)
{
    std::ofstream file(fileName, std::ios::app);
    if (file.is_open()) {
        file << "ID: " << newUser.getId() << std::endl;
        file << "Password: " << newUser.getPassword() << std::endl;
        file << "Nombre: " << newUser.getName() << std::endl;
        file << "Apellido: " << newUser.getLastName() << std::endl;
        file << "Email: " << newUser.getEmail() << std::endl;
        file << std::endl; // Separador entre usuarios
        file.close();
        std::cout << "Datos del usuario guardados en " << fileName << std::endl;
    } else {
        std::cout << "Error al abrir el archivo para escritura." << std::endl;
    }
}
