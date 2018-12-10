#include "iostream"
#include "vector"
#include "algorithm"
#include "functional"
template<typename T>
void g(T&& val) {}
template<typename T>
void f(T val) {}
template<typename T>
void u(const T& val) {}

template<typename T>
void v(T&& val) {}
template<typename T>
void v(T val) {}
template<typename T>
void v(const T& val) {}

template<typename T>
void w(T &&val) { std::vector<T> v; }
int main()
{
	int i = 0; 
	const int ci = i;
	g(i);		// T���ƶ�Ϊ int&
	g(ci);		// T���ƶ�Ϊ const int&
	g(i*ci);	// ��ֵ T���ƶ�Ϊint
	g( i = ci );// T���ƶ�Ϊ int&
	f(i);		// T���ƶ�Ϊ int
	f(ci);		// T���ƶ�Ϊ int
	u(i);		// T���ƶ�Ϊ int
	u(ci);		// T���ƶ�Ϊ int
	u(100);		// T���ƶ�Ϊ int
	//v(ci);		// ambiguous
	//v(100);		// ambiguous

	// ERROR
	//std::vector<int&> v;
	//v.push_back(i);
	// ERROR
	//w(i); 
	return 0;
}