#pragma once
#include "../Models/Movie.hpp"
#include "../Lists/DoublyLinkedList.hpp"
class IMovieRepository
{
public:
    virtual Movie getMovieByTitle(const std::string& title) = 0;
    virtual Movie getMovieByID(const std::string& id) = 0;
    virtual DoublyLinkedList<Movie> getAllMovies() = 0;
    virtual DoublyLinkedList<Movie> getMoviesByClasification(const std::string& clasification) = 0;
    virtual DoublyLinkedList<Movie> getMoviesByGenre(const std::string& genre) = 0;
};
