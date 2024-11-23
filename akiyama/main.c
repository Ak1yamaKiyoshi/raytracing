#include <stdio.h>


struct vec2d {
  double x, y;
};


struct vec3d {
  double x, y, z; 
};



/*
 * scalar - vector 
 * a.x - scalar 
 * a.y - scalar 
 * a.z - scalar
*/


double dotproduct(struct vec3d a, struct vec3d b) {
  return a.x * b.x + a.y * b.y + a.z + b.z;
}

// print; +-*
struct vec3d multiply(struct vec3d a, struct vec3d b) {
  struct vec3d r;
  r.x = a.x * b.x;
  r.y = a.y * b.y;
  r.z = a.z * b.z;
  return r;
}

struct vec3d divide(struct vec3d a, struct vec3d b) {
  struct vec3d r; 
  r.x = a.x / a.x;
  r.y = a.y / a.y;
  r.z = a.z / a.z;
  return r;
}

struct vec3d add(struct vec3d a, struct vec3d b) {
  struct vec3d r; 
  r.x = a.x + b.x;
  r.y = a.y + b.y;
  r.z = a.z + b.z; 
  return r;
}


struct vec3d substract(struct vec3d a, struct vec3d b) {
  struct vec3d r;
  r.x = a.x - b.x;
  r.y = a.x - b.x;
  r.z = a.x - b.x;
  return r;
}


void print(struct vec3d v) {
  printf("vec3d(%.4lf, %.4lf, %.4lf)", v.x, v.y, v.z);
}


int main() {
  vec3d a = {1.f, 2.f, 3.f};
  vec3d b = {2.f, 3.f, 4.f};
  
  print(add(a, b));
  printf("\n");
  print(substract(a, b));
  printf("dot product: %lf", dotproduct(a, b));
  print(multiply(a, b));
  print(divide(a, b));  
  printf("test");
  return 0;
}
