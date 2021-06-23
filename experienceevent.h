#ifndef _EXPERIENCEEVENT_H_
#define _EXPERIENCEEVENT_H_

#include "ast.hpp"
#include <boost/config/warning_disable.hpp>
#include <boost/spirit/home/x3.hpp>

#include <string>

namespace client {
namespace parser {
namespace x3 = boost::spirit::x3;
using experienceevent_type =
    x3::rule<class experienceevent, ast::experienceevent>;
BOOST_SPIRIT_DECLARE(experienceevent_type);
} // namespace parser

parser::experienceevent_type experienceevent();
} // namespace client

#endif
