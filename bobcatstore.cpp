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
void checkoutItems(store cloth[100]);
int main()
{
    int num;
    store cloth[100];
    // Initialize the array elements
    for (int i = 0; i < 100; i++) {
        cloth[i].product = "";
        cloth[i].price = 0;
    }

    readPrice(cloth);
    
    while(true){
        displayChart();
        cout<<"Enter a number you want to pick  " ;
        cin>>num;



        if (num==1){
            displayItems(cloth);
        }else if (num==2){
            checkoutItems(cloth);
        }else if (num==4){
            return -1;
        }
        
    }

return 0;
}

void readPrice(store cloth[100]){
    ifstream fin("bobcatstore.txt");

    int i = 0; 
    while(fin>>cloth[i].price) {
        fin.ignore();
        getline(fin,cloth[i].product);
        
        
        i++;
    }


    fin.close();
}

void displayItems(store cloth[100]){
    cout<<"*****Enter the number you wanna pick******"<<endl;
    for (int count=0;count<5;count++){
        cout<<count+1<<")"<<cloth[count].product<<" "<<cloth[count].price<<"$"<<endl;
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

void checkoutItems(store cloth[100]){
    int num1;
    cout<<"**************************************"<<endl;
    cout<<"Enter the number of the product you want to check out ";
    cin>>num1;
    num1 = num1 - 1;
    cout<<"You choose"<<cloth[num1].product<<" and the price is "<<cloth[num1].price<<"$"<<endl;

}

