#include<GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <cmath>

#include "Renderer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"


int main(void)
{
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* window = glfwCreateWindow(640, 400, "OPENGL COURSE", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    /* Initializing GLEW, make sure to insert GLEW_STATIC in preprocessor settings*/
    if (glewInit() != GLEW_OK)
        return -1;

    std::cout << "Version of OpenGL: " << glGetString(GL_VERSION) << std::endl;

    float vertices[] = {
        -0.5f, -0.5f,
         0.5f, -0.5f,
         0.5f,  0.5f,
        -0.5f,  0.5f
    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    VertexArray va;

    VertexBuffer vb(vertices, 4 * 2 * sizeof(float));

    VertexBufferLayout layout;
    layout.Push<float>(2, false);
    va.AddBuffer(vb, layout);

    IndexBuffer ib(indices, 6 * sizeof(unsigned int));
    
    Shader shader("res/Basic.shader");
    shader.Bind();

    va.Unbind();
    vb.Unbind();
    ib.Unbind();
    shader.Unbind();
    
    float c = 0.0f;
    float step = 0.05f;

    Renderer renderer;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        shader.Bind();

        /* Render here */
        renderer.Clear();

        shader.SetUniform4f("u_Color", 0.2f, 0.0f, sin(c), 1.0f);

        if (c > 1.0f)                 step = -0.05f;
        else if (c < 0.0f)            step =  0.05f;
        c += step;
        
        /* Drawing first triangle*/
        renderer.Draw(va, ib);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}