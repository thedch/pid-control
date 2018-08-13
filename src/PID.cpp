#include <algorithm>
#include <iostream>

#include "PID.h"

using namespace std;


PID::PID(double Kp_, double Ki_, double Kd_, bool is_steer_) {
  Kp = Kp_;
  Ki = Ki_;
  Kd = Kd_;
  pid_previous_error = 0;
  pid_integral = 0;
  is_steer = is_steer_;
}

PID::~PID() {}


double PID::UpdateError(double error) {
  // Pass in cross track error, get out new steering angle?
  double pid_dt = 1; // Set timestep to be 1 for now
  pid_integral = pid_integral + (error * pid_dt); // 0 + 0.75 * 1
  double pid_derivative = (error - pid_previous_error) / pid_dt;
  pid_previous_error = error;

  double new_angle = (Kp * error) + (Ki * pid_integral) + (Kd * pid_derivative);

  if (is_steer) {
    cout << "DEBUG: " << error << " " << Kp << " " << Ki << " " << Kd << " " << new_angle << endl;
  }

  return new_angle;
}

double PID::TotalError() {
  return 0;
}

