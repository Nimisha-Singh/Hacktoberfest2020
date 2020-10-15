ptcircle= 0;
for i=1:100000
   p=2*rand(1,2)-1;
   if(p(1)^2+p(2)^2<=1)
      ptcircle = ptcircle+1;
   end
  end
  estimated_pi = 4*ptcircle/i
  pi 