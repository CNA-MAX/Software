#include <FA.h>
/***************************************************
 * name         :_findMax
 * function     :求数组最大值
 * parameter    :
 *					fun_y			y序列
 *                  n				y数量
 * return       :	ArrMax			数组最大值
 * **************************************************/
double _findMax(double* fun_y, int n)
{
	double ArrMax;
	ArrMax = *(fun_y);
	if (1 == n)
	{
		return ArrMax;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			ArrMax = _Max(ArrMax, *(fun_y + i));
		}
	}
	return ArrMax;
}
/***************************************************
 * name         :_move
 * function     :向亮度高的个体移动
 * parameter    :
 *					gama			光强吸收系数
 *                  beta			最大吸收度			
 *                  alpha			步长，取值 0~1
 *                  fun_x			随机数x
 *					model			模式：0 | 1 | 2 | 3
 * return       :	fun_x			移动后的x值
 * **************************************************/
double _move(double fun_xj, double fun_xi, double gama, double beta, double alpha, int _model)
{
	double _para,i;
	i = 0 + ((double)rand() / RAND_MAX) * (1 - 0);				//生成0 ~ 1之间随机数
	if(0 == _model)
	{
		_para = fun_xi + beta * exp((-1) * gama * ((fun_xj - fun_xi) * (fun_xj - fun_xi)))* (fun_xj - fun_xi) - alpha * i;
	}
	if (1 == _model)
	{
		_para = fun_xi + beta * exp((-1) * gama * ((fun_xj - fun_xi) * (fun_xj - fun_xi)))* (fun_xj - fun_xi) + alpha * i;
	}
	if (2 == _model)
	{
		_para = fun_xi + beta * exp((-1) * gama * ((fun_xj - fun_xi) * (fun_xj - fun_xi)))* (fun_xj - fun_xi) + alpha * (-1 + (1 + 1)) * i;
	}
	if (3 == _model)
	{
		_para = fun_xi + alpha * (-1 + (1 + 1)) * i;
	}

	return _para;
}
/***************************************************
 * name         :FA
 * function     :FA算法
 * parameter    :
 *                  MaxGeneration   迭代次数
 *                  nCount			种群个体数量
 *                  _para @			0：光强吸收系数
 *									1：最大吸收度
 *									2：步长，取值 0~1
 *									3：最优个体值
 *									4：全局最优值
 *                  *fun_x          随机数x
 *                  *fun_y          随机数x，对应y值
 * return       : null
 * **************************************************/
double FA(int MaxGeneration,int nCount, double* _para,double* fun_x, double* fun_y)
{
	int	i, j;
	int _Generation = 1;	//迭代代数
	while (_Generation <= MaxGeneration)
	{
		//
		for (i = 0; i < nCount; i++)
		{
			for (j = 0; j < i; j++)
			{
				if ((*(fun_y + j)) > (*(fun_y + i)))
				{
					if (*(fun_x + i) > 5)
					{
						*(fun_x + i) = _move(*(fun_y + j), *(fun_y + i), *_para ,*(_para + 1), *(_para + 2),0);		//向亮度大的点移动
					}
					else if (*(fun_x + i) < -5)
					{
						*(fun_x + i) = _move(*(fun_y + j), *(fun_y + i), *_para, *(_para + 1), *(_para + 2), 1);
					}else
					{
						*(fun_x + i) = _move(*(fun_y + j), *(fun_y + i), *_para, *(_para + 1), *(_para + 2), 2);
					}
				}
			}
			//本身是最亮则随机移动
			if ( *(fun_y + i) == _findMax(fun_y, nCount) )
			{
				*(fun_x + i) = _move(*(fun_y + j), *(fun_y + i), *_para, *(_para + 1), *(_para + 2),3);
			}

		}
			//更新光强
		_upData_y(nCount, fun_x, fun_y);
		*(_para + 3) = _findMax(fun_y, nCount);
		if (*(_para + 3) > *(_para + 4))
		{
			*(_para + 4) = *(_para + 3);
		}
		_Generation++;
	}
	return 0;
}