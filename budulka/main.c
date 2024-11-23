#include <stdio.h>
#include <math.h>

struct vec2d {
  double x, y;
};


struct vec3d {
  double x, y, z; 
};

struct roots {
	int roots;
	double t1;
	double t2;
}; 

struct ray_output {
	int found;
	struct vec3d p;
};
	
/*
 * scalar - vector 
 * a.x - scalar 
 * a.y - scalar 
 * a.z - scalar
*/


double dotproduct(struct vec3d a, struct vec3d b) {
  //printf("axbx= {%lf}\n, ayby = {%lf}\n, azbz = {%lf}", a.x * b.x, a.y * b.y, a.z );
  return a.x * b.x + a.y * b.y + a.z * b.z;
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
  r.y = a.y - b.y;
  r.z = a.z - b.z;
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
  printf("vec3d(%.4lf, %.4lf, %.4lf)\n", v.x, v.y, v.z);
}

double length(struct vec3d a) {
	return sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2));
}

double sphere(struct vec3d c, double r) {
	return length(c) - r;
}



struct roots solve_quadratic_eq(double a, double b, double c) {
	struct roots r;
	double d = pow(b, 2) - 4 * a * c;
	printf("disc : %lf\n", d);
	if (d > 0) {
		r.roots = 2;
		double x1 = (-b - sqrt(d)) / (2 * a); 
		double x2 = (-b + sqrt(d)) / (2 * a);
		if (x1 < x2) {
			r.t1 = x1;
			r.t2 = x2;
		}
		else {
			r.t1 = x2;
			r.t2 = x1;
		}

	}

	else if (d == 0) {
		r.roots = 1;
		if (-b + sqrt(d)) {
			r.t1 = (-b + sqrt(d)) / (2 * a);
		} else {
			r.t1 = (-b - sqrt(d)) / (2 * a); 
		}
	}
	else {
		r.roots = 0;
	}
	return r;
}

struct vec3d ray_equation(struct vec3d o, double t, struct vec3d d) {
	return add(o, multiply3d_by_scalar(d, t));
}


struct ray_output ray(struct vec3d o, struct vec3d v, struct vec3d c, double r) {
	struct vec3d d = subtract(v, o);
	print(d);
	//P = O + tD
	double a = dotproduct(d, d);
	printf("a : {%lf}", a);
	struct vec3d co = subtract(o, c);
	print(co);
	double b = 2 * dotproduct(co, d);
	printf("b: {%lf}", b);
	double f = dotproduct(co, co) - pow(r, 2);
	printf("C: %lf", f);
	struct roots roots = solve_quadratic_eq(a, b, f);
	printf("roots num: %d, %lf, %lf", roots.roots, roots.t1, roots.t2);
	struct ray_output p;
	if (roots.roots == 0) {
		p.found = 0;
	}
	else {
		p.found = 1;
		p.p = ray_equation(o, roots.t1, d);
	}
	return p;
	
	
}


int main() {
  struct vec3d c  = {2.f, 2.f, 3.f};
  struct vec3d v = {1.f, 1.f, 1.f};
  struct vec3d o = {0.f, 0.f, 0.f};
  double r = 1;
  struct ray_output ray_traced;
  ray_traced = ray(o, v, c, r);
  printf("Sphere point found at {%lf, %lf, %lf}", ray_traced.p.x, ray_traced.p.y, ray_traced.p.z);

  
  return 0;
}
