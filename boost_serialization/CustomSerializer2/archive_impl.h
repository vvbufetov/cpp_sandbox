#ifndef ARCHIVE_IMPL_H_
#define ARCHIVE_IMPL_H_

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

namespace archive {

struct oarchive_impl {
    boost::archive::text_oarchive oa;

    oarchive_impl (std::ostream& os)
        : oa(os)
    {}
};

struct iarchive_impl {
    boost::archive::text_iarchive ia;

    iarchive_impl (std::istream& is)
        : ia(is)
    {}
};

};

#endif // ARCHIVE_IMPL_H_
