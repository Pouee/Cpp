#include "iostream"
#include "memory"
using namespace std;
template<typename T>
class Bug {
public:
	~Bug() {
		T()();
	}
};
struct Del {
	void operator()() {
		cout << "Del" << endl;
	}
};
int main()
{
	// ����ʱ�� Ч�ʸ� ���ܱ����������ʽ
	Bug<Del> b();
	// ͨ���ڱ���ʱ��ɾ����,unique_ptr�����˼�ӵ���ɾ����������ʱ����
	// ͨ������ʱ��ɾ����,shared_ptrʹ�û�����ɾ������Ϊ����
	return 0; 
}