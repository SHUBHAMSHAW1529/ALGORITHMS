lo fast_power(lo base,lo power)
{
 lo result=1;
 while(power>0)
 {
   if(power%2==1)
   result=(result%m*base%m)%m;
   base=(base%m*base%m)%m;
   power/=2;
 }
 return result;
}
