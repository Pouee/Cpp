#include "iostream"
#include "string"
// ����ģ����Ա���һ��ģ���һ����ͨ��ģ�庯������.
// ������һ��,������ͬ�ĺ���������в�ͬ���������͵Ĳ���
// ����һ������,���ѡ������������ģ��ʵ���ƶϳɹ��ĺ���ģ��ʵ��
// ��ѡ�ĺ���ģ�����ǿ��е�,��Ϊģ��ʵ���ƶϻ��ų��κβ����е�ģ��
// ������һ��,���ǡ��һ�������ṩ���κ��������������õ�ƥ��,��ѡ��˺���
// ����,����ж�������ṩ��ͬ���õ�ƥ��,��:
// -- ���ͬ���õĺ�����ֻ��һ���Ƿ�ģ�庯��,��ѡ��˺���
// -- ���ͬ���õĺ�����û�з�ģ�庯��,���ж������ģ��,������һ��ģ���
//	  ����ģ���������,��ѡ���ģ��
// -- ����,�˵���������
using namespace std;
template<typename T>
int f(T val) { cout << "TEMPLATE" << endl; return 0; }
void f(int val) { cout << "NONE-TEMPLATE" << endl; }
template <typename T>
void debug_rep(const T& t) 
{
	cout << "debug_rep(const T&)" << endl; 
}
template <typename T>
void debug_rep(T *t)
{
	cout << "debug_rep(T*)" << endl;
}
int main()
{
	int m = 10; 
	f(m);
	const int ci = 10;
	// ���ж������ģ���һ�������ṩͬ���õ�ƥ����,Ӧѡ�����������İ汾
	debug_rep(3);
	debug_rep(ci);
	debug_rep(&m);
	system("pause");
	return 0; 
}