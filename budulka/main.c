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


struct vec3d subtract(struct vec3d a, struct vec3d b) {
  struct vec3d r;
  r.x = a.x - b.x;
  r.y = a.x - b.x;
  r.z = a.x - b.x;
  return r;
}

struct vec3d crossproduct(struct vec3d a, struct vec3d b) {
	struct vec3d r;
	r.x = a.y * b.z - b.y * a.z;
	r.y = a.z * b.x - b.z * a.x;
	r.z = a.x * b.y - a.y * b.x;
	return r;
}


struct vec2d multiply2d_by_scalar(struct vec2d a, double k) {
	struct vec2d r;
	r.x = a.x * k;
	r.y = a.y * k;
	return r;
} 

struct vec3d multiply3d_by_scalar(struct vec3d a, double k) {
	struct vec3d r;
	r.x = a.x * k;
	r.y = a.y * k;
	r.z = a.z * k;
	return r;
}

void print(struct vec3d v) {
  printf("vec3d(%.4lf, %.4lf, %.4lf)", v.x, v.y, v.z);
}


int main() {
  struct vec3d a = {1.f, 2.f, 3.f};
  struct vec3d b = {2.f, 3.f, 4.f};
  
  print(add(a, b));
  printf("\n");
  print(subtract(a, b));
  printf("dot product: %lf\n", dotproduct(a, b));
  print(multiply(a, b));
  print(divide(a, b));  
  printf("test\n");
  struct vec3d r = crossproduct(a, b);
  printf("cross_product: vector{%lf, %lf, %lf}", r.x, r.y, r.z);

  return 0;
}
