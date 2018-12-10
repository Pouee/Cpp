#include "iostream"
struct Test {
	Test() 
	{ 
		std::cout << " Test()" << std::endl;
	}
	Test(const Test&) 
	{
		std::cout << "Test(const Test&)" << std::endl;
	}
	Test(const Test&&)
	{
		std::cout << "Test(const Test&&)" << std::endl;
	}
	Test(int)
	{
		std::cout << "Test(int)" << std::endl;
	}
	void operator=(const Test&)
	{
		std::cout << "operator=(const Test&)" << std::endl;
	}
	void operator=(const Test&&)
	{
		std::cout << "operator=(const Test&&)" << std::endl;
	}
	~Test()
	{
		std::cout << "~Test()" << std::endl;
	}
};
template<typename T>
struct G {
	void f(const T&) 
	{
		std::cout << "const T&" << std::endl;
	}
	void f(T&& ) 
	{
		std::cout << "T&&" << std::endl;
	}
};
// ģ����������ƶ�Ϊһ����������,��һ���Զ�ģ���ڵĴ�����������˾��ȵ�Ӱ��
// �����Ƕ�һ����ֵ����f3ʱ,�������泣��42,TΪint.�ڴ������,�ֲ�����t������
// Ϊint,��ͨ����������val��ֵ����ʼ��.�����Ƕ�t��ֵʱ,����val���ֲ���.
// ��һ����,�����Ƕ�һ����ֵi����f3ʱ,��TΪint&.�����Ƕ��岢��ʼ���ֲ�����tʱ
// ����������int&.��˶�t�ĳ�ʼ�����󶨵�val,�����Ƕ�t��ֵʱ,Ҳͬʱ�ı���val��
// ֵ
template<typename T>
void f3(T&& val) 
{
	T t = val;	// �������ǰ�һ������
	t = 200;	// ��ֵֻ�ı�t���Ǽȸı�t�ָı�val
}
// ���������漰�����Ϳ�������ͨ(������)����,Ҳ��������������ʱ,��д��ȷ�Ĵ����
// ����쳣����.����ʹ�����·�ʽ����
template<typename T>
void f3(const T & val) 
{
	std::cout << "PP" << std::endl;
	T t = val;	
	t = 200;	
}
void f4(const int &v) {
	std::cout << "const int &v" << std::endl;
}
void f4(int && v) {
	std::cout << "int &&v" << std::endl;
}

int main()
{
	
	int&& rri = 100;
	f3(rri);	//��i��Ч��һ��
	int i = 100;
	f3(i);
	//f4(i);
	// ��ģ�岻��������������
	G<int>().f(i);
	//std::cout << i << std::endl;
	system("pause");
	return 0; 
}