#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

string keywords[32]=
{
	"auto","break","case","char","const","continue","default","do",
	"double","else","enum","extern","float","for","goto","if",
	"int","long","register","return","short","signed","sizeof","static",
	"struct","switch","typedef","union","unsigned","void","volatile","while"
};


int judge(string k){             //判断单词k是否为关键词，是的话返回1
	int n=0;
	for(int i=0;i<32;i++){
		if(k==keywords[i]){
			n++;
			break;
		}
	}
	if(n!=0){
		return 1;
	}
	else
		return 0;
}


int main(){
	string file,w;
	int total=0;
	cout<<"input the file name:";
	cin>>file;
	ifstream File(file.c_str());
	
	while(File>>w){
		cout<<w<<endl;
	}
	cout<<total;
}



