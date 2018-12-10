#include "iostream"
#include "vector"
#include "initializer_list"
#include "stdexcept"
#include "memory"
#include "utility"
using namespace std;

namespace Test1 {
	// ģ�庯��
	// ģ�嶨���Թؼ���template��ʼ,���һ��ģ������б�(template parameter list)
	// ����һ�����ŷָ���һ������ģ�����(template parameter)���б�,��С�ں�(<)�ʹ��ں�(>)��Χ����
	// ģ�������ʾ��������������õ������ͻ�ֵ,��ʹ��ģ��ʱ,����(��ʽ�ػ���ʽ��)ָ��ģ��ʵ��(template argument),����󶨵�ģ�������
	// T��ģ�����Ͳ���(type parameter).һ����˵,���ǿ��Խ����Ͳ�����������˵����,�����������ͻ�����˵����һ��ʹ��
	// ���Ͳ���ǰ����ʹ�ùؼ���class��typename.��typename��ָ��ģ�����Ͳ�������class��Ϊֱ��
	template<typename T>
	int compare(const T& v1,const T& v2) 
	{
		// ��ʹ��С�ڽ����˶Դ������͵�Ҫ��
		if (v1 < v2) return -1;
		if (v2 < v1) return 1;
		return 0; 
	}
	
	// ��ģ�嶨����,ģ������б���Ϊ��
	// template<>	void fun() {}
	
	// ���˶������Ͳ���,��������ģ���ж�������Ͳ���(nontype parameter).
	// һ�������Ͳ�����ʾһ��ֵ����һ�����ͣ�����ͨ��һ���ض�������������
	// �ؼ���class��typename��ָ�������Ͳ���
	// �󶨵����������Ͳ�����ʵ�α�����һ���������ʽ
	// �󶨵�ָ������÷����Ͳ�����ʵ�α�����о�̬��������
	// ָ�����Ҳ������nullptr��һ��ֵΪ0�ĳ������ʽ����ʼ�� 
	template<typename T,size_t len>
	inline constexpr size_t length(const T(&arr)[len]) {
		return len; 
	}
	// ������������һ��ģ�嶨��ʱ,���������ɴ���.
	// ֻ�е�����ʵ������ģ���һ���ض��汾ʱ,�����������ɴ���
	// ģ���ͷ�ļ�ͨ���Ȱ�������Ҳ��������
	// ��������������ʵ�����ڼ䱨��
	// ��֤���ݸ�ģ���ʵ��֧��ģ����Ҫ��Ĳ���,�Լ���Щ������ģ��������ȷ�Ĺ���,�ǵ����ߵ�����
}
namespace Test2 {
	
	// ǰ������
	template<typename> class Blob;
	template<typename T>
	bool operator==(const Blob<T>& b1, const Blob<T>& b2) {
		//Blob<long> b; b.data;
		return false;
	}
	template<typename T>
	class Pal {
	public:	
		void f() {
			//Blob<char> c; c.data;
			//Blob<Pal> c1; c1.data;
		}
	};

	// ��ģ��
	template <typename T> class Blob {
	public:
		// ��һ�������һ����Ԫ����ʱ,������Ԫ�����Ƿ���ģ�����໥�޹ص�
		// ���һ����ģ�����һ����ģ����Ԫ,����Ԫ����Ȩ���Է�������ģ��ʵ��
		// �����Ԫ������ģ��,�������Ȩ��������Ԫģ��ʵ��,Ҳ������Ȩ���ض�ʵ��
		
		// һ��һ�Ѻù�ϵ:��ģ������һ��(�����)ģ����Ѻù�ϵ���������ʽ
		// �ǽ�����Ӧʵ��������Ԫ��ĵ��Ѻù�ϵ



		// ÿ��Blobʵ��������Ȩ����������ͬ����ʵ��������������
		//template <typename>
		friend bool operator==<>(const Blob<T>&, const Blob<T>&);
		// Blob<T> can refer to the full specialization of 
		// operator<< for its T
		template <typename X>	// ������X ��ȻG++���벻��
		//template <typename>
		friend ostream& operator<<(ostream& os, const Blob<X>&);
		//template<typename>
		//friend ostream& operator<<(ostream& os, const Blob&);
		//friend ostream& operator<< (ostream& os, const Blob&) {
		//	return os << "nothing";
		//}

		// һ����Ҳ���Խ���һ��ģ���ÿ��ʵ��������Ϊ�Լ�����Ԫ,����
		// �޶��ض���ʵ��Ϊ��Ԫ

		// Blob��ÿ��ʵ��������Pal<int>����Ԫ
		// friend class Pal<int> ;
		// Blob��ÿ��ʵ������ͬʵ������Pal����Ϊ��Ԫ
		// friend class Pal<T>;
		// Pal������ʵ������Blob��ÿ��ʵ������Ԫ,����Ҫǰ������
		template<typename X>
		friend class Pal;	//��Ҫ<X>
		// Pen��һ����ģ����,����Blob����ʵ������Ԫ
		friend class Pen;

		//typedef T value_type; 
		using value_type = T;
		//typedef typename std::vector<T>::size_type size_type;
		using size_type = typename std::vector<T>::size_type;
		// ����ģ���Լ�����������,���ǿ���ֱ��ʹ��ģ���������ṩʵ��
		// Blob<T>();
		Blob() ;
		Blob(std::initializer_list<T>);
		size_type size() const { return data->size(); }
		bool empty() const { return data->empty(); }
		void push_back(const T& t) { data->push_back(t); }
		void push_back(T&& t) { data->push_back(std::move(t)); }
		typename std::vector<T>::iterator begin() { return data->begin(); }
		typename std::vector<T>::iterator end() { return data->end(); }
		void pop_back();
		T& back();
		T& operator[](size_type i);
	private:
		std::shared_ptr<std::vector<T> > data; 
		void check(size_type i,const std::string &msg) const ;
	};
	template <typename T>
	void Blob<T>::check(size_type i, const std::string &msg) const {
		if (i < 0 || i >= size()) {
			throw std::out_of_range(msg);
		}
	};
	template <typename T>
	T& Blob<T>::back() {
		check(0, "back on empty Blob");
		return data->back();
	}
	template <typename T>
	T& Blob<T>::operator[](size_type i) {
		// ��ģ���������� ���Բ���ָ��ʵ�� 
		// �������ȼ���Blob<T> &b = *this;
		Blob &b = *this;
		check(i, "subscript out of range");
		return (*b.data)[i];
	}
	template <typename T>
	void Blob<T>::pop_back() {
		check(0, "pop_back on empty Blob");
		data->pop_back();
	}
	template <typename T>
	Blob<T>::Blob():data(std::make_shared<std::vector<T>>()) {}
	template <typename T>
	Blob<T>::Blob(std::initializer_list<T> il) : data(std::make_shared<std::vector<T> >(il)) {}
	template<typename T>
	ostream& operator<< (ostream& os, const Blob<T>&) {
		Blob<long> b; b.data;
		return os << "nothing";
	}
	typedef Blob<string> StrBlob;
	// C++11
	template <typename T> using twin = pair<T, T>;
	template <typename T> using PairNo = pair<T, unsigned>;
}
namespace Test3 {
	
	// ��Ԫ������������ƫ������ֻ������ȫ������
	template<class T> class A {}; // primary
	template<class T> class A<T*> {}; // partial
	template<> class A<int> {}; // full
	class X {
		//template<class T> friend class A<T*>; // error!
		friend class A<int>; // OK
	};
	// When a friend declaration refers to a full specialization of a 
	// function template, the keyword inline and default arguments cannot
	// be used.
	//template<class T> void f(int);
	//template<> void f<int>(int);
	//class X {
		//friend void f<int>(int x = 1); // error: default args not allowed
	//};
}
namespace Test4 {
	// ֵ��ע�����,��Ȼ��Ԫͨ����˵Ӧ����һ�������һ������,��������ȫ����
	// ��һ������������ʵ����Blob,�����������͵��Ѻù�ϵ�������,�Ա�������
	// ������������ʵ����Bar��������
	template <typename T> class Bar {
		friend T; // �˴�����дclass
	private:
		int m;
	};
	struct Foo {
		void f() {
			Bar<Foo> b;
			b.m;
		}
	};
}
namespace Test5 {
	template<typename T, int N>
	class Foo {
	public:
		static int k ;
	};
	// ��Ԫ���ʶ �������
	template<typename T,int N>
	int Foo<T,N>::k = N;
}
namespace Test6 {
	template<typename elemType> class ListItem {};
	template<typename elemType> class List {
	private:
		ListItem<elemType> l;
	};
}
int main()
{
	{
		/*
		// �����ǵ���һ������ģ��ʱ,������(ͨ��)�ú���ʵ����Ϊ�����ƶ�ģ��ʵ��.
		// ���������ƶϳ���ģ�����Ϊ����ʵ����(instantiate)һ���ض��汾�ĺ���
		// ��������ʵ����һ��ģ��ʱ,��ʹ��ʵ�ʵ�ģ��ʵ�δ����Ӧ��ģ�����������
		// ��ģ���һ����"ʵ��".���������ɵĺ���ͨ����Ϊģ���ʵ��
		cout << Test1::compare(1, 2) << endl;
		int arr[30];
		cout << Test1::length(arr) << endl;
		*/
	}
	{
		// �����ṩ����Ĳ��� ��ʾģ�����(explicit template argument)
		// һ����ģ���ÿ��ʵ�����γ�һ����������.����Blob<int>���κ�����
		// Blob���Ͷ�û�й���,Ҳ������κ�����Blob���͵ĳ�Ա���������Ȩ��
		// Ĭ�������,����һ��ʵ�����˵���ģ��,���Աֻ����ʹ��ʱ��ʵ����
		/*
		Test2::Blob<int> b1;
		
		Test2::Blob<long> b2 = {1,2,3,4,5,6};
		Test2::Blob<int> b3;
		for (int s : b2) {
			cout << s << endl;
		}
		cout << b2[1] << endl;
		cout << Test2::operator==(b1,b3) << endl;
		cout << (b1 == b3) << endl;
		cout << b1 << endl;
		Test2::Pal<int> p;
		p.f();
		//test<>();
		//class T {
			// �޷��ھֲ�����������Ԫ
			//template<typename T>
			//friend class Test2::Blob;
		//};
		*/
	}
	{
		/*
		Test4::Bar<Test4::Foo> b;
		Test4::Foo f;
		f.f();
		*/
	}
	{
		/*
		cout << Test5::Foo<int, 4>::k << endl;
		Test5::Foo<int, 4>::k = 50;
		cout << Test5::Foo<int, 4>::k << endl;

		cout << Test5::Foo<int, 5>::k << endl;
		Test5::Foo<int, 5>::k = 150;
		cout << Test5::Foo<int, 5>::k << endl;

		cout << Test5::Foo<int, 4>::k << endl;
		cout << Test5::Foo<int, 5>::k << endl;
		*/
	}
	{
		Test6::List<int> l;
	}
	system("pause");
	return 0; 
}