#if 0
#include "boost/scoped_ptr.hpp"
#include <string>
#include <iostream>

int main()
{
    boost::scoped_ptr<std::string> p(new std::string("Use scoped_ptr often."));

    if (p){
        std::cout << *p << std::endl;
    }

    size_t  i = p->size();

    *p = "Acts just like a pointer";
    return 0;
}

#endif


#if 0

#include "boost/shared_ptr.hpp"
#include <vector>
#include <iostream>

class A
{
public:
    virtual void sing() = 0;

protected:
    virtual ~A()
    {
    };
};


class B : public A
{
public:
    virtual void sing()
    {
        std::cout << "Do re mi fa so la";
    }
};

boost::shared_ptr<A> createA()
{
    boost::shared_ptr<A> p(new B());
    return p;
}

int main()
{
    typedef std::vector<boost::shared_ptr<A> > container_type;
    typedef container_type::iterator iterator;

    container_type container;
    for (int i = 0; i < 10; ++i)
    {
        container.push_back(createA());
    }

    std::cout << "The choir is gathered: \n";
    iterator end = container.end();
    for (iterator it = container.begin(); it != end; ++it)
    {
        (*it)->sing();
    }

    return 0;
}

#endif


#if 0

#include <iostream>
#include <boost/smart_ptr/shared_ptr.hpp>

class IntDeleter
{
public:
    void operator()(int* p)
    {
        std::cout << "delete p" << std::endl;
    }
};

int main()
{
    boost::shared_ptr<int> p(new int, IntDeleter());
    *p = 10;
    return  0;
}

#endif


#if 0


#include <iostream>
#include <boost/shared_ptr.hpp>

class A
{
    class deleter
    {
    public:
        void operator()(A *p)
        {
            delete p;
        }
    };

    friend class deleter;

public:
    virtual void sing()
    {
        std::cout << "Lalalalalalalalalalala";
    }

    static boost::shared_ptr<A> createA()
    {
        boost::shared_ptr<A> p(new A(), A::deleter());
        return p;
    }

protected:
    virtual ~A()
    {
    };
};

int main()
{
    boost::shared_ptr<A> p = A::createA();
    p->sing();
    return 0;
}


#endif


#if 0


#include <iostream>
#include "boost/intrusive_ptr.hpp"

template < typename T >
void intrusive_ptr_add_ref(T *t)
{
    t->add_ref();
}

template < typename T >
void intrusive_ptr_release(T *t)
{
    if (t->release() <= 0)
        delete t;
}

class reference_counter
{
    int ref_count_;
public:
    reference_counter() : ref_count_(0)
    {
    }

    virtual ~reference_counter()
    {
    }

    void add_ref()
    {
        ++ref_count_;
    }

    int release()
    {
        return --ref_count_;
    }

protected:
    reference_counter &operator=(const reference_counter &)
    {
        return *this;
    }

private:
    reference_counter(const reference_counter &);
};

class some_class : public reference_counter
{
public:
    some_class()
    {
        std::cout << "some_class::some_class()\n";
    }

    some_class(const some_class &other)
    {
        std::cout << "some_class(const some_class& other)\n";
    }

    ~some_class()
    {
        std::cout << "some_class::~some_class()\n";
    }
};

int main()
{
    std::cout << "Before start of scope\n";
    {
        boost::intrusive_ptr<some_class> p1(new some_class());
        boost::intrusive_ptr<some_class> p2(p1);
    }
    std::cout << "After end of scope \n";
}

#endif


#if 1

#include "boost/shared_ptr.hpp"
#include "boost/weak_ptr.hpp"
#include <iostream>
#include <cassert>

class A
{
};

int main()
{
    boost::weak_ptr<A> w;
    assert(w.expired());
    {
        boost::shared_ptr<A> p(new A());
        assert(p.use_count() == 1);
        w = p;
        assert(p.use_count() == 1);

        boost::shared_ptr<A> p2(w);

    }
    assert(w.expired());
    boost::shared_ptr<A> p3 = assert(!p3);
}

#endif




