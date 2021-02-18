#Approach
#Two pointer

string reverseWord(string str){
    
  //Your code here
  int len = str.length();
  for (int i = 0, j = len - 1; i < j; i++, j--) {
      char temp = str[j];
      str[j] = str[i];
      str[i] = temp;
  }
  
  return str;
}