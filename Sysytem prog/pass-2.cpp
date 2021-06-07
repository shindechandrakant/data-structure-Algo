#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define vs vector<string>
#define table unordered_map<int, pair<string,int>>
#define ump(dataTyp1, dataTyp2) unordered_map<(dataTyp1), (dataTyp2)>
#define mp(dataTyp1, dataTyp2) map<(dataTyp1), (dataTyp2)>
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))
#define MOD 1000000007

// problem statement -> 
// Problem link -> 

table symbol;
table literal;

// identify constant
bool isConstant(string str, int &val) {


	if(str[0] >= '0' and str[0] <= '9') {
		
		try {
			val = stoi(str);
			return true;
		}
		catch(...) {
			return false;
		}
	}
	return false;
}

// Read pass1 line by line
bool readInput(stringstream &ss, vector<vs> &passOne) {

	string str;
	vs line;
	while(getline(ss, str, ' ')) {

		if(str == "-")
			return false;

		if(str.size() != 0 and str != " ")
			line.push_back(str);
	}
	passOne.push_back(line);
	return true;
}

// read tables
bool readTable(stringstream &ss, table &tt) {

	string str;
	string indx = "";
	string symbol = "";
	string address = "";
	while(getline(ss, str, ' ')) {

		if(str == "-")
			return false;
		if(indx.size() == 0) 
			indx = str;
		else if(symbol.size() == 0)
			symbol = str;
		else
			address = str;
	}

	tt[stoi(indx)] = {symbol, stoi(address) };
	return true;
}

pair<string, string> extractTouple(string tuple) {

	
	tuple.pop_back();
	tuple.erase(tuple.begin());

	int i = 0;
	string type;
	string num;
	for(i = 0; tuple[i] != ','; i++) {

		type.push_back(tuple[i]);
	}

	for(i +=1; i < tuple.size(); i++) {

		num.push_back(tuple[i]);
	}

	return { type, num };
}

vs analysisLine(vs &line) {

	vs targeCode;

	for(int i = 0; i < line.size(); i++) {

		int constant;

		if(isConstant(line[i], constant)) {

			targeCode.push_back(line[i]);
		}
		else {

			// 100 (DL,2) (C,3)
			auto it = extractTouple(line[i]);

			if(it.first == "AD") {
				return { "-----------" };
			}
			else if(it.first == "C") {
				continue;
			}
			else if(it.first == "S") {

				auto it1 = symbol[stoi(it.second)];
				targeCode.push_back(to_string(it1.second));
			}
			else if(it.first == "L") {

				auto it1 = literal[stoi(it.second)];
				targeCode.push_back(to_string(it1.second));
			}
			else {
				targeCode.push_back(it.second);
			}

		}
	}

	return targeCode;
}

namespace display {

	void displyData(vector<vs> output) {

		for(int i = 0; i < output.size(); i++)
		{
			for(int j = 0; j < output[i].size(); j++) {

				cout<<output[i][j]<<" ";
			}
			cout<<endl;
		}
	}

	// unordered_map<int, pair<string,int>>

	void displyTable(table &tt) {

		for(auto it: tt) {
			auto tuple = it.second;
			cout<<it.first<<" "<<tuple.first<<" "<<tuple.second<<endl;
		}
		cout<<endl<<endl;
	}
};
using namespace display;


int main() {

	freopen("../io/input.txt", "r", stdin);
	freopen("../io/output.txt", "w", stdout);


	vector<vs> output;
	vector<vs> passOne;
	string str;

	// Read pass 1 code
	while(getline(cin, str)) {

		stringstream ss(str);
		
 		bool valid = readInput(ss, passOne);

 		if(not valid)
 			break;
	}

	cin.clear();
	// Read Sybmol Table
	while(getline(cin, str)) {

		stringstream ss(str);

 		bool valid = readTable(ss, symbol);

 		if(not valid)
 			break;
	}

	cin.clear();
	// Read Literal Table
	while(getline(cin, str)) {

		stringstream ss(str);
 		bool valid = readTable(ss, literal);

 		if(not valid)
 			break;
	}


	// displyData(passOne);
	// cout<<endl<<endl;

	// displyTable(symbol);
	// displyTable(literal);


	for(int i = 0; i < passOne.size(); i++) {

		output.push_back(analysisLine(passOne[i]));
	}


	displyData(output);



	fclose(stdin);
	fclose(stdout);
}

/*
---Assebmly-----|------Pass 1-----------------|-----Pass 2-----
START 100 		| (AD, 1) (C ,100)			  | ----------- 
A DS 3  		| 100 (DL, 2) (C ,3)  		  | 100 2 
L1 MOVER AREG F | 103 (IS, 4) (REGS, 1)(S ,3) | 103 4 1 102 
ADD BREG ='1' 	| 104 (IS, 1) (REGS, 2)(L, 1) | 104 1 2 100
D EQU F+1 		| 	  (AD, 04)				  | -----------
L1 PRINT DC 	| 105 (IS, 10)(S ,4)		  | 105 10 103
ORIGIN A-1 		| 	  (AD, 03)				  | ----------- 
C DC ='5' 		| 99  (DL, 1) (L, 2) 		  | 99 1 101 
LTORG 			| 	  (AD, 05)				  | ----------- 
F DS 20 		| 102 (DL, 2) (C ,20) 		  | 102 2 
STOP			| 122 (IS, 0) 				  | 122 0 
END 			|	  (AD, 2) 				  | ----------- 


Symbol Table : 
1   A   100     
5   C   99      
4   D   103     
3   F   102     
2   L1  105     


Literal Table : 
1   ='1'100     
2   ='5'101     


(AD,1) (C,100)
100 (DL,2) (C,3)
103 (IS,4) (REGS,1) (S,3)
104 (IS,1) (REGS,2) (L,1)
(AD,4)
105 (IS,10) (S,4)
(AD,3)
(DL,1) (L,2)
(AD,5)
(DL,2) (C,20)
122 (IS,0)
(AD,2)
- Symbol
1 A 100
5 C 99
4 D 103
3 F 102
2 L1 105
- Literal
1 ='1' 100
2 ='5' 101

*/