// ����� �� ����? 
// 1. �ڵ� ���� - ������ �ſ� �پ���
// 2. Polymorphism (������) - ����� �ϳ��� ���ȴµ� ����Ǵ°� �پ���
// - static binding
// - dynamic binding  

#include <iostream>
using namespace std;

// [����] ���� ���ڸ� ����Ҷ��� �˾ƺ� �� ���� *�� �ٲٰ� �ʹ�.
// main()�� �������� ����ǰ� class�� �ڵ��ض�.

class StarString : public string{
	friend ostream& operator<<(ostream& os, const StarString& s) {		//friend�� private�̿��� ��� ����
		
		for (char c : s) {
			if (isdigit(c))
				c = '*';
			cout << c;
		}
		return os;
	}
};

int main()
{
	StarString s{ "2023�� 11�� 23��" };			//string�� ����ϸ� �״�� ��� ���� - string�� ��ӹ����� ���� ������?

	// s = s + " ���ڿ��� ���� ������ NO.1";		// �غ���

	cout << s << '\n';			//****�� **�� **��

}