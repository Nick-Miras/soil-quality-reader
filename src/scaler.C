/***************************************************************************/
/* File automatically generated with scikinC (github.com/landerli/scikinC) */
/*                                                                         */
/*                       D O   N O T   E D I T   ! ! !                     */
/*                                                                         */
/*  File generated on 2026-03-18 10:58                                     */
/*  by nickanthonymiras                                                   */
/*  using StandardScalerConverter                        as converter      */
/*                                                                         */
/***************************************************************************/
#define FLOAT_T float

    extern "C" 
    FLOAT_T* scaler (FLOAT_T* ret, const FLOAT_T *input)
    {
      int c; 
      FLOAT_T mean [] = {1.65967339532773872079, 43.44794738035835734991, 28.85041959628033580998, 63.22767067362213566639}; 
      FLOAT_T scale[] = {0.93831522259273647535, 27.16954197018304029143, 9.65017332765280677620, 22.72803980088702857643}; 

      for (c = 0; c < 4; ++c)
        ret [c] = (input[c] - mean[c]) / scale[c];

      return ret;
    }
      

    extern "C" 
    FLOAT_T* scaler_inverse (FLOAT_T* ret, const FLOAT_T *input)
    {
      int c; 
      FLOAT_T mean [] = {1.65967339532773872079, 43.44794738035835734991, 28.85041959628033580998, 63.22767067362213566639}; 
      FLOAT_T scale[] = {0.93831522259273647535, 27.16954197018304029143, 9.65017332765280677620, 22.72803980088702857643}; 

      for (c = 0; c < 4; ++c)
        ret [c] = (input[c] * scale[c]) + mean[c]; 

      return ret;
    }
    
