#include <vcl.h>
#include <string>
enum Sex{w=0,m,a};
enum Busyness{full=0,semi,any};
enum Education{high=0,secon,spec,non};
enum Family{married=0,single,children,nomatter};
class Base{
	private:
	String city, specialisation;
	int age,salary;
	enum Sex sex;
	enum Education edu;
	enum Busyness busyness;
	enum Family family;
	public:
	Base(String c, String s, int a, int sa, int se, int e, int b, int f){
		city=c;
		specialisation=s;
		age=a;
		sex=se;
		salary=sa;
		busyness=b;
		edu=e;
		family=f;
		return;
	}
	public: String City(){
		return city;
	}
	String Specialisation(){
		return specialisation;
	}
	enum Sex Sex(){
		return sex;
	}
	enum Education Edu(){
		return edu;
	}
	enum Busyness Busyness(){
		return busyness;
	}
	enum Family Family(){
		return family;
	}
	int Age(){
		return age;
	}
	int Salary(){
		return salary;
	}
};
