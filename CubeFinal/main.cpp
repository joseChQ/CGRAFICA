#include "shader_s.h"
#include "camera.h"
#include "cube.h"
#include "superrubick.h"
#include <GLFW/glfw3.h>
#include <filesystem>
#define STB_IMAGE_IMPLEMENTATION 
#include "stb_image.h"
#include <iostream>
#include <random>
//######SOLVER##############
#include "Cube.hpp"
#include "Cross.hpp"
#include "Corners.hpp"
#include "Edges.hpp"
#include "OLL.hpp"
#include "PLL.hpp"


//######SOLVER##############
#define PI 3.1415926535897
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
// pass projection matrix to shader (as projection matrix rarely changes there's no need to do this per frame)
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void processInput(GLFWwindow* window);

void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
// settings
Camera camera(glm::vec3(1.0f, 1.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;
// timing
float deltaTime = 0.0f; // time between current frame and last frame
float lastFrame = 0.0f;

int P1[3];
int P2[3];

int PI1[3];
int PI2[3];

int CameraA;
int N = 27;
Srubick CT;
int main()
{
    Cube myCube(false);//SOLVER
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);


    // build and compile our shader zprogram
    // ------------------------------------
    //"D:\\Computer Science\\2020-2\\Computación Gráfica\\GLFW_GLAD_GLUT_GLEW_cmake_project\\GLFW_GLAD_GLUT_GLEW_cmake_project\\src\\Texturas\\4.1.texture.vs", "D:\\Computer Science\\2020-2\\Computación Gráfica\\GLFW_GLAD_GLUT_GLEW_cmake_project\\GLFW_GLAD_GLUT_GLEW_cmake_project\\src\\Texturas\\4.1.texture.fs"
    Shader ourShader("C:\\Users\\ACER\\Documents\\2020-2\\Cgraphica\\LAB\\plantilla\\GLFW_GLAD_GLUT_GLEW_cmake_project\\src\\CubeFinal\\4.1.texture.vs", "C:\\Users\\ACER\\Documents\\2020-2\\Cgraphica\\LAB\\plantilla\\GLFW_GLAD_GLUT_GLEW_cmake_project\\src\\CubeFinal\\4.1.texture.fs");


    CT.fun();
    ///////////////////////////////////////////////////
    unsigned int texture1, texture2;
    // texture 1
    // unsigned int texture;
    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);   // set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load("C:\\Users\\ACER\\Documents\\2020-2\\Cgraphica\\LAB\\plantilla\\GLFW_GLAD_GLUT_GLEW_cmake_project\\src\\CubeFinal\\Emo3.jpg", &width, &height, &nrChannels, 0);
    //unsigned char* data = stbi_load(FileSystem::getPath("D:\\Computer Science\\2020-2\\Computación Gráfica\\GLFW_GLAD_GLUT_GLEW_cmake_project\\GLFW_GLAD_GLUT_GLEW_cmake_project\\src\\Texturas\\wall.jpg").c_str(), &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    // texture 2
    // ---------
    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    /*data = stbi_load("C:\\Users\\ACER\\Documents\\2020-2\\Cgraphica\\LAB\\plantilla\\GLFW_GLAD_GLUT_GLEW_cmake_project\\src\\CubeFinal\\side.png", &width, &height, &nrChannels, 0);
    if (data)
    {
        // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    */
    // tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
    // -------------------------------------------------------------------------------------------
    ourShader.use();
    ourShader.setInt("texture1", 0);
    ourShader.setInt("texture2", 1);
    // pass projection matrix to shader (as projection matrix rarely changes there's no need to do this per frame)

    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
    ourShader.setMat4("projection", projection);

    // render loop
    // -----------
    //std::cout << "Precione A, para la Camara" << std::endl;
    std::cout << "Preciose R, para desordenar" << std::endl;
    std::cout << "Preciose T, para ordenar" << std::endl;
    std::cout << "Preciose R, para desordenar" << std::endl;
    std::cout << "Preciose U, para expandir" << std::endl;
    std::cout << "Preciose I, para comprimir" << std::endl;
    float cubeR = 0;
    const float radius = 0.4f;
    float pX = -0.2;
    float pZ = 0.2;
    float x1 = -0.0;
    float y1 = 0.0;
    bool check[27];
    bool check2 = 0;
    while (!glfwWindowShouldClose(window))
    {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwSetKeyCallback(window, key_callback);
        glfwSetScrollCallback(window, scroll_callback);
        // glfwSetCursorPosCallback(window, mouse_callback);

         // bind textures on corresponding texture units
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);
        //    glActiveTexture(GL_TEXTURE1);
        //    glBindTexture(GL_TEXTURE_2D, texture2);

            // activate shader
        ourShader.use();

        // pass projection matrix to shader (note that in this case it could change every frame)
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        ourShader.setMat4("projection", projection);

        // camera/view transformation
        glm::mat4 view = camera.GetViewMatrix();
        ourShader.setMat4("view", view);
        // DIAMANTE

        CT.fun();
        /*//////////////
        *//////////////

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                glBindVertexArray(CT.mrubick[i]->cubitos[j]->VAO);
                glm::mat4 model = glm::mat4(1.0f);
                model = glm::translate(model, CT.pos[i]);
                CT.mrubick[i]->cubitos[j]->rotateX(model, check[i], j);
                CT.mrubick[i]->cubitos[j]->rotateY(model, check[i], j);
                CT.mrubick[i]->cubitos[j]->rotateZ(model, check[i], j);
                model = glm::translate(model, CT.mrubick[i]->pos[j]);
                ourShader.setMat4("model", model);
                if (i != 13)
                    glDrawArrays(GL_TRIANGLES, 0, 38);

            }
        }
        for (int i = 0; i < N; ++i) {
            CT.mrubick[i]->BeforeFINAL(check[i]);
            CT.mrubick[i]->FINAL();
            CT.mrubick[i]->startD();
        }
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
}
//

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_R && action == GLFW_PRESS) {
        if (!P1[0])
        {
            for (int i = 0; i < N; ++i)
            {
                CT.mrubick[i]->desordenar();
            }

        }
        P1[0] == 1;

    }

    if (key == GLFW_KEY_T && action == GLFW_PRESS) {
        //P1[1] ^= 1;
        if (!P1[1])
        {
            for (int i = 0; i < N; ++i)
            {
                CT.mrubick[i]->funcionResolver();
            }
        }
        P1[1] = 1;
    }
    if (key == GLFW_KEY_Y && action == GLFW_PRESS) {
        P1[2] ^= 1;
    }
    if (key == GLFW_KEY_F && action == GLFW_PRESS) {
        P2[0] ^= 1;
    }
    if (key == GLFW_KEY_G && action == GLFW_PRESS) {
        P2[1] ^= 1;
    }
    if (key == GLFW_KEY_H && action == GLFW_PRESS) {
        P2[2] ^= 1;
    }
    ////////////////////////////////////
    if (key == GLFW_KEY_U && action == GLFW_PRESS) {
        CT.Alejar();
    }
    if (key == GLFW_KEY_I && action == GLFW_PRESS) {
        CT.Acercar();
    }
    if (key == GLFW_KEY_O && action == GLFW_PRESS) {
        PI1[2] ^= 1;
    }
    if (key == GLFW_KEY_J && action == GLFW_PRESS) {
        PI2[0] ^= 1;
    }
    if (key == GLFW_KEY_K && action == GLFW_PRESS) {
        PI2[1] ^= 1;
    }
    if (key == GLFW_KEY_L && action == GLFW_PRESS) {
        PI2[2] ^= 1;
    }
}
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(yoffset);
}