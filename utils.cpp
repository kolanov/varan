#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "utils.h"

//3d ----------------------------------------------//
double cuboid::volume() {
    return a*b*h; }
void cuboid::render() {}

double prism::volume() {
    return 1/2*(a*b*h); }
void prism::render() {}

double pyramid::volume() {
    return 1/3*(a*b*h); }
void pyramid::render() {}

double cylinder::volume() {
    return M_PI*r*r*h; }
void cylinder::render() {}

double footing1::volume() {
    return a*b*h + A*B*H;}
void footing1::render() {}

// 2d --------------------------------------//
// next update


// app ------------------------------------//

// rendering
void metaData::TextCentered(std::string text) {
    float windowWidth = ImGui::GetWindowSize().x;
    float textWidth = ImGui::CalcTextSize(text.c_str()).x;
    ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
    ImGui::Text("%s", text.c_str());
}

void metaData::render3D() {
    TextCentered("cuboids volumes");
}


