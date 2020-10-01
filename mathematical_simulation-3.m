x = 1:10; 
    y1 = x + randn(1,10); 
    scatter(x,y1,25,'b','*') 
    P = polyfit(x,y1,1);
    yfit = P(1)*x+P(2);
    hold on;
    plot(x,yfit,'r-.');