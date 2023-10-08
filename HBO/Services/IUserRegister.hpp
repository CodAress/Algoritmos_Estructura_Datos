#pragma once
#include "../Models/User.hpp"
class IUserRegister
{
public:
    virtual void registerUser(const User& newUser) = 0;
};
