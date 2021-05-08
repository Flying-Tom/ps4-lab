#include <string>
using namespace std;

#include <Exceptions/GLException.h>

GLException::GLException(const string &s) : message(s) {}

string GLException::GetMessage() const {
  return message;
}

