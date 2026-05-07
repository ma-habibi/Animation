#include "animation.h"

Animation::Vec3 Animation::vec3_translate(const Vec3 source,
                                          const Vec3 translation) {
  return Vec3{source.x + translation.x, source.y + translation.y,
              source.z + translation.z};
}