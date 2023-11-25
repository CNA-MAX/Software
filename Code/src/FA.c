#include <FA.h>
/***************************************************
 * name         :_findMax
 * function     :���������ֵ
 * parameter    :
 *					fun_y			y����
 *                  n				y����
 * return       :	ArrMax			�������ֵ
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
 * function     :�����ȸߵĸ����ƶ�
 * parameter    :
 *					gama			��ǿ����ϵ��
 *                  beta			������ն�			
 *                  alpha			������ȡֵ 0~1
 *                  fun_x			�����x
 *					model			ģʽ��0 | 1 | 2 | 3
 * return       :	fun_x			�ƶ����xֵ
 * **************************************************/
double _move(double fun_xj, double fun_xi, double gama, double beta, double alpha, int _model)
{
	double _para,i;
	i = 0 + ((double)rand() / RAND_MAX) * (1 - 0);				//����0 ~ 1֮�������
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
 * function     :FA�㷨
 * parameter    :
 *                  MaxGeneration   ��������
 *                  nCount			��Ⱥ��������
 *                  _para @			0����ǿ����ϵ��
 *									1��������ն�
 *									2��������ȡֵ 0~1
 *									3�����Ÿ���ֵ
 *									4��ȫ������ֵ
 *                  *fun_x          �����x
 *                  *fun_y          �����x����Ӧyֵ
 * return       : null
 * **************************************************/
double FA(int MaxGeneration,int nCount, double* _para,double* fun_x, double* fun_y)
{
	int	i, j;
	int _Generation = 1;	//��������
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
						*(fun_x + i) = _move(*(fun_y + j), *(fun_y + i), *_para ,*(_para + 1), *(_para + 2),0);		//�����ȴ�ĵ��ƶ�
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
			//����������������ƶ�
			if ( *(fun_y + i) == _findMax(fun_y, nCount) )
			{
				*(fun_x + i) = _move(*(fun_y + j), *(fun_y + i), *_para, *(_para + 1), *(_para + 2),3);
			}

		}
			//���¹�ǿ
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