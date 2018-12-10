#include "iostream"
#include "vector"
#include "xstddef"
using namespace std;

namespace Test1 {
	// �ٶ�T��һ�����Ͳ���������,��������������ʽ�����ʱ:
	// T::size_type *p ;
	// ����Ҫ֪�����������ڶ���һ����Ϊp�ı������ǽ�һ����
	// Ϊsize_type��static�������ݳ�Ա����Ϊp�ı������
	// Ĭ�������,C++���Լٶ�ͨ����������������ʵ����ֲ�������.
	// ���,�������ϣ��ʹ��һ��ģ�����Ͳ��������ͳ�Ա,�ͱ�����
	// ʾ���߱������������Ǹ�����,����ͨ��ʹ�ùؼ���typename��ʵ����һ��(����ʹ��class)
	template<typename T>
	class Blob {
		using size_type = typename std::vector<T>::size_type;
		typename T::size_type * p;
	};

	// ����������Ϊ���������ṩĬ��ʵ��һ��,����Ҳ�����ṩĬ��ģ��ʵ��
	// (default template argument).���±�׼��,���ǿ���Ϊ��������ģ��
	// �ṩĬ��ʵ��.�������C++��׼ֻ����Ϊ��ģ���ṩĬ��ʵ��
	// �뺯��Ĭ��ʵ��һ��,����һ��ģ�����,ֻ�е����Ҳ�����в�������Ĭ��
	// ʵ��ʱ,���ſ�����Ĭ��ʵ��
	template <typename T, typename F = less<T>>
	int compare(const T& v1, const T &v2, F f = F())
	{
		if (f(v1, v2)) return -1; 
		if (f(v2, v1)) return 1;
		return 0 ; 
	}
	
	// ģ��Ĭ��ʵ������ģ��
	// ���ۺ�ʱʹ��һ����ģ��,���Ƕ�������ģ����֮����ϼ�����.
	// ������ָ��������һ��ģ��ʵ��������.�ر��,���һ����ģ��
	// Ϊ������ģ��������ṩ��Ĭ��ʵ��,������ϣ��ʹ����ЩĬ��ʵ��
	// �ͱ�����ģ��֮���һ���ռ����Ŷ�:
	template <class T = int > class Numbers {
		
	};
	
}
int main()
{
	int i = Test1::compare(0, 42);
	int j = Test1::compare<int,greater<int>>(0, 42);
	cout << i << endl ;
	cout << j << endl ;
	Test1::Numbers<> n1;
	Test1::Numbers<long> n2;
	system("pause");
	return 0;
}