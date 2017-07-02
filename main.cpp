//
//  main.cpp
//  GL
//
//  Created by Paul Griffin on 2017-06-29.
//  Copyright © 2017 PCGM. All rights reserved.
//

#include <glbinding/gl/gl.h>
#include <glbinding/Binding.h>

#include <glbinding/ContextInfo.h>
#include <glbinding/Version.h>
#include <glbinding/callbacks.h>

#include <GLFW/glfw3.h>
#include <iostream>

#include "main.hpp"

//using namespace gl;
using namespace glbinding;

void error(int errnum, const char *errmsg)
{
    std::cerr << errnum << ": " << errmsg << std::endl;
}

int main()
{
    if (!glfwInit())
        return 1;

    glfwSetErrorCallback(error);
    glfwDefaultWindowHints();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef SYSTEM_DARWIN // Mac spesific initialisation
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT GL_TRUE);
#endif

    GLFWwindow *window = glfwCreateWindow(800, 600, "Learn OpenGL", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    glbinding::Binding::initialize();

    glViewport(0, 0, 800, 600);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        //Rendering
        glClearColor(0.2f, 1.0f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        //End rendering

        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

/**

void error(int errnum, const char * errmsg){
    std::cerr << errnum << ": " << errmsg << std::endl;
}


int main()
{
    if (!glfwInit())
        return 1;
    glfwSetErrorCallback(error);
    glfwDefaultWindowHints();
    
#ifdef SYSTEM_DARWIN
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif
    
    GLFWwindow * window = glfwCreateWindow(640, 480, "", nullptr, nullptr);
    
    glfwMakeContextCurrent(window);
    
    
    
    glbinding::Binding::initialize();
    
    std::cout << std::endl
    << "OpenGL Version:  " << ContextInfo::version() << std::endl
    << "OpenGL Vendor:   " << ContextInfo::vendor() << std::endl
    << "OpenGL Renderer: " << ContextInfo::renderer() << std::endl;
    
    
    
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        
        glBegin(GL_TRIANGLES);
        glVertex2f(1,0);
        glVertex2f(0,1);
        glVertex2f(1,1);
        glVertex2f(1,0);
        glVertex2f(0,1);
        glVertex2f(0,0);
        glEnd();
        
        glfwSwapBuffers(window);
    }
    
}
**/