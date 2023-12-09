//--------------------------------------------------------------------------------
// Animal, Dog, Bird�� ���� �������� ���� �˾ƺ���.
//--------------------------------------------------------------------------------


#include <iostream>
using namespace std;

class Animal {
public:
	virtual void move() const {			// �������� �����ϱ� ���ؼ� virtual�� �������� �Ѵ�.
		cout << "���� - �����δ�." << '\n';
	}
};
class Dog : public Animal {
public:
	void move() const /*override */{
		cout << "�� - �޸���." << '\n';
	}
};

class Bird : public Animal {
public:
	 void move() const/* override*/ {
		cout << "�� - ����." << '\n';
	}
};

int main()
{
	Dog d;
	Bird b;

	/*d.move();
	b.move();*/		// ���� ����Ѱ� �������� �ƴ�
//-------------------------------------------------------------------
	//Animal* p;
	//p = &d;
	//p->move();
	////p�� Dog�� ����Ű�� ������ d�� �ִ� Animal�� ���븸 ����� �� �ֱ⿡ Animal�� move�� ����

	//p = &b;
	//p->move();
	//// ���� ����� ����
	//-------------------------------------------------------------------
	cout << "Animal�� ũ�� -" << sizeof Animal << '\n';
	cout << "Dog�� ũ�� - " << sizeof Dog << '\n';		// ������ �����ϱ� �� - 1
	// ������ ���� �� - 8

	Animal* p;
	p = &d;
	p->move();

	p = &b;
	p->move();
	// virtual�� �ڽĿ��� override�� ���� ������ �̸��� �Լ��� ã�� ��������ش�.
	// �� �ڵ忡�� override�� �Ⱦ����� �������� ���������� override�� �Ƚ��ְ� �Ǹ�
	// ����� �������̵尡 �ȵǴ� ��찡 ���� �� �ֱ⿡ �� override�� ���� ��������� �������.
}