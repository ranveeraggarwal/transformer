class body {

private:

/* Angle Limits */

const double shoulder_x_min;
const double shoulder_x_max;
const double shoulder_y_min;
const double shoulder_y_max;
const double shoulder_z_min;
const double shoulder_z_max;

const double waist_x_min;
const double waist_x_max;
const double waist_y_min;
const double waist_y_max;
const double waist_z_min;
const double waist_z_max;

const double neck_x_min;
const double neck_x_max;
const double neck_y_min;
const double neck_y_max;
const double neck_z_min;
const double neck_z_max;

const double ankle_x_min;
const double ankle_x_max;
const double ankle_y_min;
const double ankle_y_max;

const double wrist_x_min;
const double wrist_x_max;
const double wrist_z_min;
const double wrist_z_max;

const double hip_x_min;
const double hip_x_max;
const double hip_y_min;
const double hip_y_max;
const double hip_z_min;
const double hip_z_max;

const double elbow_x_min;
const double elbow_x_max;

const double knee_x_min;
const double knee_x_max;

/* Current Angles */

double right_shoulder_x;
double right_shoulder_y;
double right_shoudler_z;

double left_shoulder_x;
double left_shoulder_y;
double left_shoudler_z;

double waist_x;
double waist_y;
double waist_z;

double neck_x;
double nexk_y;
double next_z;

double right_ankle_x;
double right_ankle_y;

double right_wrist_x;
double right_wrist_z;

double left_ankle_x;
double left_ankle_y;

double left_wrist_x;
double left_wrist_z;

double hip_x;
double hip_y;
double hip_z;

double right_elbow_x;

double left_elbow_x;

double right_knee_x;

double left_knee_x;


/* Display Lists are created here */

void init_right_hand();
void init_right_lower_arm();
void init_right_upper_arm();

void init_left_hand();
void init_left_lower_arm();
void init_right_upper_arm();

void init_head();

void init_torso();

void init_right_foot();
void init_right_leg();
void init_right_thigh();

void init_left_foot();
void init_left_leg();
void init_left_thigh();

void init_pelvis();

/* Does the appropriate transformations and calls the display lists */

public:

body();

void render();

/* Change the angles on key presses */

void move_right_shoulder_x(double t);
void move_right_shoulder_y(double t);
void move_right_shoudler_z(double t);

void move_left_shoulder_x(double t);
void move_left_shoulder_y(double t);
void move_left_shoudler_z(double t);

void move_waist_x(double t);
void move_waist_y(double t);
void move_waist_z(double t);

void move_neck_x(double t);
void move_nexk_y(double t);
void move_next_z(double t);

void move_right_ankle_x(double t);
void move_right_ankle_y(double t);

void move_right_wrist_x(double t);
void move_right_wrist_z(double t);

void move_left_ankle_x(double t);
void move_left_ankle_y(double t);

void move_left_wrist_x(double t);
void move_left_wrist_z(double t);

void move_hip_x(double t);
void move_hip_y(double t);
void move_hip_z(double t);

void move_right_elbow_x(double t);

void move_left_elbow_x(double t);

void move_right_knee_x(double t);

void move_left_knee_x(double t);


};
