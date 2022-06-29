#include <iostream>
using namespace std;
#include "Solutions.h"

int main(){

    /*fantabulous("1,4,6,3,12", 5);
    fantabulous("1,3,2,4", 4);
    fantabulous("1,7,4,12,14",5);
    fantabulous("1,15,2,5,12,14",6);
    fantabulous("3,4,12,18,21,100,4,2,1,99",10);

    subset("1,7,10,12,11,17,15,16,19,22",10);
    subset("3,6,4,12,15,19,21,25,21,44,45,47,90,92",14);
    subset("2,4,3,10,12,18,19,20",8);

    cout << infix2prefix("(7-2)*3-6") << endl;
    cout << infix2prefix("9/2-(6-4)*2+9") << endl;
    cout << infix2prefix("9/3+6/2-(4-2)") << endl;

    evaluatePrefix("-*-7236");
    evaluatePrefix("-/92+*-6429");
    evaluatePrefix("+/93-/62-42");*/

    cout << endl;
	cout << "Testing Fantabulous" << endl;
	cout << endl;
	fantabulous("2,8,12,3,9,16,4",7);
	fantabulous("1,9,3,12,30,5,4,1",8);
	fantabulous("5,19,23,42,99,5,100,1,3",9);
	fantabulous("90,103,60,50,40,30,20", 7);
	fantabulous("9,8,7,5,4,10", 6);
	cout << endl;

	cout << "Testing Subset Problem" << endl;
	cout << endl;
	subset("2,9,8,12,15,17,31,40,39,65,90,103",12);
	subset("3,7,9,10,12,18,19,31,20,40,42,92",12);
	subset("8,12,13,41,19,100,102,103,103,107",10);
	subset("1,4,3,10,5,12,11,90,102,105",10);
	subset("1,3,5,12,16,79,102,160,201,304",10);
	cout << endl;

	cout << "Testing Infix to Prefix" << endl;
	cout << endl;
	cout << infix2prefix("7-3/2+1-9/3+9") << endl;
	//cout << infix2prefix("9-2*3/8+(6-2)*3") << endl;
	cout << infix2prefix("5-(3+9)/3*4-1") << endl;
	cout << infix2prefix("3+2-1+9+2-1+3") << endl;
	cout << infix2prefix("6-2*(4+2)-9/3+6") << endl;
	cout << endl;

	cout << "Testing evaluate Prefix" << endl;
	cout << endl;

	evaluatePrefix("+-+-7/321/939");
	evaluatePrefix("+-9/*238*-623");
	evaluatePrefix("--5*/+39341");
	evaluatePrefix("+-++-+3219213");
	evaluatePrefix("+--6*2+42/936");

	

    return 0;
}