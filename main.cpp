//
//  main.cpp
//  GL
//
//  Created by Paul Griffin on 2017-06-29.
//  Copyright © 2017 PCGM. All rights reserved.
//

#include "main.hpp"

#include <glbinding/gl/gl.h>
#include <glbinding/Binding.h>

#include <glbinding/ContextInfo.h>
#include <glbinding/Version.h>
#include <glbinding/callbacks.h>

#include <GLFW/glfw3.h>
#include <iostream>

//using namespace gl;
using namespace glbinding;


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
        // ...
        glEnd();
        
        glfwSwapBuffers(window);
    }
    
}
