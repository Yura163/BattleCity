#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;
int g_windowSizeX = 640;
int g_windowSizeY = 480;
void glfwWindowSizeCallback(GLFWwindow* pwindow, int width, int height) {

    g_windowSizeX = width;
    g_windowSizeY = height;
    glViewport(0, 0, g_windowSizeX, g_windowSizeY);
}

void glfwKeyCallback(GLFWwindow* pwindow, int key, int scancode, int action, int mode) {
    if (key==GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(pwindow, GL_TRUE);
    }

}
int main(void)
{
    

    /* Initialize the library */
    if (!glfwInit())
    {
        cout << "glfwInit failed" << endl;
        return -1;
    }
       
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);  
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    /* Create a windowed mode window and its OpenGL context */
    GLFWwindow* pwindow = glfwCreateWindow(g_windowSizeX, g_windowSizeY, "Myproject", nullptr, nullptr);
    if (!pwindow)
    {
        cout << "glfwCreateWindow failed!" << endl;
        glfwTerminate();
        return -1;
    }

    glfwSetWindowSizeCallback(pwindow, glfwWindowSizeCallback);
    glfwSetKeyCallback(pwindow, glfwKeyCallback);
    /* Make the window's context current */
    glfwMakeContextCurrent(pwindow);
if(!gladLoadGL())
{
    cout << "Can't load GLAD!" << endl;
	
	}
cout << "Renderer" << glGetString(GL_RENDERER) << endl;
cout << "OpenGL version:" << glGetString(GL_VERSION)<< endl;
	
	glClearColor(1,0,1,0);
	
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pwindow))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pwindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}