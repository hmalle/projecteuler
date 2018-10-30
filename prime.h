#ifndef prime.h
#define prime.h

bool isprime( int num){
  //Ignore all integers less than 2
  if (num<2){
    return false;
  }
  //Take care of 2 and 3
  if (num ==2||num==3 ){
    return true;
  }
  //Checks if num%6 ==1 or -5 then check for its primality
  if (num%6==1||num%6==5){
    int sx= 6;
    for (int i=1;(6*i-1)<=int(sqrt(num)); i++) {
      sx = 6*i;
      if(num%(sx-1)==0 || num%(sx+1)==0){
        return false;
      }
    }
    return true;
  }
}

bool miller_rabin(int n){

}

#endif
