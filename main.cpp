#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "utils.h"
#include "globals.h"

float marginX = 15.0;
int width, height;


int main() {
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 900, "Varan 1.0.0", NULL, NULL);
    glfwMakeContextCurrent(window);
    glewInit();

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.FontGlobalScale = 2.0f;
    (void)io;
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");
    ImGui::StyleColorsDark();

    // testing stuff -----------------------------------------------//
    metaData app;
    cuboid test1 = {0};


    while (!glfwWindowShouldClose(window)) {
        // setting up window behavior ---------------- //
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        // Get current frame buffer size
        glfwGetFramebufferSize(window, &width, &height);
        ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoTitleBar |ImGuiWindowFlags_NoResize |ImGuiWindowFlags_NoMove |ImGuiWindowFlags_NoScrollbar |ImGuiWindowFlags_NoCollapse;
        ImGui::SetNextWindowPos(ImVec2(0, 0));
        ImGui::SetNextWindowSize(ImVec2((float)width, (float)height));


        // starting the ui
        ImGui::Begin("Fullscreen Window", nullptr, window_flags);

        if (ImGui::BeginTabBar("Main tabs")) {
            if (ImGui::BeginTabItem("3d elements")) {
                /*
                app.bodyHeader("cube 1", width);
                test1.render();
                */
                app.render3D();
                // button stuff ------------------------ //
                // ------------------------------------ //
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("2d elements")) {
                ImGui::Text("am too lazy to add them for now, wait till next update");
                ImGui::EndTabItem();
            }
            if (ImGui::BeginTabItem("results")) {
                ImGui::Text("hey nigga");
                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
        }
        ImGui::End();

        ImGui::Render();
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    std::cout << test1.a << std::endl;

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
