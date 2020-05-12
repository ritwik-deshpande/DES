#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

int sbox[16][16]{
  0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
  0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
  0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
  0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
  0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
  0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
  0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
  0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
  0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
  0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
  0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
  0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
  0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
  0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
  0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
  0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16 };

int rsbox[16][16] = {
  0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
  0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
  0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
  0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
  0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
  0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
  0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
  0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
  0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
  0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
  0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
  0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
  0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
  0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
  0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
  0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d };


string hex2bin(string s){ 
        // hexadecimal to binary conversion 
    unordered_map<char, string> mp; 
    mp['0']= "0000"; 
    mp['1']= "0001"; 
    mp['2']= "0010"; 
    mp['3']= "0011"; 
    mp['4']= "0100"; 
    mp['5']= "0101"; 
    mp['6']= "0110"; 
    mp['7']= "0111"; 
    mp['8']= "1000"; 
    mp['9']= "1001"; 
    mp['A']= "1010"; 
    mp['B']= "1011"; 
    mp['C']= "1100"; 
    mp['D']= "1101"; 
    mp['E']= "1110"; 
    mp['F']= "1111"; 
    string bin=""; 
    for(int i=0; i<s.size(); i++){ 
    	if(s[i]>=97)
    		s[i] = s[i] - 32;
        bin+= mp[s[i]]; 
    } 
    return bin; 
} 
string bin2hex(string s){ 
        // binary to hexadecimal conversion 
    unordered_map<string, string> mp; 
    mp["0000"]= "0"; 
    mp["0001"]= "1"; 
    mp["0010"]= "2"; 
    mp["0011"]= "3"; 
    mp["0100"]= "4"; 
    mp["0101"]= "5"; 
    mp["0110"]= "6"; 
    mp["0111"]= "7"; 
    mp["1000"]= "8"; 
    mp["1001"]= "9"; 
    mp["1010"]= "A"; 
    mp["1011"]= "B"; 
    mp["1100"]= "C"; 
    mp["1101"]= "D"; 
    mp["1110"]= "E"; 
    mp["1111"]= "F"; 
    string hex=""; 
    for(int i=0; i<s.length(); i+=4){ 
        string ch=""; 
        ch+= s[i]; 
        ch+= s[i+1]; 
        ch+= s[i+2]; 
        ch+= s[i+3]; 
        hex+= mp[ch]; 
    } 
    return hex; 
} 

int bin2dec(string n) 
{ 
    string num = n; 
    int dec_value = 0; 
  
    // Initializing base value to 1, i.e 2^0 
    int base = 1; 
  
    int len = num.length(); 
    for (int i = len - 1; i >= 0; i--) { 
        if (num[i] == '1') 
            dec_value += base; 
        base = base * 2; 
    } 
  
    return dec_value; 
} 


typedef struct WordNode
{
	bitset<32> word_32;
} Word;

bitset<32> SubWord(bitset<32> input){
	bitset<32> output; 
	
	string answer = "";
	bitset<32> retval;

	for (int i = 0; i < 32; i = i + 8)
	{
		/* code */
		int row = bin2dec(bitset<4>(input.to_string(),i,4).to_string());
		int col = bin2dec(bitset<4>(input.to_string(),i+4,4).to_string());

		
		answer = answer + bitset<8>(sbox[row][col]).to_string();

	}

	return bitset<32>(answer);

}

bitset<32> invSubWord(bitset<32> input){
	bitset<32> output; 
	
	string answer = "";
	bitset<32> retval;

	for (int i = 0; i < 32; i = i + 8)
	{
		/* code */
		int row = bin2dec(bitset<4>(input.to_string(),i,4).to_string());
		int col = bin2dec(bitset<4>(input.to_string(),i+4,4).to_string());

		
		answer = answer + bitset<8>(rsbox[row][col]).to_string();

	}

	return bitset<32>(answer);

}

bitset<32> RotWord(bitset<32> input,string dir){
	bitset<32> output;
	if(dir == "left"){
		string padding = "";
	    for (int i = 0; i < 24; ++i)
	    {
	    	/* code */
	    	padding = padding + "0";
	    }
		bitset<32> wrapper((padding + input.to_string()),24,8);
		//cout<<"Wrapper "<<bin2hex(wrapper.to_string())<<endl;
		output = input<<8;

		output = output^wrapper;

	}
	else{
		string padding = "";
	    for (int i = 0; i < 24; ++i)
	    {
	    	/* code */
	    	padding = padding + "0";
	    }
	    string wrap_temp = "";
	    string inp_str = bin2hex(input.to_string());

	    wrap_temp = wrap_temp + inp_str[inp_str.size()-2] + inp_str[inp_str.size()-1];

	    wrap_temp = hex2bin(wrap_temp);
		bitset<32> wrapper(( wrap_temp + padding));

		//cout<<"Wrapper "<<bin2hex(wrapper.to_string())<<endl;
		output = input>>8;

		output = output^wrapper;
	}
    
	return output;


}
void KeyGeneration(vector<Word> &key_words,string cipherkey_128){

	for(int i=0;i<4;i++){
		string temp = "";
		for (int j = 0; j < 8; ++j)
		{
			temp = temp + cipherkey_128[8*i + j];
		}
		//cout<<temp<<"     The hex value is "<<hex2bin(temp)<<"       "<<hex2bin(temp).size()<<endl;
		key_words[i].word_32 = bitset<32>(hex2bin(temp));

		
	}

	string rcon_strings[] = {"01000000","02000000","04000000","08000000","10000000","20000000","40000000","80000000","1B000000","36000000"};
	vector<bitset<32>> RCon(10);
	for (int i = 0; i < 10; ++i)
	{
		RCon[i] = bitset<32>(hex2bin(rcon_strings[i]));
	}
	

	bitset<32> t;

	for (int i = 4; i < 44; ++i)
	{
		/* code */
		if(i%4 != 0){
			key_words[i].word_32 = key_words[i-1].word_32^key_words[i-4].word_32;
		}
		else{
			//cout<<"After Left Shift"<<bin2hex(RotWord(key_words[i-1].word_32).to_string())<<endl;
			
			t = SubWord(RotWord(key_words[i-1].word_32,"left"))^RCon[(i/4) -1];
			
			//cout<< "After Entire Process"<<bin2hex(t.to_string())<<endl;

			key_words[i].word_32 = key_words[i-4].word_32 ^ t;

		}
		//cout<<"Round Key Generated"<<bin2hex(key_words[i].word_32.to_string())<<endl;
	}

}


void displayState(vector<Word> state){

	for (int i = 0; i < 4; ++i)
	{
		/* code */
		cout<<bin2hex(state[i].word_32.to_string())<<" "<<endl;
			
	}
	cout<<endl;

}

void getRoundKey(vector<Word> &round_key,int round_number,vector<Word> key_words){

	string round_key_text = "";

	for (int i = 0; i < 4; ++i)
	{
		/* code */
		round_key_text = round_key_text + bin2hex(key_words[round_number*4 + i].word_32.to_string());
	}
	//round_key_text = key_words[0].word_32.to_string() + key_words[8*j + 2*i].word_32.to_string() + key_words[8*j + 2*i].word_32.to_string() + key_words[8*j + 2*i].word_32.to_string()

	// cout<<"Key for round "<<round_number<<endl;
	// cout<<round_key_text<<endl;
	for (int i = 0; i < 4; ++i)
	{
		/* code */
		string temp = "";
		for (int j = 0; j < 4; ++j)
		{
			temp = temp + round_key_text[8*j + 2*i]+ round_key_text[8*j + 1 + 2*i];
		}
		//cout<<temp<<endl;
		round_key[i].word_32 = bitset<32>(hex2bin(temp));
	}
}

void shiftRows(bitset<32> &input ,int number_of_shifts){
	for (int i = 0; i < number_of_shifts; ++i)
	{
		/* code */

		input = RotWord(input,"left");
	}
}

void invshiftRows(bitset<32> &input ,int number_of_shifts){
	for (int i = 0; i < number_of_shifts; ++i)
	{
		/* code */

		input = RotWord(input,"right");
	}
}

bitset<8> multiply(bitset<8> a,bitset<8> b){

	bitset<8> modulo("00011011");
	bitset<8> answer("00000000");
	for (int i = 0; i < 8; ++i)
	{
		
		if(b[i] == 1){
			
			answer = answer^a;

		}
			


		if(a[7] == 1){
			a = a<<1;

			a = a^modulo;

		}
		else{
			a = a<<1;
		}

	}//cout<<answer<<endl;
	return answer;
}

string mixColumns(string column){

	vector<bitset<8>> t(4);
	vector<bitset<8>> col(4);


	string retval;
	
	for (int i = 0; i < 4; ++i)
	{
		/* code */
		string temp ="";
		

		temp = temp + column[2*i] + column[2*i+1];
		
		
		t[i] = bitset<8>(hex2bin(temp));
		// cout<<temp<<endl;
		// cout<<t[i]<<endl;
	}

	//cout<<multiply(bitset<8>("10011110"),bitset<8>("00100110"))<<endl;

	col[0] = multiply(t[0],bitset<8>(0x02))^multiply(t[1],bitset<8>(0x03))^t[2]^t[3];
	col[1] = multiply(t[1],bitset<8>(0x02))^multiply(t[2],bitset<8>(0x03))^t[0]^t[3];
	col[2] = multiply(t[2],bitset<8>(0x02))^multiply(t[3],bitset<8>(0x03))^t[0]^t[1];
	col[3] = multiply(t[3],bitset<8>(0x02))^multiply(t[0],bitset<8>(0x03))^t[1]^t[2];

	for (int i = 0; i < 4; ++i)
	{
		//cout<<"Final Result is:"<<bin2hex(col[i].to_string())<<endl;
		retval = retval + bin2hex(col[i].to_string());
	}

	
	// cout<<"Col 0 is"<<col<<endl;
	// retval = retval + col.to_string();
	return retval;

}

string invmixColumns(string column){

	vector<bitset<8>> t(4);
	vector<bitset<8>> col(4);


	string retval;
	
	for (int i = 0; i < 4; ++i)
	{
		/* code */
		string temp ="";
		

		temp = temp + column[2*i] + column[2*i+1];
		
		
		t[i] = bitset<8>(hex2bin(temp));
		// cout<<temp<<endl;
		// cout<<t[i]<<endl;
	}

	//cout<<multiply(bitset<8>("10011110"),bitset<8>("00100110"))<<endl;

	col[0] = multiply(t[0],bitset<8>(0x0e))^multiply(t[1],bitset<8>(0x0b))^multiply(t[2],bitset<8>(0x0d))^multiply(t[3],bitset<8>(0x09));
	col[1] = multiply(t[1],bitset<8>(0x0e))^multiply(t[2],bitset<8>(0x0b))^multiply(t[3],bitset<8>(0x0d))^multiply(t[0],bitset<8>(0x09));
	col[2] = multiply(t[2],bitset<8>(0x0e))^multiply(t[3],bitset<8>(0x0b))^multiply(t[0],bitset<8>(0x0d))^multiply(t[1],bitset<8>(0x09));
	col[3] = multiply(t[3],bitset<8>(0x0e))^multiply(t[0],bitset<8>(0x0b))^multiply(t[1],bitset<8>(0x0d))^multiply(t[2],bitset<8>(0x09));

	for (int i = 0; i < 4; ++i)
	{
		//cout<<"Final Result is:"<<bin2hex(col[i].to_string())<<endl;
		retval = retval + bin2hex(col[i].to_string());
	}

	
	// cout<<"Col 0 is"<<col<<endl;
	// retval = retval + col.to_string();
	return retval;

}

void ApplyRoundKey(vector<Word> &state,int round_number,vector<Word> key_words){

	//cout<<"Apply Round Key"<<endl;

	vector<Word> round_key(4);

	getRoundKey(round_key,round_number,key_words);
	
	for (int i = 0; i < 4; ++i)
	{
		/* code */
		state[i].word_32 = state[i].word_32^round_key[i].word_32;
	}

}

string encrypt(string plaintext_128,vector<Word> key_words){

	vector<Word> state(4);
	for(int i=0;i<4;i++){
		string temp = "";
		for (int j = 0; j < 4; ++j)
		{
			temp = temp + plaintext_128[8*j + 2*i] + plaintext_128[8*j + 1 + 2*i];
		}
		//cout<<temp<<endl;
		//cout<<temp<<"     The hex value is "<<hex2bin(temp)<<"       "<<hex2bin(temp).size()<<endl;
		state[i].word_32 = bitset<32>(hex2bin(temp));

		
	}

	// cout<<"Initial State"<<endl;
	// displayState(state);

	ApplyRoundKey(state,0,key_words);

	// cout<<"At the end of round 0"<<endl;
	// displayState(state);


	//Round 1

	for(int round = 1;round <=9;round++){
		for (int i = 0; i < 4; ++i)
		{
			/* code */
			state[i].word_32 = SubWord(state[i].word_32);
		}
		//displayState(state);

		for (int i = 0; i < 4; ++i)
		{
			/* code */
			shiftRows(state[i].word_32,i);
		}
		//displayState(state);
		vector<string> mixed_columns(4);
		
		for (int i = 0; i < 4; ++i)
		{
			/* code */
			string column = "";
			string row;
			for (int j = 0; j < 4; ++j)
			{
				/* code */
				row = bin2hex(state[j].word_32.to_string());
				
				column = column + row[2*i] + row[2*i+1];
				
			}
			//cout<<"Columns is:"<<column<<endl;
			mixed_columns[i] = mixColumns(column);
		}
		for (int i = 0; i < 4; ++i) { 		
		/* code */ 		
		// state[i].word_32 =   		
		string temp = ""; 		
			for (int j = 0; j < 4; ++j) { 			/* code */ 			
					temp = temp + mixed_columns[j][2*i] + mixed_columns[j][2*i+1]; 		
				} 		
			//cout<<"The row is"<<temp<<endl; 
			state[i].word_32 = bitset<32> (hex2bin(temp));	
		}

		// cout<<" After mix columns "<<round<<endl;
		// displayState(state);

		ApplyRoundKey(state,round,key_words);



		// cout<<"End of Round  "<<round<<endl;
		// displayState(state);
		// 

	}

	for (int i = 0; i < 4; ++i)
	{
		/* code */
		state[i].word_32 = SubWord(state[i].word_32);
	}
	//displayState(state);

	for (int i = 0; i < 4; ++i)
	{
		/* code */
		shiftRows(state[i].word_32,i);
	}

	ApplyRoundKey(state,10,key_words);

	// cout<<"End of Round  10 "<<endl;

	// displayState(state);

	string temp_answer = "";
	string final_answer = "";

	for (int i = 0; i < 4; ++i)
	{
		/* code */
		temp_answer = temp_answer + bin2hex(state[i].word_32.to_string());
	}
	string t1,t2;
	for (int i = 0; i < 4; ++i)
	{
		/* code */
		for (int j = 0; j < 4; ++j)
		{
			/* code */

			t1 = temp_answer[8*j + 2*i];
			
			if(t1[0]>= 65 && t1[0]<97)
				t1[0] = t1[0] + 32;

			t2 = temp_answer[8*j + 2*i + 1];
			
			if(t2[0]>= 65 && t2[0]<97)
				t2[0] = t2[0] + 32;


			string temp = t1+t2;
			
			final_answer = final_answer + temp;
		}

	}

	return final_answer;
}


string decrypt(string cipher_128,vector<Word> key_words){

	vector<Word> state(4);
	for(int i=0;i<4;i++){
		string temp = "";
		for (int j = 0; j < 4; ++j)
		{
			temp = temp + cipher_128[8*j + 2*i] + cipher_128[8*j + 1 + 2*i];
		}
		//cout<<temp<<endl;
		//cout<<temp<<"     The hex value is "<<hex2bin(temp)<<"       "<<hex2bin(temp).size()<<endl;
		state[i].word_32 = bitset<32>(hex2bin(temp));

		
	}

	// cout<<"Initial State"<<endl;
	// displayState(state);

	ApplyRoundKey(state,10,key_words);

	// cout<<"At the end of round 0"<<endl;
	// displayState(state);


	//Round 1

	for(int round = 9;round >0;round--){


		for (int i = 0; i < 4; ++i)
		{
			/* code */
			invshiftRows(state[i].word_32,i);
		}

		for (int i = 0; i < 4; ++i)
		{
			/* code */
			state[i].word_32 = invSubWord(state[i].word_32);
		}
		//cout<<"Cancelled Round"<<round + 1<<endl;
		// displayState(state);

		ApplyRoundKey(state,round,key_words);

		
		// cout<<"After row shifts"<<endl;
		//displayState(state);
		vector<string> mixed_columns(4);
		
		for (int i = 0; i < 4; ++i)
		{
			/* code */
			string column = "";
			string row;
			for (int j = 0; j < 4; ++j)
			{
				/* code */
				row = bin2hex(state[j].word_32.to_string());
				
				column = column + row[2*i] + row[2*i+1];
				
			}
			//cout<<"Columns is:"<<column<<endl;
			mixed_columns[i] = invmixColumns(column);
		}
		for (int i = 0; i < 4; ++i) { 		
		/* code */ 		
		// state[i].word_32 =   		
		string temp = ""; 		
			for (int j = 0; j < 4; ++j) { 			/* code */ 			
					temp = temp + mixed_columns[j][2*i] + mixed_columns[j][2*i+1]; 		
				} 		
			//cout<<"The row is"<<temp<<endl; 
			state[i].word_32 = bitset<32> (hex2bin(temp));	
		}
		// cout<<" After mix columns "<<round<<endl;
		// displayState(state);
		

	}

	for (int i = 0; i < 4; ++i)
	{
		/* code */
		invshiftRows(state[i].word_32,i);
	}

	for (int i = 0; i < 4; ++i)
	{
		/* code */
		state[i].word_32 = invSubWord(state[i].word_32);
	}
	//displayState(state);

	

	ApplyRoundKey(state,0,key_words);

	// cout<<"After round 10"<<endl;
	// displayState(state);

	string temp_answer = "";
	string final_answer = "";

	for (int i = 0; i < 4; ++i)
	{
		/* code */
		temp_answer = temp_answer + bin2hex(state[i].word_32.to_string());
	}
	string t1,t2;
	for (int i = 0; i < 4; ++i)
	{
		/* code */
		for (int j = 0; j < 4; ++j)
		{
			/* code */

			t1 = temp_answer[8*j + 2*i];
			
			if(t1[0]>= 65 && t1[0]<97)
				t1[0] = t1[0] + 32;

			t2 = temp_answer[8*j + 2*i + 1];
			
			if(t2[0]>= 65 && t2[0]<97)
				t2[0] = t2[0] + 32;


			string temp = t1+t2;
			
			final_answer = final_answer + temp;
		}

	}

	return final_answer;



}



string Slice(string plaintext,int start,int end){
  string retval = "";
  for(int i = start;i<end;i++){
    retval = retval + plaintext[i];
  }
  return retval;
}

int main(){

	string plaintext = "00112233445566778899aabbccddeeff1234";
	string cipherkey_128 = "000102030405060708090a0b0c0d0e0f";
	string ciphertext;
	int pt_size;
	int initial_size;
	int blocks;
	string pt_block;
	string ct_block;
	//string temp_plaintext;
	vector<Word> key_words(44);

	

	KeyGeneration(key_words,cipherkey_128);

	// for (int i = 0; i < 44; ++i)
	// {
	// 	/* code */
	// 	//cout<<"Key Word "<<i<<"  "<<bin2hex(key_words[i].word_32.to_string())<<endl;
	// }

	blocks = ceil((float)plaintext.size()/(float)32);

	pt_size = blocks*32;

	initial_size = plaintext.size();
   for(int i = 0;i<pt_size - initial_size;i++){
    plaintext = plaintext +'0';
   }

   for(int i = 0;i<blocks;i++){

      pt_block = Slice(plaintext,i*32,(i+1)*32);

     // cout<<pt_block<<endl;
      ciphertext = ciphertext + encrypt(pt_block,key_words);
      //cout<<ciphertext<<endl;

   }


	cout<<ciphertext<<endl;

	plaintext = "";
	for(int i = 0;i<blocks;i++){

      ct_block = Slice(ciphertext,i*32,(i+1)*32);

     // cout<<pt_block<<endl;
      plaintext =plaintext + decrypt(ct_block,key_words);
      //cout<<ciphertext<<endl;

   }


	cout<<plaintext<<endl;

	return 0;
}