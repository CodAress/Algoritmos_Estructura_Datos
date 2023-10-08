#pragma once
#ifndef IMOVIEREGISTER_H
#define IMOVIEREGISTER_H
#include "../Models/Movie.hpp"
class IMovieRegister
{
public:
    virtual void registerMovie(const Movie& newMovie) = 0;
};
#endif // !IMOVIEREGISTER_H

