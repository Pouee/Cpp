#include "iostream"
#include "numeric"
#include "vector"
#include "algorithm"
#include "tuple"
// ����һ��������,���˻�ȡ���С֮��,�����ܶ�������Ψһ���������
// ��չ(expand)��.����չһ����ʱ,���ǻ�Ҫ�ṩ����ÿ����չԪ�ص�ģ
// ʽ(pattern).��չһ�������ǽ����ֽ�Ϊ���ɵ�Ԫ��,��ÿ��Ԫ��Ӧ��ģ
// ʽ,�����չ����б�.
using namespace std;

template<typename T,typename...Args>
// Args ��չArgs,��������Args&Ӧ�õ�Args��ÿ��Ԫ��
int f(T& t,Args&... args)
{	
	// Args expand
	tuple<T,Args...> tup;
	// args expand and Args expand
	// { f<Args[0]>(args[0]),f<Args[1]>(args[1]),... };
	initializer_list<T> tmp = { f<Args>(args)... };
	// args expand
	initializer_list<T> v = { t++, args++...};
	for_each(v.begin(), v.end(), [](const T& a) {cout << a << endl; });
	return 0;
}

int main()
{
	int i, j, k; 
	i = 1;
	j = 2;
	k = 3;
	f(i, j, k);
	cout << "i:" << i << "j:" << j << "k:" << k << endl;
	system("pause");
	return 0; 
}