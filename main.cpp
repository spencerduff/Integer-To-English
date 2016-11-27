#include <iostream>
#include <string>

using namespace std;

void intToEnglish(int a);
int numOfDiv(int a);
string deca(int a);
void printCheck(int a);
void printDiv(int a);
int divideDown(int a);
void printMod(int a);
int divideDownThreePlaces(int a);
bool checkDiv(int a);


int main(){
	int a;

	cout << "Enter an integer you could like output to English: " << endl;
	cin >> a;

	intToEnglish(a);

	cout << endl;

}


void intToEnglish(int a){
	if (a < 0){
		cout << "negative ";
		a = abs(a);
	}
	if (a == 0)
		return;
	int place = numOfDiv(a);

	int powToMod = (pow(10, place));

	//check subPlace (eg. million, thousand, hundred)
	//if it's a combined, (eg. nineteen, twenty, eleven)
	//deal with it now
	string subPlace = deca(place);
	if (subPlace == "checkTens"){
			printCheck(a);
			//skip a place
			intToEnglish(a % (powToMod / 10));
			//don't follow recursion again
			return;
	}
	if (subPlace == "checkThousands"){
			printCheck(a);
			//skip a place
			intToEnglish(a % (powToMod / 10));
			//don't follow recursion again
			return;
	}
	if (subPlace == "checkMillion"){
			printCheck(a);
			//skip a place
			intToEnglish(a % (powToMod / 10));
			//don't follow recursion again
			return;
	}

	//print myself and subplace then recurse
	printDiv(a);
	if ((place % 3) != 2)
		cout << subPlace;
	if ((place % 3) == 2){	
		int b = divideDownThreePlaces(a);
		if (checkDiv(b % 100) && checkDiv(b % 10))
			cout << subPlace;
		else cout << "hundred ";
	}

	

	intToEnglish(a % powToMod);
}

int numOfDiv(int a){
	int count = 0;

	while (a > 9){
		a /= 10;
		count++;
	}
	return count;
}

string deca(int a){
	if (a == 1)	return "checkTens";
	else if (a == 2) return "hundred ";
	else if (a == 3) return "thousand ";
	else if (a == 4) return "checkThousands";
	else if (a == 5) return "hundred thousand ";
	else if (a == 6) return "million ";
	else if (a == 7) return "checkMillion";
	else if (a == 8) return "hundred million ";
	else if (a == 9) return "billion ";
	else return "Error: out of bounds ";
}

void printDiv(int a){
	while (a > 9){
		a /= 10;
	}
	if (a == 1)	cout << "one ";
	else if (a == 2) cout << "two ";
	else if (a == 3) cout << "three ";
	else if (a == 4) cout << "four ";
	else if (a == 5) cout << "five ";
	else if (a == 6) cout << "six ";
	else if (a == 7) cout << "seven ";
	else if (a == 8) cout << "eight ";
	else if (a == 9) cout << "nine ";
	return;
}

bool checkDiv(int a){
	while (a > 9){
		a /= 10;
	}
	if (a != 0) return false;
	return true;
}

void printCheck(int a){
	string subPlace = "";
	if (a >= 1000000) subPlace = "million ";
	else if (a >= 1000) subPlace = "thousand ";
	a = divideDown(a);
	if (a < 100 && a >= 90){
		if (a > 90){
			cout << "ninety ";
			printMod(a);
			cout << subPlace;
		}
		else cout << "ninety " << subPlace;
	}
	else if (a < 90 && a >= 80){
		if (a > 80){
			cout << "eighty ";
			printMod(a);
			cout << subPlace;
		}
		else cout << "eighty " << subPlace;
	}
	else if (a < 80 && a >= 70){
		if (a > 70){
			cout << "seventy ";
			printMod(a);
			cout << subPlace;
		}
		else cout << "seventy " << subPlace;
	}
	else if (a < 70 && a >= 60){
		if (a > 60){
			cout << "sixty ";
			printMod(a);
			cout << subPlace;
		}
		else cout << "sixty " << subPlace;
	}
	else if (a < 60 && a >= 50){
		if (a > 50){
			cout << "fifty ";
			printMod(a);
			cout << subPlace;
		}
		else cout << "fifty " << subPlace;
	}
	else if (a < 50 && a >= 40){
		if (a > 40){
			cout << "fourty ";
			printMod(a);
			cout << subPlace;
		}
		else cout << "fourty " << subPlace;
	}
	else if (a < 40 && a >= 30){
		if (a > 30){
			cout << "thirty ";
			printMod(a);
			cout << subPlace;
		}
		else cout << "thirty " << subPlace;
	}
	else if (a < 30 && a >= 20){
		if (a > 20){
			cout << "twenty ";
			printMod(a);
			cout << subPlace;
		}
		else cout << "twenty " << subPlace;
	}
	else if (a == 19) cout << "nineteen " << subPlace;
	else if (a == 18) cout << "eighteen " << subPlace;
	else if (a == 17) cout << "seventeen " << subPlace;
	else if (a == 16) cout << "sixteen " << subPlace;
	else if (a == 15) cout << "fifteen " << subPlace;
	else if (a == 14) cout << "fourteen " << subPlace;
	else if (a == 13) cout << "thirteen " << subPlace;
	else if (a == 12) cout << "twelve " << subPlace;
	else if (a == 11) cout << "eleven " << subPlace;
	else if (a == 10) cout << "ten " << subPlace;
	return;
}

int divideDown(int a){
	while (a > 99){
		a /= 10;
	}
	return a;
}

int divideDownThreePlaces(int a){
	while (a > 999){
		a /= 10;
	}
	return a;
}

void printMod(int a){
	a %= 10;
	if (a == 1)	cout << "one ";
	else if (a == 2) cout << "two ";
	else if (a == 3) cout << "three ";
	else if (a == 4) cout << "four ";
	else if (a == 5) cout << "five ";
	else if (a == 6) cout << "six ";
	else if (a == 7) cout << "seven ";
	else if (a == 8) cout << "eight ";
	else if (a == 9) cout << "nine ";
	return;
}