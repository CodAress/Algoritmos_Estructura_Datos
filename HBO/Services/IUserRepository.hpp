#pragma once
#include "../Models/User.hpp"
#include "../Lists/DoublyLinkedList.hpp"
class IUserRepository
{
public:
    virtual std::string getPasswordByEmail(const std::string& email) = 0;
    virtual User getUser(const std::string& id) = 0;
    virtual DoublyLinkedList<User> getAllUsers() = 0;
};
