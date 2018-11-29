#include "lattice_graph.hpp"

using namespace std;
using namespace Eigen;

LatticeMotion::LatticeMotion(const vector<double>& turn_radius,
                             double arc_length)
    : turn_radius_(turn_radius), arc_length_(arc_length) {
  after_motion_relative_poses_.clear();
  for (double radius : turn_radius) {
    after_motion_relative_poses_.push_back(this->get_after_motion_pose(radius));
  }

  for (pose p : this->after_motion_relative_poses_)
    cout << p.x << " " << p.y << " " << p.theta << endl;

  cout << "LatticeMotion created." << endl;
}

LatticeMotion::~LatticeMotion() { cout << "LatticeMotion killed." << endl; }

pose LatticeMotion::get_after_motion_pose(double radius) {
  double relative_x = radius * sin(this->arc_length_ / radius);
  double relative_y = radius - radius * cos(this->arc_length_ / radius);
  double relative_theta = this->arc_length_ / radius;
  pose after_motion_pose = {
      .x = relative_x, .y = relative_y, .theta = relative_theta};
  return after_motion_pose;
}

pose LatticeMotion::to_global_frame(const pose& global_pose,
                                    pose relative_pose) {
  MatrixXd T(3, 3);
  T << cos(global_pose.theta), -sin(global_pose.theta), global_pose.x,
      sin(global_pose.theta), cos(global_pose.theta), global_pose.y, 0, 0, 1;
  Vector3d v(relative_pose.x, relative_pose.y, 1);

  Vector3d v_next = T * v;

  pose next_pose = {.x = v_next(0),
                    .y = v_next(1),
                    .theta = global_pose.theta + relative_pose.theta};
  return next_pose;
}

bool LatticeMotion::get_global_successors(const pose& global_pose,
                                          vector<pose>& global_successors) {
  global_successors.clear();

  // center trajectory successor
  pose mid = {.x = this->arc_length_, .y = 0, .theta = 0};
  pose global_mid = this->to_global_frame(global_pose, mid);
  global_successors.push_back(global_mid);

  // get the rest of the successors
  for (pose p : after_motion_relative_poses_) {
    pose global_p = this->to_global_frame(global_pose, p);
    global_successors.push_back(global_p);
  }

  return true;
}