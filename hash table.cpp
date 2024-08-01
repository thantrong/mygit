#include <iostream>
#include <unordered_map>
#include "cctype"
#include "string"
using namespace std;

string toLow(string input ){
    string quocgia;
    for (int i = 0; i< input.length();i++){
        quocgia += tolower(input[i]);
    }
    return quocgia;
}
void thudocuaquocgia(string input){
    string quocgia = toLow(input);
    unordered_map<string,string>thudo;

    thudo["brunei"]= "Bandar Seri Begawan";
    thudo["campuchia"]= "Phnom Penh";
    thudo["đông timo"]= "Dili";
    thudo["indonesia"]= "Jakarata";
    thudo["laos"]= "Viên Chăn";
    thudo["lao"]= "Viên Chăn";
    thudo["malaysia"]= "Kuala Lumpur";
    thudo["myanmar"]= "Naypyidaw";
    thudo["philippines"]= "Manila";
    thudo["singapore"]= "Singapore";
    thudo["thái lan"]= "Bangkok";
    thudo["thai lan"]= "Bangkok";
    thudo["việt nam"]= "Hà Nội";
    thudo["viet nam"]= "Hà Nội";

    if(thudo.find(quocgia)==thudo.end()){
        cout<<"Thủ đô của "<<input<<" không có trong danh sách hoặc quốc gia không chính xác"<<endl;
    }
    else{
        cout<<"Thủ đô của "<<input<<" là "<<thudo[quocgia]<<endl;
    }
}
int main() {
    bool fl = true;
    while(fl){

        cout<<"Nhập tên quốc gia trong Đông Nam Á\n ";
        string test ;
        getline(cin,test);
        thudocuaquocgia(test);
        cout<<"Bạn có muốn tiếp tục tìm không\n";
        cout<<" Y/N ";
        string loop;
        cin>>loop;
        cin.ignore();
        cout<<"----------------------------------------------\n";
        if (loop == "Y"|| loop =="y" ? fl = true: fl = false);
    }
}
