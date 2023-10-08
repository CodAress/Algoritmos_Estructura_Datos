#pragma once
#include "../Services/RegisterUserInTxt.hpp"
#include "../Services/RepositoryUserInTxt.hpp"

class ManagerUser
{
private:
    static ManagerUser* managerUser;

    ManagerUser()
    {
        userRepository = new RepositoryUserInTxt();
        userRegister = new RegisterUserInTxt();
    }

private:
    IUserRegister* userRegister;
    IUserRepository* userRepository;

public:
    ManagerUser(const ManagerUser&) = delete;
    ~ManagerUser()
    {
        delete userRepository;
        delete userRegister;
    }

    static ManagerUser* getInstance()
    {
        if (managerUser == nullptr) {
            managerUser = new ManagerUser();
        }
        return managerUser;
    }

    void registerUser(const User& newUser)
    {
        userRegister->registerUser(newUser);
    }
    User getUserById(const std::string& id)
    {
        return userRepository->getUser(id);
    }
    std::string getPasswordByEmail(const std::string& email)
    {
        return userRepository->getPasswordByEmail(email);
    }
    DoublyLinkedList<User> getAllUsers()
    {
        return userRepository->getAllUsers();
    }
};

ManagerUser* ManagerUser::managerUser = nullptr;