#pragma once

#include "MemoryData.h"

class MemoryArray: public MemoryData {
public:
    MemoryArray()
        : MemoryData(Type::Boolean, sizeof(unsigned int)) {
        MemoryManager::Set<unsigned int>(GetAddress(), 0);
    }

private:
    unsigned int GetSize() {
        return MemoryManager::Get<unsigned int>(GetAddress());
    }
    void SetSize(unsigned int size) {
        MemoryManager::Set<unsigned int>(GetAddress(), size);
    }

public:
    bool IsKeyExist(MemoryData key) {
        for (unsigned int i = 0; i < GetSize(); i++)
            if (GetKeyByIndex(i).Equals(key))
                return true;
        return false;
    }

    unsigned int GetKeyIndex(MemoryData key) {
        for (unsigned int i = 0; i < GetSize(); i++)
            if (GetKeyByIndex(i).Equals(key))
                return i;
        return 0;
    }

    MemoryData GetKeyByIndex(unsigned int index) {
        if (index >= GetSize())
            throw new OutOfArrayException(index, GetSize());
        return MemoryManager::Get<MemoryData>(GetAddress() + sizeof(unsigned int) + (index * 2) * sizeof(MemoryData));
    }
    MemoryData GetValueByIndex(unsigned int index) {
        if (index >= GetSize())
            throw new OutOfArrayException(index, GetSize());
        return MemoryManager::Get<MemoryData>(GetAddress() + sizeof(unsigned int) + (index * 2 + 1) * sizeof(MemoryData));
    }

    void Set(MemoryData key, MemoryData value) {
        if (IsKeyExist(key)) {
            unsigned int index = GetKeyIndex(key);
            MemoryManager::Set<MemoryData>(GetAddress() + sizeof(unsigned int) + (index * 2 + 1) * sizeof(MemoryData), value);
        }
        else {
            this->address = MemoryManager::Reallocate(this->address, sizeof(unsigned int) + (sizeof(MemoryData) * (GetSize() + 1) * 2));
            MemoryManager::Set<MemoryData>(this->address + sizeof(unsigned int) + (sizeof(MemoryData) * (GetSize() * 2)), key);
            MemoryManager::Set<MemoryData>(this->address + sizeof(unsigned int) + (sizeof(MemoryData) * (GetSize() * 2 + 1)), value);
            SetSize(GetSize() + 1);
        }
    }

    void Add(MemoryData value) {
        Set(MemoryInteger(GetSize()), value);
    }

    MemoryData Get(MemoryData key) {
        if (IsKeyExist(key))
            return GetValueByIndex(GetKeyIndex(key));
        return MemoryData();
    }

    void Destroy(){

        MemoryData::Destroy();
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
        return GetSize() != 0;
    }
    string ToString() {
        return "(array)";
    }
};
