#include <random>
#include <vector>

#include "./cosine_similarity.h"
#include <benchmark/benchmark.h>

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

static void BM_CosineSimilarity_ref(benchmark::State &state) {
  /* cout << "ok" << std::endl; */
  const int sz = 300;
  vector<float> A = rand_vector(sz, 1234);
  vector<float> B = rand_vector(sz, 5678);

  for (auto _ : state) {
    /* auto cos = A[0]; */
    auto cos = cosine_similarity_ref(static_cast<int>(sz),
                                     static_cast<float *>(A.data()),
                                     static_cast<float *>(B.data()));
    benchmark::DoNotOptimize(cos);
  }
}

static void BM_CosineSimilarity_dd(benchmark::State &state) {
  const int sz = 300;
  vector<float> A = rand_vector(sz, 1234);
  vector<float> B = rand_vector(sz, 5678);

  for (auto _ : state) {
    auto cos = cosine_similarity_dd(static_cast<const int>(sz),
                                    static_cast<const float *>(A.data()),
                                    static_cast<const float *>(B.data()));
    benchmark::DoNotOptimize(cos);
  }
}

/* static void BM_CosineSimilarity_dot(benchmark::State &state) { */
/*   /1* cout << "ok" << std::endl; *1/ */
/*   const int sz = 300; */
/*   vector<float> A = rand_vector(sz, 1234); */
/*   vector<float> B = rand_vector(sz, 5678); */

/*   for (auto _ : state) { */
/*     /1* auto cos = A[0]; *1/ */
/*     auto cos = dot(static_cast<int>(sz), static_cast<float *>(A.data()), */
/*                    static_cast<float *>(B.data())); */
/*     benchmark::DoNotOptimize(cos); */
/*   } */
/* } */
/* BENCHMARK(BM_CosineSimilarity_dot); */
BENCHMARK(BM_CosineSimilarity_ref);
BENCHMARK(BM_CosineSimilarity_dd);
BENCHMARK_MAIN()
