%% function rutaExp=intermedio(r)
% Añade a la ruta puntos intermedios.
% Devuleve otra ruta con lo puntos añadidos.
function rutaExp=intermedio(r,n)
rutaO=r;
j=1;
[nVertices,trash]=size(rutaO);
for i=0:nVertices-1
   if i==0
       incremento=rutaO(i+1,:)/n;
       for k=1:n;
           rutaExp(j,:)=incremento*k;
           j=j+1;
       end
       disp(rutaExp);
   else
       incremento=(rutaO(i,:)-rutaO(i+1,:))/n;
       for k=1:n;
           rutaExp(j,:)=rutaO(i,:)-incremento*k;
           j=j+1;
       end
   end
end
%rutaExp=rutaO(nVertices,:);
%disp(rutaExp)

