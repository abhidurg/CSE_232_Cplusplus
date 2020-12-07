/*
 * Abhiram Durgaraju
 * CSE 232
 * Project 04 - Run-length encoding
 */

#include<iostream>
using std::cout; using std::cin; using std::endl;
#include<iomanip>
using std::setprecision;
#include<string>
using std::string;

// global variable, as per requirements
const string code = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

string encode_seq(string seq, char encoder) {
	string res = "";
	if (seq.length() <= 3) {
		//don't encode
		return seq;
	}
	else {
		res.push_back(encoder);
		res.push_back(code.at(seq.length() - 4));
			res.push_back(seq.at(0));
	}
	return res;
}


string encode(string to_encode, char encoder) {
	string seq = "";
	string res = "";
	for (char c : to_encode) {
		if (seq.empty() || c == seq.back()) {
			//add this char to current seq
			seq.push_back(c);
		} 
		else {
			//send seq to encode_seq fcn and append to res, reset seq
			res += encode_seq(seq, encoder);
			seq.clear();
			seq.push_back(c);
		}
	}
	res += encode_seq(seq, encoder); //ensures final seq gets added to res string
	return res;
}

string decode_seq(string seq, char encoder) {
	string res = "";
	long num = 4 + code.find(seq.at(1));
	char c = seq.at(2);
	res.assign(num, c);
	return res;
}

string decode(string to_decode, char encoder) {
	string seq = "";
	string res = "";
	for (decltype(to_decode.length()) i = 0; i < to_decode.length(); ++i) {
		char c = to_decode.at(i);
		if (c == encoder) {
			//decode 3-char seq, and skip second two chars of encoded seq in to_decode string
			res += decode_seq(to_decode.substr(i, 3), encoder);
			i += 2; 
		}
		else {
			//add non-encoded char to res
			res.push_back(c);
		}
	}
	return res;
}

double reduction(string original, string encoded) {
	double ratio = static_cast<double>(encoded.length()) / static_cast<double>(original.length());
	return ratio;
}

int main (){
  long test_num;
  cin >> test_num;

  switch(test_num) { //access case based on test_num

  case 1: {
    string input;
    char sep;
    cin >> input;
    cin >> sep;
    cout << encode_seq(input, sep);
    break;
  }

  case 2:{
    string input;
    char sep;
    cin >> input;
    cin >> sep;
    cout << encode(input, sep);
    break;
  }

  case 3:{
    string input;
    char sep;
    cin >> input;
    cin >> sep;
    cout << decode_seq(input, sep);
    break;
  }

  case 4:{
    string input;
    char sep;
    cin >> input;
    cin >> sep;
    cout << decode(input, sep);
    break;
  }

  case 5:{
    string s1,s2;
    cin >> s1;
    cin >> s2;
    cout << setprecision(2);
    cout << reduction(s1,s2);
    break;
  }
    
  } 
}  