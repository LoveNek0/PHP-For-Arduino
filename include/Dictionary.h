#pragma once

#include "MemoryData.h"

class MemoryDataDictionary {
private:
	unsigned int size = 0;
	MemoryData** keys = NULL;
	MemoryData** values = NULL;

public:
	MemoryDataDictionary() {

	}

	~MemoryDataDictionary() {
		delete keys;
		delete values;
	}

	void Append(MemoryData key, MemoryData value) {
		MemoryData** k = new MemoryData * [size + 1];
		MemoryData** v = new MemoryData * [size + 1];
		k[size] = &key;
		v[size] = &value;
		for (unsigned int i = 0; i < size; i++) {
			k[i] = keys[i];
			v[i] = values[i];
		}
		size++;
		keys = k;
		values = v;
	}

	bool IsKeyExist(MemoryData key) {

	}

	MemoryData Get(MemoryData key) {
		for (unsigned int i = 0; i < size; i++)
			if (keys[i] == key)
				return values[i];
		return 
	}
};
