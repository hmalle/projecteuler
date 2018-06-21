#ifndef prime.h
#define prime.h

bool isprime( int num)
{
  if ( num< 2 ) 
    return false;
  if (num ==2 or num==3 )
    return true;
  if (num%2==0 or num%3==0)
    return false;
  if (num %6 ==1 or num%6==5 ) {
    int sx= 6;
    for (int i=1; (6*i-1)<=int(sqrt(num)); i++) {
      sx = 6*i;
      if ( num%(sx-1)==0 or num%(sx+1)==0 )
      return false;
    }
    return true;
  }
}

bool miller_rabin(int n){
}

#endif
