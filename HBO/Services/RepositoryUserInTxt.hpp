#pragma once
#include "IUserRepository.hpp"
#include <fstream>
#include <iostream>

class RepositoryUserInTxt : public IUserRepository
{
private:
    static inline std::string namefile = "RegistrosUsuarios.txt";

public:
    std::string getPasswordByEmail(const std::string& email) override
    {
        std::ifstream file(namefile);
        if (file.is_open()) {
            std::string line;
            std::string password = ""; // Contraseña cargada con valor inicial

            while (std::getline(file, line)) {
                size_t delimiterPos = line.find(": ");
                if (delimiterPos != std::string::npos) {
                    std::string key = line.substr(0, delimiterPos);
                    std::string value = line.substr(delimiterPos + 2); // +2 para omitir ": "

                    if (key == "Email" && value == email) {
                        std::getline(file, line); // Obtener la siguiente línea
                        delimiterPos = line.find(": ");
                        if (delimiterPos != std::string::npos) {
                            key = line.substr(0, delimiterPos);
                            value = line.substr(delimiterPos + 2); // +2 para omitir ": "

                            if (key == "Password") {
                                password = value; // Actualizar la contraseña cargada
                            }
                        }
                    }
                }
            }
            file.close();
            return password;
        } else {
            std::cout << "Error al abrir el archivo para lectura." << std::endl;
            return ""; // Contraseña vacía en caso de error
        }
    }
    User getUser(const std::string& id) override
    {
        std::ifstream file(namefile);
        if (file.is_open()) {
            std::string line;
            User loadedUser("", "", "", "", ""); // Usuario cargado con valores iniciales

            while (std::getline(file, line)) {
                size_t delimiterPos = line.find(": ");
                if (delimiterPos != std::string::npos) {
                    std::string key = line.substr(0, delimiterPos);
                    std::string value = line.substr(delimiterPos + 2); // +2 para omitir ": "

                    if (key == "ID" && value == id) {
                        loadedUser.setId(value); // Actualizar el ID del usuario cargado
                    } else if (key == "Password") {
                        loadedUser.setPassword(value);
                    } else if (key == "Nombre") {
                        loadedUser.setName(value);
                    } else if (key == "Apellido") {
                        loadedUser.setLastName(value);
                    } else if (key == "Email") {
                        loadedUser.setEmail(value);
                    }
                }
            }
            file.close();
            return loadedUser;
        } else {
            std::cout << "Error al abrir el archivo para lectura." << std::endl;
            return User("", "", "", "", ""); // Usuario vacío en caso de error
        }
    }
    DoublyLinkedList<User> getAllUsers() override
    {
        std::ifstream file(namefile);
        DoublyLinkedList<User> users;
        if (file.is_open()) {
            std::string line;
            User loadedUser("", "", "", "", ""); // Usuario cargado con valores iniciales

            while (std::getline(file, line)) {
                size_t delimiterPos = line.find(": ");
                if (delimiterPos != std::string::npos) {
                    std::string key = line.substr(0, delimiterPos);
                    std::string value = line.substr(delimiterPos + 2); // +2 para omitir ": "

                    if (key == "ID") {
                        loadedUser.setId(value); // Actualizar el ID del usuario cargado
                    } else if (key == "Password") {
                        loadedUser.setPassword(value);
                    } else if (key == "Nombre") {
                        loadedUser.setName(value);
                    } else if (key == "Apellido") {
                        loadedUser.setLastName(value);
                    } else if (key == "Email") {
                        loadedUser.setEmail(value);
                    }
                } else if (line.empty()) {
                    users.push_back(loadedUser);
                    loadedUser = User("", "", "", "", ""); // Reiniciar el usuario cargado
                }
            }
            file.close();
            return users;
        } else {
            std::cerr << "Error al abrir el archivo para lectura." << std::endl;
            return users; // Lista vacía en caso de error
        }
    }
};