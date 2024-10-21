#include<bits/stdc++.h>
#include<string>
using namespace std;

struct Sinhvien{
    string name;
    string classcode;
};

int main(){
    map<int,Sinhvien> sv;
    string command;
    int ID;
    string StudentID,Fullname,Classcode;

    while(1){
        getline(cin,command);
        if(command.substr(0,6)=="Insert"){
            
            string data = command.substr(command.find('(')+1,command.find(')')-command.find('(')-1);
            stringstream ss(data);

            getline(ss,StudentID,',');  
            ID=stoi(StudentID);

            getline(ss,Fullname,',');  
            getline(ss,Classcode);
           sv[ID]={Fullname,Classcode};
        }
        else if(command.substr(0,6)=="Delete"){
            StudentID = command.substr(command.find('(')+1,command.find(')')-command.find('(')-1); 
            ID=stoi(StudentID);
            sv.erase(ID);
        }
        else if(command.substr(0,5)=="Infor"){
            StudentID = command.substr(command.find('(')+1,command.find(')')-command.find('(')-1);
            ID=stoi(StudentID);
            if(sv.find(ID)==sv.end()){
                cout << "NA.NA" << endl;
            }
            else{
                cout << sv[ID].name << ", " << sv[ID].classcode<<endl;
            }
        }
    }

    return 0;
}