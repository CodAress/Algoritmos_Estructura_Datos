#pragma once
#include <fstream>
#include <iostream>


#include "IMovieRegister.hpp"

class RegisterMovieInTxt : public IMovieRegister
{
private:
    static inline std::string fileName = "E:/Algoritm/HBO/Sever/RegistrosPeliculas.txt";

public:

    void registerMovie(const Movie& newMovie) override
    {
        try {
            std::ofstream file(fileName, std::ios::app);
            if (file.is_open()) {
                file << "ID: " << newMovie.getId() << std::endl;
                file << "Nombre: " << newMovie.getName() << std::endl;
                file << "Genero: " << newMovie.getGenre() << std::endl;
                file << "Duracion: " << newMovie.getDuration() << std::endl;
                file << "Clasificacion: " << newMovie.getClassification() << std::endl;
                file << std::endl; // Separador entre peliculas
                file.close();
                std::cout << "Datos de la pelicula guardados en " << fileName << std::endl;
            } else {
                std::cout << "Error al abrir el archivo para escritura." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cout << "Excepción: " << e.what() << std::endl;
        }
    }
};
