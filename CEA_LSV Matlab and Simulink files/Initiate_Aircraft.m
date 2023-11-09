clear
clc
format shortE

g = 9.80665;                       % m/s²

% Adcione ao "path" do Matlab a pasta dos arquivos
% Matlab/Simulink do repositório e suas subpastas

% Aeronave para simular
Cessna_182

%%
% Getting initial X Plane data 

init = sim("Initial_Data.slx");
p0 = double(init.P0(end)); q0 = double(init.Q0(end)); r0 = double(init.R0(end)); % rad/s
theta0 = double(init.theta0(end))*pi/180; phi0 = double(init.phi0(end))*pi/180; psi0 = double(init.psi0(end))*pi/180; % rad
X0 = -double(init.Z0(end)); Y0 = double(init.X0(end)); Z0 = -double(init.Y0(end)); % m

VInertial_mps = transpose([-double(init.vZ0(end)) double(init.vX0(end)) -double(init.vY0(end))]); % mps inertial
VB_mps = HorizonToBody(VInertial_mps,psi0,theta0,phi0); % mps body

u0 = VB_mps(1); v0 = VB_mps(2); w0 = VB_mps(3); %m/s
clear init

