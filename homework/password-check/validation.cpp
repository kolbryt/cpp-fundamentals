#include "validation.hpp"
#include <algorithm>
#include <cctype>
#include <string>

std::string getErrorMessage(const ErrorCode errorCode) {
    std::string errorMessage{};
    switch (errorCode) {
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
    return errorMessage;
}

bool doPasswordsMatch(const std::string& password, const std::string& repeatedPassword) {
    return password == repeatedPassword;
}

ErrorCode checkPasswordRules(const std::string& password) {
    ErrorCode errorCode{ErrorCode::Ok};
    if (password.size() < 9) {
        errorCode = ErrorCode::PasswordNeedsAtLeastNineCharacters;
    }
    if (std::none_of(password.cbegin(), password.cend(), [](const char c) { return std::isdigit(c); })) {
        errorCode = ErrorCode::PasswordNeedsAtLeastOneNumber;
    }
    if (std::none_of(password.cbegin(), password.cend(), [](const char c) { return std::ispunct(c); })) {
        errorCode = ErrorCode::PasswordNeedsAtLeastOneSpecialCharacter;
    }
    if (std::none_of(password.cbegin(), password.cend(), [](const char c) { return std::isupper(c); })) {
        errorCode = ErrorCode::PasswordNeedsAtLeastOneUppercaseLetter;
    }
    return errorCode;
}

ErrorCode checkPassword(const std::string& password, const std::string& repeatedPassowrd) {
    if (!doPasswordsMatch(password, repeatedPassowrd)) {
        return ErrorCode::PasswordsDoNotMatch;
    }
    return checkPasswordRules(password);
}