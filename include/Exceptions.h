#pragma once

#include <exception>
using namespace std;

class InaccessibleMemoryException: public exception{
    private:
        unsigned int address;
        
    public:
        InaccessibleMemoryException(unsigned int address){
            this->address = address;
        }
        
        virtual const char* what() const throw(){
            char *msg = new char[90];
            sprintf(msg, "An attempt to access an inaccessible memory location at address %#8X", address);
            return msg;
        }
        
        unsigned int Address(){
            return address;
        }
    };

class OutOfArrayException : public exception {
private:
    unsigned int index;
    unsigned int size;

public:
    OutOfArrayException(unsigned int index, unsigned int size) {
        this->index = index;
        this->size = size;
    }

    virtual const char* what() const throw() {
        char* msg = new char[90];
        sprintf(msg, "Index %ud is out of range of array of size %ud", index, size);
        return msg;
    }

    unsigned int Index() {
        return index;
    }

    unsigned int Size() {
        return size;
    }
};
    