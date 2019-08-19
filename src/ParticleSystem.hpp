#pragma once

#include <stdio.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <cmath>
#include <random>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <sstream>
#include <map>
#include <fstream>
#include <cstdlib>
#include <stdexcept>

#include <CL/cl_gl.h>

#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_access.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/noise.hpp>
#include <fastnoise/FastNoise.h>

#include <ft2build.h>
#include FT_FREETYPE_H
#include <stb_image.h>

//Setting
#define W   1920
#define H   1080
#define NP  100

typedef struct  s_particle {
    float   x;
    float   y;
    float   z;
    float   vx;
    float   vy;
    float   vz;
}               particle;
