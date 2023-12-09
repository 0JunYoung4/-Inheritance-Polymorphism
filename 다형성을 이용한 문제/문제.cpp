//--------------------------------------------------------------------------------
// �������� ���� ������ �ذ��غ���.
//--------------------------------------------------------------------------------
#include <iostream>
#include <random>
using namespace std;
default_random_engine dre;
uniform_int_distribution uid{ 1,6 };

class Animal {
public:
	virtual void move() const {			// �������� �����ϱ� ���ؼ� virtual�� �������� �Ѵ�.
		cout << "���� - �����δ�." << '\n';
	}
};
class Dog : public Animal {
public:
	void move() const override {
		cout << "�� - �޸���." << '\n';
	}
};

class Bird : public Animal {
public:
	void move() const override {
		cout << "�� - ����." << '\n';
	}
};

// [���� 1] ���� 10������ �����ϴ� �ڵ带 �ۼ��Ѵ�.
// �ֻ����� ���� Ȧ���̸� Dog�� ����� ¦���̸� Bird�� ������.
// ��� ������ move�� ȣ���Ͽ� �������� �������� Ȯ���϶�.

//int main()
//{
//	Animal* animals[10];			// �����ͷ� ������ ������ �ٸ� ��ü�� ����Ű���� �� �� ����
//	for (Animal*& as : animals) {		// animals�� Animal* �̴ϱ� *&�� ����� ��
//		if (uid(dre) % 2)			// Ȧ���϶� new�� ����� Dog��ŭ�� �޸𸮸� �Ҵ�����
//			as = new Dog;
//		else as = new Bird;			// ¦���϶� Bird��ŭ�� �޸𸮸� �Ҵ��� �ش�.
//	}
//
//	for (Animal*& as : animals)		// ������ moveȣ�� �����ָ� virtual�� ���� Dog�� Bird�� move�� ����ȴ�.
//		as->move();
//
//	for (Animal*& as : animals)
//		delete as;				// new�� �����Ҵ��� ������ �� delete�� ������� �Ѵ�. 
//}

// [���� 2] ���� ���� ������ �����ϴ� �ڵ带 �ۼ��Ѵ�.
// �� ���������� ����� �Է¿� ������.		
// �ֻ����� ���� Ȧ���̸� Dog�� ����� ¦���̸� Bird�� ������.
// ��� ������ move�� ȣ���Ͽ� �������� �������� Ȯ���϶�.


int main()
{
	int num;
	
	cout << "������ ������ �� - ";
	cin >> num;

	Animal** animals = new Animal*[num];			// �츮�� ����ڰ� �Է��� �� ��ŭ Animal*�� ����� ��� �Ѵ�.
													// �̶� Animal*�� �迭�� ��������� �� �޸𸮸� ����Ű�� 
													// �̸��� Ÿ���� Animal**���� �Ѵ�.

	for (int i = 0; i < num; ++i) {
		if (uid(dre) % 2)
			animals[i] = new Dog;
		else animals[i] = new Bird;
	}

	for (int i = 0; i < num; ++i) {
		animals[i]->move();
	}
	for (int i = 0; i < num; ++i)
		delete animals[i];		// ���⿡�� ������°� Dog�� Bird�� �޸�
	delete[] animals;			// ó�� �Ҵ��� Animal*[]�� �޸�
}
// ������� new�� ������ �°� delete�� ����� �Ѵ�.