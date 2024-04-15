//
// Created by vladm on 5/20/2023.
//

#ifndef LAB_11_12_NUMEEXCEPTION_H
#define LAB_11_12_NUMEEXCEPTION_H


#include <exception>
#include <string>



class NumeException : public std::exception {
private:
    std::string message;

public:
    explicit NumeException(const std::string& errorMessage) : message(errorMessage) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};


#endif //LAB_11_12_NUMEEXCEPTION_H
