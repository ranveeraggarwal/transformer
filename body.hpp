#include "basics.hpp"

#include <fstream>

#define pelvis 1
#define torso 2
#define head 3
#define right_upper_arm 4
#define right_lower_arm 5
#define right_hand 6
#define left_upper_arm 7
#define left_lower_arm 8
#define left_hand 9
#define right_thigh 10
#define right_leg 11
#define right_foot 12
#define left_thigh 13
#define left_leg 14
#define left_foot 15
#define rs_joint 16
#define ls_joint 17

class body {

private:

double pos_x;
double pos_y;
double pos_z;

double rotate_x_angle; 
double rotate_y_angle; 
double rotate_z_angle; 

double ortho_y_angle;

double elbows_y_offset;

double ip_pos_x;
double ip_pos_y;
double ip_pos_z;

double ip_rotate_x_angle; 
double ip_rotate_y_angle; 
double ip_rotate_z_angle; 

double ip_ortho_y_angle;

double ip_elbows_y_offset;

/* Angle Limits */

static double shoulder_x_min;
static double shoulder_x_max;
static double shoulder_y_min;
static double shoulder_y_max;
static double shoulder_z_min;
static double shoulder_z_max;

static double waist_x_min;
static double waist_x_max;
static double waist_y_min;
static double waist_y_max;
static double waist_z_min;
static double waist_z_max;

static double neck_x_min;
static double neck_x_max;
static double neck_y_min;
static double neck_y_max;
static double neck_z_min;
static double neck_z_max;

static double ankle_x_min;
static double ankle_x_max;
static double ankle_y_min;
static double ankle_y_max;

static double wrist_x_min;
static double wrist_x_max;
static double wrist_z_min;
static double wrist_z_max;

static double hip_x_min;
static double hip_x_max;
static double hip_y_min;
static double hip_y_max;
static double hip_z_min;
static double hip_z_max;

static double elbow_x_min;
static double elbow_x_max;

static double knee_x_min;
static double knee_x_max;

/* Current Angles */

double right_shoulder_x;
double right_shoulder_y;
double right_shoulder_z;

double left_shoulder_x;
double left_shoulder_y;
double left_shoulder_z;

double waist_x;
double waist_y;
double waist_z;

double neck_x;
double neck_y;
double neck_z;

double right_ankle_x;
double right_ankle_y;

double right_wrist_x;
double right_wrist_z;

double left_ankle_x;
double left_ankle_y;

double left_wrist_x;
double left_wrist_z;

double right_hip_x;
double right_hip_y;
double right_hip_z;

double left_hip_x;
double left_hip_y;
double left_hip_z;

double right_elbow_x;

double left_elbow_x;

double right_knee_x;

double left_knee_x;

double rs_joint_x;
double ls_joint_x;

double ip_right_shoulder_x;
double ip_right_shoulder_y;
double ip_right_shoulder_z;

double ip_left_shoulder_x;
double ip_left_shoulder_y;
double ip_left_shoulder_z;

double ip_waist_x;
double ip_waist_y;
double ip_waist_z;

double ip_neck_x;
double ip_neck_y;
double ip_neck_z;

double ip_right_ankle_x;
double ip_right_ankle_y;

double ip_right_wrist_x;
double ip_right_wrist_z;

double ip_left_ankle_x;
double ip_left_ankle_y;

double ip_left_wrist_x;
double ip_left_wrist_z;

double ip_right_hip_x;
double ip_right_hip_y;
double ip_right_hip_z;

double ip_left_hip_x;
double ip_left_hip_y;
double ip_left_hip_z;

double ip_right_elbow_x;

double ip_left_elbow_x;

double ip_right_knee_x;

double ip_left_knee_x;

double ip_rs_joint_x;
double ip_ls_joint_x;


/* Display Lists are created here */

void init_right_hand();
void init_right_lower_arm();
void init_right_upper_arm();

void init_left_hand();
void init_left_lower_arm();
void init_left_upper_arm();

void init_head();

void init_torso();

void init_right_foot();
void init_right_leg();
void init_right_thigh();

void init_left_foot();
void init_left_leg();
void init_left_thigh();

void init_pelvis();

void init_joints();

/* Does the appropriate transformations and calls the display lists */

public:

body();

void render();

/* Change the angles on key presses */

void move_right_shoulder_x(double t);
void move_right_shoulder_y(double t);
void move_right_shoulder_z(double t);

void move_left_shoulder_x(double t);
void move_left_shoulder_y(double t);
void move_left_shoulder_z(double t);

void move_waist_x(double t);
void move_waist_y(double t);
void move_waist_z(double t);

void move_neck_x(double t);
void move_neck_y(double t);
void move_neck_z(double t);

void move_right_ankle_x(double t);
void move_right_ankle_y(double t);

void move_right_wrist_x(double t);
void move_right_wrist_z(double t);

void move_left_ankle_x(double t);
void move_left_ankle_y(double t);

void move_left_wrist_x(double t);
void move_left_wrist_z(double t);

void move_left_hip_x(double t);
void move_left_hip_y(double t);
void move_left_hip_z(double t);

void move_right_hip_x(double t);
void move_right_hip_y(double t);
void move_right_hip_z(double t);

void move_right_elbow_x(double t);

void move_left_elbow_x(double t);

void move_right_knee_x(double t);

void move_left_knee_x(double t);

void rotate_x(double t);
void rotate_y(double t);
void rotate_z(double t);

void move_camera_r(double t);
void move_camera_t(double t);
void move_camera_p(double p);

void move(double t, double turn);
void move_x(double t);
void move_y(double t);

void rotate_y_ortho(double t);

bool transformed;
void transform();
void revert();
bool transforming;
int count_revert;
int count_transform;
int count_elbows_in;
int count_elbows_out;
int camera;
int ip_camera;
double dist;
double turn;
double wheel_rotate_angle;
double lookat_x;
double lookat_y;
double lookat_z;
bool headlight;
bool day;
bool moon_toggle;
double ip_turn;
double ip_wheel_rotate_angle;
double ip_lookat_x;
double ip_lookat_y;
double ip_lookat_z;
bool ip_headlight;
bool ip_day;
bool ip_moon_toggle;


double tree_x[100];
double tree_z[100];
bool tree_standing[100];
bool ip_tree_standing[100];
double tree_fall_angle[100];
double tree_y_angle[100];

/* Camera */
double camera_r;
double camera_t;
double camera_p;
double ip_camera_r;
double ip_camera_t;
double ip_camera_p;

bool camera_free;
bool ip_camera_free;

int frames;
int ip_frames;
void keyframe();
std::fstream keyfile;
bool playback;
bool terminate;
void playback_init();
void readframe();
void interpolate();
void linear_interpolate(double &, double &);
void angular_interpolate(double &, double &);
};

