class DanhSachMayLoc {
private:
	MayLoc* _danhSach;
	int _N;
public:
	DanhSachMayLoc (){
		this->_N=0;
		this->_danhSach=NULL;
	}
	~DanhSachMayLoc(){
		for(MayLoc* temp=this->_danhSach[0];temp<=this->_danhSach[_N-1];temp++){
			if(temp){
				delete temp;
				temp=NULL;
			}
			else {
				break;
			}
		}
	}
	long DON_GIA_THUE_LY_TAM;
	long DON_GIA_THUE_XUC_TAC;
	void nhap(){
		cout<<"Nhap luong may:";
		cin>>this->_N;
		for(int i=0;i<_N;i++){
			int choice=0;
			cout<<"Nhap loai may: 1 = may ly tam, 2 = may xuc tac:\n";
			cin>>choice;
			if(choice==1){
				this->_danhSach[i]=new MayLyTam();
				
			}
			else {
				this->_danhSach[i]=new MayXucTac();
			}
			this->_danhSach[i]->nhap();
		}
	}
	float tinhLuongNuoc(){
		float sum=0.0;
		for(int i=0;i<this->_N;i++){
			sum+=this->_danhSach[i]->tinhLuongNuoc();
		}
		return sum;
	}
	long tonhChiPhi(){
		long sum=0;
		for(int i=0;i<this->_N;i++){
			sum+=this->_danhSach[i]->tinhChiPhi();
		}
		return sum;
	}
}
long Ao::DON_GIA_THUE_LY_TAM=50000;
long Ao::DON_GIA_THUE_XUC_TAC=80000;
class Ao{
private:
	int _M;
	DanhSachMayLoc _ds;
public:
	void nhap(){
		cout<<"Nhap luong nuoc: ";
		cin>>this->_M;
		cout<<"Nhap danh sach:\n";
		this->_ds.nhap();
	}
	bool AoDuocLocHetKhong(){
		if(this->_M>this->_ds.tinhLuongNuoc()){
			return false;
		}
		else {
			return true;
		}
	}
	long tongChiPhi(){
		return this->_ds.tinhChiPhi();
	}
	Ao(){
		this->_M=0;
	}
	~Ao(){
		this->_M=0;
		this->_ds.~DanhSachMayLoc();
	}
};