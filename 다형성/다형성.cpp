//--------------------------------------------------------------------------------
// Animal, Dog, Bird를 통해 다형성에 대해 알아본다.
//--------------------------------------------------------------------------------


#include <iostream>
using namespace std;

class Animal {
public:
	virtual void move() const {			// 다형성을 구현하기 위해선 virtual을 사용해줘야 한다.
		cout << "동물 - 움직인다." << '\n';
	}
};
class Dog : public Animal {
public:
	void move() const /*override */{
		cout << "개 - 달린다." << '\n';
	}
};

class Bird : public Animal {
public:
	 void move() const/* override*/ {
		cout << "새 - 난다." << '\n';
	}
};

int main()
{
	Dog d;
	Bird b;

	/*d.move();
	b.move();*/		// 각각 출력한건 다형성이 아님
//-------------------------------------------------------------------
	//Animal* p;
	//p = &d;
	//p->move();
	////p가 Dog를 가리키고 있지만 d에 있는 Animal의 내용만 사용할 수 있기에 Animal의 move가 실행

	//p = &b;
	//p->move();
	//// 위의 설명과 같음
	//-------------------------------------------------------------------
	cout << "Animal의 크기 -" << sizeof Animal << '\n';
	cout << "Dog의 크기 - " << sizeof Dog << '\n';		// 다형성 구현하기 전 - 1
	// 다형성 구현 후 - 8

	Animal* p;
	p = &d;
	p->move();

	p = &b;
	p->move();
	// virtual은 자식에서 override가 붙은 동일한 이름의 함수를 찾아 실행시켜준다.
	// 위 코드에선 override를 안쓰더라도 다형성이 구현되지만 override를 안써주게 되면
	// 제대로 오버라이드가 안되는 경우가 생길 수 있기에 꼭 override를 통해 명시적으로 적어두자.
}