#include "iostream"
#include "algorithm"
#include "numeric"
#include "type_traits"
using namespace std;
// ���ǲ�֪�����ؽ����׼ȷ����,��֪����������������������е�Ԫ������
// β�÷������������ڲ����б�֮�������������� �����÷��ص���һ����ֵ
template <typename It>
auto fcn(It beg, It end) -> 
		// Ϊ��ʹ��ģ�������Ա ����ʹ��typename 
		typename remove_reference<decltype(*beg)>::type{
	return *beg;
}
int main()
{
	// fcn((int*)0, (int*)0); returnType int ;
	return 0;
}