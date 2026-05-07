#include "animation.h"

#include <cmath>

/* Translate a source vector by a given translation vector */
Animation::Vec3 Animation::vec3_translate(const Vec3 source,
                                          const Vec3 translation) {
  return Vec3{source.x + translation.x, source.y + translation.y,
              source.z + translation.z};
}

/* Rotate a source vector by a given rotation vector along the X and Z axis */
Animation::Vec3 Animation::vec3_rotate_xz(const Vec3 source,
                                          const float angle) {
  const float cos_t = cosf(angle);
  const float sin_t = sinf(angle);
  return Vec3{
      source.x * cos_t - source.z * sin_t,
      source.y,
      source.x * sin_t + source.z * cos_t,
  };
}