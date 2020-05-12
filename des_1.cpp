#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

//initial permutation


int IP[] = 
{
 58, 50, 42, 34, 26, 18, 10, 2,
 60, 52, 44, 36, 28, 20, 12, 4,
 62, 54, 46, 38, 30, 22, 14, 6,
 64, 56, 48, 40, 32, 24, 16, 8,
 57, 49, 41, 33, 25, 17,  9, 1,
 59, 51, 43, 35, 27, 19, 11, 3,
 61, 53, 45, 37, 29, 21, 13, 5,
 63, 55, 47, 39, 31, 23, 15, 7
};
// Expanstion D box
int ED[] = 
{
 32,  1,  2,  3,  4,  5,
  4,  5,  6,  7,  8,  9,
  8,  9, 10, 11, 12, 13,
 12, 13, 14, 15, 16, 17,
 16, 17, 18, 19, 20, 21,
 20, 21, 22, 23, 24, 25,
 24, 25, 26, 27, 28, 29,
 28, 29, 30, 31, 32,  1
};
// P-box
int P[] = 
{
 16,  7, 20, 21,
 29, 12, 28, 17,
  1, 15, 23, 26,
  5, 18, 31, 10,
  2,  8, 24, 14,
 32, 27,  3,  9,
 19, 13, 30,  6,
 22, 11,  4, 25
};
// Final permutation
int FP[] = 
{
 40, 8, 48, 16, 56, 24, 64, 32,
 39, 7, 47, 15, 55, 23, 63, 31,
 38, 6, 46, 14, 54, 22, 62, 30,
 37, 5, 45, 13, 53, 21, 61, 29,
 36, 4, 44, 12, 52, 20, 60, 28,
 35, 3, 43, 11, 51, 19, 59, 27,
 34, 2, 42, 10, 50, 18, 58, 26,
 33, 1, 41,  9, 49, 17, 57, 25
};
// S-boxes
int S1[4][16] = 
{
14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7,
0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8,
4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0,
15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13,
};

int S2[4][16] = 
{
15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10,
3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5,
0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15,
13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9
};

int S3[4][16] = 
{
10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8,
13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1,
13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7,
1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12
};

int S4[4][16] = 
{
7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15,
13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9,
10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4,
3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14
};

int S5[4][16] = 
{
2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9,
14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6,
4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14,
11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3
};

int S6[4][16] = 
{
12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11,
10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8,
9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6,
4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13
};

int S7[4][16]= 
{
4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1,
13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6,
1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2,
6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12
};

int S8[4][16]= 
{
13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7,
1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2,
7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8,
2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11
};
int CP_56[56]=  
    {    57,49,41,33,25,17,9, 
        1,58,50,42,34,26,18, 
        10,2,59,51,43,35,27, 
        19,11,3,60,52,44,36,           
        63,55,47,39,31,23,15, 
        7,62,54,46,38,30,22, 
        14,6,61,53,45,37,29, 
        21,13,5,28,20,12,4 
    };
// No. of bit shifts  
    int BITSHIFTS[16]= 
    {    1, 1, 2, 2, 
        2, 2, 2, 2,  
        1, 2, 2, 2,  
        2, 2, 2, 1 
    };
//compression D-box
int CD_48[48]= 
{ 14,17,11,24,1,5, 
3,28,15,6,21,10, 
23,19,12,4,26,8, 
16,7,27,20,13,2, 
41,52,31,37,47,55, 
30,40,51,45,33,48, 
44,49,39,56,34,53, 
46,42,50,36,29,32 
};

typedef struct HashMapNode
{
  int arr[4][16];
  
}HashMap;

template<int X,int Y>
bitset<X> PBoxOperation(bitset<Y> key_in_binary,int PTable[]){
  
   bitset<X> retval;
   for(int i= 0;i<X;i++){
       retval[X - 1 - i] = key_in_binary[Y - PTable[i]];
   }

   return retval;
}

bitset<48> generateRoundKey(bitset<56> &key_in_binary_56,int roundShift){
   

    
        string str_key_56 = key_in_binary_56.to_string();
        bitset<28> left_half(str_key_56,0,28);
      
        bitset<28> right_half(str_key_56,28,28);

        for(int k=0;k<roundShift;k++){
            int temp = right_half[27];
            right_half = right_half<<1;
            right_half[0] = temp;
        }
        
        for(int k=0;k<roundShift;k++){
            int temp = left_half[27];
            left_half = left_half<<1;
            left_half[0] = temp;
        }
        
        
        
        bitset<56> combine_key_in_binary_56(left_half.to_string()+right_half.to_string());
   
   key_in_binary_56 = combine_key_in_binary_56;
   return PBoxOperation<48,56>(key_in_binary_56,CD_48);
   
}
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

vector<bitset<48>> keyGeneration(string key){
   vector<bitset<48>> key_for_rounds(16);
  // bitset<64> key_in_binary_64;
   
  bitset<56> key_in_binary_56;
  
   
   
   bitset<64> key_in_binary_64(key);
   
  // cout<<"The initial key is"<<key<<endl;
   
   key_in_binary_56 = PBoxOperation<56,64>(key_in_binary_64,CP_56);
   //cout<<"The 56 bit key is: "<<bin2hex(key_in_binary_56.to_string())<<endl;
   
   for(int i =0;i<16;i++){
       key_for_rounds[i] = generateRoundKey(key_in_binary_56,BITSHIFTS[i]);
    
      //cout<<"Round Key:"<<i<<":  "<<bin2hex(key_for_rounds[i].to_string())<<endl;
   }

   return key_for_rounds;
   
}

bitset<32> mixer(bitset<32> left_half,bitset<32> right_half,bitset<48> key_for_round,HashMap sboxes[8]){

   // cout<<"Mixer function"<<endl;
    bitset<48> temp;



    temp = PBoxOperation<48,32>(right_half,ED);

    temp = key_for_round^temp;


    string sbox_result = "";
    int j = 0;
    for(int i=0;i<8*6;i=i+6){

      int row = bin2dec(to_string(temp[47 - i]) + to_string(temp[47 - i -5]));

      int col = bin2dec(to_string(temp[47 - i - 1]) +to_string(temp[47 -i - 2]) +to_string(temp[47-i-3]) +to_string(temp[47-i-4]));
     // cout<<"row :"<<row<<"col :"<<col<<"Value :"<<sboxes[j].arr[row][col]<<endl;
      sbox_result = sbox_result + bitset<4> (sboxes[j].arr[row][col]).to_string();
     // cout<<sbox_result<<endl;
      j++;
    }

    bitset<32> retval(sbox_result);

    retval = PBoxOperation<32,32>(retval,P);

    retval = left_half^retval;


    //cout<<retval<<endl;

    return retval;


    
    
}

void copy(HashMap &h,int arr[4][16] ,int row,int col){

  for (int i = 0; i < row; ++i)
    {
       for (int j = 0; j < col; ++j)
       {
         /* code */
          h.arr[i][j] = arr[i][j];
       }
    }

}

string bin2ASCII(string data){

    std::stringstream sstream(data);
    std::string output;
    while(sstream.good())
    {
        std::bitset<8> bits;
        sstream >> bits;
        char c = char(bits.to_ulong());
        output += c;
    }

    return output;
}


string ASCII2bin(string s) 
{ 
    int n = s.length(); 
  
    string retval = "";
    for (int i = 0; i < n; i++) 
    { 
        // convert each char to 
        // ASCII value 
        int val = int(s[i]); 
  
        // Convert ASCII value to binary 
        string bin = ""; 
        while (val > 0) 
        { 
            (val % 2)? bin.push_back('1') : 
                       bin.push_back('0'); 
            val /= 2; 
        } 
        reverse(bin.begin(), bin.end()); 
  
        bitset<8> bs(bin);
       // cout<<s[i]<<" :"<<bin<<"  :"<<bin.size()<<endl;
        retval = retval + bs.to_string();
    } 

    return retval;
} 


string encrypt(string plaintext,string key){

   vector<bitset<48>> key_for_rounds(16);
  
   
   bitset<64> pt_binary_64(plaintext);
   //cout<<"Initial State:"<<bin2hex(pt_binary_64.to_string())<<endl;
      
   pt_binary_64 = PBoxOperation<64,64>(pt_binary_64,IP);

   // cout<<"Initial permutation:"<<bin2hex(pt_binary_64.to_string())<<endl;
   
   key_for_rounds = keyGeneration(key);

   HashMap sboxes[8];
   copy(sboxes[0],S1,4,16);
   copy(sboxes[1],S2,4,16);
   copy(sboxes[2],S3,4,16);
   copy(sboxes[3],S4,4,16);
   copy(sboxes[4],S5,4,16);
   copy(sboxes[5],S6,4,16);
   copy(sboxes[6],S7,4,16);
   copy(sboxes[7],S8,4,16);
   
   bitset<32> left_half(pt_binary_64.to_string(),0,32);
   bitset<32> right_half(pt_binary_64.to_string(),32,32); 

   bitset<32> temp;

   for (int i = 0; i < 16; ++i)
   {
     /* code */
      temp = left_half;
     
      left_half = right_half;
      
      
      right_half = mixer(temp,right_half,key_for_rounds[i],sboxes);
     // cout<<"after round  "<<i<<endl;
      bitset<64> temp1(left_half.to_string() + right_half.to_string());
     // cout<<bin2hex(temp1.to_string())<<endl;

   }

   // cout<<"Final Result"<<endl;

   // cout<<left_half<<endl;
   // cout<<right_half<<endl;
   

   bitset<64> ct_binary_64(right_half.to_string() + left_half.to_string());

   ct_binary_64 = PBoxOperation<64,64>(ct_binary_64,FP);


   //cout<<"Binary CT"<<ct_binary_64<<endl;
   // cout<<"Final permutation"<<endl;
   // cout<<bin2hex(ct_binary_64.to_string())<<endl;
   
   return ct_binary_64.to_string();
}


string decrypt(string ciphertext,string key){

   vector<bitset<48>> key_for_rounds(16);
  
   
   bitset<64> ct_binary_64(ciphertext);

   //cout<<"Initial State:"<<bin2hex(ct_binary_64.to_string())<<endl;
      
   ct_binary_64 = PBoxOperation<64,64>(ct_binary_64,IP);
  // cout<<"Initial permutation:"<<bin2hex(ct_binary_64.to_string())<<endl;
   key_for_rounds = keyGeneration(key);

   HashMap sboxes[8];
   copy(sboxes[0],S1,4,16);
   copy(sboxes[1],S2,4,16);
   copy(sboxes[2],S3,4,16);
   copy(sboxes[3],S4,4,16);
   copy(sboxes[4],S5,4,16);
   copy(sboxes[5],S6,4,16);
   copy(sboxes[6],S7,4,16);
   copy(sboxes[7],S8,4,16);
   
   bitset<32> left_half(ct_binary_64.to_string(),0,32);
   bitset<32> right_half(ct_binary_64.to_string(),32,32); 

   bitset<32> temp;

   for (int i = 15; i >=0; i--)
   {
     /* code */
      temp = left_half;
     
      left_half = right_half;
      
      
      right_half = mixer(temp,right_half,key_for_rounds[i],sboxes);
     // // cout<<"after round  "<<i<<endl;
     //  bitset<64> temp1(left_half.to_string() + right_half.to_string());
     //  cout<<bin2hex(temp1.to_string())<<endl;
   }

  // right_half = mixer(left_half,right_half,key_for_rounds[0],sboxes);
   // cout<<"Final Result"<<endl;

   // cout<<left_half<<endl;
   // cout<<right_half<<endl;
   

   bitset<64> pt_binary_64(right_half.to_string() + left_half.to_string());

   //cout<<"final round befor FP:"<<bin2hex(pt_binary_64.to_string())<<endl;
   pt_binary_64 = PBoxOperation<64,64>(pt_binary_64,FP);

  // cout<<"final round after FP:"<<bin2hex(pt_binary_64.to_string())<<endl;

   //cout<<"Binary CT"<<ct_binary_64<<endl;
   //cout<<bin2hex(ct_binary_64.to_string())<<endl;
   
   return pt_binary_64.to_string();
}

string Slice(string plaintext,int start,int end){
  string retval = "";
  for(int i = start;i<end;i++){
    retval = retval + plaintext[i];
  }
  return retval;
}

int main (){
   string plaintext;
   string key;
   string pt_block;
   string ct_block;
   string ciphertext = "";
   int blocks;
   int pt_size;
   int initial_size;
   // cin>>plaintext;
   // cin>>key;

   plaintext = "asdfghjk";
   key = "asdfghjk";
   // cout<<key<<endl;

   



   blocks = ceil((float)plaintext.size()/(float)8);
   pt_size = blocks*64;

   //cout<<blocks<<endl;
   plaintext = ASCII2bin(plaintext);
   key = ASCII2bin(key);

   initial_size = plaintext.size();
   for(int i = 0;i<pt_size - initial_size;i++){
    plaintext = plaintext +'0';
   }


   //cout<<"Final PlainText is"<<plaintext<<endl;

   for(int i = 0;i<blocks;i++){

      pt_block = Slice(plaintext,i*64,(i+1)*64);

     // cout<<pt_block<<endl;
      ciphertext = ciphertext + encrypt(pt_block,key);
      //cout<<ciphertext<<endl;

   }
   cout<<ciphertext<<endl;
   //cout<<"PlainText"<<plaintext<<endl;
   
   plaintext = "";
  for(int i = 0;i<blocks;i++){

      ct_block = Slice(ciphertext,i*64,(i+1)*64);

     // cout<<pt_block<<endl;
      plaintext =plaintext + decrypt(ct_block,key);
      //cout<<ciphertext<<endl;

   }
   cout<<plaintext<<endl;

   //plaintext = "0110000101110011011001000110011001100111011010000110101001101011011011";
   



   return 0;
}
