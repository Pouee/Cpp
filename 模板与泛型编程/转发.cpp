#include "iostream"
#include "type_traits"

// ĳЩ������Ҫ����һ������ʵ����ͬ���Ͳ����ת������������.�ڴ������,
// ������Ҫ���ֱ�ת��ʵ�ε���������,����ʵ�������Ƿ���const���Լ�ʵ������
// ֵ������ֵ

template<typename T>
auto forwardArg(int && arg) {
	return static_cast<int&&>(arg);
}

// ����һ���ɵ��ö������������������ģ��
// flip1��һ����������ʵ��:����const�����ö�ʧ��
template <typename F,typename T1,typename T2>
void flip1(F f, T1&& t1, T2&& t2) 
{ 
	//static_cast<int&&>(t1);
	forwardArg<int>(t1);
	//f(forwardArg<T1>(t1), forwardArg<T2>(t2));
	//f(std::forward<T1>(t1), std::forward<T2>(t2));
}

void f(int v1, int &v2) {
	std::cout << v1 << " " << ++v2 << std::endl;
}
void g(int v1, int v2) {
	std::cout << v1 << " " << ++v2 << std::endl;
}
int main()
{

	int i = 100, j = 200;
	flip1(g, 200, 100);
	//g(100, 200);
	std::cout << i << " " << j << std::endl;
	system("pause");
	return 0;
}