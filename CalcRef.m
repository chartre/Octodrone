function CurrRef = CalcRef (SPpos, LastRef, Ts, radio)
%%bla bla bla

maxVx = 3;
maxVy = 1.85;

DistXY = SPpos -LastRef;

if (norm(DistXY)>(0.5*radio))
    CurrRef = LastRef + 0*DistXY;
else
        minTx=abs(DistXY(1))/maxVx;
        minTy=abs(DistXY(2))/maxVy;
        minT=max(minTx,minTy);
        
        if minT<Ts
            CurrRef = SPpos;
        else
            CurrRef= LastRef+(Ts/minT)*DistXY
        end
end
