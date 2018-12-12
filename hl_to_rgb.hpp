
// Copyright 2018 Thomas E. Vaughan
// See LICENSE.

// This code was used as a starting point for a BASIC macro in the LibreOffice
// spreadsheet.  That macro was used to generate color-values in the
// spreadsheet.  These values were copied by hand into the graphviz-dot file,
// from which the final diagram is derived.

struct color {
  float r;
  float g;
  float b;
};

// Convert hue and lightness into rgb color for a saturation of 1.
// lightness must be greater than 0.5.
inline color hl_to_rgb(float hue, float lightness) {
  float const p = 2 * lightness - 1;
  auto f = [&](float t) {
    if (t < 0) {
      t += 1;
    }
    if (t > 1) {
      t -= 1;
    }
    float const c = (1 - p) * 6;
    if (t < 1.0f / 6) {
      return p + c * t;
    }
    if (t < 0.5f) {
      return 1.0f;
    }
    if (t < 2.0f / 3) {
      return p + c * (2.0f / 3 - t);
    }
    return p;
  };
  float constexpr third = 1.0f / 3;
  return {f(hue + third), f(hue), f(hue - third)};
}

