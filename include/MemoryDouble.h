#pragma once

#include "MemoryData.h"

class MemoryDouble : public MemoryData {
public:
    MemoryDouble(long double value)
        : MemoryData(Type::Double, sizeof(long double)) {
        MemoryManager::Set<long double>(GetAddress(), value);
    }
    explicit MemoryDouble(MemoryData data) {
        this->type = Type::Double;
        if (data.GetType())
            this->address = data.GetAddress();
        else {
            this->address = MemoryManager::Allocate(sizeof(long double));
            MemoryManager::Set<long double>(this->address, data.ToLongDouble());
        }
    }

    MemoryInteger ToMemoryInteger();
    MemoryDouble ToMemoryDouble();
    MemoryBoolean ToMemoryBoolean();

    long long int ToLongLongInteger() {
        return ToLongDouble();
    }
    long double ToLongDouble() {
        return MemoryManager::Get<long double>(GetAddress());
    }
    bool ToBoolean() {
        return ToLongDouble() != 0.0;
    }
    string ToString() {
        return to_string(ToLongDouble());
    }
};
