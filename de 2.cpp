class Cos:public Function {
	public:
		double Value(double x) {
		return cos(x);
		}
		double Derive(double x) {
		return -sin(x);
		}
	};
	c. 
	
	double DaoHamThuong(Function* f, Function* g, double x){
		if (g != NULL) {
			return (f->Derive()*g->Value()-f->Value()*g->Derive())/(g->Value()*g->Value())
		}
		return 0;
	}
	
	double DaoHamCuaHamHop(Function* f, Function* g, double x){
		if (f != NULL && g != NULL){
			return f->Derive(g->Value())*g->Derive();
		}
		return 0;
	}