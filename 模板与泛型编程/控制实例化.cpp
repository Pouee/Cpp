#include "iostream"
#include "string"
using namespace std;
// �ڴ�ϵͳ��,�ڶ���ļ���ʵ������ͬģ��Ķ��⿪�����ܷǳ�����,
// ���±�׼��,���ǿ���ͨ����ʾʵ����(explicit instantiation)
// ���������ֿ���.
// һ����ʾʵ������������ʽ:
// extren template declaration ;
// template declaration ;
// declaration ��һ�����������,��������ģ������ѱ��滻Ϊģ�����

template<typename T>
class Blob {
public:
	void f();
};
template<typename T>
T compare(const T&,const T&) {return 0; }

// ������������externģ������ʱ,�������ٱ��ļ�������ʵ��������
// ��һ������Ϊextern�ͱ�ʾ��ŵ�ڳ�������λ���и�ʵ������һ����
// extern����(����).����һ������ʵ�����İ汾,�����ж��extern��
// ����,������ֻ��һ������
// ���ڱ�������ʹ��һ��ģ��ʱ�Զ�����ʵ����,���extern���������
// �����κ�ʹ�ô�ʵ�����汾�Ĵ���֮ǰ
// ��ÿ��ʵ��������,�ڳ�����ĳ��λ�ñ���������ʽ��ʵ��������
// note:ʵ���������ʵ�������г�Ա,��һ����ģ���ʵ����������
// ���ͱ���������ģ������г�Ա����(������C++11��)
//extern template class Blob<string>;				// ���� 
template class Blob<string>;
template int compare(const int&, const int&);	// ����
//extern template int compare(const int&, const int&);
int main()
{
	compare(1, 2);
	// VS2017 �ܹ��������� G++����
	 Blob<string> b;
	// b.f();
	return 0; 
}
