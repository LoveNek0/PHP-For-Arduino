#pragma once

#include "MemoryData.h"

class MemoryInteger : public MemoryData{
public:
    MemoryInteger(long long int value)
        : MemoryData(Type::Integer, sizeof(long long int)){
        MemoryManager::Set<long long int>(GetAddress(), value);
    }
    explicit MemoryInteger(MemoryData data) {
        this->type = Type::Integer;
        if(data.GetType())
            this->address = data.GetAddress();
        else {
            this->address = MemoryManager::Allocate(sizeof(long long int));
            MemoryManager::Set<long long int>(this->address, data.ToLongLongInteger());
        }
    }
    
    MemoryInteger ToMemoryInteger();
    MemoryDouble ToMemoryDouble();
    MemoryBoolean ToMemoryBoolean();
    
    long long int ToLongLongInteger(){
        return MemoryManager::Get<long long int>(GetAddress());
    }
    long double ToLongDouble(){
        return (long double)ToLongLongInteger();
    }
    bool ToBoolean(){
        return ToLongLongInteger() != 0;
    }
    string ToString(){
        return to_string(ToLongLongInteger());
    }
};
