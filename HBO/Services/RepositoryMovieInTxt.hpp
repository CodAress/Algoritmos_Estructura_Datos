#pragma once
#include "IMovieRepository.hpp"
#include <fstream>
#include <iostream>

class RepositoryMovieInTxt : public IMovieRepository
{
private:
    static inline std::string namefile = "E:/Algoritm/HBO/Sever/RegistrosPeliculas.txt";

public:
    Movie getMovieByTitle(const std::string& title) override
    {
        std::ifstream file(namefile);
        Movie loadedMovie("", "", "", "", ""); // Película cargada con valores iniciales
        bool found = false; // Variable para indicar si se encontró la película

        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                size_t delimiterPos = line.find(": ");
                if (delimiterPos != std::string::npos) {
                    std::string key = line.substr(0, delimiterPos);
                    std::string value = line.substr(delimiterPos + 2); // +2 para omitir ": "

                    if (key == "Nombre") {
                        loadedMovie.setName(value);
                    } else if (key == "Genero") {
                        loadedMovie.setGenre(value);
                    } else if (key == "Duracion") {
                        loadedMovie.setDuration(value);
                    } else if (key == "Clasificacion") {
                        loadedMovie.setClassification(value);
                    }

                } else if (line.empty()) {
                    if (loadedMovie.getName() == title) {
                        found = true;
                        break; // Película encontrada, salir del bucle
                    }
                    loadedMovie = Movie("", "", "", "", ""); // Reiniciar la película cargada
                }
            }
            file.close();

            if (found) {
                return loadedMovie; // Devolver la película encontrada
            } else {
                // Si no se encontró la película, devolver una película vacía o lanzar una excepción, según prefieras.
                std::cout << "Película no encontrada." << std::endl;
                return Movie("", "", "", "", "");
            }
        } else {
            std::cout << "Error al abrir el archivo para lectura." << std::endl;
            return loadedMovie; // Devolver una película vacía en caso de error
        }
        
    }
    Movie getMovieByID(const std::string& id) override
    {
        std::ifstream file(namefile);
        Movie loadedMovie("", "", "", "", ""); // Usuario cargado con valores iniciales

        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                size_t delimiterPos = line.find(": ");
                if (delimiterPos != std::string::npos) {
                    std::string key = line.substr(0, delimiterPos);
                    std::string value = line.substr(delimiterPos + 2); // +2 para omitir ": "

                    if (key == "ID") {
                        loadedMovie.setId(value); // Actualizar el ID del usuario cargado
                    } else if (key == "Nombre") {
                        loadedMovie.setName(value);
                    } else if (key == "Genero") {
                        loadedMovie.setGenre(value);
                    } else if (key == "Duracion") {
                        loadedMovie.setDuration(value);
                    } else if (key == "Clasificacion") {
                        loadedMovie.setClassification(value);
                    }

                } else if (line.empty()) {
                    if (loadedMovie.getId() == id) {
                        file.close();
                        return loadedMovie;
                    }
                    loadedMovie = Movie("", "", "", "", ""); // Reiniciar el usuario cargado
                }
            }
            file.close();
            return loadedMovie;
        } else {
            std::cout << "Error al abrir el archivo para lectura." << std::endl;
            return loadedMovie; // Usuario vacío en caso de error
        }
    }
    DoublyLinkedList<Movie> getAllMovies() override{
        std::ifstream file(namefile);
        DoublyLinkedList<Movie> Movies;
        if (file.is_open()) {
            std::string line;
            Movie loadedMovie("", "", "", "", ""); // Usuario cargado con valores iniciales

            while (std::getline(file, line)) 
            {
                size_t delimiterPos = line.find(": ");
                if (delimiterPos != std::string::npos) {
                    std::string key = line.substr(0, delimiterPos);
                    std::string value = line.substr(delimiterPos + 2); // +2 para omitir ": "

                if (key == "ID") {
                    loadedMovie.setId(value); // Actualizar el ID del usuario cargado
                } else if (key == "Nombre") {
                    loadedMovie.setName(value);
                } else if (key == "Genero") {
                    loadedMovie.setGenre(value);
                } else if (key == "Duracion") {
                    loadedMovie.setDuration(value);
                } else if (key == "Clasificacion") {
                    loadedMovie.setClassification(value);
                }
                } else if (line.empty()) {
                Movies.push_back(loadedMovie);
                loadedMovie = Movie("", "", "", "", ""); // Reiniciar el usuario cargado
                }
            }
            file.close();
            return Movies;
        } else {
            std::cerr << "Error al abrir el archivo para lectura." << std::endl;
            return Movies; // Lista vacía en caso de error
        }
    }
    DoublyLinkedList<Movie> getMoviesByClasification(const std::string& clasification) override
    {
        std::ifstream file(namefile);
        DoublyLinkedList<Movie> Movies;
        if (file.is_open()) {
            std::string line;
            Movie loadedMovie("", "", "", "", ""); // Usuario cargado con valores iniciales

            while (std::getline(file, line)) {
                size_t delimiterPos = line.find(": ");
                if (delimiterPos != std::string::npos) {
                    std::string key = line.substr(0, delimiterPos);
                    std::string value = line.substr(delimiterPos + 2); // +2 para omitir ": "

                    if (key == "ID") {
                        loadedMovie.setId(value); // Actualizar el ID del usuario cargado
                    } else if (key == "Nombre") {
                        loadedMovie.setName(value);
                    } else if (key == "Genero") {
                        loadedMovie.setGenre(value);
                    } else if (key == "Duracion") {
                        loadedMovie.setDuration(value);
                    } else if (key == "Clasificacion") {
                        loadedMovie.setClassification(value);
                    }
                } else if (line.empty()) {
                    if (loadedMovie.getClassification() == clasification) {
                        Movies.push_back(loadedMovie);
                    }
                    loadedMovie = Movie("", "", "", "", ""); // Reiniciar el usuario cargado
                }
            }
            file.close();
            return Movies;
        } else {
            std::cerr << "Error al abrir el archivo para lectura." << std::endl;
            return Movies; // Lista vacía en caso de error
        }
    }

    DoublyLinkedList<Movie> getMoviesByGenre(const std::string& genre) override
    {
        std::ifstream file(namefile);
        DoublyLinkedList<Movie> Movies;
        if (file.is_open()) {
            std::string line;
            Movie loadedMovie("", "", "", "", ""); // Usuario cargado con valores iniciales

            while (std::getline(file, line)) {
                size_t delimiterPos = line.find(": ");
                if (delimiterPos != std::string::npos) {
                    std::string key = line.substr(0, delimiterPos);
                    std::string value = line.substr(delimiterPos + 2); // +2 para omitir ": "

                    if (key == "ID") {
                        loadedMovie.setId(value); // Actualizar el ID del usuario cargado
                    } else if (key == "Nombre") {
                        loadedMovie.setName(value);
                    } else if (key == "Genero") {
                        loadedMovie.setGenre(value);
                    } else if (key == "Duracion") {
                        loadedMovie.setDuration(value);
                    } else if (key == "Clasificacion") {
                        loadedMovie.setClassification(value);
                    }
                } else if (line.empty()) {
                    if (loadedMovie.getGenre() == genre) {
                        Movies.push_back(loadedMovie);
                    }
                    loadedMovie = Movie("", "", "", "", ""); // Reiniciar el usuario cargado
                }
            }
            file.close();
            return Movies;
        } else {
            std::cerr << "Error al abrir el archivo para lectura." << std::endl;
            return Movies; // Lista vacía en caso de error
        }
    }
};

