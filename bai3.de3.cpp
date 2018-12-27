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

void Xuatngchoi(Ngchoi nc){
	cout<<"\nTen nguoi choi: "<<nc.ten<<endl;
	cout<<"\nDiem: "<<nc.diem<<endl;
}
void Xuatdsngchoi(){
	size_t n = nc.size();
	for(int i = 0; i < n; i++)
	{
		Xuatngchoi(nc[i]);
	}			
}

void Luutenngchoi(Ngchoi &ng,int diem){
	
	string s;
	cout<<"\n Nhap ten nguoi choi: ";
	fflush(stdin);
	getline(cin,s);
	ng.ten = s;
	ng.diem = diem;
	nc.push_back(ng);
	
}

void Xuatde(int so){
	ifstream f;
	 if(so == 1){
	  f.open("INPUT1.txt ");	
      }
      else if(so == 2){
	 f.open("INPUT2.txt ");	
      }
       else if(so == 3){
	 f.open("INPUT3.txt ");	
      }
		string s,ans;
		Cauhoi_dapan de;
		Ngchoi an;
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
			
				 
				//
			}
			else 
				cout<<"\nBan tl sai!\n\n";
			
		}
	Luutenngchoi(an,diem);
	Xuatngchoi(an);
}

void Docde(){ //mo file can doc
	int chonde;
	cout<<"\n Nhap vao 1 or 2 or 3 tuong ung voi bo de muon chon: \n";
	cin>>chonde;
	
	if(chonde == 1){
		
		Xuatde(1);
	}
	else if (chonde == 2){
		Xuatde(2);
	}
	else if (chonde == 3){
		Xuatde(3);
	}
			
	
}

int main(){
	int tam;
	
	do{	
	cout<<"\nBan co muon choi ? (nhap 0 la dung): ";
	cin>>tam;
	if(tam!=0)
	Docde();
} while(tam!=0);
	cout<<"\n Danh sach nguoi choi la: ";
	Xuatdsngchoi();

	getch();
}
