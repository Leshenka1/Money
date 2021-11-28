#include <iostream>
#include "money.h"
using namespace std;

int main()
{
	money sum1;
	money sum2;

	cout << "enter amount of first sum" << endl;
	double pound1, shilling1, penny1, pound2, shilling2, penny2;
	cin >> pound1 >> shilling1 >> penny1;
	cout << "enter second sum" << endl;
	cin>> pound2 >> shilling2 >> penny2;

	try 
	{
		sum1.SetPound(pound1);
		sum1.SetShilling(shilling1);
		sum1.SetPenny(penny1);
		sum2.SetPound(pound2); 
		sum2.SetShilling(shilling2);
		sum2.SetPenny(penny2);
	}
	catch (const exception &ex)
	{
		cout << ex.what() << endl;
		return 0;
	}


	cout << "--------------------------------" << endl;
	cout<<"first sum \t" << sum1 << endl;
	cout <<"second sum \t" << sum2<<endl;

	cout<< "--------------------------------" << endl;

	cout <<"sum1 + sum2 \t"<<"\t" << sum1 + sum2 << endl;
	cout << "sum1 - sum2 \t" << "\t" << sum1 - sum2 << endl;
	cout << "-sum1       \t" <<"\t" << -sum1 << endl;
	cout << "sum1 += sum2 \t" << "\t" << (sum1 += sum2) << endl;
	cout << "sum1 -= sum2 \t" << "\t" << (sum1 -= sum2) << endl;
	cout << "sum1 == sum2 \t" << "\t" << (sum1 == sum2) << endl;
  
	
	return 0;
}