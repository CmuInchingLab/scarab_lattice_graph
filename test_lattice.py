import matplotlib.pyplot as plt
import numpy as np
import pdb


def get_delta_x(radius, arc_length):
  return radius * np.sin(arc_length/radius)

def get_delta_y(radius, arc_length):
  return radius - radius * np.cos(arc_length/radius)

def find_distance(x1, y1, x2, y2):
  return (x1 - x2)**2 + (y1 - y2)**2

if __name__ == "__main__":
  x = 3
  y = 3
  plt.plot(x, y, 'bx')

  # fixed
  arc_length = 1.0
  max_radius = 2.0
  gen_n_branches = 2

  # given
  min_radius = 1.0
  desired_branches_per_side = 2

  # initial generation
  neg_radius = list(np.linspace(-max_radius, -min_radius, num=gen_n_branches))
  pos_radius = list(np.linspace(min_radius, max_radius, num=gen_n_branches))
  radius = pos_radius + neg_radius

  # center, infinite turning radius
  x_mid = x + arc_length
  y_mid = y
  plt.plot(x_mid, y_mid, 'rx')

  # distance from center
  eps = 1e-3
  tmp_x = get_delta_x(radius[0], arc_length) + x
  tmp_y = get_delta_y(radius[0], arc_length) + y
  min_dist = find_distance(tmp_x, tmp_y, x_mid, y_mid)

  for r in radius:
    x_r = get_delta_x(r, arc_length) + x
    y_r = get_delta_y(r, arc_length) + y
    plt.plot(x_r, y_r, 'rx')


  plt.show()