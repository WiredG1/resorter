unsigned int multibleIndexOf(String str, char c){
  str += c;
  unsigned int l = str.length();
  unsigned int counter = 0;
  for(unsigned int i = 0; i < l; i++){
     if(str[i] == c){
      counter++;
     }
  }
  return counter;
}

String* split(String str, char c, int occurrences){
  String* re = new String[occurrences];
  for(unsigned int i = 0; i < occurrences; i++){
    int ind = str.indexOf(c);
    re[i] = str.substring(0,ind);
    str = str.substring(ind+1);
  }
  return re;
}

