class body {

public body();

/* Angle Limits */

private const double shoulder_x_min;
private const double shoulder_x_max;
private const double shoulder_y_min;
private const double shoulder_y_max;
private const double shoulder_z_min;
private const double shoulder_z_max;

private const double waist_x_min;
private const double waist_x_max;
private const double waist_y_min;
private const double waist_y_max;
private const double waist_z_min;
private const double waist_z_max;

private const double neck_x_min;
private const double neck_x_max;
private const double neck_y_min;
private const double neck_y_max;
private const double neck_z_min;
private const double neck_z_max;

private const double ankle_x_min;
private const double ankle_x_max;
private const double ankle_y_min;
private const double ankle_y_max;

private const double wrist_x_min;
private const double wrist_x_max;
private const double wrist_z_min;
private const double wrist_z_max;

private const double hip_x_min;
private const double hip_x_max;
private const double hip_y_min;
private const double hip_y_max;
private const double hip_z_min;
private const double hip_z_max;

private const double elbow_x_min;
private const double elbow_x_max;

private const double knee_x_min;
private const double knee_x_max;

/* Current Angles */

private double right_shoulder_x;
private double right_shoulder_y;
private double right_shoudler_z;

private double left_shoulder_x;
private double left_shoulder_y;
private double left_shoudler_z;

private double waist_x;
private double waist_y;
private double waist_z;

private double neck_x;
private double nexk_y;
private double next_z;

private double right_ankle_x;
private double right_ankle_y;

private double right_wrist_x;
private double right_wrist_z;

private double left_ankle_x;
private double left_ankle_y;

private double left_wrist_x;
private double left_wrist_z;

private double hip_x;
private double hip_y;
private double hip_z;

private double right_elbow_x;

private double left_elbow_x;

private double right_knee_x;

private double left_knee_x;


/* Display Lists are created here */

private void init_right_hand();
private void init_right_lower_arm();
private void init_right_upper_arm();

private void init_left_hand();
private void init_left_lower_arm();
private void init_right_upper_arm();

private void init_head();

private void init_torso();

private void init_right_foot();
private void init_right_leg();
private void init_right_thigh();

private void init_left_foot();
private void init_left_leg();
private void init_left_thigh();

private void init_pelvis();

/* Does the appropriate transformations and calls the display lists */

public void render();

/* Change the angles on key presses */

public void move_right_shoulder_x(double t);
public void move_right_shoulder_y(double t);
public void move_right_shoudler_z(double t);

public void move_left_shoulder_x(double t);
public void move_left_shoulder_y(double t);
public void move_left_shoudler_z(double t);

public void move_waist_x(double t);
public void move_waist_y(double t);
public void move_waist_z(double t);

public void move_neck_x(double t);
public void move_nexk_y(double t);
public void move_next_z(double t);

public void move_right_ankle_x(double t);
public void move_right_ankle_y(double t);

public void move_right_wrist_x(double t);
public void move_right_wrist_z(double t);

public void move_left_ankle_x(double t);
public void move_left_ankle_y(double t);

public void move_left_wrist_x(double t);
public void move_left_wrist_z(double t);

public void move_hip_x(double t);
public void move_hip_y(double t);
public void move_hip_z(double t);

public void move_right_elbow_x(double t);

public void move_left_elbow_x(double t);

public void move_right_knee_x(double t);

public void move_left_knee_x(double t);


};
