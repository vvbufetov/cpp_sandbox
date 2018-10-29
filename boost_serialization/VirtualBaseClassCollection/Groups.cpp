#include "Groups.h"
#include "archive_impl.h"
#include <boost/serialization/split_member.hpp>

/*
    Hidden implementation classes
*/

struct ActorBase : IActor {
    enum Type { INT, FLOAT };
    Type    m_type;
    ActorBase (const Type t) : m_type(t) {}
};

std::string type_to_str (const ActorBase::Type type)
{
    switch (type) {
        case ActorBase::INT: return "int";
        case ActorBase::FLOAT: return "float";
        default: return "";
    }
}

template<ActorBase::Type type, typename T>
struct Actor : ActorBase {
    std::map<T, int> breaks;

    Actor () : ActorBase(type) {}

    Actor (const std::vector<T>& values)
        : ActorBase(type)
    {
        for (auto& v : values)
            breaks.emplace(std::pair<T,int>( v, breaks.size()+1 ));
    }

    Value group (const Value& value) override {
        auto it = breaks.lower_bound( value.as<int>() );
        return Value( it == breaks.end() ? (int)(breaks.size() + 1) : it->second );
    }

    friend std::ostream& operator<< (std::ostream& os, const Actor<type,T>& groups)
    {
        os << type_to_str(type);
        for (auto& v : groups.breaks)
            os << " " << v.first;
        return os;
    }

    // hidden boost serialization
    template<class Archive>
    void save(Archive & ar, const unsigned int version) const
    {
        int size = breaks.size();
        ar << size;
        for (auto& item : breaks)
            ar << item.first;
    }

    template<class Archive>
    void load(Archive & ar, const unsigned int version)
    {
        breaks.clear();
        int size = 0;
        ar >> size;
        while (size --> 0) {
            T v;
            ar >> v;
            breaks.emplace(std::pair<T,int>( v, breaks.size()+1 ));
        }
    }

    BOOST_SERIALIZATION_SPLIT_MEMBER()
};

// instantiations
typedef Actor<ActorBase::INT, int> ActorInt;
typedef Actor<ActorBase::FLOAT, double> ActorFloat;


Groups::Groups ()
{}

void Groups::add (const std::string& name, std::vector<int> & breaks)
{
    m_actors[name] = actor_ptr_t(new ActorInt(breaks));
}

void Groups::add (const std::string& name, std::vector<double> & breaks)
{
    m_actors[name] = actor_ptr_t(new ActorFloat(breaks));
}

Value Groups::group (const std::string& name, const Value& value)
{
    auto it = m_actors.find(name);
    if (it == m_actors.end()) return value;
    else return it->second->group(value);
}

std::ostream& operator<< (std::ostream& os, const Groups& groups)
{
    for (auto& item : groups.m_actors) {
        ActorBase* bp = dynamic_cast<ActorBase*>( item.second.get() );
        switch (bp->m_type) {
            case ActorBase::INT: {
                ActorInt* ap = dynamic_cast<ActorInt*>( bp );
                os << item.first << " " << *ap << std::endl;
                break;
                }
            case ActorBase::FLOAT: {
                ActorFloat* ap = dynamic_cast<ActorFloat*>( bp );
                os << item.first << " " << *ap << std::endl;
                break;
                }
            default: break;
        }
    }
    return os;
}

void Groups::save_object(archive::oarchive_impl* aimpl)
{
    int size = m_actors.size();
    aimpl->oa << size;

    for (auto& item : m_actors) {
        std::string name = item.first;
        aimpl->oa << name;

        ActorBase* bp = dynamic_cast<ActorBase*>( item.second.get() );
        ActorBase::Type t = bp->m_type;
        aimpl->oa << t;

        switch (t) {
            case ActorBase::INT: {
                ActorInt* ap = dynamic_cast<ActorInt*>( bp );
                aimpl->oa << *ap;
                break;}
            case ActorBase::FLOAT: {
                ActorFloat* ap = dynamic_cast<ActorFloat*>( bp );
                aimpl->oa << *ap;
                break; }
            default: break;
        }
    }
}

void Groups::load_object(archive::iarchive_impl* aimpl)
{
    int size = 0;
    aimpl->ia >> size;

    while (size --> 0) {
        std::string name;
        aimpl->ia >> name;

        ActorBase::Type t;
        aimpl->ia >> t;

        switch (t) {
            case ActorBase::INT: {
                m_actors[name] = std::shared_ptr<ActorInt>( new ActorInt );
                ActorInt* ap = dynamic_cast<ActorInt*>( m_actors[name].get() );
                aimpl->ia >> *ap;
                break;}
            case ActorBase::FLOAT: {
                m_actors[name] = std::shared_ptr<ActorFloat>( new ActorFloat );
                ActorFloat* ap = dynamic_cast<ActorFloat*>( m_actors[name].get() );
                aimpl->ia >> *ap;
                break; }
            default: break;
        }
    }
}
