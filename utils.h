
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
    double a = 0.0;
    double b = 0.0;
    double h = 0.0;

    int repeat = 1;
    double volume();
    void render(std::string idx);
};

struct prism {
    double a = 0.0;
    double b = 0.0;
    double h = 0.0;

    int repeat = 1;
    double volume();
    void render(std::string idx);
};

struct pyramid {
    double a = 0.0;
    double b = 0.0;
    double h = 0.0;

    int repeat = 1;
    double volume();
    void render(std::string idx);
};

struct cylinder {
    double h = 0.0;
    double r = 0.0;

    int repeat = 1;
    double volume();
    void render(std::string idx);
};

struct hollowCylinder {
    double h = 0.0;
    double r = 0.0;
    double R = 0.0;

    int repeat = 1;
    double volume();
    void render(std::string idx);
};

struct footing1 {
    double a = 0.0;
    double b = 0.0;
    double h = 0.0;
    double A = 0.0;
    double B = 0.0;
    double H = 0.0;

    int repeat = 1;
    double volume();
    void render(std::string idx);
};

struct footing2 {
    double a;
    double b;
    double h;
    double A;
    double B;
    double H;

    int repeat = 1;
    double volume();
    void render(std::string idx);
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
    std::vector <hollowCylinder> holowCylinders;
    std::vector <footing1> f1s;
    std::vector <footing2> f2s;

    // 2d
    // wait for next update lil Nigger

    //rendering stufff

    void bodyHeader(std::string text, size_t idx);

    template<typename T>
    void renderBlock3d(std::vector<T>& Grp, std::string type, float up, int width) {
        ImGui::Dummy(ImVec2(0.0f, up));
        std::string temp = type + " volumes";
        TextCentered(temp);

        for (size_t i = 0; i < Grp.size(); i++) {
            bodyHeader(type + " " + std::to_string(i + 1), i);
            if (ImGui::Button(("X##" + type + std::to_string(i)).c_str(), ImVec2(30.0f, 30.0f))) {
                Grp.erase(Grp.begin() + i);}
            Grp[i].render(std::to_string(i + 1));
            ImGui::Dummy(ImVec2(0.0f, 10.0f));
        }

        ImGui::SetCursorPosX(15.0f);
        if (ImGui::Button(("+##" + type).c_str(), ImVec2(width - 30.0f, 30.0f))) {
            T shap;// default constructor, you can set defaults here
            Grp.push_back(shap);
        }
    }

    void TextCentered(std::string text);
    void render3D();

    //result
    std::string result3D;

};
