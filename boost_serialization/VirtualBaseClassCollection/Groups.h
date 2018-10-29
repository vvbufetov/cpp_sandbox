#ifndef GROUPS_H_
#define GROUPS_H_

#include <string>
#include <vector>
#include <map>
#include <ostream>
#include "Value.h"
#include <memory>
#include "archive.h"

struct IActor {
    virtual Value group (const Value& value) = 0;
};

class Groups {
    typedef std::shared_ptr<IActor> actor_ptr_t;

 public:
    Groups ();
    void add (const std::string& name, std::vector<int> & breaks);
    void add (const std::string& name, std::vector<double> & breaks);
    Value group (const std::string& name, const Value& value);

    friend std::ostream& operator<< (std::ostream& os, const Groups& groups);

 private:
    std::map<std::string, actor_ptr_t> m_actors;

    friend class archive::archive;
    void save_object(archive::oarchive_impl*);
    void load_object(archive::iarchive_impl*);
};

std::ostream& operator<< (std::ostream& os, const Groups& groups);


#endif // GROUPS_H_