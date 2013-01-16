function bateria (esc)
%BATERIA Summary of this function goes here
%   Detailed explanation goes here
for i=1:2
    if i==1;
%         nothing
    else
        plot(scdatavx.time,scdatavx.signals(1,1).values)
    end
    esc=esc+1;
    sim('PIDPitch');
    hold on,plot(scdatavx.time,scdatavx.signals(1,1).values)
    
end

end