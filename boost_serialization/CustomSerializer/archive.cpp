#include "archive.h"
#include "archive_impl.h"

using namespace archive;

oarchive::oarchive (std::ostream& os)
    : impl( new oarchive_impl(os) )
{}

oarchive::~oarchive ()
{
    delete impl;
}

iarchive::iarchive (std::istream& is)
    : impl( new iarchive_impl(is) )
{}

iarchive::~iarchive ()
{
    delete impl;
}

