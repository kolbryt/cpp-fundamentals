#pragma once
#include <string>
#include "validation.hpp"
// TODO: Put implementations here

std::string getErrorMessage(ErrorCode errorCode) {
    std::string errorMessage{};
    switch(errorCode) {
    case ErrorCode::Ok:
        errorMessage = "Ok";
        break;
    case ErrorCode::PasswordNeedsAtLeastNineCharacters:
        errorMessage = "Password needs to have at least nine characters";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneNumber:
        errorMessage = "Password needs to have at least one number";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter:
        errorMessage = "Password needs to have at least one special character";
        break;
    case ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter:
        errorMessage = "Password needs to have at least one uppercase letter";
        break;
    case ErrorCode::PasswordsDoNotMatch:
        errorMessage = "Passwords do not match";
        break;
    default:
        errorMessage = "An unkown error occured";
        break;
    }
}

bool doPasswordsMatch(std::string password, std::string repeatedPassword) {
    return password == repeatedPassword;
}