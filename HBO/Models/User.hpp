#pragma once
#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>
class User
{
private:
    std::string _id;
    std::string _password;
    std::string _name;
    std::string _lastName;
    std::string _email;

public:
    User(std::string id, std::string password, std::string name, std::string lastName, std::string email):
    _id(id), _password(password), _name(name), _lastName(lastName), _email(email) {}

    ~User() { }

    std::string getId() const { return _id; }
    std::string getPassword() const { return _password; }
    std::string getName() const { return _name; }
    std::string getLastName() const { return _lastName; }
    std::string getEmail() const { return _email; }

    void printUser() {
        std::cout << "ID: " << _id << std::endl;
        std::cout << "Password: " << _password << std::endl;
        std::cout << "Name: " << _name << std::endl;
        std::cout << "Last Name: " << _lastName << std::endl;
        std::cout << "Email: " << _email << std::endl;
    }

    void setId(std::string id) { _id = id; }
    void setPassword(std::string password) { _password = password; }
    void setName(std::string name) { _name = name; }
    void setLastName(std::string lastName) { _lastName = lastName; }
    void setEmail(std::string email) { _email = email; }

};
#endif // USER_H