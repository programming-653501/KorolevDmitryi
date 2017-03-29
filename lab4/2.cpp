#include <fstream>
int _tmain(int argc, _TCHAR* argv[])
{
	char buff[50];
    long double arr[20];
	int c,num,i,j; double d;
	ifstream in;
	ofstream out;
	in.open("4.txt");
	num=0;
	buff[0]='4';
	while(buff[0]!='\0'){
	in>>buff;
	i=c=0;
	d=0;
	while (buff[i]!='.'&&buff[i]!='\0'&&buff[i]!=','&&buff[i]!='.'){
		c=c*8+buff[i]-48;
		i++;
	}
	if(buff[i]=='.'||buff[i]==','||buff[i]=='.'){
		i++;
		j=2;
		while (buff[i]!='\0'){
			d+=(double(buff[i]-48))/j/j/j;
			j*=2;
			i++;
		}
	}
	arr[num]=c+d;
	num++;
	}
	in.close();
	out.open("4.txt");
	for (i = 0; i < num-1; i++) {
		out<<arr[i]<<" ";
	}
	out.close();
	return 0;
}
