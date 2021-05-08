#ifndef NEGATIVECYCLE_EXCEPTION
#define NEGATIVECYCLE_EXCEPTION

#include <Exceptions/GLException.h>

class NegativeCycleException : public GLException
{
protected:
    std::string message;

public:
    explicit NegativeCycleException(const std::string &s) : GLException(&s);
    virtual std::string GetMessage() const;
};

#endif
