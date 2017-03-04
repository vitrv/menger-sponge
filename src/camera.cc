#include "camera.h"

namespace {
	float pan_speed = 0.1f;
	float roll_speed = 0.1f;
	float rotation_speed = 0.05f;
	float zoom_speed = 0.1f;
	float horizon = 3.14f;
	float vertical = 0.0f;
};

// FIXME: Calculate the view matrix
glm::mat4 Camera::get_view_matrix() const
{
    //double x, y;
    //glfwGetCursorPos(window, &x, &y);
    //glfwSetCursorPos(window, window_width/2, window_height /2);

    horizon += (rotation_speed * float(window_width /2 - x - prev_x))/ 60;
    vertical+= (rotation_speed * float(window_height/2 - y - prev_y))/ 60;

    glm::vec3 position(  //Postion of camera
    cos(vertical) * sin(horizon),
    sin(vertical),
    cos(vertical) * cos(horizon));

    glm::vec3 target(0,0,0); //Positon of cube

    //glm::vec3 right = glm::vec3(sin(horizon - 3.14f/2.0f),0, cos(horizon - 3.14f/2.0f));
    //glm::vec3 up = glm::cross( right, target );

    glm::mat4 translation;
    translation[3][0] = -position.x;
    translation[3][1] = -position.y;
    translation[3][2] = -position.z;
    glm::mat4 rotation;
    glm::vec3 zaxis = glm::normalize(position - target);
    glm::vec3 xaxis = glm::normalize(glm::cross(glm::normalize(up_), zaxis));
    glm::vec3 yaxis = glm::cross(zaxis, xaxis);
    rotation[0][0] = xaxis.x; // First column, first row
    rotation[1][0] = xaxis.y;
    rotation[2][0] = xaxis.z;
    rotation[0][1] = yaxis.x; // First column, second row
    rotation[1][1] = yaxis.y;
    rotation[2][1] = yaxis.z;
    rotation[0][2] = zaxis.x; // First column, third row
    rotation[1][2] = zaxis.y;
    rotation[2][2] = zaxis.z; 

    glm::mat4 view = rotation * translation;
    return view;

}
