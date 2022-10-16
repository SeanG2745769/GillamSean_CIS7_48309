// Get firstname/lastname
#include <iostream>
#include <string>
	
int main()	
{
    int i;

    std::string firstname;
    std::string lastname;
    std::cout<<"Enter First Name? ";
    std::cin>>firstname;
    std::cin.ignore();
    for(i=0; firstname[i] ; i++) firstname [i]=toupper(firstname[i]);
    std::cout<<"Enter Last Name? ";
    std::cin>>lastname;
    std::cin.ignore();
    for(i=0; lastname[i] ; i++) lastname [i]=toupper(lastname[i]);	
    std::cout << firstname << " " << lastname;
    return 0;
}