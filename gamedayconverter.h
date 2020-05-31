#include "experienceevent.h"
#include <yaml-cpp/yaml.h>

#include <iostream>

namespace YAML {
template <> struct convert<gameday> {

  static Node encode(const gameday &rhs) {
    Node node;

    for (auto p : rhs.events) {
      node.push_back(p);
    }

    return node;
  }

  static bool decode(const Node &node, gameday &rhs) {

    if (!node.IsSequence()) {
      return false;
    }

    rhs.events.clear();

    for (auto p : node) {
      rhs.events.push_back(p.as<experienceevent>());
    }

    return true;
  }
};
} // namespace YAML