#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define vs vector<string>
#define pi pair<ll, ll>
#define table map<string, pair<int,int>>
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))

// map<string, int> imperative; // IS
// map<string, int> declarative; //DL
// map<string, int> registers; //REGS
// map<string, int> assembly; // AD

namespace formats {

	ostream &field(ostream &input) {

		input.setf(ios::left);
		input.fill(' ');
		input.width(8);
		return input;
	}

	ostream &nums(ostream &input) {

		input.setf(ios::left);
		input.fill(' ');
		input.width(4);
		return input;
	}
};

using namespace formats;

map<string, pair<string, int> > mnemonic;
map<string, pair<int,int>> symbol;
map<string, pair<int,int>> literal;
stack<pair<string, string> > remaning;

void readDirectives() {
	
	// IS
	vector<pair<string, int> > temp = {
		{ "STOP", 0 },
		{ "ADD", 1 },
		{ "SUB", 2 },
		{ "MULT", 3 },
		{ "MOVER", 4 },
		{ "MOVEM", 5 },
		{ "COMP", 6 },
		{ "BC", 7 },
		{ "DIV", 8 },
		{ "READ", 9 },
		{ "PRINT", 10 }
	};

	for(auto it : temp) {

		mnemonic[it.first] = { "IS",   it.second };
	}


	// registers 
	vector<string> regs = {
		"AREG",
		"BREG",
		"CREG",
		"DREG",
		"EREG",
		"FREG"
	};

	for(int i = 0; i < regs.size(); i++) {

		mnemonic[regs[i]] = { "REGS", i+1 };
	}


	// Assembly => AD  
	// start  01
	// end  02
	// origin 03
	// equ 05
	// ltorg 05

	vector<string> ad = {

		"START",
		"END",
		"ORIGIN",
		"EQU",
		"LTORG"
	};

	for(int i = 0; i < ad.size(); i++) {

		mnemonic[ad[i]] = { "AD", i+1 };
	}
	

	// declarative
	mnemonic["DC"] = { "DL", 1 };
	mnemonic["DS"] = { "DL", 2 };
}

bool isConstant(string str, int &val) {


	if(str[0] >= '0' and str[str.size()-1] <= '9') {
		
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

bool isLiteral(string str) {

	return str[0] == '=' and str[1] == '\'' and str[str.size()-1] == '\'';
}

string handelliteral(string &instruction, int &pc) {

	if(literal.count(instruction) != 0) {

		return "(L, " + to_string(literal[instruction].first) + ")";
	}
	else {

		literal[instruction] = { literal.size()+1, pc };
		return "(L, " + to_string(literal[instruction].first) +")";
	}
}

void assignAddressToLiteral(int &pc) {

	// cout<<"\nbefore"<<pc<<endl;

	for(auto &it: literal) {

		auto &tuple = it.second;
		pc++;
		tuple.second = pc;
		// cout<<"\n"<<pc<<endl;
	}
	pc++;
}

vs handelImperative(vs &line, int &pc) {

	vs output;
	int old = pc;
	output.push_back(to_string(pc));

	for(int i = 0; i < line.size(); i++) {

		string str;
		if(mnemonic.count(line[i])) {

			auto it = mnemonic[line[i]];
			str = "(" + it.first + ", " + to_string(it.second) +")";
		}
		else {

			int constant = 0;
			if(isLiteral(line[i])) {
				//if literal
				str = handelliteral(line[i], pc);
			}
			else if(isConstant(line[i], constant)) {
				// constant
				pc += constant;
				str = "(C ," + line[i] +")";
			}
			else {

				//table map<string, pair<int,int>> 
			// 			symbol, 	sr, address

				if(i == 0) {

					if(symbol.count(line[i]) == 0) {

						symbol[line[i]] = { symbol.size()+1, pc };
					}
					else {
						symbol[line[i]].second = pc;
					}
					
				} else {

					if(symbol.count(line[i]) == 0) {

						symbol[line[i]] = { symbol.size()+1, 0 };
					}
					str = "(S ," + to_string(symbol[line[i]].first) +")";
				}
			}
		}
		if(str.size() > 0)
			output.push_back(str);
	}

	if(old == pc)
		pc++;
	return output;
}

vs handelAssembly(vs &line, int &pc) {

	vs output;
	
	int old = pc;

	// AD
	// no pc here
	// 
	// "START",
	// "END",
	// "ORIGIN",-> change ---------
	// "EQU", > assign value---------
	// "LTORG" -> assign pc to all literals ---
	output.push_back("0");
	for(int i = 0; i < line.size(); i++) {

		string str;
		if(mnemonic.count(line[i])) {

			auto it = mnemonic[line[i]];
			str = "(" + it.first + ", " + to_string(it.second) +")";

			if(line[i] == "LTORG") {

				// cout<<" here "<<pc<<endl;
				assignAddressToLiteral(pc);
				output.push_back("(AD, 05)");
				return output;
			}
			else if(line[i] == "EQU") {

				string variable = line[i-1];

				string value = line[i+1];
				string sym;
				sym.push_back(value[0]);
				// cout<<value[0]<<endl;
				// cout<<endl<<variable<<" "<<value<<" "<<sym<<endl;
				if(symbol.count(variable) == 0) {

					symbol[variable] = { symbol.size()+1, 0};
				}

				if(symbol.count(sym) == 0) {

					symbol[sym] = { symbol.size()+1, 0};
				}

				if(symbol[sym].second != 0) {

					symbol[variable].second = symbol[sym].second + stoi(value[2]+"");
				}
				else {
					remaning.push({ variable, value });
				}

				output.push_back("(AD, 04)");
				return output;
			}
			else if(line[i] == "ORIGIN") {

				string next = line[i+1];

				char operation = next[1];
				string s;
				s.push_back(next[0]);
				int constant = next[2] - '0';

				pc = symbol[s].second;

				if(operation == '-') 
					pc -= constant;
				else
					pc += constant;

				output.push_back("(AD, 03)");
				return output;
			}
		}
		else {

			int constant = 0;
			if(isLiteral(line[i])) {
				//if literal
				str = handelliteral(line[i], pc);
			}
			else if(isConstant(line[i], constant)) {
				// constant
				pc += constant;
				str = "(C ," + line[i] +")";
			}
		}

		if(str.size() > 0)
			output.push_back(str);
	}

	if(old == pc)
		pc++;
	return output;
}

vs handelDeclarative(vs &line, int &pc) {

	vs output;

	output.push_back(to_string(pc));
	for(int i = 0; i < line.size(); i++) {

		string str;
		if(mnemonic.count(line[i])) {

			auto it = mnemonic[line[i]];
			str = "(" + it.first + ", " + to_string(it.second) +")";
		}
		else {

			int constant = 0;
			if(isLiteral(line[i])) {
				//if literal
				str = handelliteral(line[i], pc);
			}
			else if(isConstant(line[i], constant)) {
				// constant
				pc += constant;
				str = "(C ," + line[i] +")";
			}
			else {

				//table map<string, pair<int,int>> 
			// 			symbol, 	sr, address

				if(i == 0) {

					if(symbol.count(line[i]) == 0) {

						symbol[line[i]] = { symbol.size()+1, pc };
					}
					else {
						symbol[line[i]].second = pc;
					}
					
				} else {

					if(symbol.count(line[i]) == 0) {

						symbol[line[i]] = { symbol.size()+1, 0 };
					}
					str = "(S ," + to_string(symbol[line[i]].first) +")";
				}
			}
		}

		if(str.size() > 0)
			output.push_back(str);
	}

	return output;
}

vs scanLine(vs &line, int &pc) {

	vs output;
	int old = pc;
	string type;

	for(int i = 0; i < line.size(); i++) {

		if(mnemonic.count(line[i]) != 0) {

			auto it = mnemonic[line[i]];
			// it contain type and number
			// map<string, pair<string, int> > mnemonic;
			
			if(it.first == "IS" or it.first == "AD" or it.first == "DL") {
				type = it.first;
				break;
			}
		}
	}

	if(type == "IS") {

		output = handelImperative(line, pc);
	}
	else if(type == "AD") {

		output = handelAssembly(line, pc);
	}
	else if(type == "DL") {

		output = handelDeclarative(line, pc);
	}

	return output;
}

void assignValueToRemainingSymbols() {

	while(not remaning.empty()) {

		auto it = remaning.top();
		remaning.pop();
	
		string temp, operation, val;
		temp.push_back(it.second[0]);
		int ival = 0;
		if(it.second.size() >= 2) {

			operation.push_back(it.second[1]);
			val.push_back(it.second[2]);
			ival = stoi(val);

			if(operation == "-")
				ival -= symbol[temp].second;
			else
				ival += symbol[temp].second;
		}
		else {

			ival = symbol[temp].second;
		}

		symbol[it.first].second = ival;
	}
}

string isUndefinedHere() {

	string ans;

	for(auto it: symbol) {

		// map<string, pair<int,int>>
			  // symbol sr, add
		auto tuple = it.second;

		if(tuple.second == 0) {

			ans += ( "Symbol " + it.first + " is not defined\n");
		}
	}



	return ans;
}

namespace display {

	void disply(vector<vs> output) {

		for(int i = 0; i < output.size(); i++)
		{
			int x;
			for(int j = 0; j < output[i].size(); j++) {

				if(isConstant(output[i][j], x)) {

					if(x == 0)
						cout<<nums<<" ";
					else
						cout<<nums<<output[i][j];
				}
				else {

					cout<<field<<output[i][j];				
				}
			}
			cout<<endl;
		}
	}

	void displyTable(table &tt, string msg) {


		cout<<endl<<endl<<msg<<" : \n";

		for(auto it: tt) {
			auto tuple = it.second;
			cout<<nums<<tuple.first<<nums<<it.first<<field<<tuple.second<<endl;
		}
		// cout<<endl<<endl;
	}
};

using namespace display;

int main() {

		
	string str;
	readDirectives();
	vector<vs> output;
	int programCounter = 0;
	while(getline(cin, str)) {

		stringstream ss(str);
		vs instructions;
 
		while(getline(ss, str, ' ')) {

			instructions.push_back(str);
		}
		output.push_back(scanLine(instructions, programCounter));
		
	}
		

	assignValueToRemainingSymbols();

	string err = isUndefinedHere();

	if(err.size() >= 1) {

		cout<<err;
	}
	else {
		disply(output);
		displyTable(symbol, "Symbol Table");
		displyTable(literal, "Literal Table");
	}
}



/*
------Assembly code-----------pass-1 ------

start 100				(AD, 01) (C, 100)			-------------
A DS 3				100 (DL, 02) (C, 3)				100 02
L1 MOVER AREG, B 	103 (IS, 04) (1) 		(S, 3)	103 04 01 101
ADD BREG '1'		104 (IS, 01) (2)		(L, 1)	104 01 02 100
D EQU B+1				(AD, 04)					-------------
L1 PRINT D 			105 (IS, 10) (S, 4)				105 10 00 102
ORIGIN A-1				(AD, 03)					-------------
C DC '5'			99	(DL, 01) (L, 2)				99 01
LTORG					(AD, 05)					-------------
B DS 20				102 (DL, 02) (C, 20)			102 02
STOP				122 (IS, 00)					122 00
END						(AD, 02)					-------------

------------symbolTable--------------

srNo	symbolTable 	Address  
 1			A 				100
 2			L1				103
 3			B 				101
 4			D 				102
 5			C 				99

 ---------------LiteralTable---------

srNo	symbolTable 	Address
 1 			1'				100

*/
