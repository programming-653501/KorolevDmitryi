#include "Unit2.h"
class Client: public Base{
	private:
	String name, contacts;
	public:
	Client(String Name, String Contacts,String c, String s, int a, int sa,
					int se, int e, int b, int f):
						Base(c,s,a,sa,se,e,b,f){
		name=Name;
		contacts=Contacts;
	}
	String Name(){
		return name;
	}
	String Contacts(){
		return contacts;
	}
};
