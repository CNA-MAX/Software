#include <Function.h>
#include <FA.h>
/***************************************************
 * name         :_upData_y
 * function     :更新光强
 * parameter    :
 *                  NumCount        更新个体数量
 *                  *fun_x          更新x地址
 *                  *fun_y          更新y地址
 * return       : null
 * **************************************************/
double _upData_y(int NumCount,double* fun_x, double* fun_y)
{

    for (int i = 0; i < NumCount; i++)
    {
        *(fun_y + i) = 2.0 * cos(*(fun_x + i)) + 3.0 * sin(*(fun_x + i));             
    }
    return 0;
}

/***************************************************
 * name         :Function
 * function     :产生随机数
 * parameter    :
 *                  NumCount        生成随机数数量
 *                  _RangeMax       随机数上限
 *                  _RangeMin       随机数下限
 *                  *fun_x          生成随机数x
 *                  *fun_y          生成随机数y
 * return       : null
 * **************************************************/
double Function(int NumCount,double _RangeMin, double _RangeMax, double *fun_x,double *fun_y)
{
    srand((unsigned int)time(NULL));                                                        //随机数种子
    for (int i = 0; i < NumCount; i++)
    {
        *(fun_x + i) = _RangeMin + ((double)rand() / RAND_MAX) * (_RangeMax - _RangeMin);   //给定范围内产生随机数
        *(fun_y + i) = 2.0 * cos(*(fun_x + i)) + 3.0 * sin(*(fun_x + i));                   //给定函数
        printf("\tAdd_x = %f  Add_y = %f\n", *(fun_x + i), *(fun_y + i));

    }
 
    return 0;
}
/***************************************************
 * name         :_Max
 * function     :求最大值
 * parameter    :
 *                  Num1
 *                  Num2
 * return       : Max value
 * **************************************************/
double _Max(double Num1, double Num2)
{
    if (Num1 > Num2)
    {   
        return Num1;
    }
    return Num2;
}
