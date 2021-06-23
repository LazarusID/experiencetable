#ifndef _EXPERIENCEEVENT_DEF_H_
#define _EXPERIENCEEVENT_DEF_H_

#include <boost/config/warning_disable.hpp>
#include <boost/spirit/home/x3.hpp>

#include "ast.hpp"
#include "ast_adapted.hpp"
#include "experienceevent.h"

namespace client {
namespace parser {

namespace x3 = boost::spirit::x3;
namespace ascii = boost::spirit::x3::ascii;

using ascii::char_;
using x3::int_;
using x3::lexeme;
using x3::lit;

x3::rule<class experienceevent, ast::experienceevent> const experienceevent =
    "experienceevent";

auto const quoted_string = lexeme['"' >> +(char_ - '"') >> '"'];
auto const ident = lexeme[alpha >> *alnum];

auto const experienceevent_def = ident >> int_;

} // namespace parser
} // namespace client

#endif