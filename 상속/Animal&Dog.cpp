//--------------------------------------------------------------------------------
// Animal�� DogŬ������ ���� ��ӿ� ���� �����ϱ�
//--------------------------------------------------------------------------------

#include <iostream>
using namespace std;

class Animal {
	int age{};
public:
	Animal() {
		cout << "Animal �⺻����" << '\n';
	}
	Animal(int n) : age{ n } {
		cout << "Animal ����" << '\n';
	}
	~Animal() {
		cout << "Animal �Ҹ�" << '\n';
	}

	void move() const {
		cout << age << "�� - �����δ�." << '\n';
	}
};

class Dog : public Animal {
	string name;
public:
	Dog() {
		cout << "Dog �⺻����" << '\n';
	}
	Dog(int n) : Animal{ n } {		// Animal�� age�� ������ �� ���⿡ �׳� ���ѱ�
		cout << "Dog ����" << '\n';
	}
	~Dog() {
		cout << "Dog �Ҹ�" << '\n';
	}
};

int main() {
	//Dog dog{ 10 };

	//dog.move();			// Dog�� Animal�� ��ӹ޾ұ⿡ move�� �� �� �ִ�.

	Animal a;
	Dog d;
	Animal* pa;
	Dog* pd;
	pa = &d;
	pd = static_cast<Dog*>(pa);
}

// �⺻������ �� ĳ������ �ȴ�. Dog d, Animal a  a=d ó�� 
// d���� a�� ������ �ֱ⿡ �����ϴ�.
// ������ �ٿ�ĳ���� d = a�� �Ұ��� �ϴ�. 
// a���� d�� ���� ������ ���⿡
// ������ �����͸� ����Ѵٸ� �ٿ� ĳ������ �ǵ��� �� �� ������ ���� ��õ������ �ʴ´�.
// Animal* pa, Dog* pd�� ���� pa = &d , pd = pa�� �Ѵٸ� �� ���� �ִ�.
// �̷��� �Ѵٸ� pa�� Dog�� ����Ű�� �ֱ⿡ ������� ������ ������ �̷��Ը� �� ��� ������ �߻��Ѵ�.