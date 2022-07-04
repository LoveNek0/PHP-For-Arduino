#include "MemoryNull.h"
#include "MemoryInteger.h"
#include "MemoryDouble.h"
#include "MemoryBoolean.h"

MemoryInteger MemoryNull::ToMemoryInteger() {
	return MemoryInteger(0);
}

MemoryDouble MemoryNull::ToMemoryDouble() {
	return MemoryDouble(0);
}

MemoryBoolean MemoryNull::ToMemoryBoolean() {
	return MemoryBoolean(false);
}
