#include "iostream"
#include "tuple"
#include "string"
using namespace std;
template<typename T>
int compare(const T&, const T&) {
	return 0; 
}
void func(int(*)(const int&,const int&)) {}
void func(int(*)(const string&, const string&)) {}
// ��������һ������ģ��ʵ���ĵ�ַʱ,
// ����������ı�������:��ÿ��ģ�������Ψһȷ�������ͻ�ֵ
int main()
{
	// ��������һ������ģ���ʼ��һ������ָ���Ϊһ������
	// ָ�븳ֵʱ,����������ָ����������ƶ�ģ��ʵ��
	int(*pf)(const int&, const int&) = compare;
	// �޷�ȷ�� ������ʾָ������
	func(compare<int>);
	return 0; 
}