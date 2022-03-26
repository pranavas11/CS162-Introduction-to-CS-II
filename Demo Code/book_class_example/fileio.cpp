#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct 

int main(){

    fstream f;
    f.open("input.txt");

    int num = 0;
    string tmp_string; 

    if(f.is_open()){
        while(f.good()){
            getline(f,tmp_string,',');
            cout << tmp_string << " ";
            num++;
        }



    }else{
        cout << "FILE PROBLEMS" << endl;
    }
    cout << num << endl;

    //f << "This is a file." << endl;

    f.close();

    //f.open("inputs2.txt");


    return 0;
}