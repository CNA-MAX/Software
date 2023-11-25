#include <FA.h>
#include <Function.h>

int main()
{
    int n;      //��Ⱥ������Ŀ
    int MaxGeneration = 0;//��������
    double* x, * y, p[5];
    double _RangeMin, _RangeMax;
  
    printf("\t\t\tө����㷨\n");
    printf("\tEnter a number to n(limits is 0 - 50):\n");
    scanf_s("%d", &n);
    x = malloc(100*sizeof(double));
    y = malloc(100 * sizeof(double));
    _RangeMin = -5.0;
    _RangeMax = 10000;
    Function(n, _RangeMin, _RangeMax, x, y);        //�������ã����������
    

    p[0] = 0.01;  // ��ǿ����ϵ��
    p[1] = 1.0;   // ���������ͨ��Ϊ0
    p[2] = 0.1;// ���� - [0, 1]
    
    MaxGeneration = 1000000;

    p[3] = _findMax(y,n); // ��ʼ��Ⱥ������ǿ
    p[4] = 0;

    FA(MaxGeneration, n, p, x, y);

    printf("\n\n\tȫ������ֵ = %f\n", p[3]);

    system("pause");
    return 0;
}