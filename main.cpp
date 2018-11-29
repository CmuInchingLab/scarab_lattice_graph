#include "lattice_graph.hpp"

using namespace std;
using Eigen::MatrixXd;

// this main executable is for testing
int main() {
  vector<double> turn_radius = {1.0, 2.0, -2.0, -1.0};
  double arc_length = 1.0;

  LatticeMotion motion_handler(turn_radius, arc_length);

  vector<double> radius = motion_handler.get_radius();
  for (double r : radius) cout << r << " ";
  cout << endl;

  int n = motion_handler.get_n_branches();
  cout << n << endl;

  double a = motion_handler.get_arc_length();
  cout << a << endl;

  // test get successors
  pose start_pose = {.x = 0.0, .y = 0.0, .theta = 0.0};
  vector<pose> global_successors;
  if (motion_handler.get_global_successors(start_pose, global_successors)) {
    cout << "function working." << endl;
    for (pose p : global_successors)
      cout << p.x << " " << p.y << " " << p.theta << endl;
  }

  // test to global frame
  pose relative_pose = {.x = 2.4, .y = 12, .theta = 0.5};
  pose global_pose = motion_handler.to_global_frame(start_pose, relative_pose);
  cout << global_pose.x << " " << global_pose.y << " " << global_pose.theta
       << endl;

  cout << "All done." << endl;
  return 0;
}