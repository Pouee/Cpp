#include "iostream"
#include "type_traits"
#include "string"
template<typename T>	
inline
typename std::remove_reference<T>::type&& move(T&& t) {
	// ��һ����ֵstatic_cast��һ����ֵ�����������(C++11)
	// ��Ȼ������ʽ�ؽ�һ����ֵת��Ϊ��ֵ����,��������static_cast��ʽ����ת��

	return static_cast<typename std::remove_reference<T>::type&&>(t);
}
int main()
{
	decltype(move(1)) i = move(1);
	
	return 0; 
}