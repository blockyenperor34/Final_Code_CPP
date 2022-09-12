#include<iostream>
#include <time.h> 

using namespace std;
int Fnum;
int Gminnum;
int Gmaxnum;
int status;

void init() {
	//srand((unsigned int)time(0));
	double min = 1;
	double max = 100;
	Fnum = (max - min) * rand() / (RAND_MAX + 1.0) + min;
	Gminnum = min;
	Gmaxnum = max;
	
}

void guess(int Gnum) { // 1 = correct,2 = smaller than ans, 3 = bigger than ans
	if (Gnum == Fnum) {
		//cout << "You Won!" << Fnum << endl;
		status =  1;
	}
	else {
		if (Gnum < Fnum) {
			Gminnum = Gnum;
			status = 2;
		}
		else {
			if (Gnum > Fnum) {
				Gmaxnum = Gnum;
				status = 3;
			}
		}
	}
}

int main() {
	int Unum;
	char agin = 'n';
	init();
	
enter:
	//cout << Fnum; //for debugging
	cout << "請輸入一個數字("<<Gminnum<<"-"<<Gmaxnum<<"):";
	cin >> Unum;
	guess(Unum);
	switch (status) {
	case 1:
		cout <<endl<< "你贏了!!111" << endl;
		cout << "再玩一次嗎?(y/n):";
		cin >> agin;
		//agin = cin.get();

		if (agin == 'y') {
			init();
			system("CLS");
			
			goto enter;
		}
		else {
			goto exit;
		}
		//goto exit;
		break;
	case 2:
		goto enter;
		break;
	case 3: 
		goto enter;
		break;
	default:
		cout << "ERROR: unexpected status." << endl;

	}


exit:
	system("pause");
	return 0;
}