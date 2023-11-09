% % Cessna 182 data
S_ft2 = 174;                    % ft²
mean_c_ft = 4.9;                % ft
b_ft = 36;                      % ft
max_deflections = 5;           % deg

% Cruise flight characteristics 
Alt_ft = 5000;                  % ft
M = 0.201;           
True_speed_ftps = 220.1;        % ft/s
q_bar_lbspft2 = 49.6;           % lbs/ft²
CG_percentCMA = 0.264;          % %CMA
alpha_deg = 0;                  % °
mass_lbs = 2650;                % lbs
Ixx_slugft2 = 948;              % slug.ft²
Iyy_slugft2 = 1346;             % slug.ft²
Izz_slugft2 = 1967;             % slug.ft²
Ixz_slugft2 = 0;                % slug.ft²
Inertia = [Ixx_slugft2       0       -Ixz_slugft2;
               0         Iyy_slugft2        0;
          -Ixz_slugft2       0        Izz_slugft2].*1.3558179619;

% Stability 

C_D0 = 0.027;
C_Dalpha = 0.121;
C_DdeltaE = 0;

C_L0 = 0.307;
C_Lalpha = 4.41;
C_Lalphadot = 1.7;
C_Lq = 3.9;
C_LdeltaE = 0.43;

C_m0 = 0.04;
C_malpha = -0.613;
C_malphadot = -7.27;
C_mq = -12.4;
C_mdeltaE = -1.122;

C_lbeta = -0.0923;
C_lp = -0.484;
C_lr = 0.0798;
C_ldeltaA = 0.229;
C_ldeltaR = 0.0147;

C_Ybeta =-0.393;
C_Yp = -0.075;
C_Yr = 0.214;
C_YdeltaA = 0;
C_YdeltaR = 0.187;

C_nbeta = 0.0587;
C_np = -0.0278;
C_nr = -0.0937;
C_ndeltaA = -0.0216;
C_ndeltaR = -0.0645;

% Propulsive system
T_max_N = 4690;                 % N
V_ref_mps = 30;                 % m/s
rho_ref_kgpm3 = 1.225;          % kg/m³
n_v = -1;
n_rho = 1;
eta_T_deg = 0;                  % °