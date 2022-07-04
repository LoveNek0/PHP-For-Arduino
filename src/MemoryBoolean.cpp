#include "MemoryNull.h"
#include "MemoryInteger.h"
#include "MemoryDouble.h"
#include "MemoryBoolean.h"

MemoryInteger MemoryBoolean::ToMemoryInteger() {
	return MemoryInteger(ToLongLongInteger());
}

MemoryDouble MemoryBoolean::ToMemoryDouble() {
	return MemoryDouble(ToLongDouble());
}

MemoryBoolean MemoryBoolean::ToMemoryBoolean() {
	return *this;
}
