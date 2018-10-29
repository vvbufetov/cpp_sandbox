#include "Value.h"

Value::Value ()
    : type(EMPTY)
{}

Value::Value (int v)
    : i_value(v), type(INTEGER)
{}

Value::Value (double d)
    : f_value(d), type(FLOAT)
{}


std::ostream& operator<< (std::ostream& os, const Value& value)
{
    switch (value.type) {
        case Value::INTEGER: os << value.i_value; break;
        case Value::FLOAT:   os << value.f_value; break;
        default: break;
    }
    return os;
}
