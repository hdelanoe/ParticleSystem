#pragma once

#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <omp.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "glut.h"
#include "glui.h"
#include "CL/cl.h"
#include "CL/cl_gl.h"

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

struct xyzw
{
    float x, y, z, w;
}

struct rgba
{
    float r, g, b, a;
}

typedef struct  s_particle {
    struct xyzw;
    struct rgba;
}               particle;
