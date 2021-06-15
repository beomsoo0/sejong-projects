function P = Probable_Lottery(m,r,n)
    P = C_Lottery(r,m) *  C_Lottery(n-r, r-m) /   C_Lottery(n, r);
   
    function C = C_Lottery(n, r)
      C = factorial(abs(n)) / (factorial(abs(r)) * factorial(abs(n-r)));
    end

end
