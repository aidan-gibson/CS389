#include <iostream>
#include <random>
#include <chrono>
#include <iomanip>
using namespace std;
using namespace chrono;

//returns sum of floating point array
float sum(const uintmax_t size,const float* arr){
  float total = 0.0;
  for (size_t i = 0; i<size;i++){
    total+=arr[i];
  }
  return total;
}


// Function that returns an array of 'size' floating point numbers in the range [-bound, bound]
float* generate_random_list(unsigned int size, float bound){
//  random_device rd;
//  mt19937 gen(rd()); //if i wanted to seed w random device instead of size
  mt19937 gen(size);
  uniform_real_distribution<float> dist(-bound, bound);
  auto arr = new float[size];

  for (size_t i = 0; i < size; i++) {
    arr[i] = dist(gen);
  }
  return arr;
}

void update_coords(float* xs, float* ys, float* zs, const float* vx, const float* vy, const float* vz){
  for(size_t i = 0; i<sizeof(xs);i++){
    xs[i] = xs[i] + vx[i];
    ys[i] = ys[i] + vy[i];
    zs[i] = zs[i] + vz[i];
  }
}



int main(int argc, char* argv[]) {
//  generate_random_list test code
  //  float* arr= generate_random_list(10,10);
  //  for (size_t i = 0; i<10; i++){
  //    cout << arr[i] << " ";
  //  }
  //  cout << "\n";
  //  float* arr2= generate_random_list(10,10);
  //  for (size_t i = 0; i<10; i++){
  //    cout << arr2[i] << " ";
  //  }

  if (argc!=3){
    cout << "Required arguments: vector_length(N) and iterations_num(M)";
  }
  const uintmax_t size = atoi(argv[1]); //objects in space
  const uintmax_t iters = atoi(argv[2]); //game turns
  float* xs = generate_random_list(size, 1000.);
  float* ys = generate_random_list(size, 1000.);
  float* zs = generate_random_list(size, 1000.);
  const float* vx = generate_random_list(size, 1.);
  const float* vy = generate_random_list(size, 1.);
  const float* vz = generate_random_list(size, 1.);
//  xs test code
  //  for (size_t i = 0; i<size; i++){
  //    cout << i << " ";
  //    cout << xs[i] << "\n";
  //  }

//  time running update_coords iters amount of times

// A floating point milliseconds type
  using FpMicroseconds =
      duration<float, microseconds::period>;

  static_assert(treat_as_floating_point<FpMicroseconds::rep>::value,
                "Rep required to be floating point");

  auto start = high_resolution_clock::now();
  for (size_t i = 0; i<iters;i++){
    update_coords(xs, ys, zs, vx, vy, vz);
  }
  auto stop = high_resolution_clock::now();
  auto t = FpMicroseconds (stop - start);
  float mean_time = t.count()/(size*iters);
  float chksum = sum(size,xs) + sum(size,ys) + sum(size,zs);
  cout << fixed << setprecision(20)<< "Mean time per coordinate: " << mean_time <<"us\n";
  cout << "Final checksum is: " << chksum << "\n";

  return 0;
}
