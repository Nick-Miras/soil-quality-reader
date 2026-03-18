//
// Created by Nick Anthony Miras on 3/18/26.
//

#ifndef SOIL_QUALITY_READER_SCALER_H
#define SOIL_QUALITY_READER_SCALER_H
#define FLOAT_T float

extern "C" FLOAT_T* scaler(FLOAT_T* ret, const FLOAT_T *input);
extern "C" FLOAT_T* scaler_inverse(FLOAT_T* ret, const FLOAT_T *input);

#endif //SOIL_QUALITY_READER_SCALER_H