#include "iostream"
#include "memory"
#include "vector"
using namespace std;
// һ����(��������ͨ�໹����ģ��)���԰���������ģ��ĳ�Ա����.
// ���ֳ�Ա����Ϊ��Աģ��(member template).��Աģ�岻�����麯��
template<typename TYPE>
class DebugDelete {
public:
	explicit DebugDelete(ostream &os = cerr) :os(os) {}
	template<typename T> 
	void operator()(T *p);
private:
	ostream& os; 
};
// ����ģ�����ͨ������Ա��ͬ,��Աģ���Ǻ���ģ��.����������ģ���ⶨ��һ����Ա
// ģ��ʱ,����ͬʱΪ��ģ��ͳ�Աģ���ṩģ������б�.��ģ��Ĳ����б���ǰ,���
// ��Ա�Լ��Ĳ����б�
template<typename M>
template<typename T>
void DebugDelete<M>::operator() < T > (T *p) {
	os << "delete ..." << typeid(T).name() << endl;
	delete p;
}
template<typename It>
void foreach(It b, It e) {
	for (; b != e; ++b) {
		cout << *b << endl;
	}
}
#define macro_foreach(begin,end)	\
		{	auto b = begin, e = end ;\
			for (; (b) != (e); ++(b)) { \
				cout << *(b) << endl; \
			}\
		}


int main()
{

	double *p1 = new double;
	int *p2 = new int;
	DebugDelete<int> d;
	d(p1);
	DebugDelete<int>()(p2);
	unique_ptr<int, DebugDelete<int>> p(new int, DebugDelete<int>());
	int arr[10] = { 12,22,3,4,5,6,1,2,4,5 };
	
	macro_foreach(begin(arr), end(arr));
	foreach(begin(arr), end(arr));
	system("pause");
	return 0 ; 
}