#pragma once
#include "../Services/RegisterMovieInTxt.hpp"
#include "../Services/RepositoryMovieInTxt.hpp"

class ManagerMovie
{
private:
    static ManagerMovie* managerMovie;
    ManagerMovie()
    {
        MovieRepository = new RepositoryMovieInTxt();
        MovieRegister = new RegisterMovieInTxt();
    }

private:
    IMovieRegister* MovieRegister;
    IMovieRepository* MovieRepository;

public:
    ManagerMovie(const ManagerMovie&) = delete;
    ~ManagerMovie() 
    {
        delete MovieRepository;
        delete MovieRegister;
    }

    static ManagerMovie* getInstance()
    {
        if (managerMovie == nullptr) {
            managerMovie = new ManagerMovie();
        }
        return managerMovie;
    }

    void registerMovie(const Movie& newMovie)
    {
        MovieRegister->registerMovie(newMovie);
    }
    Movie getMovieById(const std::string& id)
    {
        return MovieRepository->getMovieByID(id);
    }
    DoublyLinkedList<Movie> getMoviesdByClasification(const std::string& email)
    {
        return MovieRepository->getMoviesByClasification(email);
    }
    DoublyLinkedList<Movie> getAllMovies()
    {
        return MovieRepository->getAllMovies();
    }
    Movie getMovieByTitle(const std::string& title)
    {
        return MovieRepository->getMovieByTitle(title);
    }
};
ManagerMovie* ManagerMovie::managerMovie = nullptr;