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
void cuboid::render(std::string idx) {
    float spacing = 5.0f;
    float inputWidth = ImGui::GetContentRegionAvail().x - 50;// size of input box

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("a:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##a" + idx).c_str(), &a, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("b:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##b" + idx).c_str(), &b, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("h:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##h" + idx).c_str(), &h, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("times repeated:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth - 182);
    ImGui::InputInt(("##r" + idx).c_str(), &repeat, 0, 1);
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    std::string tempStr = "total volume : " + std::to_string(volume()) + " x " + std::to_string(repeat);
    ImGui::Text(tempStr.c_str());
}

double prism::volume() {
    return 1/2*(a*b*h); }
void prism::render(std::string idx) {
    float spacing = 5.0f;
    float inputWidth = ImGui::GetContentRegionAvail().x - 50;// size of input box

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("a:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##ap" + idx).c_str(), &a, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("b:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##bp" + idx).c_str(), &b, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("h:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##hp" + idx).c_str(), &h, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("times repeated:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth - 182);
    ImGui::InputInt(("##rp" + idx).c_str(), &repeat, 0, 1);
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    std::string tempStr = "total volume : " + std::to_string(volume()) + " x " + std::to_string(repeat);
    ImGui::Text(tempStr.c_str());
}

double pyramid::volume() {
    return 1/3*(a*b*h); }
void pyramid::render(std::string idx) {
    float spacing = 5.0f;
    float inputWidth = ImGui::GetContentRegionAvail().x - 50;// size of input box

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("a:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##apy" + idx).c_str(), &a, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("b:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##bpy" + idx).c_str(), &b, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("h:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##hpy" + idx).c_str(), &h, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("times repeated:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth - 182);
    ImGui::InputInt(("##rpy" + idx).c_str(), &repeat, 0, 1);
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    std::string tempStr = "total volume : " + std::to_string(volume()) + " x " + std::to_string(repeat);
    ImGui::Text(tempStr.c_str());
}

double cylinder::volume() {
    return M_PI*r*r*h; }
void cylinder::render(std::string idx) {
    float spacing = 5.0f;
    float inputWidth = ImGui::GetContentRegionAvail().x - 50;// size of input box

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("r:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##rac" + idx).c_str(), &r, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("h:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##hc" + idx).c_str(), &h, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("times repeated:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth - 182);
    ImGui::InputInt(("##rc" + idx).c_str(), &repeat, 0, 1);
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    std::string tempStr = "total volume : " + std::to_string(volume()) + " x " + std::to_string(repeat);
    ImGui::Text(tempStr.c_str());
}

double hollowCylinder::volume() {
    return M_PI*R*R*h - M_PI*r*r*h;}
void hollowCylinder::render(std::string idx) {
    float spacing = 5.0f;
    float inputWidth = ImGui::GetContentRegionAvail().x - 50;// size of input box

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("R:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##Rahc" + idx).c_str(), &R, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("r:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##rahc" + idx).c_str(), &r, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("h:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##hhc" + idx).c_str(), &h, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("times repeated:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth - 182);
    ImGui::InputInt(("##rhc" + idx).c_str(), &repeat, 0, 1);
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    std::string tempStr = "total volume : " + std::to_string(volume()) + " x " + std::to_string(repeat);
    ImGui::Text(tempStr.c_str());
}

double footing1::volume() {
    return a*b*h + A*B*H;}
void footing1::render(std::string idx) {}

// 2d --------------------------------------//
// next update


// app ------------------------------------//

// rendering

void metaData::bodyHeader(std::string text, size_t idx) {
    ImGui::Dummy(ImVec2(0.0f, 10.0f));
    ImGui::SetCursorPosX(marginX);
    if (ImGui::Button(text.c_str(), ImVec2(width - marginX*2.0f - 35.0f, marginX*2.0f))) {}
    ImGui::SameLine(0.0f, 5.0f);
}

void metaData::TextCentered(std::string text) {
    float windowWidth = ImGui::GetWindowSize().x;
    float textWidth = ImGui::CalcTextSize(text.c_str()).x;
    ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
    ImGui::Text("%s", text.c_str());
}


void metaData::render3D() {

    renderBlock3d(cuboids, "cube", 20.0f, width);
    renderBlock3d(prisms, "prism", 20.0f, width);
    renderBlock3d(pyramids, "pyramid", 20.0f, width);
    renderBlock3d(cylinders, "cylinder", 20.0f, width);
    renderBlock3d(holowCylinders, "hollow cylinder", 20.0f, width);
    renderBlock3d(f1s, "footing type 1", 20.0f, width);

}


