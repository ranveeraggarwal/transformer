#include "body.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

void body::rotate_y(double t) {

    double new_t = rotate_y_angle + t;
    if(new_t > 360)
        new_t -= 360;
    else if(new_t < 0)
        new_t += 360;
    rotate_y_angle = new_t;

}

void body::move_camera_r(double t) {
    double new_r = camera_r + t;
    if(new_r < 0.2)
        new_r = 0.2;
    if(new_r > 7)
        new_r = 7;
    camera_r = new_r;
}

void body::move_camera_t(double t) {

    double new_t = camera_t + t;
    if(new_t > 360)
        new_t -= 360;
    else if(new_t < 0)
        new_t += 360;
    camera_t = new_t;

}

void body::move_camera_p(double t) {

    double new_t = camera_p + t;
    if(new_t > 360)
        new_t -= 360;
    else if(new_t < 0)
        new_t += 360;
    camera_p = new_t;

}

void body::move_waist_x(double t) {
    double new_t = waist_x + t;
    if(new_t > waist_x_max)
        new_t = waist_x_max;
    else if(new_t < waist_x_min)
        new_t = waist_x_min;
    waist_x = new_t;
}

void body::move_waist_y(double t) {
    double new_t = waist_y + t;
    if(new_t > waist_y_max)
        new_t = waist_y_max;
    else if(new_t < waist_y_min)
        new_t = waist_y_min;
    waist_y = new_t;
}

void body::move_waist_z(double t) {
    double new_t = waist_z + t;
    if(new_t > waist_z_max)
        new_t = waist_z_max;
    else if(new_t < waist_z_min)
        new_t = waist_z_min;
    waist_z = new_t;
}

void body::move_right_shoulder_x(double t)
{
    double new_t = right_shoulder_x + t;
    if(new_t > 360)
        new_t = 360-new_t;
    right_shoulder_x = new_t;
}

void body::move_right_shoulder_y(double t)
{
    double new_t = right_shoulder_y + t;
    if(new_t > shoulder_y_max)
        new_t = shoulder_y_max;
    else if(new_t < shoulder_y_min)
        new_t = shoulder_y_min;
    right_shoulder_y = new_t;
}

void body::move_right_shoulder_z(double t)
{
    double new_t = right_shoulder_z + t;
    if(new_t > shoulder_z_max)
        new_t = shoulder_z_max;
    else if(new_t < shoulder_z_min)
        new_t = shoulder_z_min;
    right_shoulder_z = new_t;
}

void body::move_left_shoulder_x(double t)
{
    double new_t = left_shoulder_x + t;
    if(new_t > 360)
        new_t = 360-new_t;
    left_shoulder_x = new_t;
}

void body::move_left_shoulder_y(double t)
{
    double new_t = left_shoulder_y + t;
    if(new_t > shoulder_y_max)
        new_t = shoulder_y_max;
    else if(new_t < shoulder_y_min)
        new_t = shoulder_y_min;
    left_shoulder_y = new_t;
}

void body::move_left_shoulder_z(double t)
{
    double new_t = left_shoulder_z + t;
    if(new_t > shoulder_z_max)
        new_t = shoulder_z_max;
    else if(new_t < shoulder_z_min)
        new_t = shoulder_z_min;
    left_shoulder_z = new_t;
}

void body::move_right_elbow_x(double t)
{
    double new_t = right_elbow_x + t;
    if(new_t > elbow_x_max)
        new_t = elbow_x_max;
    else if(new_t < elbow_x_min)
        new_t = elbow_x_min;
    right_elbow_x = new_t;
}

void body::move_left_elbow_x(double t)
{
    double new_t = left_elbow_x + t;
    if(new_t > elbow_x_max)
        new_t = elbow_x_max;
    else if(new_t < elbow_x_min)
        new_t = elbow_x_min;
    left_elbow_x = new_t;
}

void body::move_right_wrist_x(double t)
{
    double new_t = right_wrist_x + t;
    if(new_t > wrist_x_max)
        new_t = wrist_x_max;
    else if(new_t < wrist_x_min)
        new_t = wrist_x_min;
    right_wrist_x = new_t;
}

void body::move_right_wrist_z(double t)
{
    double new_t = right_wrist_z + t;
    if(new_t > wrist_z_max)
        new_t = wrist_z_max;
    else if(new_t < wrist_z_min)
        new_t = wrist_z_min;
    right_wrist_z = new_t;
}

void body::move_left_wrist_x(double t)
{
    double new_t = left_wrist_x + t;
    if(new_t > wrist_x_max)
        new_t = wrist_x_max;
    else if(new_t < wrist_x_min)
        new_t = wrist_x_min;
    left_wrist_x = new_t;
}

void body::move_left_wrist_z(double t)
{
    double new_t = left_wrist_z + t;
    if(new_t > wrist_z_max)
        new_t = wrist_z_max;
    else if(new_t < wrist_z_min)
        new_t = wrist_z_min;
    left_wrist_z = new_t;
}

void body::move_right_hip_x(double t)
{
    double new_t = right_hip_x + t;
    if(new_t > hip_x_max)
        new_t = hip_x_max;
    else if(new_t < hip_x_min)
        new_t = hip_x_min;
    right_hip_x = new_t;
}

void body::move_right_hip_y(double t)
{
    double new_t = right_hip_y + t;
    if(new_t > hip_y_max)
        new_t = hip_y_max;
    else if(new_t < hip_y_min)
        new_t = hip_y_min;
    right_hip_y = new_t;
}

void body::move_right_hip_z(double t)
{
    double new_t = right_hip_z + t;
    if(new_t > hip_z_max)
        new_t = hip_z_max;
    else if(new_t < hip_z_min)
        new_t = hip_z_min;
    right_hip_z = new_t;
}

void body::move_left_hip_x(double t)
{
    double new_t = left_hip_x + t;
    if(new_t > hip_x_max)
        new_t = hip_x_max;
    else if(new_t < hip_x_min)
        new_t = hip_x_min;
    left_hip_x = new_t;
}

void body::move_left_hip_y(double t)
{
    double new_t = left_hip_y + t;
    if(new_t > hip_y_max)
        new_t = hip_y_max;
    else if(new_t < hip_y_min)
        new_t = hip_y_min;
    left_hip_y = new_t;
}

void body::move_left_hip_z(double t)
{
    double new_t = left_hip_z + t;
    if(new_t < hip_z_max)
        new_t = hip_z_max;
    else if(new_t > -hip_z_min)
        new_t = -hip_z_min;
    left_hip_z = new_t;
}

void body::move_right_knee_x(double t)
{
    double new_t = right_knee_x + t;
    if(new_t > knee_x_max)
        new_t = knee_x_max;
    else if(new_t < knee_x_min)
        new_t = knee_x_min;
    right_knee_x = new_t;
}

void body::move_left_knee_x(double t)
{
    double new_t = left_knee_x + t;
    if(new_t > knee_x_max)
        new_t = knee_x_max;
    else if(new_t < knee_x_min)
        new_t = knee_x_min;
    left_knee_x = new_t;
}

void body::move_right_ankle_x(double t)
{
    double new_t = right_ankle_x + t;
    if(new_t > ankle_x_max)
        new_t = ankle_x_max;
    else if(new_t < ankle_x_min)
        new_t = ankle_x_min;
    right_ankle_x = new_t;
}

void body::move_right_ankle_y(double t)
{
    double new_t = right_ankle_y + t;
    if(new_t > ankle_y_max)
        new_t = ankle_y_max;
    else if(new_t < ankle_y_min)
        new_t = ankle_y_min;
    right_ankle_y = new_t;
}

void body::move_left_ankle_x(double t)
{
    double new_t = left_ankle_x + t;
    if(new_t > ankle_x_max)
        new_t = ankle_x_max;
    else if(new_t < ankle_x_min)
        new_t = ankle_x_min;
    left_ankle_x = new_t;
}

void body::move_left_ankle_y(double t)
{
    double new_t = left_ankle_y + t;
    if(new_t > ankle_y_max)
        new_t = ankle_y_max;
    else if(new_t < ankle_y_min)
        new_t = ankle_y_min;
    left_ankle_y = new_t;
}

void body::move_neck_x(double t)
{
    double new_t = neck_x + t;
    if(new_t > neck_x_max)
        new_t = neck_x_max;
    else if(new_t < neck_x_min)
        new_t = neck_x_min;
    neck_x = new_t;
}

void body::move_neck_y(double t)
{
    double new_t = neck_y + t;
    if(new_t > neck_y_max)
        new_t = neck_y_max;
    else if(new_t < neck_y_min)
        new_t = neck_y_min;
    neck_y = new_t;
}

void body::move_neck_z(double t)
{
    double new_t = neck_z + t;
    if(new_t > neck_z_max)
        new_t = neck_z_max;
    else if(new_t < neck_z_min)
        new_t = neck_z_min;
    neck_z = new_t;
}
void body::transform()
{
    if(count_elbows_in > 0) {
        elbows_y_offset = 0.3 - (0.3 - elbows_y_offset) * (count_elbows_in - 1) / (double)count_elbows_in;
        count_elbows_in--;
    }
    else if(count_transform > 0) {
     /*Waist*/
    waist_x = waist_x * (count_transform - 1) / (double)count_transform;

    /*Neck*/
    neck_x = -180 - (-180 - neck_x) * (count_transform - 1) / (double)count_transform;
    neck_y = neck_y * (count_transform - 1) / (double)count_transform;
    neck_z = neck_z * (count_transform - 1) / (double)count_transform;

    /*Right Shoulder*/
    right_shoulder_x = -0 - (-0 - right_shoulder_x) * (count_transform - 1) / (double)count_transform;
    right_shoulder_y = 0 - (0 - right_shoulder_y) * (count_transform - 1) / (double)count_transform;
    right_shoulder_z = right_shoulder_z * (count_transform - 1) / (double)count_transform;

    /*Left Shoulder*/
    left_shoulder_x = -0 - (-0 - left_shoulder_x) * (count_transform - 1) / (double)count_transform;
    left_shoulder_y = -0 - (-0 - left_shoulder_y) * (count_transform - 1) / (double)count_transform;
    left_shoulder_z = left_shoulder_z * (count_transform - 1) / (double)count_transform;

    /*Right Hip*/
    right_hip_x = 90 - (90 - right_hip_x) * (count_transform - 1) / (double)count_transform;
    right_hip_y = right_hip_y * (count_transform - 1) / (double)count_transform;
    right_hip_z = right_hip_z * (count_transform - 1) / (double)count_transform;

    /*Left Hip*/
    left_hip_x = 90 - (90 - left_hip_x) * (count_transform - 1) / (double)count_transform;
    left_hip_y = left_hip_y * (count_transform - 1) / (double)count_transform;
    left_hip_z = left_hip_z * (count_transform - 1) / (double)count_transform;

    /*Left Elbow*/
    left_elbow_x = left_elbow_x * (count_transform - 1) / (double)count_transform;

    /*Right Elbow*/
    right_elbow_x = right_elbow_x * (count_transform - 1) / (double)count_transform;

    /*Left Knee*/
//    left_knee_x = 180 - (180 - left_knee_x) * (count_transform - 1) / (double)count_transform;
    left_knee_x = left_knee_x * (count_transform - 1) / (double)count_transform;

    /*Right Knee*/
    //right_knee_x = 180 - (180 - right_knee_x) * (count_transform - 1) / (double)count_transform;

    right_knee_x = right_knee_x * (count_transform - 1) / (double)count_transform;

    /*Left Ankle*/
    //left_ankle_x = -180 - (-180 - left_ankle_x) * (count_transform - 1) / (double)count_transform;
    left_ankle_y = 180 - (180 - left_ankle_y) * (count_transform - 1) / (double)count_transform;
    //left_ankle_x = left_ankle_x * (count_transform - 1) / (double)count_transform;
    //left_ankle_y = left_ankle_y * (count_transform - 1) / (double)count_transform;

    /*Right Ankle*/
    right_ankle_y = -180 - (-180 -right_ankle_y) * (count_transform - 1) / (double)count_transform;
    //right_ankle_y = 90 - (90- right_ankle_y) * (count_transform - 1) / (double)count_transform;

    //right_ankle_x = right_ankle_x * (count_transform - 1) / (double)count_transform;
    //right_ankle_y = right_ankle_y * (count_transform - 1) / (double)count_transform;

    /*Shoulder Joints*/
    rs_joint_x = -90 - (-90 -rs_joint_x) * (count_transform - 1) / (double)count_transform;
    ls_joint_x = 90 - (90- ls_joint_x) * (count_transform - 1) / (double)count_transform;

    count_transform--;   
    }    
}
void body::revert()
{

    if(count_revert > 0) {
     /*Waist*/
    waist_x =  waist_x * (count_revert - 1) / (double)count_revert;

    /*Neck*/
    neck_x = neck_x * (count_revert - 1) / (double)count_revert;
    neck_y = neck_y * (count_revert - 1) / (double)count_revert;
    neck_z = neck_z * (count_revert - 1) / (double)count_revert;

    /*Right Shoulder*/
    right_shoulder_x = right_shoulder_x * (count_revert - 1) / (double)count_revert;
    right_shoulder_y = right_shoulder_y * (count_revert - 1) / (double)count_revert;
    right_shoulder_z = right_shoulder_z * (count_revert - 1) / (double)count_revert;

    /*Left Shoulder*/
    left_shoulder_x = left_shoulder_x * (count_revert - 1) / (double)count_revert;
    left_shoulder_y = left_shoulder_y * (count_revert - 1) / (double)count_revert;
    left_shoulder_z = left_shoulder_z * (count_revert - 1) / (double)count_revert;

    /*Right Hip*/
    right_hip_x = right_hip_x * (count_revert - 1) / (double)count_revert;
    right_hip_y = right_hip_y * (count_revert - 1) / (double)count_revert;
    right_hip_z = right_hip_z * (count_revert - 1) / (double)count_revert;

    /*Left Hip*/
    left_hip_x = left_hip_x * (count_revert - 1) / (double)count_revert;
    left_hip_y = left_hip_y * (count_revert - 1) / (double)count_revert;
    left_hip_z = left_hip_z * (count_revert - 1) / (double)count_revert;

    /*Left Elbow*/
    left_elbow_x = left_elbow_x * (count_revert - 1) / (double)count_revert;

    /*Right Elbow*/
    right_elbow_x = right_elbow_x * (count_revert - 1) / (double)count_revert;

    /*Left Knee*/
    left_knee_x = left_knee_x * (count_revert - 1) / (double)count_revert;

    /*Right Knee*/
    right_knee_x = right_knee_x * (count_revert - 1) / (double)count_revert;

    /*Left Ankle*/
    left_ankle_x = left_ankle_x * (count_revert - 1) / (double)count_revert;
    left_ankle_y = left_ankle_y * (count_revert - 1) / (double)count_revert;

    /*Right Ankle*/
    right_ankle_x = right_ankle_x * (count_revert - 1) / (double)count_revert;
    right_ankle_y = right_ankle_y * (count_revert - 1) / (double)count_revert;
    /*Shoulder Joints*/
    rs_joint_x = rs_joint_x * (count_revert - 1) / (double)count_revert;
    ls_joint_x = ls_joint_x * (count_revert - 1) / (double)count_revert;

    count_revert--;   
    }
    else if(count_elbows_out > 0) {
        elbows_y_offset = elbows_y_offset * (count_elbows_out - 1) / (double)count_elbows_out;
        count_elbows_out--;
    }
}

void body::move(double t, double turn) {
    rotate_y_angle += turn;
    pos_z += t * cos(rotate_y_angle * PI / 180);
    pos_x += t * sin(rotate_y_angle * PI / 180);
    //std::cout << pos_x << " " << pos_z << std::endl;
}

void body::move_x(double t) {
    pos_x += t;
}

void body::move_y(double t) {
    pos_y += t;
}

void body::rotate_y_ortho(double t) {
    double new_t = ortho_y_angle + t;
    if(new_t > 360)
        new_t -= 360;
    if(new_t < 0)
        new_t += 360;
    ortho_y_angle = new_t;
}
