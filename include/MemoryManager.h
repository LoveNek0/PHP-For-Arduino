#pragma once

#include <stdlib.h>
#include <exception>
#include <string>
#include <iostream>
#include <vector>

#include "Memory.h"

using namespace std;

#define null    0

class MemoryManager{ 
private:
    struct Block{
        unsigned int size;
        unsigned int address;
        unsigned int next;
        bool free;
        
        string ToString(){
            return "Size: " + to_string(size) + 
                    " Address: " + to_string(address) +
                    " Next: " + to_string(next) +
                    " Free: " + (free?"yes":"no");
        }
    };

private:
    static Memory* memory;
    static unsigned int start;
    
    static void JoinEmpty() {
        unsigned int current = start;
        while(memory->Get<Block>(current).next != null) {
            Block cur = memory->Get<Block>(current);
            Block next = memory->Get<Block>(cur.next);
            if (cur.free && next.free) {
                cur.next = next.next;
                cur.size += sizeof(Block) + next.size;
                memory->Set<Block>(current, cur);
                continue;
            }
            current = memory->Get<Block>(current).next;
        }
    }

public:
    static void Initialize(char *file, unsigned int size){
        memory = new Memory(file, size);
        start = 1;
        Block block;
        block.size = memory->Size() - sizeof(Block) - 1;
        block.address = sizeof(Block);
        block.next = 0;
        block.free = true;
        memory->Set<Block>(start, block);
    }
    
    static unsigned int Allocate(unsigned int size){
        for (unsigned int current = start; current != null; current = memory->Get<Block>(current).next) {
            Block cur = memory->Get<Block>(current);
            if (cur.free) {
                if (cur.size == size) {
                    cur.free = false;
                    memory->Set<Block>(current, cur);
                    return cur.address;
                }
                if (cur.size > sizeof(Block) + size) {
                    Block next;
                    next.next = cur.next;
                    next.address = cur.address + cur.size - size;
                    next.size = size;
                    next.free = false;
                    cur.next = next.address - sizeof(Block);
                    cur.size -= size + sizeof(Block);
                    memory->Set<Block>(current, cur);
                    memory->Set<Block>(cur.next, next);
                    return next.address;
                }
            }
        }
        JoinEmpty();
        return Allocate(size);
    }
    
    static void Deallocate(unsigned int address){
        unsigned int current = start;
        while(current != null){
            Block block = memory->Get<Block>(current);
            if(!block.free && address >= block.address && address < block.address + block.size){
                block.free = true;
                memory->Set<Block>(current, block);
                break;
            }
            current = block.next;
        }
    }
    
    static unsigned int Reallocate(unsigned int from, unsigned int size){
        unsigned int current = start;
        while(current != null){
            Block block = memory->Get<Block>(current);
            if(!block.free && from >= block.address && from < block.address + block.size){
                unsigned int address = Allocate(size);
                Copy(from, address, min(size, block.size - (from - block.address)));
                Deallocate(from);
                return address;
            }
            current = block.next;
        }
        throw new InaccessibleMemoryException(from);
    }
    
    template <typename T>
    static T Get(unsigned int address){
        unsigned int current = start;
        while(current != 0){
            Block block = memory->Get<Block>(current);
            if(!block.free && 
                address >= block.address &&
                address < block.address + block.size &&
                address + sizeof(T) <= block.address + block.size){
                return memory->Get<T>(address);
            }
            current = block.next;
        }
        throw new InaccessibleMemoryException(address);
    }
    
    template <typename T>
    static void Set(unsigned int address, T data){
        unsigned int current = start;
        while(current != 0){
            Block block = memory->Get<Block>(current);
            if(!block.free && address >= block.address && 
            address < block.address + block.size && 
            address + sizeof(T) <= block.address + block.size){
                memory->Set<T>(address, data);
                return;
            }
            current = block.next;
        }
        throw new InaccessibleMemoryException(address);
    }
    
    static void Copy(unsigned int from, unsigned int to, unsigned int size){
        for(unsigned int i = 0; i < size; i++)
            Set<char>(to + i, Get<char>(from + i));
    }
    
    static unsigned int BlockSize(unsigned int address){
        unsigned int current = start;
        while(current != 0){
            Block block = memory->Get<Block>(current);
            if(address >= block.address && 
            address < block.address + block.size)
                return block.size;
            current = block.next;
        }
        return 0;
    }
    
    static char* GetBytes(unsigned int address, unsigned int count){
        unsigned int current = start;
        while(current != 0){
            Block block = memory->Get<Block>(current);
            if(!block.free && 
                address >= block.address &&
                address < block.address + block.size &&
                address + count <= block.address + block.size){
                return memory->Get(address, count);
            }
            current = block.next;
        }
        throw new InaccessibleMemoryException(address);
    }
    static void SetBytes(unsigned int address, char* data, unsigned int count){
        unsigned int current = start;
        while(current != 0){
            Block block = memory->Get<Block>(current);
            if(!block.free && address >= block.address && 
            address < block.address + block.size && 
            address + count <= block.address + block.size){
                memory->Set(address, data, count);
                return;
            }
            current = block.next;
        }
        throw new InaccessibleMemoryException(address);
    }
    
    static void Dump(){
        unsigned int current = start;
        unsigned int id = 1;
        while(current != null){
            cout << "#" << id++ << " Position: " << to_string(current) << " " << memory->Get<Block>(current).ToString() << endl;
            current = memory->Get<Block>(current).next;
        }
    }
};
