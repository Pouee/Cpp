#include "iostream"
using namespace std;
// ��д��һģ��,ʹ֮���κο��ܵ�ģ��ʵ�ζ�������ʵ�,�Ⲣ�������ܰ쵽
// ��ĳЩ�����,ͨ��ģ��Ķ�����ض������ǲ����ʵ�:ͨ�ö�����ܱ���ʧ
// �ܻ������ò���ȷ.����ʱ��,����Ҳ��������ĳЩ�ض�֪ʶ����д����Ч��
// ����,�����Ǵ�ͨ��ģ��ʵ����.�����ǲ���(��ϣ��)ʹ��ģ��汾ʱ,��
// �Զ��������ģ���һ���������汾
template<typename T>
int compare(const T& v1, const T& v2)
{
	if (v1 < v2) return -1;
	if (v2 < v1) return 1;
	return 0;
}
// ��compare��������ģ��������(template specialization)
// �����庯��ģ����������汾ʱ,���Ǳ����Ͻӹ��˱������Ĺ���.��,���Ƕ�ԭģ���
// һ������ʵ���ṩ�˶���.��Ҫ����ҪŪ��:һ���������汾��������һ��ʵ��,���Ǻ�
// ������һ�����ذ汾.
template<>
int compare(const char* const &v1, const char * const &v2)
{
	return strcmp(v1, v2);
}
// ������������ѡ�÷�ģ��汾
int compare(const char* const &v1, const char * const &v2)
{
	return strcmp(v1, v2);
}
// ����ֻ�ܲ���������(partial specialization)��ģ��,���ܲ�������������ģ��
template <class T>
struct remove_refer {
	typedef T type;
};
template <class T>
struct remove_refer<T&> {
	typedef T type;
};
template <class T>
struct remove_refer<T&&> {
	typedef T type;
};

template <typename T>
struct Foo {
	void f() { cout << "hi!" << endl; }
	int k;
};
template<>
void Foo<int>::f() {
	cout << "member specialization!" << endl;
}
template <>
struct Foo<double> {

};
int main()
{
	Foo<int> f; 
	f.f();
	Foo<double> d;

	system("pause");
	return 0;
}
