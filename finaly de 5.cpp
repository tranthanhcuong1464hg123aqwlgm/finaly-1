class BigInterger{
		string _bigNum;
	public:
		BigInterger(){
			this->_bigNum="";
		}
		BigInterger(string s){
			for(int i=0;i<s.size();i++){
				if(s[i]==' '){
					for(int j=i;j<s.size();j++){
						s[i]=s[i+1];
					}
					i--;
					s[s.size()-1]=0;
				}
			}
			this->_bigNum=s;
		}
		friend istream& operator>>(istream& is, BigInterger& bigNum){
			getline(is,this->_bigNum);
			return is;
		}
		bool operator==(const BigInterger& bNum){
			if(this->_bigNum==bNum._bigNum){
				return true;
			}
			else {
				return false;
			}
		}
	};