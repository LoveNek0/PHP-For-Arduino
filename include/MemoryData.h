#pragma once

#include <stdlib.h>
#include <string>

#include "MemoryManager.h"

#define null 0

using namespace std;

class MemoryNull;
class MemoryInteger;
class MemoryDouble;
class MemoryBoolean;
class MemoryArray;
class MemoryString;
class MemoryObject;

class MemoryData{
public:
    enum Type{
        Null,
        Integer,
        Double,
        Boolean,
        Array,
        String,
        Object
    };
    
protected:
    unsigned int address;
    Type type;

protected:    
    MemoryData(Type type, unsigned int size){
        this->type = type;
        this->address = MemoryManager::Allocate(size);
    }

public:
    MemoryData() {
        this->type = Type::Null;
        this->address = 0;
    }

public:
    void Destroy(){
        MemoryManager::Deallocate(address);
    }
    
    unsigned int GetAddress(){
        return address;
    }
    Type GetType(){
        return type;
    }
    
    bool Equals(MemoryData data) {
        switch (type) {
        case Type::Null:
            switch (data.type) {
            case Type::Null:
                return true;
            case Type::Integer:
                return ToLongLongInteger() == data.ToLongLongInteger();
            case Type::Double:
                return ToLongDouble() == data.ToLongDouble();
            case Type::Boolean:
                return ToBoolean() == data.ToBoolean();
            }
            break;
        case Type::Integer:
            switch (data.type) {
            case Type::Null:
                return ToLongLongInteger() == data.ToLongLongInteger();
            case Type::Integer:
                return ToLongLongInteger() == data.ToLongLongInteger();
            case Type::Double:
                return ToLongLongInteger() == data.ToLongLongInteger();
            case Type::Boolean:
                return ToLongLongInteger() == data.ToLongLongInteger();
            }
            break;
        case Type::Boolean:
            switch (data.type) {
            case Type::Null:
                return ToBoolean() == data.ToBoolean();
            case Type::Integer:
                return ToBoolean() == data.ToBoolean();
            case Type::Double:
                return ToBoolean() == data.ToBoolean();
            case Type::Boolean:
                return ToBoolean() == data.ToBoolean();
            }
            break;
        }
    }
    bool EqualsWithType(MemoryData data) {
        if (type != data.type)
            return false;
        return Equals(data);
    }

public:
    MemoryNull ToMemoryNull();

    virtual MemoryInteger ToMemoryInteger();
    virtual MemoryDouble ToMemoryDouble();
    virtual MemoryBoolean ToMemoryBoolean();

    virtual long long int ToLongLongInteger();
    virtual long double ToLongDouble();
    virtual bool ToBoolean();
    virtual string ToString();
};
