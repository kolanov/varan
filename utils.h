
#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <vector>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"


// 3d shapes ---------------------------------------//
struct cuboid {
    double a;
    double b;
    double h;

    int repeat;
    double volume();
    void render();
};

struct prism {
    double a;
    double b;
    double h;

    double volume();
    void render();
};

struct pyramid {
    double a;
    double b;
    double h;

    double volume();
    void render();
};

struct cylinder {
    double h;
    double r;

    double volume();
    void render();
};

struct footing1 {
    double a;
    double b;
    double h;
    double A;
    double B;
    double H;

    double volume();
    void render();
};

struct footing2 {
    double a;
    double b;
    double h;
    double A;
    double B;
    double H;

    double volume();
    void render();
};


// 2d shapes ----------------------------------------//
// sorry nigga u'll have to wait till am in the mood

// app stuff -------------------//
struct metaData {
    // 3d
    std::vector <cuboid> cuboids;
    std::vector <prism> prisms;
    std::vector <pyramid> pyramids;
    std::vector <cylinder> cylinders;
    std::vector <footing1> f1s;
    std::vector <footing2> f2s;

    // 2d
    // wait for next update lil Nigger

    //rendering stufff
    void bodyHeader(std::string text, float width);
    void TextCentered(std::string text);
    void render3D();

    //result
    std::string result3D;

};
