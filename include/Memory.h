#pragma once

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#include "Exceptions.h"

class Memory{
private:
    char *filename;
    unsigned long long int size;
    
public:
    Memory(char *filename, unsigned long long int size){
        this->filename = filename;
        this->size = size;
        Reset();
    }
    
    void Reset(){
        FILE *file = fopen(filename, "wb");
        char c;
        fwrite(&c, sizeof(char), size, file);
        fclose(file);
    }
    
    unsigned int Size(){
        return size;
    }
    
    void Set(unsigned int address, void *bytes, unsigned int count){
        if(address + count >= size)
            return;
        FILE *file = fopen(filename, "rb+");
        fseek(file, address, SEEK_SET);
        fwrite(bytes, count, 1, file);
        fclose(file);
    }
    template <typename T>
    void Set(unsigned int address, T data){
        Set(address, &data, sizeof(T));
    }
    char *Get(unsigned int address, unsigned int count){
        if(address + count >= size)
            throw new InaccessibleMemoryException(address);
        char *out = new char[count];
        FILE *file = fopen(filename, "rb");
        fseek(file, address, SEEK_SET);
        fread(out, count, 1, file);
        fclose(file);
        return out;
    }
    template <typename T>
    T Get(unsigned int address){
        unsigned int count = sizeof(T);
        if(address + count >= size)
            throw new InaccessibleMemoryException(address);
        T out;
        FILE *file = fopen(filename, "rb");
        fseek(file, address, SEEK_SET);
        fread(&out, count, 1, file);
        fclose(file);
        return out;
    }
};
