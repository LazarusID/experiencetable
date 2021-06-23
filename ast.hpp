#ifndef _AST_H_
#define _AST_H_

#include <boost/fusion/include/io.hpp>
#include <iostream>
#include <string>

namespace client {
namespace ast {

struct experienceevent {

  experienceevent() : name(""), points(0), reason(""){};
  experienceevent(std::string c, unsigned int p, std::string r)
      : name(c), points(p), reason(r){};

  std::string name;
  unsigned int points;
  std::string reason;
};

using boost::fusion::operator<<;

} // namespace ast
} // namespace client

#endif
