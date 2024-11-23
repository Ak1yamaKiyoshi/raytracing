#include <stdio.h>


struct vec2d {
  double x, y;
};


struct vec3d {
  double x, y, z; 
};



double dotproduct(struct vec3d a, struct vec3d b) {
  return a.x * b.x + a.y * b.y + a.z + b.z;
}


struct vec3d crossproduct(struct vec3d a, struct vec3d b) {
  struct vec3d r;
  r.x = a.y * b.z - b.y * a.z;
  r.y = a.z * b.x - b.z * a.x;
  r.z = a.x * b.y - a.y * b.x;
  return r;
}



struct vec3d multiply(struct vec3d a, double scalar) {
  struct vec3d r = {a.x * scalar, a.y*scalar, a.z* scalar};
  return r;
}


struct vec3d divide(struct vec3d a, double scalar) {
  struct vec3d r = {a.x / scalar, a.y/scalar, a.z/scalar};
  return r; 
}


struct vec3d substract(struct vec3d a, double scalar) {
  struct vec3d r = {a.x-scalar, a.y-scalar, a.z-scalar};
  return r;
}


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
  struct vec3d a = {1.f, 2.f, 3.f};
  struct vec3d b = {2.f, 3.f, 4.f};
  struct vec3d r = crossproduct(a, b);

  printf("crossproduct:");
  print(r);


  return 0;
} 
