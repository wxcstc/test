#include<iostream>
using namespace std;

void cvKalmanCorrect4(cvKalman_t *pKalman,float *pMeasurement){
    float measurementMatrix_T[8];

    // temp2 = H*P'(k)
    gemm_kernel_24_44(pKalman->measurementMatrix,pKalman->errorCovPre,pKalman->temp2);

    // temp3 = temp2*Ht + R
    transpose_24(pKalman->measurementMatrix,measurementMatrix_T);
    gemm_kernel_24_42(pKalman->temp2,measurementMatrix_T,pKalman->temp3);
    add_kernel_22(pKalman->temp3,pKalman->measurementNoiseCov);

    // temp4 = inv(temp3)*temp2 = Kt(k)
    solve(pKalman->temp3,pKalman->temp2,pKalman->temp4);

    //K(k)
    transpose_kernel_24(pKalman->temp4,pKalman->gain);

    // temp5 = z(k) - H*x'(k)

    temp5 = measurement - measurementMatrix*statePre;

    // x(k) = x'(k) + K(k)*temp5
    gemm_kernel_42_21(pKalman->gain,pKalman->temp5,pKalman->state);
    add_kernel_41(pKalman->)
    statePost = statePre + gain*temp5;

    // P(k) = P'(k) - K(k)*temp2
    errorCovPost = errorCovPre - gain*temp2;
}
int  main(){

    return 0;
}
