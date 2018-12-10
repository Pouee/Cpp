#include "iostream"
void f(const int &a) {  }
void g(int a) {}
void u(int &&a) { std::cout << typeid(a).name() << std::endl; }

template<typename T>
T&& forwardArg(T&& t) {
	return static_cast<T&&>(t);
}
template<typename T>
T&& forwardArg(T& t) {
	return static_cast<T&&>(t);
}

template<typename F,typename T>
void indictectCall(F f,T&& t) {
	// ������������贫�����ͱ���������������(������const)

	// ��� f(forwardArg(t)); 
	// ���t���������������Ļ��ڴ˺��������򽫻�����ֵ
	// ����,forward����������ʾָ��ģ��ʵ�������� ���򶼽�Ϊ��ֵ
	
	// ��� f(forwardArg<T>(t));
	// ��ʱ��������� 
	//		1)t��������������� indictectCall(f,100)
	//			�����������,T�����ƶ�Ϊint����,��t����ȴ��һ����ֵ
	//			����T�Ѿ����޶�Ϊint,�����޷���������"�۵�",����������
	//			�������:����һ����ֵ�汾
	//		2)t�����ͱ������� indictectCall(f,i)
	//			�����������,T�����ƶ�Ϊint&,��ʱt��һ����ֵ�������ض�����
	//			����,���ȵ���T&������(& &�۵�Ϊ&)

	// ��ʱ�����Ѿ���������ת������������,��������û��ʲô����
	//forwardArg<int>(100);
	f(forwardArg<T>(t));	
	std::cout << t << std::endl;
}

int main()
{
	
	int i = 10;
	std::forward<int&>(100);
	forwardArg<int>(1000);
	//indictectCall(f, i);
	indictectCall(u, 100);
	//indictectCall(g, i);
	std::cout << i << std::endl;
	system("pause");
	return 0; 
}