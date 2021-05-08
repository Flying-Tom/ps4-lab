#ifndef NEGATIVECYCLE_EXCEPTION
#define NEGATIVECYCLE

#include <Algorithms/Exceptions/GLException.h>

class NegativeCycleException : public GLException
{
protected:
    std::string message;

public:
    explicit GLException(const std::string &s);
    virtual std::string GetMessage() const;
};

ostream &operator<<(ostream &os, const GLException &e);

#endif
