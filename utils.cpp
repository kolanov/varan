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
#include "globals.h"

//3d ----------------------------------------------//
double cuboid::volume() {
    return a*b*h; }
void cuboid::render() {
    float spacing = 5.0f;
    float inputWidth = ImGui::GetContentRegionAvail().x - 50;// size of input box

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("a:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble("##a", &a, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("b:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble("##b", &b, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("h:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble("##h", &h, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("times repeated:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth - 182);
    ImGui::InputInt("##r", &repeat, 0, 1);
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    std::string tempStr = "total volume : " + std::to_string(volume()) + " x " + std::to_string(repeat);
    ImGui::Text(tempStr.c_str());
}

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
void metaData::bodyHeader(std::string text) {
    ImGui::Dummy(ImVec2(0.0f, 10.0f));
    ImGui::SetCursorPosX(marginX);
    if (ImGui::Button(text.c_str(), ImVec2(width - marginX*2, marginX*2.0f))) {}
}
void metaData::TextCentered(std::string text) {
    float windowWidth = ImGui::GetWindowSize().x;
    float textWidth = ImGui::CalcTextSize(text.c_str()).x;
    ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
    ImGui::Text("%s", text.c_str());
}
void metaData::render3D() {
    ImGui::Dummy(ImVec2(0.0f, 10.0f));
    TextCentered("cuboids volumes");

    for (size_t i = 0; i < cuboids.size(); i++) {
        bodyHeader("cube " + std::to_string(i + 1));
        cuboids[i].render();
        ImGui::Dummy(ImVec2(0.0f, 10.0f));
    }

// add new cube button
    ImGui::SetCursorPosX(marginX);
    if (ImGui::Button("+", ImVec2(width - marginX*2.0f, marginX*2.0f))) {
        cuboid cube;        // default constructor, you can set defaults here
        cube.a = 1.0;
        cube.b = 1.0;
        cube.h = 1.0;
        cube.repeat = 1;
        cuboids.push_back(cube);
        std::cout << cuboids.size() << std::endl;
    }
}


