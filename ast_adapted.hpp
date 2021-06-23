#ifndef _AST_ADAPTED_H_
#define _AST_ADAPTED_H_

#include "ast.hpp"
#include <boost/fusion/include/adapt_struct.hpp>


BOOST_FUSION_ADAPT_STRUCT(client::ast::experienceevent, name, points, reason)

#endif