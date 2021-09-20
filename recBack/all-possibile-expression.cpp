#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace chrono;
#define ll long long int
#define MOD 1000000007
#define vi vector<ll>
#define pi pair<ll, ll>
#define vb vector<bool>
#define vs vector<string>
#define newline(n) for(int i = 0; i < (n); i++ )cout<<endl;
#define infor(vect) for(auto it : (vect)) { cout<<it<<endl; }
#define ump unordered_map
#define mp map
#define v2d(name, m, n, inti) vector<vi>(name)(m, vi(n, inti))
#define MOD 1000000007

/*
problem statement -> Print all possible expressions that evaluate to a target
Problem link -> https://www.geeksforgeeks.org/print-all-possible-expressions-that-evaluate-to-a-target/
*/

bool isItoperator(char ch) {

	return ch == '+' or ch == '-' or ch == '/' or ch == '*' or ch == '^';
}



int evaluateExpression(string expression) {

	//	BODMAS
	vector<string> segemts;
	string temp;
	for(int i = 0; i < expression.size(); i++) {


		if(isItoperator(expression[i])) {

			segemts.push_back(temp);
			temp = "";
			temp.push_back(expression[i]);
			segemts.push_back(temp);
			temp = "";
		}
		else {

			temp.push_back(expression[i]);
		}
	}

	segemts.push_back(temp);


	for(auto it : segemts) {

		cout<<it<<endl;
	}

	return 2;



}


// void possibleExpressions(string str, int target, string expsf) {


// }


int main() {

	freopen("../io/input.txt", "r", stdin);
	freopen("../io/output.txt", "w", stdout);
	auto start = high_resolution_clock::now();


  

	string str;
	cin>>str;
	int target;
	cin>>target;

	evaluateExpression(str);












	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout<<"\n\nTime :"<<(duration.count()/1000.0)<<" ms" << endl;
	fclose(stdin);
	fclose(stdout);


}

/*

// CPP program to evaluate a given
// expression where tokens are
// separated by space.
#include <bits/stdc++.h>
using namespace std;

// Function to find precedence of
// operators.
int precedence(char op){
	if(op == '+'||op == '-')
	return 1;
	if(op == '*'||op == '/')
	return 2;
	return 0;
}

// Function to perform arithmetic operations.
int applyOp(int a, int b, char op){
	switch(op){
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
	}
}

// Function that returns value of
// expression after evaluation.
int evaluate(string tokens){
	int i;
	
	// stack to store integer values.
	stack <int> values;
	
	// stack to store operators.
	stack <char> ops;
	
	for(i = 0; i < tokens.length(); i++){
		
		// Current token is a whitespace,
		// skip it.
		if(tokens[i] == ' ')
			continue;
		
		// Current token is an opening
		// brace, push it to 'ops'
		else if(tokens[i] == '('){
			ops.push(tokens[i]);
		}
		
		// Current token is a number, push
		// it to stack for numbers.
		else if(isdigit(tokens[i])){
			int val = 0;
			
			// There may be more than one
			// digits in number.
			while(i < tokens.length() &&
						isdigit(tokens[i]))
			{
				val = (val*10) + (tokens[i]-'0');
				i++;
			}
			
			values.push(val);
			
			// right now the i points to
			// the character next to the digit,
			// since the for loop also increases
			// the i, we would skip one
			// token position; we need to
			// decrease the value of i by 1 to
			// correct the offset.
			i--;
		}
		
		// Closing brace encountered, solve
		// entire brace.
		else if(tokens[i] == ')')
		{
			while(!ops.empty() && ops.top() != '(')
			{
				int val2 = values.top();
				values.pop();
				
				int val1 = values.top();
				values.pop();
				
				char op = ops.top();
				ops.pop();
				
				values.push(applyOp(val1, val2, op));
			}
			
			// pop opening brace.
			if(!ops.empty())
			ops.pop();
		}
		
		// Current token is an operator.
		else
		{
			// While top of 'ops' has same or greater
			// precedence to current token, which
			// is an operator. Apply operator on top
			// of 'ops' to top two elements in values stack.
			while(!ops.empty() && precedence(ops.top())
								>= precedence(tokens[i])){
				int val2 = values.top();
				values.pop();
				
				int val1 = values.top();
				values.pop();
				
				char op = ops.top();
				ops.pop();
				
				values.push(applyOp(val1, val2, op));
			}
			
			// Push current token to 'ops'.
			ops.push(tokens[i]);
		}
	}
	
	// Entire expression has been parsed at this
	// point, apply remaining ops to remaining
	// values.
	while(!ops.empty()){
		int val2 = values.top();
		values.pop();
				
		int val1 = values.top();
		values.pop();
				
		char op = ops.top();
		ops.pop();
				
		values.push(applyOp(val1, val2, op));
	}
	
	// Top of 'values' contains result, return it.
	return values.top();
}

int main() {
	cout << evaluate("10 + 2 * 6") << "\n";
	cout << evaluate("100 * 2 + 12") << "\n";
	cout << evaluate("100 * ( 2 + 12 )") << "\n";
	cout << evaluate("100 * ( 2 + 12 ) / 14");
	return 0;
}

// This code is contributed by Nikhil jindal.











*/