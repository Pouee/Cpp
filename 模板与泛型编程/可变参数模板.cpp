#include "iostream"
#include "stdexcept"
using namespace std;
// һ���ɱ����ģ��(variadic template)���ǿ��Խ��ܿɱ���Ŀ������
// ģ�庯����ģ����.�ɱ���Ŀ�Ĳ�������Ϊ������(parameter packet)
// �������ֲ�����:ģ�������(template parameter packet),��ʾ���
// ����ģ�����;����������(function parameter packet),��ʾ���
// ������������

// Args��һ��ģ�������;rest��һ������������
// Args��ʾ�������ģ�����Ͳ���
// rest��ʾ���������������
template <typename T,typename ...Args>
void foo(const T& t, const Args...rest) 
{
	// ��������Ҫ֪�������ж���Ԫ��ʱ,��ʹ��sizeof...�����
	// ����sizeof��sizeof...Ҳ����һ���������ʽ,���Ҳ����
	// ��ʵ����ֵ
	cout << sizeof...(Args) << endl;
	cout << sizeof...(rest) << endl;
}
// ��ֹ�ݹ麯��
int variadic_print(const char *format);
// ���ǿ���ʹ��һ��initializer_list������һ�����Խ��ܿɱ���Ŀʵ�εĺ���
// ����,����ʵ�α��������ͬ������(�����ǵ����Ϳ���ת��Ϊͬһ����������).
// �����ǼȲ�֪����Ҫ�����ʵ�ε���ĿҲ��֪�����ǵ�����ʱ,�ɱ����������
// �����õ�
template <typename T,typename...Args>
int variadic_print(const char *format,T t,Args...args)
{
	while (*format)
	{
		if (*format == '%' && *(++format) != '%')
		{
			std::cout << t;
			// recursively call
			return 1 + variadic_print(++format,args...);
		}
		std::cout << *format++;
	}
	throw std::logic_error("too many arguments");
}
int variadic_print(const char *format) 
{
	while (*format)
	{
		if (*format == '%' && *(++format) != '%')
		{
			throw std::runtime_error("invalid format string:missing arguments");
		}
		std::cout << *format++;
	}
	return 0; 
}
// �������һ������ �˰汾����������,��˱�����ѡ��˰汾
template<typename T>
void print(T t) 
{
	cout << t << endl;
}
template<typename T,typename...Args>
void print(T t, Args...args) 
{
	cout << t << endl;
	print(args...);
}
int main()
{
	int ret = variadic_print("just like dreaming:( %d , %d , %s )", 1, 222, "hello");
	cout << endl; 
	cout << "count:" << ret << endl;
	print(1, 2, 3, 4, 5, 6);
	system("pause");
	return 0; 
}