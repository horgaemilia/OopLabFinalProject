#pragma once
#include <string>
#include <exception>

class RepoException : public std::exception
{
    std::string message;
public:
    RepoException(const std::string& msg) : message(msg) {}

    virtual const char* what() const noexcept override;
};

class ValidatorException : public std::exception
{
    std::string message;
public:
    ValidatorException(const std::string& msg) : message(msg) {}

    virtual const char* what() const noexcept override;
};