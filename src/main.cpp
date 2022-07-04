
#include <iostream>
#include "MemoryInteger.h"
#include "MemoryDouble.h"
#include "MemoryBoolean.h"
#include "MemoryManager.h"

using namespace std;

#define null 0

int main(int argc, char *argv[]){
    MemoryManager::Initialize("vram", 1024);

    MemoryManager::Dump();
    cout << endl;

    MemoryData a = MemoryDouble(123.456);
    cout << a.ToLongLongInteger() << " " << a.ToLongDouble() << " " << a.ToBoolean() << " " << a.ToString() << endl;
    MemoryManager::Dump();
    cout << endl;


    MemoryData b = a.ToMemoryInteger();
    cout << b.ToLongLongInteger() << " " << b.ToLongDouble() << " " << b.ToBoolean() << " " << b.ToString() << endl;
    MemoryManager::Dump();
    cout << endl;

    MemoryData c = b.ToMemoryBoolean();
    cout << c.ToLongLongInteger() << " " << c.ToLongDouble() << " " << c.ToBoolean() << " " << c.ToString() << endl;
    MemoryManager::Dump();
    cout << endl;

    system("pause");
    return 0;
}



/*
template <typename T>
class Array{
private:
    unsigned int size;
    T *elements;

public:
    Array(){
        size = 0;
        elements = null;
    }
    ~Array(){
        delete elements;
    }

    T& Get(unsigned int index){
        if(index < size)
            return elements[index];
    }

    void Set(unsigned int index, T element){
        if(index < size)
            elements[index] = element;
        else if(index == size)
            Append(element);
    }

    void Append(T element){
        T *t = new T[size + 1];
        t[size] = element;
        for(unsigned int i = 0; i < size; i++)
            t[i] = elements[i];
        delete elements;
        size++;
        elements = t;
    }

    void Remove(unsigned int index){
        if(index >= size)
            return;
        T *t = new T[size - 1];
        unsigned int c = 0;
        for(unsigned int i = 0; i < size; i++)
            if(i != index)
                t[c++] = elements[i];
        delete elements;
        size--;
        elements = t;
    }

    void Popend(){
        Remove(size - 1);
    }

    void Print(){
        cout << "Size: " << size << endl;
        for(unsigned int i = 0; i < size; i++)
            cout << "\t" << elements[i] << endl;
    }

    unsigned int Size(){
        return size;
    }
};

class VariableBlock{
private:
    struct Variable{

    };
private:
    Array<
};

class FunctionArguments{

};
class IExtension;
class IExtensionFunction{
private:
    char *name;

protected:
    IExtensionFunction(char *name){
        this->name = name;
    }

public:
    virtual MemoryData Execute(FunctionArguments arguments);
    char *GetName(){
        return name;
    }
};

class IExtensionClass{
protected:
    struct Function{
    public:
        enum Type{
            Private,
            Protected,
            Public
        };
    private:
        typedef MemoryData(*func)(FunctionArguments);
        char *name;
        Type type;
        func function;

    public:
        Function(char *name, Type type, func function){
            this->name = name;
            this->type = type;
            this->function = function;
        }
        char *GetName(){
            return name;
        }
        Type GetType(){
            return type;
        }
        MemoryData Execute(FunctionArguments args){
            return function(args);
        }
    };

private:
    char *name;
    Array<Function> functions;

protected:
    IExtensionClass(char *name){
        this->name = name;
    }

    void RegisterFunction(Function function){
        functions.Append(function);
    }

public:
    char *GetName(){
        return name;
    }
};

class ExtensionManager{
private:
    Array<IExtensionFunction*> functions;
    Array<IExtensionClass*> classes;

public:
    void RegisterFunction(IExtensionFunction* _function){
        functions.Append(_function);
    }
    void RegisterClass(IExtensionClass* _class){
        classes.Append(_class);
    }

    bool ContainFunction(char *name){
        for(unsigned int i = 0; i < classes.Size(); i++)
            if(strcmp(functions.Get(i)->GetName(), name) == 0)
                return true;
        return false;
    }

    bool ContainClass(char *name){
        for(unsigned int i = 0; i < classes.Size(); i++)
            if(strcmp(classes.Get(i)->GetName(), name) == 0)
                return true;
        return false;
    }

};
*/
