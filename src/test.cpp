/**
* @file test
* @description Test project for Doubly Circular Linked List
* @course Veri Yapıları 1-C
* @assignment 1
* @date 28.11.2020
* @author Furkan Cebar (furkan.cebar@ogr.sakarya.edu.tr)
*/

#include "List.hpp"
#include <fstream>
#include <iostream>

#define filepath "doc/Sayilar.txt"

//Takes string and convert it to dynamic int array
int* Reader(const std::string& line) {
	int count = 1;
	for (char i : line) {
		if (i == ' ') count++;
	}
	std::stringstream lineReader(line);

	int *numbers = new int[count];
	numbers[0] = count;
	for (int i = 1; i <= count; ++i) {
		lineReader >> numbers[i];
	}
	return numbers;
}

int main() {
	List *max = new List();
	List *min = new List();
	std::ifstream reader(filepath);
	std::string line;
	std::getline(reader,line);

	int *array = Reader(line);

	array >> *max;
	array >> *min;

	delete array;

	while (std::getline(reader,line)) {
		array = Reader(line);
		if (array[1] < min->FindByIndex(0)) {
			array >> *min;
		}
		if (array[1] > max->FindByIndex(0)) {
			array >> *max;
		}
		delete array;
	}



	std::cout << "MAX: " << max->GetMiddleNode() << std::endl;
	std::cout << max << std::endl;
	std::cout << "MIN: " << min->GetMiddleNode() << std::endl;
	std::cout << min << std::endl;
	std::cout << std::endl;

	List *temp = new List(max->FindByIndex(0));


	int size = min->Size() / 2;
	for (int i = 1; i <= size; ++i) {
		temp->AddRight(min->FindByIndex(-1));
		min->RemoveAt(-1);
	}
	for (int i = 1; i <= size; ++i) {
		temp->AddLeft(min->FindByIndex(1));
		min->RemoveAt(1);
	}

	size = max->Size() / 2;
	for (int i = 1; i <= size; ++i) {
		min->AddRight(max->FindByIndex(i * -1));
	}
	for (int i = 1; i <= size; ++i) {
		min->AddLeft(max->FindByIndex(i));
	}

	delete max;

	max = temp;

	std::cout << "MAX: " << max->GetMiddleNode() << std::endl;
	std::cout << max << std::endl;
	std::cout << "MIN: " << min->GetMiddleNode() << std::endl;
	std::cout << min << std::endl;
	std::cout << std::endl;


	delete min;
	delete max;

}

/*
int main()
{
	List *isimler = new List();
	int sec=0;
	string isim;
	do{
		system("CLS");
		cout<<"1.Isim Ekle"<<endl;
		cout<<"2.Isim Sil"<<endl;
		cout<<"3.Konumdan Isim Sil"<<endl;
		cout<<"4.Konuma Isim Ekle"<<endl;
		cout<<"5.Konum Bul"<<endl;
		cout<<"6.Isim Sayisi"<<endl;
		cout<<"7.Ilk Isim"<<endl;
		cout<<"8.Son Isim"<<endl;
		cout<<"9.Isimleri Listele"<<endl;
		cout<<"10.Isimleri Konumdan itibaren Listele"<<endl;
		cout<<"11.Isimleri Temizle"<<endl;
		cout<<"12.Cikis"<<endl;
		cout<<"Secim:";
		cin>>sec;
		system("CLS");
		switch(sec){
			case 1:
				cout<<"Isim:";
				cin.ignore();
				getline(cin,isim);
				isimler->add(isim);
			break;
			case 2:
				cout<<"Isim:";
				cin.ignore();
				getline(cin,isim);
				try{
					isimler->remove(isim);				
				}
				catch(ElemanYok &elemanYok){
					cout<<endl<<elemanYok.Mesaj()<<endl;
					cin.get();
				}
			break;
			case 3:
				try{
					int konum;
					cout<<"Konum:";
					cin>>konum;
					isimler->removeAt(konum);				
				}
				catch(ElemanYok &elemanYok){
					cout<<endl<<elemanYok.Mesaj()<<endl;
					cin.ignore();
					cin.get();
				}
			break;
			case 4:
				try{
					string isim;
					int konum;
					cout<<"Konum:";
					cin>>konum;
					cout<<"Isim:";
					cin.ignore();
					getline(cin,isim);
					isimler->insert(konum,isim);
				}
				catch(Tasma &tasma){
					cout<<endl<<tasma.Mesaj()<<endl;
					cin.get();
				}
			break;
			case 5:
				try{
					string isim;
					cout<<"Isim:";
					cin.ignore();
					getline(cin,isim);
					cout<<"Konum:"<<isimler->indexOf(isim);
					cin.get();
				}
				catch(ElemanYok &elemanYok){
					cout<<endl<<elemanYok.Mesaj()<<endl;
					cin.get();
				}
			break;
			case 6:			
				cout<<"Isim Sayisi:"<<isimler->Count()<<endl;
				cin.ignore();
				cin.get();
			break;	
			case 7:
				try{
					cout<<"Ilk Isim:"<<isimler->first()<<endl;
					cin.ignore();
					cin.get();
				}
				catch(ListeBos &listeBos){
					cout<<endl<<listeBos.Mesaj()<<endl;
					cin.get();
				}
			break;	
			case 8:
				try{
					cout<<"Son Isim:"<<isimler->last()<<endl;
					cin.ignore();
					cin.get();
				}
				catch(ListeBos &listeBos){
					cout<<endl<<listeBos.Mesaj()<<endl;
					cin.get();
				}
			break;	
			case 9:			
				cout<<"ISIMLER:"<<endl;
				cout<<*isimler<<endl;
				cin.ignore();
				cin.get();
			break;	
			case 10:			
				int konum;
				cout<<"Konum:";
				cin>>konum;
				cout<<"ISIMLER:"<<endl;
				isimler->printAllFromPosition(konum);
				cin.ignore();
				cin.get();
			break;	
			case 11:
				isimler->clear();
				cout<<endl<<"Tum isimler silindi."<<endl;
				cin.ignore();
				cin.get();
			break;
			case 12:
			break;
			default:
				cout<<endl<<"Yanlis tercih!"<<endl;
				cin.ignore();
				cin.get();
			break;
		}
		system("CLS");
	}while(sec != 12);
	delete isimler;
}*/