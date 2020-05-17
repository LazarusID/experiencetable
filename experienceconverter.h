#include "experienceevent.h"
#include <yaml-cpp/yaml.h>

namespace YAML {
template <> struct convert<experienceevent> {

  static Node encode(const experienceevent &rhs) {
    Node node;
    node["character"] = rhs.character;
    node["points"] = rhs.points;
    node["reason"] = rhs.reason;

    return node;
  }

  static bool decode(const Node &node, experienceevent &rhs) {
    if (node.size() != 3) {
      return false;
    }

    rhs.character = node["character"].as<string>();
    rhs.points = node["points"].as<int>();
    rhs.reason = node["reason"].as<string>();

    return true;
  }
};
} // namespace YAML
