#include<math.h>
#include<iostream>
using namespace std;
#define  GAM     4096.e0
#define  GAMSQ   16777216.e0
#define  RGAMSQ  5.9604645e-8

#define  TWO 2.e0
#define ONE 1.e0
#define ZERO 0.e0
#ifdef DOUBLE
#define ABS(x) fabs(x)
#else
#define ABS(x) fabsf(x)
#endif

#define FLOAT float

void rotmg(FLOAT *dd1, FLOAT *dd2, FLOAT *dx1, FLOAT dy1, FLOAT *dparam){



	FLOAT du, dp1, dp2, dq2, dq1, dh11=ZERO, dh21=ZERO, dh12=ZERO, dh22=ZERO, dflag=-ONE, dtemp;

	if(*dd1 < ZERO)
	{
		dflag = -ONE;
		dh11  = ZERO;
		dh12  = ZERO;
		dh21  = ZERO;
		dh22  = ZERO;

		*dd1  = ZERO;
		*dd2  = ZERO;
		*dx1  = ZERO;
	}
	else
	{
		dp2 = *dd2 * dy1;
		if(dp2 == ZERO)
		{
			dflag = -TWO;
			dparam[0] = dflag;
			return;
		}
		dp1 = *dd1 * *dx1;
		dq2 =  dp2 * dy1;
		dq1 =  dp1 * *dx1;
		if(ABS(dq1) > ABS(dq2))
		{
			dh21 = -  dy1 / *dx1;
			dh12 =    dp2 /  dp1;

			du   = ONE - dh12 * dh21;
			if(du > ZERO)
			{
				dflag = ZERO;
				*dd1  = *dd1 / du;
				*dd2  = *dd2 / du;
				*dx1  = *dx1 * du;

			}
		}
		else
		{
			if(dq2 < ZERO)
			{
				dflag = -ONE;

				dh11  = ZERO;
				dh12  = ZERO;
				dh21  = ZERO;
				dh22  = ZERO;

				*dd1  = ZERO;
				*dd2  = ZERO;
				*dx1  = ZERO;
			}
			else
			{
				dflag = ONE;

				dh11  =  dp1 /  dp2;
				dh22  = *dx1 /  dy1;
				du    =  ONE + dh11 * dh22;
				dtemp = *dd2 / du;

				*dd2  = *dd1 / du;
				*dd1  = dtemp;
				*dx1  = dy1 * du;
			}
		}


		if(*dd1 != ZERO)
		{
			if( (*dd1 <= RGAMSQ) || (*dd1 >= GAMSQ) )
			{
				if(dflag == ZERO)
				{
					dh11  =  ONE;
					dh22  =  ONE;
					dflag = -ONE;
				}
				else
				{
						dh21  = -ONE;
						dh12  =  ONE;
						dflag = -ONE;
				}
				if( *dd1 <= RGAMSQ )
				{
					while (ABS(*dd1) <= RGAMSQ) {
						*dd1  = *dd1 * (GAM * GAM);
						*dx1  = *dx1 / GAM;
						dh11  = dh11 / GAM;
						dh12  = dh12 / GAM;
					}
				}
				else
				{
					while (ABS(*dd1) >= GAMSQ) {
						*dd1  = *dd1 / (GAM * GAM);
						*dx1  = *dx1 * GAM;
						dh11  = dh11 * GAM;
						dh12  = dh12 * GAM;
					}
				}
			}
		}

		if(*dd2 != ZERO)
		{
			if( (ABS(*dd2) <= RGAMSQ) || (ABS(*dd2) >= GAMSQ) )
			{
				if(dflag == ZERO)
				{
					dh11  =  ONE;
					dh22  =  ONE;
					dflag = -ONE;
				}
				else
				{
						dh21  = -ONE;
						dh12  =  ONE;
						dflag = -ONE;
				}
				if( ABS(*dd2) <= RGAMSQ )
				{
					while (ABS(*dd2) <= RGAMSQ) {
						*dd2  = *dd2 * (GAM * GAM);
						dh21  = dh21 / GAM;
						dh22  = dh22 / GAM;
					}
				}
				else
				{
					while (ABS(*dd2) >= GAMSQ) {
						*dd2  = *dd2 / (GAM * GAM);
						dh21  = dh21 * GAM;
						dh22  = dh22 * GAM;
					}
				}
			}
		}

	}

	if(dflag < ZERO)
	{
		dparam[1] = dh11;
		dparam[2] = dh21;
		dparam[3] = dh12;
		dparam[4] = dh22;
	}
	else
	{
		if(dflag == ZERO)
		{
			dparam[2] = dh21;
			dparam[3] = dh12;
		}
		else
		{
			dparam[1] = dh11;
			dparam[4] = dh22;
		}
	}


	dparam[0] = dflag;
	return;
}

void rotmgg(FLOAT *dd1, FLOAT *dd2, FLOAT *dx1, FLOAT dy1, FLOAT *dparam){



	FLOAT du, dp1, dp2, dq2, dq1, dh11=ZERO, dh21=ZERO, dh12=ZERO, dh22=ZERO, dflag=-ONE, dtemp;

	if(*dd1 < ZERO)
	{
		dflag = -ONE;
		dh11  = ZERO;
		dh12  = ZERO;
		dh21  = ZERO;
		dh22  = ZERO;

		*dd1  = ZERO;
		*dd2  = ZERO;
		*dx1  = ZERO;
	}
	else
	{
		dp2 = *dd2 * dy1;
		if(dp2 == ZERO)
		{
			dflag = -TWO;
			dparam[0] = dflag;
			return;
		}
		dp1 = *dd1 * *dx1;
		dq2 =  dp2 * dy1;
		dq1 =  dp1 * *dx1;
		if(ABS(dq1) > ABS(dq2))
		{
			dh21 = -  dy1 / *dx1;
			dh12 =    dp2 /  dp1;

			du   = ONE - dh12 * dh21;
			if(du > ZERO)
			{
				dflag = ZERO;
				//dh11  =  ONE;
                //dh22  =  ONE;
				*dd1  = *dd1 / du;
				*dd2  = *dd2 / du;
				*dx1  = *dx1 * du;

			}
		}
		else
		{
			if(dq2 < ZERO)
			{
				dflag = -ONE;

				dh11  = ZERO;
				dh12  = ZERO;
				dh21  = ZERO;
				dh22  = ZERO;

				*dd1  = ZERO;
				*dd2  = ZERO;
				*dx1  = ZERO;
			}
			else
			{
				dflag = ONE;
                //dh21  = -ONE;
                //dh12  =  ONE;
				dh11  =  dp1 /  dp2;
				dh22  = *dx1 /  dy1;
				du    =  ONE + dh11 * dh22;
				dtemp = *dd2 / du;

				*dd2  = *dd1 / du;
				*dd1  = dtemp;
				*dx1  = dy1 * du;
			}
		}


		if(*dd1 != ZERO)
		{
			if( (*dd1 <= RGAMSQ) || (*dd1 >= GAMSQ) )
			{
			    if(dflag==0.0){
			        dh11  =  ONE;
                    dh22  =  ONE;
                    dflag = -1.0;
			    }else{
			        dflag = -1.0;
                    dh21  = -ONE;
                    dh12  =  ONE;
			    }
				if( *dd1 <= RGAMSQ )
				{
					while (ABS(*dd1) <= RGAMSQ) {
						*dd1  = *dd1 * (GAM * GAM);
						*dx1  = *dx1 / GAM;
						dh11  = dh11 / GAM;
						dh12  = dh12 / GAM;
					}
				}
				else
				{
					while (ABS(*dd1) >= GAMSQ) {
						*dd1  = *dd1 / (GAM * GAM);
						*dx1  = *dx1 * GAM;
						dh11  = dh11 * GAM;
						dh12  = dh12 * GAM;
					}
				}
			}
		}

		if(*dd2 != ZERO)
		{
			if( (ABS(*dd2) <= RGAMSQ) || (ABS(*dd2) >= GAMSQ) )
			{
				dflag = -1.0;
				if( ABS(*dd2) <= RGAMSQ )
				{
					while (ABS(*dd2) <= RGAMSQ) {
						*dd2  = *dd2 * (GAM * GAM);
						dh21  = dh21 / GAM;
						dh22  = dh22 / GAM;
					}
				}
				else
				{
					while (ABS(*dd2) >= GAMSQ) {
						*dd2  = *dd2 / (GAM * GAM);
						dh21  = dh21 * GAM;
						dh22  = dh22 * GAM;
					}
				}
			}
		}

	}

	if(dflag < ZERO)
	{
		dparam[1] = dh11;
		dparam[2] = dh21;
		dparam[3] = dh12;
		dparam[4] = dh22;
	}
	else
	{
		if(dflag == ZERO)
		{
			dparam[2] = dh21;
			dparam[3] = dh12;
		}
		else
		{
			dparam[1] = dh11;
			dparam[4] = dh22;
		}
	}


	dparam[0] = dflag;
	return;
}
void test(FLOAT *dd1, FLOAT *dd2, FLOAT *dx1, FLOAT dy1, FLOAT *dparam){
	FLOAT du, dp1, dp2, dq2, dq1, dh11=ZERO, dh21=ZERO, dh12=ZERO, dh22=ZERO, dflag=-ONE, dtemp;

	if (*dd2 == ZERO || dy1 == ZERO)
	{
		dflag = -TWO;
		dparam[0] = dflag;
		return;
	}

	if(*dd1 < ZERO)
	{
		dflag = -ONE;
		dh11  = ZERO;
		dh12  = ZERO;
		dh21  = ZERO;
		dh22  = ZERO;

		*dd1  = ZERO;
		*dd2  = ZERO;
		*dx1  = ZERO;
	}
	else if ((*dd1 == ZERO || *dx1 == ZERO) && *dd2 > ZERO)
	{
		dflag = ONE;
		dh12 = 1;
		dh21 = -1;
		*dx1 = dy1;
		dtemp = *dd1;
		*dd1 = *dd2;
		*dd2 = dtemp;
	}
	else
	{
		dp2 = *dd2 * dy1;
		if(dp2 == ZERO)
		{
			dflag = -TWO;
			dparam[0] = dflag;
			return;
		}
		dp1 = *dd1 * *dx1;
		dq2 =  dp2 * dy1;
		dq1 =  dp1 * *dx1;
		if(ABS(dq1) > ABS(dq2))
		{
			dflag = ZERO;
			dh11  =  ONE;
			dh22  =  ONE;
			dh21 = -  dy1 / *dx1;
			dh12 =    dp2 /  dp1;

			du   = ONE - dh12 * dh21;
			if(du > ZERO)
			{
				dflag = ZERO;
				*dd1  = *dd1 / du;
				*dd2  = *dd2 / du;
				*dx1  = *dx1 * du;
			} else {
				dflag = -ONE;

				dh11  = ZERO;
				dh12  = ZERO;
				dh21  = ZERO;
				dh22  = ZERO;

				*dd1  = ZERO;
				*dd2  = ZERO;
				*dx1  = ZERO;
			}

		}
		else
		{
			if(dq2 < ZERO)
			{
				dflag = -ONE;

				dh11  = ZERO;
				dh12  = ZERO;
				dh21  = ZERO;
				dh22  = ZERO;

				*dd1  = ZERO;
				*dd2  = ZERO;
				*dx1  = ZERO;
			}
			else
			{
				dflag =  ONE;
				dh21  = -ONE;
				dh12  =  ONE;

				dh11  =  dp1 /  dp2;
				dh22  = *dx1 /  dy1;
				du    =  ONE + dh11 * dh22;
				dtemp = *dd2 / du;

				*dd2  = *dd1 / du;
				*dd1  = dtemp;
				*dx1  = dy1 * du;
			}
		}


		while ( *dd1 <= RGAMSQ && *dd1 != ZERO)
		{
			dflag = -ONE;
			*dd1  = *dd1 * (GAM * GAM);
			*dx1  = *dx1 / GAM;
			dh11  = dh11 / GAM;
			dh12  = dh12 / GAM;
		}
		while (ABS(*dd1) > GAMSQ) {
			dflag = -ONE;
			*dd1  = *dd1 / (GAM * GAM);
			*dx1  = *dx1 * GAM;
			dh11  = dh11 * GAM;
			dh12  = dh12 * GAM;
		}

		while (ABS(*dd2) <= RGAMSQ && *dd2 != ZERO) {
			dflag = -ONE;
			*dd2  = *dd2 * (GAM * GAM);
			dh21  = dh21 / GAM;
			dh22  = dh22 / GAM;
		}
		while (ABS(*dd2) > GAMSQ) {
			dflag = -ONE;
			*dd2  = *dd2 / (GAM * GAM);
			dh21  = dh21 * GAM;
			dh22  = dh22 * GAM;
		}

	}

	if(dflag < ZERO)
	{
		dparam[1] = dh11;
		dparam[2] = dh21;
		dparam[3] = dh12;
		dparam[4] = dh22;
	}
	else
	{
		if(dflag == ZERO)
		{
			dparam[2] = dh21;
			dparam[3] = dh12;
		}
		else
		{
			dparam[1] = dh11;
			dparam[4] = dh22;
		}
	}


	dparam[0] = dflag;
	return;
}
#include<stdio.h>
int main(){
    float paramm[9]={1600000000,800000000,8.0,7.0,0.0,0.0,0.0,0.0,0.0};
    float param[9]={5.9e-8,5.960464e-8,1,150,0,0,0,0,0};
    test(&param[0],&param[1],&param[2],param[3],&param[4]);
    for(int i=0;i<9;i++){
        printf("%.6f,",param[i]);
    }
    printf("\n");
    return 0;
}

