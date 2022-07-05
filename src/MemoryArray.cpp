#include "MemoryNull.h"
#include "MemoryInteger.h"
#include "MemoryDouble.h"
#include "MemoryBoolean.h"
#include "MemoryArray.h"

MemoryInteger MemoryArray::ToMemoryInteger() {
	return MemoryInteger(GetSize() != 0 ? 1 : 0);
}

MemoryDouble MemoryArray::ToMemoryDouble() {
	return MemoryDouble(GetSize() != 0 ? 1 : 0);
}

MemoryBoolean MemoryArray::ToMemoryBoolean() {
	return MemoryBoolean(GetSize() != 0);
}
