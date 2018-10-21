//
// Created by Marco on 13/10/2018.
//
#include <string>

// Error is a type representing an error.
struct Error {
    std::string what;
};

// Either is a struct used to wrap any response that could also
// be an error. The error property is set nu NULL when the struct
// is instantiated and the generic T can be set to the expected
// value that should be returned in case if success.
template<typename T>
struct Either {
    Either() : error(NULL) {}

    Error *error;
    T expected;
};