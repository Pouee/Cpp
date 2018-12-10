#include "iostream"
#include "thread"
#include "type_traits"
// �±�׼��,���ǿ������ʹ�ÿɱ����ģ����forward��������д����,
// ʵ�ֽ���ʵ�β���ش��ݸ���������
using namespace std;
template<typename F,typename...Types>
auto f(F fn,Types&&...args) 
	-> decltype(fn(std::forward<Types>(args)...))
{
	// ������ֵ���ú��� Ӧ�ñ���ʹ��Types��������Ϣ(��һ��)
	// cout << "void f(Types&&...args)" << endl;
	// perfect forwarding
	return fn(std::forward<Types>(args)...);
}
// �ɱ��������ͨ�������ǵĲ���ת������������.
// fun�������������,ÿ����������һ��ģ��������͵���ֵ����
template<typename... Args>
// ��Args��չΪһ����ֵ���õ��б�
void fun(Args&&... args)
{
	// f ��ʵ�μ���չArgs����չargs
	f(std::forward<Args>(args)...);
}
// 
int main()
{
	int i, j, k, m, n;
	j = 1;
	k = 2;
	m = 3;
	n = 5;
	auto fnc = [](int &a, int &b, int &c, int &d)-> int {
		a++; b++; c++; d++;
		return a + b + c + d;
	};
	cout << f( fnc, j, k, m, n) << endl;
	cout << j << k << m << n << endl;
	f(printf, "Hello World! %d\n", 1);
	f(scanf_s, "%d", &i);
	system("pause");
	return 0;
}