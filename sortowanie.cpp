#include <iostream>

using namespace std;

int tab[10]={5,2,3,6,1,15,17,22,32,8};
int a,x=1,licznik=0;
int main()

{
	cout << "sortowanie babelkowe" << endl;
	while (x!=0){
		x=0;
		for (int i=0;i<10;i++){
			if (i != 9){
				if (tab[i] > tab[i+1]){
					a=tab[i];
					tab[i]=tab[i+1];
					tab[i+1]=a;
					x++;
				}
			}
			licznik++;
		}
	}
	for (int i=0;i<10;i++){
		cout << tab[i] << ", ";
	}
	cout << endl << "liczba krokow =" << licznik << endl;
}