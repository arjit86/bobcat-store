#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
struct store {
    string product;
    int price;
};

void displayItems(store cloth[100]);
void readPrice (store cloth[100]);
void displayChart();
int main()
{
    int num;
    store cloth[100];
    readPrice(cloth);
    
    while(true){
        displayChart();
        cout<<"Enter a number you want to pick  " ;
        cin>>num;



        if (num==1){
            displayItems(cloth);
        }
        if (num==4){
            return -1 ;
        }
        
    }

return 0;
}

void readPrice(store cloth[100]){
    ifstream fin("bobcatstore.txt");
    int i = 1; 
    while(!fin.eof() && i<5) {
        
        fin>>cloth[i].price;
        fin.ignore();
        getline(fin,cloth[i].product);
        
        
        i++;
    }


    fin.close();
}

void displayItems(store cloth[100]){
    cout<<"*****Enter the number you wanna pick******"<<endl;
    for (int i=0;i<5;i++){
        cout<<")"<<cloth[i].product<<" "<<cloth[i].price<<"$"<<endl;
    }
}


void displayChart(){
    cout<<"******WELCOME TO THE BOBCAT STORE****"<<endl;
    cout<<"1)Display Items"<<endl;
    cout<<"2)Checkout Items"<<endl;
    cout<<"3)Print Receipt"<<endl;
    cout<<"4)Exit"<<endl;
    cout<<"**************************************"<<endl;
}
