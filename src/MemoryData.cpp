#include "MemoryData.h"
#include "MemoryNull.h"
#include "MemoryInteger.h"
#include "MemoryDouble.h"
#include "MemoryBoolean.h"

MemoryNull MemoryData::ToMemoryNull() {
	return MemoryNull();
}

MemoryInteger MemoryData::ToMemoryInteger() {
	switch (type) {
	case Type::Null:
		return MemoryInteger(0);
	case Type::Integer:
		return (MemoryInteger)(*this);
	case Type::Double:
		return ToMemoryDouble().ToMemoryInteger();
	case Type::Boolean:
		return ToMemoryBoolean().ToMemoryInteger();
	}
}
MemoryDouble MemoryData::ToMemoryDouble() {
	switch (type) {
	case Type::Null:
		return MemoryDouble(0);
	case Type::Integer:
		return ToMemoryInteger().ToMemoryDouble();
	case Type::Double:
		return (MemoryDouble)(*this);
	case Type::Boolean:
		return ToMemoryBoolean().ToMemoryDouble();
	}
}
MemoryBoolean MemoryData::ToMemoryBoolean() {
	switch (type) {
	case Type::Null:
		return MemoryBoolean(false);
	case Type::Integer:
		return ToMemoryInteger().ToMemoryBoolean();
	case Type::Double:
		return ToMemoryDouble().ToMemoryBoolean();
	case Type::Boolean:
		return (MemoryBoolean)(*this);
	}
}

long long int MemoryData::ToLongLongInteger() {
	switch (type) {
	case Type::Null:
		return 0;
	case Type::Integer:
		return ToMemoryInteger().ToLongLongInteger();
	case Type::Double:
		return ToMemoryDouble().ToLongLongInteger();
	case Type::Boolean:
		return ToMemoryBoolean().ToLongLongInteger();
	}
}
long double MemoryData::ToLongDouble() {
	switch (type) {
	case Type::Null:
		return 0;
	case Type::Integer:
		return ToMemoryInteger().ToLongDouble();
	case Type::Double:
		return ToMemoryDouble().ToLongDouble();
	case Type::Boolean:
		return ToMemoryBoolean().ToLongDouble();
	}
}
bool MemoryData::ToBoolean() {
	switch (type) {
	case Type::Null:
		return 0;
	case Type::Integer:
		return ToMemoryInteger().ToBoolean();
	case Type::Double:
		return ToMemoryDouble().ToBoolean();
	case Type::Boolean:
		return ToMemoryBoolean().ToBoolean();
	}
}
string MemoryData::ToString() {
	switch (type) {
	case Type::Null:
		return 0;
	case Type::Integer:
		return ToMemoryInteger().ToString();
	case Type::Double:
		return ToMemoryDouble().ToString();
	case Type::Boolean:
		return ToMemoryBoolean().ToString();
	}
}
