#include <stdio.h>
#include <math.h>
#include <malloc.h>


struct vec2d {
  double x, y;
};


struct vec3d {
  double x, y, z; 
};



double dotproduct_3d(struct vec3d a, struct vec3d b) {
  return a.x * b.x + a.y * b.y + a.z * b.z;
}


double len(struct vec3d vec) {
  return sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
} 


struct vec3d crossproduct_3d(struct vec3d a, struct vec3d b) {
  struct vec3d r;
  r.x = a.y * b.z - b.y * a.z;
  r.y = a.z * b.x - b.z * a.x;
  r.z = a.x * b.y - a.y * b.x;
  return r;
}



struct vec3d multiply_3d_scalar(struct vec3d a, double scalar) {
  struct vec3d r = {a.x * scalar, a.y*scalar, a.z* scalar};
  return r;
}


struct vec3d divide_3d_scalar(struct vec3d a, double scalar) {
  struct vec3d r = {a.x / scalar, a.y/scalar, a.z/scalar};
  return r; 
}


struct vec3d subtract_3d_scalar(struct vec3d a, double scalar) {
  struct vec3d r = {a.x-scalar, a.y-scalar, a.z-scalar};
  return r;
}


struct vec3d multiply_3d(struct vec3d a, struct vec3d b) {
  struct vec3d r;
  r.x = a.x * b.x;
  r.y = a.y * b.y;
  r.z = a.z * b.z;
  return r;
}


struct vec3d divide_3d(struct vec3d a, struct vec3d b) {
  struct vec3d r; 
  r.x = a.x / a.x;
  r.y = a.y / a.y;
  r.z = a.z / a.z;
  return r;
}


struct vec3d add_3d(struct vec3d a, struct vec3d b) {
  struct vec3d r; 
  r.x = a.x + b.x;
  r.y = a.y + b.y;
  r.z = a.z + b.z; 
  return r;
}


struct vec3d subtract_3d(struct vec3d a, struct vec3d b) {
  struct vec3d r;
  r.x = a.x - b.x;
  r.y = a.y - b.y;
  r.z = a.z - b.z;
  return r;
}

struct vec2d subtract_2d(struct vec2d a, struct vec2d b) {
  struct vec2d r = {a.x - b.x, a.y - b.y};
  return r;
}


double sphere(struct vec3d c, double radius) {
  return len(c) - radius;
}


void print(struct vec3d v) {
  printf("vec3d(%.4lf, %.4lf, %.4lf)", v.x, v.y, v.z);
}



struct arraylf {
  size_t len;
  double *p;
}; 


struct vec3d ray2sphere(struct vec3d plane_point, struct vec3d camera, struct vec3d sphere, double r) {
  
  struct arraylf result;
  double t = 1.f;
  struct vec3d d = subtract_3d(plane_point, camera); 
  d = multiply_3d_scalar(d, t);
  struct vec3d co = subtract_3d(camera, sphere);
 
  struct vec3d dump = {-99999, -99999, -99999};
  double a = dotproduct_3d(d, d);
  double b = 2 * dotproduct_3d(co, d);
  double c = dotproduct_3d(co, co) - r*r;
  

  double discriminant = b*b - 4*a*c;
  if (discriminant < 0) {
    result.len = 0;
    return dump;
  }

  printf("equasion:  a: %lf b: %lf c: %lf \n", a, b, c);
  
  result.len = 2;
  result.p = (double*)malloc(sizeof(double)*2);

  result.p[0] = (-b + sqrt(discriminant)) / (2*a);
  result.p[1] = (-b - sqrt(discriminant)) / (2*a);

  if (result.p[0] > result.p[1]) {
     double point = result.p[0];
     result.p[0] = result.p[1];
     result.p[1] = point;
  }

  struct vec3d new_d = multiply_3d_scalar(d, result.p[1]);
  struct vec3d sphere_point = add_3d(camera,  new_d);
  
  // printf("sphere point:\n");
  // print(sphere_point);

  return sphere_point;//result;
}


int main() {
  struct vec3d sphere = {2.f, 2.f, 3.f};
  struct vec3d camera = {0.f, 0.f, 0.f};
  struct vec3d v = {1.f, 1.f, 1.f};
  double sphere_radius = 1;
  struct vec3d touching_sphere;

  int width = 200, height = 200; 
  struct arraylf equasions;

  touching_sphere = ray2sphere(v, camera, sphere, sphere_radius);
  print(touching_sphere);



  // struct vec3d a = {1.f, 2.f, 3.f};
  // struct vec3d b = {2.f, 3.f, 4.f};
  
  // sphere(a, 1); 

  return 0;
} 
