#include"iostream"
#include"string.h"
#include"vector"
#include"fstream"
#include"conio.h"
#include"stdlib.h"
using namespace std;

struct Cauhoi_dapan{
	string CH;
	string A, B, C, D;
	string DA;
};
vector<Cauhoi_dapan> dscau;

struct Ngchoi{
	string ten;
	int diem;
};
vector<Ngchoi> nc;


void Luutenngchoi(){
	Ngchoi ng;
	string s;
	cout<<"\n Nhap ten nguoi choi: ";
	getline(cin,s);
	ng.ten = s;
	

}

void Luudiemvaoten(int diem){

	Ngchoi ng;
	ng.diem = diem;
	cout<<"diem tong la: "<<diem<<endl;
	Luutenngchoi();
	nc.push_back(ng);
}


void Docde(){ //doc file
	int chonde;
	cout<<"\n Nhap vao 1 or 2 or 3 tuong ung voi bo de muon chon: \n";
	cin>>chonde;
	
	if(chonde == 1){
		ifstream f("INPUT1.txt ");
		
		string s,ans;
		Cauhoi_dapan de;
		int sl; //sl cau hoi
	    int diem=0;
		getline(f,s); sl = atoi(s.c_str());
		
		for(int i=0; i<sl; i++){
			
			getline(f,s); de.CH=s;
			cout<< s <<endl;
			getline(f,s); de.A=s;
			cout<< s <<endl;
			getline(f,s); de.B=s;
			cout<< s <<endl;
			getline(f,s); de.C=s;
			cout<< s <<endl;
			getline(f,s); de.D=s;
			cout<< s <<endl;
			getline(f,s); de.DA=s; // dap an co san
			
			dscau.push_back(de);
			cout<<"\n Nhap dap an A or B or C or D: ";
			cin>>ans;
			if(dscau[i].DA == ans){
				cout<<"\nBan tl dung!\n\n";
				// cho nay de luu diem vao vector diem
				 diem+=1;
				 Luudiemvaoten(diem);
				//
			}
			else 
				cout<<"\nBan tl sai!\n\n";
			
		}
			
	}
}


int main(){
	Docde();
	
	getch();
}
