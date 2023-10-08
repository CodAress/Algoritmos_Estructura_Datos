#pragma once
#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
class Movie
{
private:
    std::string _id;
    std::string _name;
    std::string _genre;
    std::string _duration;
    std::string _classification;
public:
    Movie(std::string id,std::string name, std::string genre, std::string duration, std::string classification): 
    _id(id), _name(name), _genre(genre), _duration(duration), _classification(classification) {}
    ~Movie() {}

    //getters
    std::string getId() const { return _id; }
    std::string getName() const { return _name; }
    std::string getGenre() const { return _genre; }
    std::string getDuration() const { return _duration; }
    std::string getClassification() const { return _classification; }

    void printMovie() {
        std::cout << "ID: " << _id << std::endl;
        std::cout << "Name: " << _name << std::endl;
        std::cout << "Genre: " << _genre << std::endl;
        std::cout << "Duration: " << _duration << std::endl;
        std::cout << "Classification: " << _classification << std::endl;
    }

    //setters
    void setId(std::string id) { _id = id; }
    void setName(std::string name) { _name = name; }
    void setGenre(std::string genre) { _genre = genre; }
    void setDuration(std::string duration) { _duration = duration; }
    void setClassification(std::string classification) { _classification = classification; }


};
#endif // MOVIE_H