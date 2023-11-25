#include <FA.h>
#include <Function.h>

int main()
{
    int n;      //种群个体数目
    int MaxGeneration = 0;//迭代次数
    double* x, * y, p[5];
    double _RangeMin, _RangeMax;
  
    printf("\t\t\t萤火虫算法\n");
    printf("\tEnter a number to n(limits is 0 - 50):\n");
    scanf_s("%d", &n);
    x = malloc(100*sizeof(double));
    y = malloc(100 * sizeof(double));
    _RangeMin = -5.0;
    _RangeMax = 10000;
    Function(n, _RangeMin, _RangeMax, x, y);        //函数调用，生成随机点
    

    p[0] = 0.01;  // 光强吸收系数
    p[1] = 1.0;   // 最大吸引度通常为0
    p[2] = 0.1;// 步长 - [0, 1]
    
    MaxGeneration = 1000000;

    p[3] = _findMax(y,n); // 初始种群的最大光强
    p[4] = 0;

    FA(MaxGeneration, n, p, x, y);

    printf("\n\n\t全局最优值 = %f\n", p[3]);

    system("pause");
    return 0;
}