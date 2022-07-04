#include "MemoryNull.h"
#include "MemoryInteger.h"
#include "MemoryDouble.h"
#include "MemoryBoolean.h"

MemoryInteger MemoryDouble::ToMemoryInteger() {
	return MemoryInteger(ToLongLongInteger());
}

MemoryDouble MemoryDouble::ToMemoryDouble() {
	return *this;
}

MemoryBoolean MemoryDouble::ToMemoryBoolean() {
	return MemoryBoolean(ToBoolean());
}
