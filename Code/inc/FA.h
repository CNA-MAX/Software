/**************include*******************/
#include <Function.h>

/***************function*****************/
double _findMax(double* fun_y, int n);
double _move(double fun_xj, double fun_xi, double gama, double beta, double alpha, int _model);
double FA(int MaxGeneration, int nCount, double* _para, double* fun_x, double* fun_y);