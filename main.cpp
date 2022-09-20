#include <iostream>
using namespace std;
string h_name,hcity;
int sbed;
int s=1;
class Hospital{
public:
string hname,city;
int beds;
public:
void thd(){
  cin.ignore();
  cout<<"ENTER THE HOSPITAL NAME"<<endl;
  getline(cin,hname);
  cout<<"ENTER CITY"<<endl;
  getline(cin,city);
  cout<<"ENTER NUMBER OF AVAILABLE BEDS"<<endl;
  cin>>beds;
}
void dhd(){
  cout<<"HOSPITAL NAME : "<<hname<<endl;
  cout<<"CITY : "<<city<<endl;
  cout<<"NO. OF AVAILABLE BEDS : "<<beds<<endl;
}
};
class Patient:public Hospital{
public:
string pname,ph,hc;
int id;
public:
void tpd(){
  cin.ignore();
  cout<<"ENTER THE PATIENT NAME"<<endl;
  getline(cin,pname);
  cout<<"ENTER THE ID"<<endl;
  cin>>id;
  cin.ignore();
  cout<<"ENTER THE HOSPITAL NAME"<<endl;
  getline(cin,ph);
  cout<<"HOSPITAL CITY : "<<endl;
  getline(cin,hc);
}
void dpd(){
  cout<<"NAME OF THE PATEINT : "<<pname<<endl;
  cout<<"PATEINT ID : "<<id<<endl;
  cout<<"PATIENT HOSITAL : "<<ph<<endl;
  
}
int search_h(){
  if(h_name==hname && hcity==city){
    return 1;
  }
  else{
    return 0;
  }
}
};
int main() {
  Patient data[100];

  int choice;
  int end=1;
  int h=0;
  int p=0;
  int search_choice;
  cout<<"HOSPITAL MANAGEMENT SYSTEM"<<endl;
  cout<<"LOADING......"<<endl;
  while(end){
    cout<<"CHOOSE THE OPTION TO PROCEED"<<endl;
    cout<<"1 - ADD HOSPITALS\n 2 - ADD PATIENT\n 3 - UPDATE BEDS\n 4 - CHECK HOSPITALS\n 5 - SEARCH\n 6 - CHECK PATIENT\n 7 - EXIT "<<endl;
    cin>>choice;
    switch(choice){
      case 1:
        cout<<"------------- ADD HOSPITALS -------------------"<<endl;
        data[h].thd();
        h++;
      break;
      case 2:
      cout<<"------------- ADD PATIENTS -------------------"<<endl;
      data[p].tpd();
      h_name= data[p].ph;
      hcity = data[p].hc;
        for(int i=0;i<h;i++){
          if(data[i].search_h()==1){
            data[i].beds = data[i].beds-1;
            s=1;
            break;
          }
          else{
            s=0;
          }
        }
      p++;
      break;
      case 3:
      cin.ignore();
      cout<<"HOSPITAL NAME : "<<endl;
      getline(cin,h_name);
      cout<<"CITY : "<<endl;
        getline(cin,hcity);
      for(int i=0;i<h;i++){
          if(data[i].search_h() == 1){
            data[i].dhd();
            cout<<"ENTER THE BEDS"<<endl;
            cin>>data[i].beds;
            cout<<"DATA UPDATED"<<endl;
            s=1;
            break;
          }
        else{
          s=0;
        }  
      }
      if(s==0){
          cout<<"NOT FOUND"<<endl;
      }
      break;
      case 4:
      for(int i=0;i<h;i++){
        data[i].dhd();
        cout<<"--------------"<<endl;
      }
      break;
      case 5:
      cout<<"CHOOSE THE OPTION BELOW "<<endl<<"1 - SEARCH BY NAME"<<endl<<"2 - SEARCH BY BEDS AVAILABLE"<<endl;
      cin>>search_choice;
      switch(search_choice){
        case 1:
        cin.ignore();
        cout<<"NAME OF THE HOSPITAL"<<endl;
        getline(cin,h_name);
        cout<<"CITY"<<endl;
        getline(cin,hcity);
        for(int i=0;i<h;i++){
          if(data[i].search_h()==1){
            cout<<"FOUND"<<endl;
            data[i].dhd();
            s=1;
            break;
          }else{
            s=0;
          }
        }
        if(s==0){
          cout<<"NOT FOUND"<<endl;
        }
        break;
        case 2:
        cout<<"ENTER THE BEDS"<<endl;
        cin>>sbed;
        for(int i=0;i<h;i++){
          if(data[i].beds==sbed){
          data[i].dhd();
          s=1;
          break;
          }
          else{
            s=0;
          }
        }
        if(s==0){
          cout<<"NOT FOUND"<<endl;
        }
        break;
      }
      break;
      case 6:
      for(int i=0;i<p;i++){
        data[i].dpd();
        cout<<"--------------"<<endl;
      }
      break;
      case 7:
      end=0;
      break;
      default:cout<<"ENTER VALID OPTION"<<endl;
    }
  }
  cout<<"VISIT AGAIN!!!!!";
} 