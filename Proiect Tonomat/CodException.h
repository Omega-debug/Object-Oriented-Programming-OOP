//
// Created by vladm on 5/20/2023.
//

#ifndef LAB_11_12_CODEXCEPTION_H
#define LAB_11_12_CODEXCEPTION_H

#include <exception>
#include <string>

class CodException : public std::exception {
private:
    std::string message;

public:
    explicit CodException(const std::string& errorMessage) : message(errorMessage) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};





#endif //LAB_11_12_CODEXCEPTION_H
