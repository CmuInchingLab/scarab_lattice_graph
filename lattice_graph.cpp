#include "lattice_graph.hpp"

using namespace std;

LatticeMotion::LatticeMotion(const vector<double>& turn_radius,
                             double arc_length)
    : turn_radius_(turn_radius), arc_length_(arc_length) {
  after_motion_relative_poses_.clear();
  for (double radius : turn_radius) {
    after_motion_relative_poses_.push_back(this->get_after_motion_pose(radius));
  }
  cout << "LatticeMotion created." << endl;
}

LatticeMotion::~LatticeMotion() { cout << "LatticeMotion killed." << endl; }

pose LatticeMotion::get_after_motion_pose(double radius) {
  double relative_x = radius * sin(this->arc_length_ / radius);
  double relative_y = radius - radius * sin(this->arc_length_ / radius);
  double relative_theta = this->arc_length_ / radius;
  pose after_motion_pose = {
      .x = relative_x, .y = relative_y, .theta = relative_theta};
  return after_motion_pose;
}

bool LatticeMotion::get_global_successors(const pose& global_pose,
                                          vector<pose>& global_successors) {
  global_successors.clear();

  // center trajectory successor
  pose mid = {.x = global_pose.x + this->arc_length_,
              .y = global_pose.y,
              .theta = global_pose.theta};
  global_successors.push_back(mid);

  // get the
  return true;
}