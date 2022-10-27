#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;

string Keyword[32]=
{
	"auto","break","case","char","const","continue","default","double",
	"do","else","enum","extern","float","for","goto","if","int","long",
	"register","return","short","signed","sizeof","static","struct",
	"switch","typedef","union","unsigned","void","volatile","while"
};

vector<int> Case_num;
int total_num = 0;
int switch_num = 0;
int case_num = 0;
int ifelse_num = 0;
int if_elseif_else_num = 0;
int stack[ 1000 ] = { 0 };
int top = -1;//Define the required variables

int judge( string s1 , string s2 )  //函数：判断s1中是否有s2，若有，则返回1
{
	int w( char str );     //
	int pos = s1.find( s2 , 0 );    //找b在a中出现的位置
	int len = s2.length();         //len为b长度
	if( pos != string::npos )     //若a里找得到b
	{
		if( pos == 0 )            //出现位置为0
		{
			if(w( s1[ pos + len ] ) == 0 )//最后一个字符+1为空
				return 1;         //返回1
			else 
				return 0;         //       
		}
		else                   //出现为其他位置
		{
			if(w( s1[ pos + len] ) == 0 && w( s1[ pos - 1] ) == 0 ) // b前后都为空
				return 1;        
			else
				return 0;   
		}
	}
	return 0;                 
}
int w( char str )
{
	if( ( str <= 'z' && str >= 'a' ) || ( str <= 'Z' && str >= 'A' ) )
	{
		return 1;
	}
	else
	{
		return 0;    
	}    
}

void sort_1(string str)
{
	for(int i = 0; i < 32; i++ )
	{
		if(judge( str , Keyword[i] ) == 1)
		{
			if( judge( str , "switch" ) )
			{
				Case_num.push_back( case_num );
				switch_num++;
				case_num = 0;
			}
			if( judge( str , "case" ))
			{
				case_num++;
			}
			total_num++;
			break;
		}
	}
}

void sort_2( string str )
{
	if( judge( str , "else if" ) )
	{
		top++;
		stack[ top ] = 2;
	}    
	else
	{
		if( judge( str , "else" ) )
		{
			if( stack[ top ] == 1 )
			{
				ifelse_num++;
				top--;
			}
			else
			{
				if( stack[ top ] == 2 )
				{
					if_elseif_else_num++;
					top--;
				}
			}
		}
		else
		{
			if(judge( str ,"if" ) )
			{
				top++;
				stack[ top ] = 1;
			}
		}
	}
}

int main()
{
	int level;
	string file,temp;
	cout << "Input the file name: " << endl;
	cin >> file;
	cout << "the completion level: " << endl;
	cin >> level;
	ifstream File( file.c_str() );
	int correspond( string a,string b );
	int correspond( char str);
	void sort_1( string str );
	void sort_2( string str );
	while ( getline( File ,temp ))   //每读取一行
	{
		istringstream istr ( temp );
		string str;
		if( level >= 3)
		{
			sort_2( temp );
		}
		while( istr >> str ) 
		{
			sort_1( str );
		}
	}
	if( level >= 1 )  //level1 and above
	{
		cout << "total num: " << total_num << endl;
	}
	if( level >= 2 ) //level2 and above
	{
		cout << "switch num: " << switch_num << endl;
		if( !Case_num.empty() )
		{
			Case_num.push_back(case_num);
		}
		else
		{
			Case_num.push_back(0);
		}
		cout << "case num: ";
		for ( int i = 1; i <= switch_num; i++)
		{
			cout<< Case_num[i] << " ";
		}
		cout << endl;
	}
	if( level >=3 ) //level3 and above
	{
		cout << "if_else num: " << ifelse_num << endl;
	}
	if( level >=4 )  //level4 and above
	{
		cout << "if_elseif_else num: " <<if_elseif_else_num << endl;
	}
}
