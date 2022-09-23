#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace chrono;

//returns sum of floating point array
double sum(const uintmax_t size,const double* arr){
  double total = 0.0;
  for (size_t i = 0; i<size;i++){
    total+=arr[i];
  }
  return total;
}


// Function that returns an array of 'size' floating point numbers in the range [-bound, bound]
double* generate_random_list(unsigned int size, double bound){
//  random_device rd;
//  mt19937 gen(rd()); //if i wanted to seed w random device instead of size
  mt19937 gen(size);
  uniform_real_distribution<> dist(-bound, bound);
  auto arr = new double[size];

  for (size_t i = 0; i < size; i++) {
    arr[i] = dist(gen);
  }
  return arr;
}

void update_coords(double* xs, double* ys, double* zs, const double* vx, const double* vy, const double* vz){
  for(size_t i = 0; i<sizeof(xs);i++){
    xs[i] = xs[i] + vx[i];
    ys[i] = ys[i] + vy[i];
    zs[i] = zs[i] + vz[i];
  }
}



int main(int argc, char* argv[]) {
//  generate_random_list test code
  //  double* arr= generate_random_list(10,10);
  //  for (size_t i = 0; i<10; i++){
  //    cout << arr[i] << " ";
  //  }
  //  cout << "\n";
  //  double* arr2= generate_random_list(10,10);
  //  for (size_t i = 0; i<10; i++){
  //    cout << arr2[i] << " ";
  //  }

  if (argc!=3){
    cout << "Required arguments: vector_length(N) and iterations_num(M)";
  }
  const uintmax_t size = atoi(argv[1]); //objects in space
  const uintmax_t iters = atoi(argv[2]); //game turns
  double* xs = generate_random_list(size, 1000.);
  double* ys = generate_random_list(size, 1000.);
  double* zs = generate_random_list(size, 1000.);
  const double* vx = generate_random_list(size, 1.);
  const double* vy = generate_random_list(size, 1.);
  const double* vz = generate_random_list(size, 1.);
//  xs test code
  //  for (size_t i = 0; i<size; i++){
  //    cout << i << " ";
  //    cout << xs[i] << "\n";
  //  }

//  time running update_coords iters amount of times

// A floating point milliseconds type
  using FpMicroseconds =
      duration<double, microseconds::period>;

  static_assert(treat_as_floating_point<FpMicroseconds::rep>::value,
                "Rep required to be floating point");

  auto start = high_resolution_clock::now();
  for (size_t i = 0; i<iters;i++){
    update_coords(xs, ys, zs, vx, vy, vz);
  }
  auto stop = high_resolution_clock::now();
  auto t = FpMicroseconds (stop - start);
  double mean_time = t.count()/(size*iters);
  double chksum = sum(size,xs) + sum(size,ys) + sum(size,zs);
  cout << fixed << setprecision(20)<< "Mean time per coordinate: " << mean_time <<"us\n";
  cout << "Final checksum is: " << chksum << "\n";

  return 0;
}
