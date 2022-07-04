#include "MemoryNull.h"
#include "MemoryInteger.h"
#include "MemoryDouble.h"
#include "MemoryBoolean.h"

MemoryInteger MemoryInteger::ToMemoryInteger() {
	return *this;
}

MemoryDouble MemoryInteger::ToMemoryDouble() {
	return MemoryDouble(ToLongDouble());
}

MemoryBoolean MemoryInteger::ToMemoryBoolean() {
	return MemoryBoolean(ToBoolean());
}
