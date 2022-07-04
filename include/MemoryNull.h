#pragma once

#include "MemoryData.h"

class MemoryNull: public MemoryData {
public:
    MemoryNull()
        : MemoryData() {}

    MemoryInteger ToMemoryInteger();
    MemoryDouble ToMemoryDouble();
    MemoryBoolean ToMemoryBoolean();

    long long int ToLongLongInteger() {
        return 0;
    }
    long double ToLongDouble() {
        return 0;
    }
    bool ToBoolean() {
        return false;
    }
    string ToString() {
        return "null";
    }
};
