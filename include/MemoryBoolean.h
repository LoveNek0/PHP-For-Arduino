#pragma once

#include "MemoryData.h"

class MemoryBoolean : public MemoryData {
public:
    MemoryBoolean(bool value)
        : MemoryData(Type::Boolean, sizeof(bool)) {
        MemoryManager::Set<bool>(GetAddress(), value);
    }
    explicit MemoryBoolean(MemoryData data) {
        this->type = Type::Boolean;
        if (data.GetType())
            this->address = data.GetAddress();
        else {
            this->address = MemoryManager::Allocate(sizeof(bool));
            MemoryManager::Set<bool>(this->address, data.ToLongDouble());
        }
    }

    MemoryInteger ToMemoryInteger();
    MemoryDouble ToMemoryDouble();
    MemoryBoolean ToMemoryBoolean();

    long long int ToLongLongInteger() {
        return ToBoolean() ? 1 : 0;
    }
    long double ToLongDouble() {
        return ToBoolean() ? 1 : 0;
    }
    bool ToBoolean() {
        return MemoryManager::Get<bool>(GetAddress());
    }
    string ToString() {
        return ToBoolean() ? "true" : "false";
    }
};
