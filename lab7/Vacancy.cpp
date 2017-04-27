#include "Baseclass.cpp"
class Vacansy : public Base
{
	private:
	String job, firm;
	public:
	Vacansy(String Job, String Firm,String c, String s, int a, int sa,
	int se, int e, int b, int f):
	Base(c,s,a,sa,se,e,b,f){
		job=Job;
		firm=Firm;
	}
	String Job(){
		return job;
	}
	String Firm(){
		return firm;
	}
};