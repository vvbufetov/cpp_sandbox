#ifndef VALUE_H_
#define VALUE_H_

#include <ostream>

class Value {
 public:
    Value ();
    Value (int v);
    Value (double d);

    template <typename T>
    T as () const
    {
        switch (type) {
            case INTEGER: return static_cast<T>( i_value );
            case FLOAT: return static_cast<T>( f_value );
            default:  return static_cast<T>(NULL);
        }
    }

    friend std::ostream& operator<< (std::ostream& os, const Value& value);

 private:
    enum Type { EMPTY, INTEGER, FLOAT };
    Type    type;
    union {
        int     i_value;
        double  f_value;
    };
};

std::ostream& operator<< (std::ostream& os, const Value& value);

#endif // VALUE_H_
