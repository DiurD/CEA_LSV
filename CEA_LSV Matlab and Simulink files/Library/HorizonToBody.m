function [T_B] = HorizonToBody(T_H,psi,theta,phi)
T_F1H = [ cos(psi) sin(psi) 0;
         -sin(psi) cos(psi) 0;
            0       0       0];

TF2F1 = [ cos(theta)    0      -sin(theta);
            0           1       0;
          sin(theta)    0       cos(theta)];

TBF2 = [    1     0             0;
            0     cos(phi)      sin(phi);   
            0     -sin(phi)     cos(phi)];

T_B = TBF2*TF2F1*T_F1H*T_H;

end