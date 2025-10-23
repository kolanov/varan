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
std::string cuboid::GenAns() {
    std::string temp = "(" + std::to_string(a) + "x" + std::to_string(b) + "x" + std::to_string(h) + ")";
    if (repeat == 1) {
        return temp;
    }
    return temp + "x" + std::to_string(repeat); }
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
    return  0.5*(a*b*h); }
std::string prism::GenAns() {
    std::string temp = std::string("1/2") + "(" + std::to_string(a) + "x" + std::to_string(b) + "x" + std::to_string(h) + ")";
    if (repeat == 1) {
        return temp;
    }
    return temp + "x" + std::to_string(repeat);
    }
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
    return 0.3333*(a*b*h); }
std::string pyramid::GenAns() {
    std::string temp = std::string("1/3") + "(" + std::to_string(a) + "x" + std::to_string(b) + "x" + std::to_string(h) + ")";
    if (repeat == 1) {
        return temp;
    }
    return temp + "x" + std::to_string(repeat);
    }
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

double frustumPyramid::volume() {
    return h*(a*b + A*B + sqrt(a*b*A*B)) / 3.0;
}
std::string frustumPyramid::GenAns() {
    std::string temp = "(1/3)" + std::to_string(h) + "(" + std::to_string(a) + "x" + std::to_string(b) + "+" + std::to_string(A) + "x" + std::to_string(B) + "+sqrt(" + std::to_string(a) + "x" + std::to_string(b) + "x" + std::to_string(A) + "x" + std::to_string(B) + "))";
    if (repeat == 1) {
        return temp;
    }
    return temp + "x" + std::to_string(repeat);
    }
void frustumPyramid::render(std::string idx) {
    float spacing = 5.0f;
    float inputWidth = ImGui::GetContentRegionAvail().x - 50;// size of input box

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("a:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##afp" + idx).c_str(), &a, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("b:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##bfp" + idx).c_str(), &b, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("A:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##Afp" + idx).c_str(), &A, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("B:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##Bfp" + idx).c_str(), &B, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("h:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##hfp" + idx).c_str(), &h, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("times repeated:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth - 182);
    ImGui::InputInt(("##rfp" + idx).c_str(), &repeat, 0, 1);
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    std::string tempStr = "total volume : " + std::to_string(volume()) + " x " + std::to_string(repeat);
    ImGui::Text(tempStr.c_str());
}

double frustumConeHollow::volume() {
    return 0.3333*M_PI*h*(R1*R1+r1*r1+r1*R1 - (R2*R2+r2*r2+r2*R2));
}
std::string frustumConeHollow::GenAns() {
    std::string temp = "(1/3)x3.14x" + std::to_string(h) + "(" + std::to_string(R1) + "x" + std::to_string(R1) + "+" + std::to_string(r1) + "x" + std::to_string(r1) + "+" + std::to_string(R1) + "x" + std::to_string(r1) + "-" + std::to_string(R2) + "x" + std::to_string(R2) + "-" + std::to_string(r2) + "x" + std::to_string(r2) + "-" + std::to_string(r2) + "x" + std::to_string(R2) + ")";
    if (repeat == 1) {
        return temp;
    }
    return temp + "x" + std::to_string(repeat);
    }
void frustumConeHollow::render(std::string idx) {
    float spacing = 5.0f;
    float inputWidth = ImGui::GetContentRegionAvail().x - 50;// size of input box

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("R1:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##R1cf" + idx).c_str(), &R1, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("r1:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##r1cf" + idx).c_str(), &r1, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("R2:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##R2cf" + idx).c_str(), &R2, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("r2:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##r2cf" + idx).c_str(), &r2, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("h:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##hcf" + idx).c_str(), &h, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("times repeated:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth - 182);
    ImGui::InputInt(("##rcf" + idx).c_str(), &repeat, 0, 1);
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    std::string tempStr = "total volume : " + std::to_string(volume()) + " x " + std::to_string(repeat);
    ImGui::Text(tempStr.c_str());
}

double cylinder::volume() {
    return M_PI*r*r*h; }
std::string cylinder::GenAns() {
    std::string temp = std::to_string(r) + "x" + std::to_string(r) + "x" + std::to_string(h) + "x3.14";
    if (repeat == 1) {
        return temp;
    }
    return temp + "x" + std::to_string(repeat);
    }
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
std::string hollowCylinder::GenAns() {
    if (repeat == 1) {
        return std::to_string(R) + "x" + std::to_string(R) + "x" + std::to_string(h) + "x3.14" + "-" + std::to_string(r) + "x" + std::to_string(r) + "x" + std::to_string(h) + "x3.14"; }
    return "(" + std::to_string(R) + "x" + std::to_string(R) + "x" + std::to_string(h) + "x3.14" + "-" + std::to_string(r) + "x" + std::to_string(r) + "x" + std::to_string(h) + " x3.14" + ")x" + std::to_string(repeat); }
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
std::string footing1::GenAns() {
    if (repeat == 1) {
        return std::to_string(a) + "x" + std::to_string(b) + "x" + std::to_string(h) + "+" + std::to_string(A) + "x" + std::to_string(B) + "x" + std::to_string(H);
    }
    return "(" + std::to_string(a) + "x" + std::to_string(b) + "x" + std::to_string(h) + "+" + std::to_string(A) + "x" + std::to_string(B) + "x" + std::to_string(H) + ")x" + std::to_string(repeat);
}
void footing1::render(std::string idx) {
    float spacing = 5.0f;
    float inputWidth = ImGui::GetContentRegionAvail().x - 50;// size of input box

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("a:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##af1" + idx).c_str(), &a, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("b:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##bf1" + idx).c_str(), &b, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("h:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##hf1" + idx).c_str(), &h, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("A:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##Af1" + idx).c_str(), &A, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("B:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##Bf1" + idx).c_str(), &B, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("H:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##Hf1" + idx).c_str(), &H, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("times repeated:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth - 182);
    ImGui::InputInt(("##rf1" + idx).c_str(), &repeat, 0, 1);
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    std::string tempStr = "total volume : " + std::to_string(volume()) + " x " + std::to_string(repeat);
    ImGui::Text(tempStr.c_str());
}

double footing2::volume() {
    return h*(a*b + A*B + sqrt(a*b*A*B))/3.0 + A*B*H;}
std::string footing2::GenAns() {
    if (repeat == 1) {
        return std::to_string(A) + "x" + std::to_string(B) + "x" + std::to_string(H) + "+(1/3)" + std::to_string(h) + "(" + std::to_string(a) + "x" + std::to_string(b) + "+" + std::to_string(A) + "x" + std::to_string(B) + "+sqrt" + std::to_string(a) + "x" + std::to_string(b) + " x " + std::to_string(A) + "x" + std::to_string(B) + "))";
    }
    return "(" + std::to_string(A) + "x" + std::to_string(B) + "x" + std::to_string(H) + "+(1/3)" + std::to_string(h) + "(" + std::to_string(a) + "x" + std::to_string(b) + "+" + std::to_string(A) + "x" + std::to_string(B) + " + sqrt(" + std::to_string(a) + "x" + std::to_string(b) + "x" + std::to_string(A) + "x" + std::to_string(B) + "))" + ")x" + std::to_string(repeat);
}
void footing2::render(std::string idx) {
    float spacing = 5.0f;
    float inputWidth = ImGui::GetContentRegionAvail().x - 50;// size of input box

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("a:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##af2" + idx).c_str(), &a, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("b:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##bf2" + idx).c_str(), &b, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("h:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##hf2" + idx).c_str(), &h, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("A:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##Af2" + idx).c_str(), &A, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("B:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##Bf2" + idx).c_str(), &B, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("H:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth);
    ImGui::InputDouble(("##Hf2" + idx).c_str(), &H, 0.1, 1.0, "%.2f");
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    ImGui::Text("times repeated:");
    ImGui::SameLine();
    ImGui::PushItemWidth(inputWidth - 182);
    ImGui::InputInt(("##rf2" + idx).c_str(), &repeat, 0, 1);
    ImGui::PopItemWidth();

    ImGui::SetCursorPosX(marginX);
    std::string tempStr = "total volume : " + std::to_string(volume()) + " x " + std::to_string(repeat);
    ImGui::Text(tempStr.c_str());
}
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
    renderBlock3d(fps, "frustum of pyramid", 20.0f, width);
    renderBlock3d(fchs, "hollow frustum of cone", 20.0f, width);
    renderBlock3d(cylinders, "cylinder", 20.0f, width);
    renderBlock3d(holowCylinders, "hollow cylinder", 20.0f, width);
    renderBlock3d(f1s, "footing type 1", 20.0f, width);
    renderBlock3d(f2s, "footing type 2", 20.0f, width);
}

void metaData::genAns3d() {
    result3D = "\n";

    genAnsBlock(cuboids);
    genAnsBlock(prisms);
    genAnsBlock(pyramids);
    genAnsBlock(fps);
    genAnsBlock(fchs);
    genAnsBlock(cylinders);
    genAnsBlock(holowCylinders);
    genAnsBlock(f1s);
    genAnsBlock(f2s);

    if (result3D.size() > 5)
        result3D.erase(result3D.end() - 5, result3D.end());

    result3D += "\n\n= ";
    genVolBlock(cuboids);
    genVolBlock(prisms);
    genVolBlock(pyramids);
    genVolBlock(fps);
    genVolBlock(fchs);
    genVolBlock(cylinders);
    genVolBlock(holowCylinders);
    genVolBlock(f1s);
    genVolBlock(f2s);

    if (result3D.size() > 5)
        result3D.erase(result3D.end() - 5, result3D.end());

    result3D += "\n\n= ";
    double total = 0.0;
    total += genTotBlock(cuboids);
    total += genTotBlock(prisms);
    total += genTotBlock(pyramids);
    total += genTotBlock(fps);
    total += genTotBlock(fchs);
    total += genTotBlock(cylinders);
    total += genTotBlock(holowCylinders);
    total += genTotBlock(f1s);
    total += genTotBlock(f2s);

    result3D += std::to_string(total);

    if (result3D.empty() || result3D == "\n")
        result3D = "No 3D result generated — please enter values.";
}


