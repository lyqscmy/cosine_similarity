#include <cstdio>
#include <vector>
#include <random>
#include "./cosine_similarity.h" 

using std::vector;

vector<float> rand_vector(const int sz, const int seed) {
  vector<float> A(sz);
  std::mt19937 gen(seed);
  std::uniform_real_distribution<float> dis(0, 1);

  for (auto &x : A) {
    x = dis(gen);
  }
  return A;
}

int main() {
  constexpr int sz = 300;
  vector<float> A = rand_vector(sz, 123);
  vector<float> B = rand_vector(sz, 124);
  printf("ref:\t%lf\n", cosine_similarity_ref(sz, A.data(), B.data()));
  printf("dd:\t%lf\n", cosine_similarity_dd(sz, A.data(), B.data()));
  return 0;
}
