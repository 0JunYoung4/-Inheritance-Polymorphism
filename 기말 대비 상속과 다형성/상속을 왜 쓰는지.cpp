// 상속을 왜 쓸까? 
// 1. 코드 재사용 - 종류가 매우 다양함
// 2. Polymorphism (다형성) - 명령은 하나만 내렸는데 실행되는건 다양함
// - static binding
// - dynamic binding  

#include <iostream>
using namespace std;

// [문제] 나는 숫자를 출력할때는 알아볼 수 없게 *로 바꾸고 싶다.
// main()이 문제없이 실행되게 class를 코딩해라.

class StarString : public string{
	friend ostream& operator<<(ostream& os, const StarString& s) {		//friend는 private이여도 상관 없음
		
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
	StarString s{ "2023년 11월 23일" };			//string을 사용하면 그대로 출력 가능 - string을 상속받으면 되지 않을까?

	// s = s + " 문자열은 내가 전문가 NO.1";		// 해보기

	cout << s << '\n';			//****년 **월 **일

}