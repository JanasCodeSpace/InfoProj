clear all;
close all;
clc;

data = dlmread('08_path.csv');

X = data(:,1);
Y = data(:,2);
Z = data(:,3) * 50;


for i=1:length(X)-1
plot3(Y(i:i+1),X(i:i+1),Z(i:i+1));
hold on;
%plot3(Y,X,Z);
axis equal;
pause(0.3)
end