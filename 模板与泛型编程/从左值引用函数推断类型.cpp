#include "iostream"
// ���к�������p��һ��ģ�����Ͳ���T������,�ǳ���Ҫ���Ǽ�ס����:
// ��������Ӧ�����������ð󶨹���;const�ǵײ��,���Ƕ����
template<typename T>
void f(T &p) {}
template<typename T>
// ʵ�α�������ֵ
void f1(T&) {}
template <typename T>
void f2(const T&) {}
int main()
{
	// ��һ������������ģ�����Ͳ�����һ����ͨ(��ֵ)����ʱ(��,����T&),�󶨹���
	// ��������,ֻ�ܴ��ݸ���һ����ֵ(��,һ��������һ�������������͵ı��ʽ),ʵ��
	// ������const����,Ҳ���Բ���.���ʵ����const��,��T�����ƶ�Ϊconst����
	int i = 0; 
	const int ci = 0;
	const int *p = nullptr; 
	const int *const q = nullptr;
	f1(i);	// �ɹ� i����ֵ T���ƶ�Ϊint
	f1(ci);	// �ɹ� ci����ֵ	T���ƶ�Ϊconst int
	f1(p);	// �ɹ� p����ֵ T���ƶ�Ϊconst int *&
	f1(q);	// �ɹ� q����ֵ T���ƶ�Ϊconst int * const&
	//f1(4);	// ���� ���ݸ�һ��&������ʵ�α�����һ����ֵ

	// ���һ�������Ĳ���������const T&,�����İ󶨹���������ǿ��Դ��ݸ����κ�
	// ���͵�ʵ��:һ������(const ��� const)��һ����ʱ�������һ������ֵ����.
	f2(i);	// �ɹ� T���ƶ�Ϊint
	f2(ci);	// �ɹ� T���ƶ�Ϊint
	f2(5);	// �ɹ� һ��const &�������԰󶨵�һ����ֵ T���ƶ�Ϊint
	return 0;
}