#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "constants.h"
#include "addPerson.h"


using namespace std;

person addPerson(string foreName, string lastName, string signature, double length){
	person createdPerson = {
		foreName,
		lastName,
		signature,
		length	
	};
	return createdPerson;
}

vector<person> addPersonToList(vector<person> personVector){
	string foreName, lastName, signature;
	double length;
	cout << "Forename: ";
	getline(cin,foreName);
	cout << "Lastname: ";
	getline(cin,lastName);
	cout << "Lenght: ";
	cin >> length;
	signature = createSignature(foreName, lastName);
	personVector.push_back(addPerson(foreName, lastName, signature, length));
	cout << endl << foreName << " " << lastName << " has been added to your list (signature: " << signature <<")" << endl;
	system("pause");
	return personVector;
}

string createSignature(string foreName, string lastName){
	string signature = "";
	transform(foreName.begin(), foreName.end(), foreName.begin(), ::tolower);
	transform(lastName.begin(), lastName.end(), lastName.begin(), ::tolower);
	signature = signature + foreName.substr(0,3);
	signature = signature + lastName.substr(0,3);
	return signature;
}