#include <string>
#include <vector>
using namespace std;
#define MAX 1001
#include <iostream>

//LONGEST COMMON SUBSTRING
//SANTIAGO TORRES ALVAREZ A01177356


void solve(string string1, string string2){
  
  int LCS[string1.length()][string2.length()];
  int maximo =0;
  for(int i =0; i<string1.length()-1;i++){
    if(string1[i] == string2[0]){
      LCS[i][0] = 1;
      maximo = 1;
    } 
    else{
      LCS[i][0] = 0;
    }
  }

  for(int j = 0;j<string2.length()-1;j++){
    if(string1[0] == string2[j]){
      LCS[0][j] =1;   
      maximo =1; 
    }else{
      LCS[0][j] = 0; 
    } 
  }
   
  for(int i=1; i<string1.length()-1;i++){
    for(int j=1 ; j < string2.length()-1; j++){
      if(string1[i] == string2[j]){
         //asignar lcs en[i-1][j-1] +1 a pos[i][j]
         LCS[i][j] = LCS[i-1][j-1] + 1;
        if(LCS[i][j] > maximo){
          maximo = LCS[i][j];
        }
      }
      else{
        LCS[i][j]= 0;
      }
    }
  }
  cout << maximo << endl;
  //cout << LCS[string1.length()-1][string2.length()-1] << endl;

}

int main() {
  string string1, string2;
  int casos;
  int aux = 1;
  cin >> casos;
  while(casos--){
    cin >> string1 >> string2;
    cout << "Case " << aux++ << ": " ;
    solve(string1, string2);
  }
  
}