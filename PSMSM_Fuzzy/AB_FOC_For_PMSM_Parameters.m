% Article for PMSM Control with IFOC
% -------Parameters--------:
Rs = 2.98;                   %Resistance Rs
Ld = 7e-2;                   %Inductance Ld
Lq = 7e-2;                   %Inductance Lq
L = Ld;
flux = 0.125;                %flux
pole = 2;                    %motor pole
J = 0.47e-4;                 %Inertia moment
B = 11e-5;                   %Friction constant
Id_ref = 0;                  
speed_ref = 500;

% -------Controller--------:
% PI current-control loop
Ts = 0.008;                  %Settling time  
zeta = 1; %damping ratio
wn = 5*zeta/Ts; %natural frequency of current loop 
Kcq = (2*zeta*wn*L) - Rs; 
t_iq = (2*zeta*L*wn-Rs) / (wn^2 * L);
%PI speed-control loop
wns = wn/10; %natural frequency of speed loop
Kcs = ((2*zeta*wns) - (B/J)) / ((1.5 *(pole^2)*flux)/J);
t_is = (2*zeta*wns -(B/J))/(wns^2);

f_spwm = 10;
% -------Informations--------:
%{
Range of motor speed for PID: 
    input: -2 / 285
    output: -0.1 / 2.7
Range of Id:
    input: -182/3.4
    output: -60/-33

Range of Iq:
    input: -0.4/0.4
    output: -103.2/36.2




%}