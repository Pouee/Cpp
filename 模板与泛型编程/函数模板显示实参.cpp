#include "iostream"
#include "algorithm"
using namespace std;
template<typename T1,typename T2,typename T3>
T1 sum(T2 t2, T3 t3) { return t2 + t3; }
// ������� �û�����ָ����������ģ�����
template<typename T1, typename T2, typename T3>
T3 alternative_sum(T2 t2, T1 t1) { return t2 + t1; }
int main()
{
	// explicit template argument 
	double d = std::max<double>(1,2.3);
	cout << d << endl;
	sum<long>(1, 3);	// T1����ʽָ���� T2��T3�ǴӺ���ʵ�������ƶ϶�����
	alternative_sum<long,long,long>(1, 3);
	long lng = 100;
	//compare(lng, 1024);		// ����:ģ�������ƥ��
	//compare<long>(lng, 1024);	// ��ȷ:����compare(long,long)
	//compare<int>(lng, 1024);	// ��ȷ:����compare(int,int)
	system("pause");
	return 0;
}