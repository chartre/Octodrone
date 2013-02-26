function PIDtest
sim('comparando_modelos');
figure
hold on;
plot(PIDtestscdata.time,PIDtestscdata.signals(1,1).values)
grid
