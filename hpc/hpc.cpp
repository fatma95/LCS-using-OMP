#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <array>
#include <string>
using namespace std;


void main(){
    string str1 = "president";
    string str2 = "providence";

     const int len1 = str1.size();
     const int len2 = str2.size();
    vector<vector<int>> indecies(len1, vector<int>(len2));
	vector<vector<string>> arrows(len1, vector<string>(len2));



    /*cout<<indecies.size()<<" " << len1<<endl;
	cout<<indecies[1].size() << " " << indecies[3].size() << len2 << endl;
*/
	for(int i = 0; i<indecies.size();i++){
			indecies[i][0]=0;
	}
	for(int i = 0; i<indecies[i].size();i++){
			indecies[0][i]=0;
	}
	for(int i = 1; i< len1;i++){
		for(int j =1 ; j<len2;j++){
			//matching condition:
			if(str1.at(i)== str2.at(j)){
				//cout << "ok";
				indecies[i][j]=indecies[i-1][j-1]+1;
				arrows[i][j] = "CORNER";
			}
			//mismatching condition
			else if (str1.at(i) != str2.at(j)){
				if (indecies[i-1][j] > indecies[i][j-1]){
					indecies[i][j]=indecies[i-1][j];
					arrows[i][j] = "UP";
				}
				else
				{
					indecies[i][j]=indecies[i][j-1];
					arrows[i][j] = "LEFT";
				}
			}
		}
	}
	for(int i = 0; i<indecies.size();i++){
		for(int j = 0;j<indecies[1].size();j++){
			cout << indecies[i][j] << " " ;
		}
		cout << endl;
	}
	for(int i = 0; i<arrows.size();i++){
		for(int j = 0;j<arrows[1].size();j++){
			cout << arrows[i][j] << " " ;
		}
		cout << endl;
	}
    system("pause");

}