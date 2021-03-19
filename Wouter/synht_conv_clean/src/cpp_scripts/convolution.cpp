#include <iostream>
#include "../headers/convolution.h"
//#include <thread>

Convolution::Convolution(std::vector<float> IRP){
  ImpulseResponse = IRP;
  SampleLength = IRP.size();
  Counter = 0;
  Convs.reserve(SampleLength + 1);
}

Convolution::~Convolution() {

}

void Convolution::ConvGenerator(std::vector<float> INV, std::vector<float> IMV, int ID){

    __m256 inputs;
    __m256 impulses;
    __m256 outy = _mm256_set_ps(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    __m256 tmp3;

    for(size_t i = 0; i + 7 < INV.size(); i += 8) {
        inputs = _mm256_set_ps(INV[i], INV[i + 1], INV[i + 2], INV[i + 3], INV[i + 4], INV[i + 5], INV[i + 6], INV[i + 7]);
        impulses = _mm256_set_ps(IMV[i], IMV[i + 1], IMV[i + 2], IMV[i + 3], IMV[i + 4], IMV[i + 5], IMV[i + 6], IMV[i + 7]);
        tmp3 = _mm256_mul_ps(inputs,impulses);
        outy = _mm256_add_ps(tmp3, outy);
    }
    __m256 tmp = _mm256_hadd_ps(outy, outy);
    tmp = _mm256_hadd_ps(tmp, tmp);
    Output += ((float*)&tmp)[3] + ((float*)&tmp)[4];
    std::cout << Output << " id = " << ID << "\n";

}

float Convolution::getSamp(float CurSampy) {
  Output = 0;
  //outy = _mm256_set_ps(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);

  InputVector.insert(InputVector.begin(), CurSampy);
    ++Counter;
    if(Counter >= SampleLength) {
        InputVector.pop_back();
    }

//  for(size_t i = 0; i + 7 < InputVector.size(); i += 8) {
//      inputs = _mm256_set_ps(InputVector[i], InputVector[i + 1], InputVector[i + 2], InputVector[i + 3], InputVector[i + 4], InputVector[i + 5], InputVector[i + 6], InputVector[i + 7]);
//      impulses = _mm256_set_ps(ImpulseResponse[i], ImpulseResponse[i + 1], ImpulseResponse[i + 2], ImpulseResponse[i + 3], ImpulseResponse[i + 4], ImpulseResponse[i + 5], ImpulseResponse[i + 6], ImpulseResponse[i + 7]);
//      tmp3 = _mm256_mul_ps(inputs,impulses);
//      outy = _mm256_add_ps(tmp3, outy);
//  }

  std::thread threads[10];
    std::cout << "kaas \n" ;
  for(int i = 0; i < 100 && i + 9 < InputVector.size(); i += 10){
      std::cout << "kaaszig" << "\n";
      std::vector<float> PartOfInput(InputVector.begin() + i, InputVector.begin() + i + 9);
      std::vector<float> PartOfImpulse(ImpulseResponse.begin() + i, ImpulseResponse.begin() + i + 9);
      threads[i] = std::thread(&Convolution::ConvGenerator, this, PartOfInput, PartOfImpulse, i);
  }
  std::cout<< InputVector.size() << " size \n";
  for(int i = 0; i < 10 && InputVector.size() > 10; i++){
      std::cout<< "kaas2 \n";
      threads[i].join();
  }
  //std::cout<< "kaas2 \n";

//  __m256 tmp = _mm256_hadd_ps(outy, outy);
////  //tmp = _mm256_hadd_ps(tmp, tmp);
//  tmp = _mm256_hadd_ps(tmp, tmp);
//  Output = ((float*)&tmp)[3] + ((float*)&tmp)[4];
////  tmp = _mm256_hadd_ps(tmp, tmp);
////  __m256d casted = _mm256_castps_pd(tmp);
////  __m128 hi = _mm_castpd_ps(_mm256_extractf128_pd(casted, 1));
////  __m128 lo = _mm_castpd_ps(_mm256_castpd256_pd128(casted));
////  __m128 odd  = _mm_shuffle_ps(hi, lo, _MM_SHUFFLE(3,1,3,1));
////  __m128 even = _mm_shuffle_ps(lo, hi, _MM_SHUFFLE(2,0,2,0));
////  __m128 together = _mm_add_ps(even, odd);
////
//  float *k = (float *)&tmp;
////
////  for(int i = 0; i < 7; ++i){
////      std::cout << k[i] << "  ";
////  }
////    std::cout << std::endl;
//    Output = k[4] + k[3];
    //std::cout << InputVector.size() << "\n";
    for(size_t i = 0; InputVector.size() > 8 && i < InputVector.size() % 8; i++) {
        //std::cout << i << "\n";
        Output += InputVector[InputVector.size()-i-1] * ImpulseResponse[InputVector.size()-i-1];
    }
//    std::cout << Output << "\n";

    // Zo maak ik het makkelijk leesbaar voor normale dingen die niet avx zijn :)
    //float NewOuty = _mm256_fmadd_ps(odds, evens, NewOuty);
//    float *f = (float *)&outy;
//////  std::cout << f;
//////  std::cout << "\n";
////
////
//    for(size_t i = 0; i < 8; ++i){
//        Output += f[i];
//    }

//    for(size_t i = 0; i < % InputVector.size(); i++) {
//
//    }
//  InputVector.push_back(CurSampy);
    //Makes a new IR instance
    //Convs.push_back(SampleConv(ImpulseResponse, CurSampy));
    //Adds all Impulse Response values
//  for(size_t i = 0; i < InputVector.size(); ++i) {
//      Output += InputVector[i] * ImpulseResponse[i];
//  }
//  for(int i = 0; i < InputVector.size()) {
//      if (InputVector.size() - i < 1024) {
//          gpuCalc<<<1, InputVector.size() - i>>>(ImpulseResponse, InputVector, i);
//          cudaDeviceSynchronize();
//          i += InputVector - i;
//      } else {
//          gpuCalc<<<1, 1024>>>(ImpulseResponse, InputVector, i);
//          cudaDeviceSynchronize();
//          i += 1024;
//      }
//  }


    return Output;
}
