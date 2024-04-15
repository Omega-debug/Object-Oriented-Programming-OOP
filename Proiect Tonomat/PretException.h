//
// Created by vladm on 5/20/2023.
//

#ifndef LAB_11_12_PRETEXCEPTION_H
#define LAB_11_12_PRETEXCEPTION_H


#include <exception>
#include <string>

class PretException : public std::exception {
private:
    std::string message;

public:
    explicit PretException(const std::string& errorMessage) : message(errorMessage) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};



#endif //LAB_11_12_PRETEXCEPTION_H
